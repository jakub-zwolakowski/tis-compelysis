# -- C files --

ifeq ($(main_C_files),)
  main_C_files=$(wildcard *.c)
endif

ifeq ($(other_C_files),)
  other_C_files =
endif

# -- Executables --

executables = $(patsubst %.c, %.out, $(main_C_files))

all: $(executables)

%.out: %.c
	-gcc -g -O0 -I. $< $(other_C_files) -lm -lpthread -o $@

# -- Tests --

test_results = $(patsubst %.out, %.test-result, $(executables))

%.test-result: %.out
	@echo ""
	@echo "--- Running test '$<' ---"
	@echo ""
	-./$< > $@ 2>&1
	@# -echo "DUMMY" > $@ 2>&1 # For FLP30

test: $(test_results)


# -- gcc --

gcc_results = $(patsubst %.out, %.gcc-result, $(executables))

%.gcc-result: %.c
	@echo ""
	@echo "--- gcc '$<' ---"
	@echo ""
	-gcc -Wall -Wpedantic -g -O0 -I. $< $(other_C_files) -lm -lpthread > $@ 2>&1

gcc: $(gcc_results)


# -- clang --

clang_results = $(patsubst %.out, %.clang-result, $(executables))

%.clang-result: %.c
	@echo ""
	@echo "--- clang '$<' ---"
	@echo ""
	-clang -std=c17 -Werror -pedantic -pedantic-errors -g -O0 -I. $< $(other_C_files) -lm -lpthread > $@ 2>&1

clang: $(clang_results)

# -- UBSan --

UBSan_executables = $(patsubst %.c, %.UBSan-out, $(main_C_files))
UBSan_results = $(patsubst %.UBSan-out, %.UBSan-run, $(UBSan_executables))

%.UBSan-out: %.c
	-clang -fsanitize=undefined -I. $< $(other_C_files) -lm -lpthread -o $@

%.UBSan-run: %.UBSan-out
	@echo ""
	@echo "--- UBSan on '$<' ---"
	@echo ""
	-./$< > $@ 2>&1
	@# -echo "DUMMY" > $@ 2>&1 # For FLP30

ubsan: $(UBSan_results)

# -- Valgrind --

valgrind_results = $(patsubst %.out, %.valgrind-run, $(executables))

%.valgrind-run: %.out
	@echo ""
	@echo "--- Valgrind on '$<' ---"
	@echo ""
	-valgrind --leak-check=yes ./$< > $@ 2>&1
	@# -echo "DUMMY" > $@ 2>&1 # For FLP30

valgrind: $(valgrind_results)

# -- TIS --

%.tis: %.c
	@echo ""
	@echo "--- TrustInSoft Analyzer on '$<' ---"
	@echo ""
	env TIS_ADVANCED_FLOAT=1 tis-analyzer --interpreter $< $(other_C_files)

tis: $(patsubst %.c, %.tis, $(main_C_files))

# -- Markdown --

markdown_files = $(patsubst %.c, %.md, $(main_C_files))

%.md: %.c %.test-result %.gcc-result %.clang-result %.UBSan-run %.valgrind-run
	echo "## $*" > $@
	echo "### Test" >> $@
	echo '```' >> $@
	cat $*.test-result >> $@
	echo '```' >> $@
	echo "### gcc" >> $@
	echo '```' >> $@
	cat $*.gcc-result >> $@
	echo '```' >> $@
	echo "### clang" >> $@
	echo '```' >> $@
	cat $*.clang-result >> $@
	echo '```' >> $@
	echo "### UBSan" >> $@
	echo '```' >> $@
	cat $*.UBSan-run >> $@
	echo '```' >> $@
	echo "### Valgrind" >> $@
	echo '```' >> $@
	cat $*.valgrind-run >> $@
	echo '```' >> $@
	ls *.md | xargs -n 1 sed -i -E 's/==[0-9]+==/==12345==/g'
	ls *.md | xargs -n 1 sed -i -E 's/0x[a-zA-Z0-9]{6,12}/0x424242424242/g'
	ls *.md | xargs -n 1 sed -i -E 's/T[0-9]{3,5}/T4242/g'
	ls *.md | xargs -n 1 sed -i -E 's/ [0-9]+,[0-9,]+ bytes/ 123,456 bytes/g'
	ls *.md | xargs -n 1 sed -i -E 's/Result: [0-9]+/Result: 12345/g'


README.md: $(markdown_files)
	echo "# Examples" > README.md
	cat $^ >> README.md

markdown: $(markdown_files) README.md

# -- clean --

clean:
	rm -f a.out
	rm -f $(executables)
	rm -f $(test_results)
	rm -f $(gcc_results)
	rm -f $(clang_results)
	rm -f $(UBSan_executables)
	rm -f $(UBSan_results)
	rm -f $(valgrind_results)
	rm -f $(markdown_files) README.md # These stay.

.PHONY = all clean %.tis markdown
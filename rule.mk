toptargets = all clean test gcc clang ubsan valgrind tis markdown

subdirs := $(wildcard */)

$(toptargets): $(subdirs)

$(subdirs):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(toptargets) $(subdirs)
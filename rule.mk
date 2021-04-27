toptargets = all clean test ubsan valgrind tis markdown

subdirs := $(wildcard */)

$(toptargets): $(subdirs)

$(subdirs):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(toptargets) $(subdirs)
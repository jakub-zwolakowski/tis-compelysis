toptargets = all clean test gcc clang ubsan valgrind tis markdown

subdirs := code-samples demo-caesar CERT_C

$(toptargets): $(subdirs)

$(subdirs):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(toptargets) $(subdirs)
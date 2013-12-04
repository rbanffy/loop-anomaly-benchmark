CC = gcc
 
CCOPT = -O2
 
BUILDDIR = build
 
all: make_builddir \
	$(BUILDDIR)/loop-call-weirdness
 
make_builddir:
	@test -d $(BUILDDIR) || mkdir $(BUILDDIR)
 
$(BUILDDIR)/loop-call-weirdness: loop-call-weirdness.c
	$(CC) $(CCOPT) $^ -o $@
 
clean:
	rm -rf $(BUILDDIR)/*

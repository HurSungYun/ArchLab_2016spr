####################################################
# Students' Makefile for the CS:APP Architecture Lab
####################################################

# Default student id
ID = 2016-11111

# Where are the different parts of the lab should be copied to when they
# are handed in.
HANDINDIR-PARTA = $(ID)/handin-parta
HANDINDIR-PARTB = $(ID)/handin-partb
HANDINDIR-PARTC = $(ID)/handin-partc

sim:
	(cd sim; make)

# Use this rule to handin all
handin:
ifneq	($(wildcard ./$(ID)/handin-part*/.*),)
	rm -r $(ID)
endif
	mkdir -p $(HANDINDIR-PARTA)
	mkdir -p $(HANDINDIR-PARTB)
	mkdir -p $(HANDINDIR-PARTC)
	cp sim/misc/sum.ys $(HANDINDIR-PARTA)/sum.ys
	cp sim/misc/rsum.ys $(HANDINDIR-PARTA)/rsum.ys
	cp sim/misc/copy.ys $(HANDINDIR-PARTA)/copy.ys
	cp sim/seq/seq-full.hcl $(HANDINDIR-PARTB)/seq-full.hcl
	cp sim/pipe/ncopy.ys $(HANDINDIR-PARTC)/ncopy.ys
	cp sim/pipe/pipe-full.hcl $(HANDINDIR-PARTC)/pipe-full.hcl
	tar cvf $(ID).tar $(ID)

clean:
	rm -f *~ *.o
ifneq	($(wildcard ./$(ID)/handin-part*/.*),)
	rm -r $(ID)
endif




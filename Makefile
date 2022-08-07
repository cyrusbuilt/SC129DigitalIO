CC := zcc
CFLAGS := +cpm --list -m -create-app -v
SOURCES := sc129tst.c sc129.c

all: clean sc129tst.com

sc129tst.com: $(SOURCES) Makefile
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

clean:
	rm -rf *.COM *.com *.o *.map *.err *.lis

CC := zcc
CFLAGS := +cpm --list -m -create-app
SOURCES := sc129tst.c sc129.c

all: sc129tst.com

sc129tst.com: $(SOURCES) Makefile
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

clean:
	rm -rf *.COM *.com *.o *.map *.err *.lis

prefix = /usr
mandir = $(PREFIX)/share/man/man1

TARGETS = hq9plus.o

hq9plus: $(TARGETS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o hq9plus $(TARGETS)

hq9plus.o: hq9plus.c
	$(CC) $(CFLAGS) -o hq9plus.o -c hq9plus.c 

install:
	cp hq9plus $(PREFIX)/bin;
	cp doc/hq9plus.1.gz $(MANDIR);

clean:
	rm -f hq9plus;
	rm -f hq9plus.o;

.PHONY: install clean

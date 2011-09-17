#include <stdio.h>

#define VERSION "1.0.0"

void usage()
{
	puts("Usage: hq9plus [OPTIONS]... [file]...\n");
}

void version()
{
	printf("hq9plus version %s\nCopyright (C) 2011 Hiromu Yakura\n", VERSION);
}

void help()
{
	puts("Usage: hq9plus [OPTIONS]... [file]...\n\nOptions:\n\t--version\tShow version number and exit successfully\n\t--help\tShow this help and exit succesfully\n");
}

int main(int argc, char* argv[])
{
	int i, accum = 0;
	char c;
	FILE *fp;

	if(argc > 1) {
		if(!strcmp(argv[1], "--version")) {
			version();
			return 0;
		} else if(!strcmp(argv[1], "--help")) {
			help();
			return 0;
		} else if(freopen(argv[1], "r", stdin) == NULL) {
			fprintf(stderr, "Failed to open file.");
			usage();
			return -1;
		}
	} else {
		usage();
		return -1;
	}

	while((c = getchar()) != EOF) {
		switch(c) {
			case 'H':
			case 'h':
				puts("Hello, world!");
				break;

			case 'Q':
			case 'q':
				fp = fopen(argv[1], "r");
				while((c = getc(fp)) != EOF)
					putchar(c);
				fclose(fp);
				break;

			case '9':
				for (i = 99; i > 1; i--) {
					printf("%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
					printf("Take one down and pass it around, %d bottles of beer on the wall.\n\n", i - 1);
				}
				printf("1 bottles of beer on the wall, 1 bottles of beer.\n");
				printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
				printf("No more bottles of beer on the wall, no more bottles of beer.\n");
				printf("Go to the store and buy some more, 99 bottles of beer on the wall.\n");
				break;

			case '+':
				accum++;
				break;
		}
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <getopt.h>
#include <string.h>
#include "palyn.c"
#define DEBUG 0

bool is_palyn(char* str) {
	int i,j;
	i=0;
	j=strlen(str)-1;
	while(i<j) {
		if (str[i] != str[j]) {
			return false;
		} else {
			i++;
			j--;
		}
	}
	return true;
}

 
void write_line_for_case(int i, char* first_str, char* last_str)
{
	mpz_t first;
	mpz_t last;
	mpz_t ctr;
	mpz_t sqrt_first;
	mpz_t sqrt_last;
	mpz_t tmp;
	mpz_t curr;
 
	mpz_init(first);
	mpz_init(last);
	mpz_init(ctr);
	mpz_set_str(ctr, "0", 10);
	mpz_init(sqrt_first);
	mpz_init(sqrt_last);
	mpz_init(tmp);
	mpz_init(curr);
 
	mpz_set_str(first, first_str, 10);
	mpz_set_str(last, last_str, 10);

	mpz_sqrt(sqrt_first, first);
	if (DEBUG) {
		gmp_printf ("square root of first: %Zd\n", sqrt_first);
	}
	mpz_sqrt(sqrt_last, last);
	if (DEBUG)
		gmp_printf ("square root of last: %Zd\n", sqrt_last);

	char *buf = malloc(256);
	char *buf2 = malloc(256);

	// Is the first elem a fair-and-square ?
	// if (sqrt(first))^2 == first and is_palym(first) and is_palym(sqrt(first))
	//mpz_add(ctr, ctr, 1);
	mpz_mul(tmp, sqrt_first, sqrt_first);
	if (mpz_cmp (first, tmp)) {
		//printf("first elem is not a square\n");
		goto step1;
	}
	char *sqrt_first_str=malloc(256);
	memset(sqrt_first_str, 0, 256);
	mpz_get_str (sqrt_first_str, 10, sqrt_first);
	if (is_palyn(first_str) && is_palyn(sqrt_first_str)) {
		if (DEBUG)
			printf("%s\n", first_str);
		mpz_add_ui (ctr, ctr, 1);
	}

	step1:
	mpz_set (curr, sqrt_first);
	memset(buf, 0, 256);
	memset(buf2, 0, 256);
	mpz_get_str (buf, 10, curr);
	get_next_palyn(buf, buf2);
	mpz_set_str(curr, buf2, 10);

	while(mpz_cmp (curr, sqrt_last) <= 0) {
		// is the square a palyn ?
		mpz_mul(tmp, curr, curr);
		memset(buf2, 0, 256);
		mpz_get_str (buf2, 10, tmp);
		if (is_palyn(buf2)) {
			if (DEBUG)
				printf("%s\n", buf2);
			mpz_add_ui (ctr, ctr, 1);
		}
		// curr = get next palym
		memset(buf, 0, 256);
		memset(buf2, 0, 256);
		mpz_get_str (buf, 10, curr);
		get_next_palyn(buf, buf2);
		mpz_set_str(curr, buf2, 10);
	}

	// Is the last elem a fair-and-square ?
//	mpz_mul(tmp, sqrt_last, sqrt_last);
//	if (mpz_cmp (last, tmp)) {
//		//printf("last elem is not a square\n");
//		goto step2;
//	}
//	char *sqrt_last_str=malloc(256);
//	memset(sqrt_last_str, 0, 256);
//	mpz_get_str (sqrt_last_str, 10, sqrt_last);
//	if (is_palyn(last_str) && is_palyn(sqrt_last_str)) {
//		if (DEBUG)
//			printf("%s\n", last_str);
//		mpz_add_ui (ctr, ctr, 1);
//	}
//	step2:
  	gmp_printf ("Case #%d: %Zd\n", i, ctr);


 /* free used memory */
mpz_clear(first);
mpz_clear(last);
mpz_clear(ctr);
mpz_clear(sqrt_first);
mpz_clear(sqrt_last);
mpz_clear(tmp);
mpz_clear(curr);
free(buf);
free(buf2);
}

char* filename;

int usage(char** argv) {
	printf ("%s -f input_file\n", argv[0]);
	exit(1);
}

char* parse_args(int argc, char **argv) {
	int c;
	while ((c = getopt (argc, argv, "f:")) != -1){
		switch (c) {
			case 'f':
				return optarg;
			default:
				usage(argv);
		}
	}
	usage(argv);
}

int main(int argc, char **argv) {
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int nb_case;
	int i; // indexes in for loop

	char* first=malloc(200);
	char* last=malloc(200);

	filename = parse_args(argc, argv);
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Unable to open \"%s\" for reading\n", filename);
		exit(1);
	}

	// Retrieving first line (should be the number of cases below)
	read = getline(&line, &len, fp);
	nb_case = atoi(line);
	//printf("Number of case: %d\n", nb_map);

	// Working on each lines (we trust the file to be valid)
	for (i=1; i<=nb_case; i++) {
		//printf("\n*** start case %d ******\n", i);
		read = getline(&line, &len, fp);
		char* space;
		char* eof;
		space = strchr(line, ' ');
		eof = strchr(line, '\n');
		memset(first, 0, 200);
		memcpy(first, line, space-line);
		//printf("first: %s\n", first);	
		memset(last, 0, 200);
		memcpy(last, space+1, eof-space-1);
		//printf("last: %s\n", last);	
		write_line_for_case(i, first, last);
	}

	if (line)
		free(line);


	return 0;
}

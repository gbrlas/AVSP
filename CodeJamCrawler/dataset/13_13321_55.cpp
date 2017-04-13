#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <getopt.h>

int check_win(int x, int y) {
	return 0;
}

typedef int bool;
#define true 1
#define false 0

int write_line_for_case(int i, char map[4][4]) {
	int x,y;
//	for (j=0; j<=3; j++) {
//		for (k=0; k<=3; k++) {
//			printf("%c", map[k][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	bool game_has_free_square=false;
	bool o_win=false;
	bool x_win=false;
	char player;
	
	// check for horizontal win
	for (y=0; y<=3; y++) {
		player='T';
		for (x=0; x<=3; x++) {
			if (map[x][y] == '.') {
				game_has_free_square=true;
				break;
			}
			if (map[x][y] ==  'O') {
				if (player == 'T')
					player = 'O';
				if (player == 'X')
					break;
				if (player == 'O' && x==3) {
					o_win = true;
					goto result;
				}
			}
			if (map[x][y] ==  'X') {
				if (player == 'T')
					player = 'X';
				if (player == 'O')
					break;
				if (player == 'X' && x==3) {
					x_win = true;
					goto result;
				}
			}
			if (map[x][y] ==  'T' && x==3) {
				if (player=='X') {
					x_win=true;
					goto result;
				} else {
					o_win=true;
					goto result;
				}
			}
		}
	}

	// check for vertical win.
	for (x=0; x<=3; x++) {
		player='T';
		for (y=0; y<=3; y++) {
			if (map[x][y] == '.') {
				break;
			}
			if (map[x][y] ==  'O') {
				if (player == 'T')
					player = 'O';
				if (player == 'X')
					break;
				if (player == 'O' && y==3) {
					o_win = true;
					goto result;
				}
			}
			if (map[x][y] ==  'X') {
				if (player == 'T')
					player = 'X';
				if (player == 'O')
					break;
				if (player == 'X' && y==3) {
					x_win = true;
					goto result;
				}
			}
			if (map[x][y] ==  'T' && y==3) {
				if (player=='X') {
					x_win=true;
					goto result;
				} else {
					o_win=true;
					goto result;
				}
			}
		}
	}

	// check for diagonal win
	player='T';
	for(x=0; x<=3; x++) {
		if (map[x][x] == '.') {
			break;
		}
		if (map[x][x] == 'O') {
			if (player == 'T') {
				player = 'O';
			}
			if (player == 'X') {
				break;
			}
			if (player == 'O' && x==3) {
				o_win = true;
				goto result;
			}
		}
		if (map[x][x] == 'X') {
			if (player == 'T') {
				player = 'X';
			}
			if (player == 'O') {
				break;
			}
			if (player == 'X' && x==3) {
				x_win = true;
				goto result;
			}
		}
		if (map[x][x] ==  'T' && x==3) {
			if (player=='X') {
				x_win=true;
				goto result;
			} else {
				o_win=true;
				goto result;
			}
		}
	}

	
	player='T';
	for(x=0; x<=3; x++) {
		if (map[x][3-x] == '.') {
			break;
		}
		if (map[x][3-x] == 'O') {
			if (player == 'T') {
				player = 'O';
			}
			if (player == 'X') {
				break;
			}
			if (player == 'O' && x==3) {
				o_win = true;
				goto result;
			}
		}
		if (map[x][3-x] == 'X') {
			if (player == 'T') {
				player = 'X';
			}
			if (player == 'O') {
				break;
			}
			if (player == 'X' && x==3) {
				x_win = true;
				goto result;
			}
		}
		if (map[x][3-x] ==  'T' && x==3) {
			if (player=='X') {
				x_win=true;
				goto result;
			} else {
				o_win=true;
				goto result;
			}
		}
	}
	result:
		if (x_win) {
			printf("Case #%d: X won\n", i);
			return 0;
		}
		if (o_win) {
			printf("Case #%d: O won\n", i);
			return 0;
		}
		if (game_has_free_square) {
			printf("Case #%d: Game has not completed\n", i);
		} else {
			printf("Case #%d: Draw\n", i);
		}
			
	
	return 0;
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
	int nb_map;
	int i,j; // indexes in for loop
	char map[4][4];

	filename = parse_args(argc, argv);
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Unable to open \"%s\" for reading\n", filename);
		exit(1);
	}

	// Retrieving first line (should be the number of map below)
	read = getline(&line, &len, fp);
	nb_map = atoi(line);
	//printf("Number of map: %d\n", nb_map);

	// Working on each lines (we trust the file to be valid)
	for (i=1; i<=nb_map; i++) {
		// read 4 lines and fill map
		for(j=0; j<=3; j++) {
			read = getline(&line, &len, fp);
			map[0][j]=line[0];
			map[1][j]=line[1];
			map[2][j]=line[2];
			map[3][j]=line[3];
		}
		write_line_for_case(i, map);
		// read the blank line
		read = getline(&line, &len, fp);
	}

	if (line)
		free(line);


	return 0;
}

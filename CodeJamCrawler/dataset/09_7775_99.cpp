#include <stdio.h>
#include <assert.h>

#define MAX_DIM 200

struct Cell {
	int id;
	int height;
	int drainstorow, drainstocol;
};

Cell map[MAX_DIM][MAX_DIM];

int main() {
	int t;
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ca++) {
		int h, w;
		scanf("%d%d", &h, &w);
		assert(1 <= h);
		assert(h < MAX_DIM);
		assert(1 <= w);
		assert(w < MAX_DIM);

		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				int h;
				scanf("%d", &h);
				map[r][c].height = h;
			}
		}

		// IO done

		// Build graph & init id
		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				map[r][c].id = -1;
				int minr = r, minc = c;
				if (r > 0 && map[r - 1][c].height < map[minr][minc].height) {minr = r - 1; minc = c;} //North
				if (c > 0 && map[r][c - 1].height < map[minr][minc].height) {minr = r; minc = c - 1;} //West
				if (c < w - 1 && map[r][c + 1].height < map[minr][minc].height) {minr = r; minc = c + 1;} //East
				if (r < h - 1 && map[r + 1][c].height < map[minr][minc].height) {minr = r + 1; minc = c;} //South
				map[r][c].drainstorow = minr;
				map[r][c].drainstocol = minc;
			}
		}

		//Transitive closure
		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				int rr = r, cc = c;
				while (map[rr][cc].drainstorow != rr || map[rr][cc].drainstocol != cc) {
					int rrt = map[rr][cc].drainstorow;
					int cct = map[rr][cc].drainstocol;
					rr = rrt;
					cc = cct;
				}
				int rr2 = r, cc2 = c;
				while (map[rr2][cc2].drainstorow != rr2 || map[rr2][cc2].drainstocol != cc2) {
					int rrt2 = map[rr2][cc2].drainstorow;
					int cct2 = map[rr2][cc2].drainstocol;
					map[rr2][cc2].drainstorow = rr;
					map[rr2][cc2].drainstocol = cc;
					rr2 = rrt2;
					cc2 = cct2;
				}
			}
		}

		//Check
		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				int rr = map[r][c].drainstorow;
				int cc = map[r][c].drainstocol;
				assert(map[rr][cc].drainstorow == rr && map[rr][cc].drainstocol == cc);
			}
		}

		//Assign ids
		int id = 0;
		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				int rr = map[r][c].drainstorow;
				int cc = map[r][c].drainstocol;
				if (map[rr][cc].id < 0) map[rr][cc].id = id++;
			}
		}

		//Output
		printf("Case #%d:\n", ca);
		for (int r = 0; r < h; r++) {
			for (int c = 0; c < w; c++) {
				int rr = map[r][c].drainstorow;
				int cc = map[r][c].drainstocol;
				printf("%c ", 'a' + map[rr][cc].id);
			}
			printf("\n");
		}
	}
	return 0;
}


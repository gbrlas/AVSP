#include <stdio.h>

typedef struct st_el_ladj {
  int comp;
  int next, prev[4], previ;
} ElemAdj;

int t, h, w;
int alt[100][100];

ElemAdj vert[100][100], *ar[80000];
int ar_atual, comp_at;

typedef enum en_dir {N, W, E, S} dir;
int x[] = {-1, 0, 0, 1}, y[] = {0, -1, 1, 0};

char map[26];

int test(int r, int c, dir D) {
  int i, j;
  i = r+x[D];
  j = c+y[D];
  if (i >= 0 && i < h && j >= 0 && j < w && alt[i][j] < alt[r][c])
    return alt[i][j];
  return -1;
}

void flow(int r, int c, dir D) {
  int i, j;
  i = r+x[D];
  j = c+y[D];
  ar[ar_atual] = &(vert[r][c]);
  ar[ar_atual+1] = &(vert[i][j]);
  vert[r][c].next = ar_atual+1;
  vert[i][j].prev[vert[i][j].previ] = ar_atual;
  vert[i][j].previ++;
  ar_atual += 2;
}

void busca_rec(ElemAdj *vert) {
  int i;
  vert->comp = comp_at;
  for (i = 0; i < vert->previ; i++)
    busca_rec(ar[vert->prev[i]]);
}

void busca(int r, int c) {
  busca_rec(&(vert[r][c]));
  comp_at++;
}

int main(void) {
  int i, j, r, c, let_at;

  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    for (j = 0; j < 26; j++)
      map[j] = '\0';

    scanf("%d %d", &h, &w);
    for (r = 0; r < h; r++)
      for (c = 0; c < w; c++) {
	scanf("%d", &(alt[r][c]));
	vert[r][c].next = vert[r][c].comp = -1;
	vert[r][c].previ = 0;
      }

    ar_atual = 0; comp_at = 0;

    /* cria grafo */
    for (r = 0; r < h; r++)
      for (c = 0; c < w; c++) {
	int alt = 10001, t; dir d = N;
	t = test(r, c, N);
	if (t >= 0 && t < alt) {
	  alt = t;
	  d = N;
	}

	t = test(r, c, W);
	if (t >= 0 && t < alt) {
	  alt = t;
	  d = W;
	}

	t = test(r, c, E);
	if (t >= 0 && t < alt) {
	  alt = t;
	  d = E;
	}

	t = test(r, c, S);
	if (t >= 0 && t < alt) {
	  alt = t;
	  d = S;
	}

	if (alt < 10001)
	  flow(r, c, d);
      }

    /* visita (componentes) */
    for (r = 0; r < h; r++)
      for (c = 0; c < w; c++)
	if (vert[r][c].next == -1)
	  busca(r, c);

    let_at = -1;
    printf("Case #%d:\n", i+1);
    for (r = 0; r < h; r++) {
      for (c = 0; c < w; c++) {
	int comp = vert[r][c].comp;
	if (map[comp] == '\0') {
	  let_at++;
	  map[comp] = 'a'+let_at;
	}
	printf("%c", map[comp]);
	if (c < w-1) printf(" ");
      }
      printf("\n");
    }
  }

  return 0;
}

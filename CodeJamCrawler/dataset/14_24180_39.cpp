#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

const int mod = 1000000007;

int M, N;
char slova[15][15];
int podmnozina[15];
int X, Y;
int pocet_v_podmnozine[15];

struct node_t
{
	char pismeno;
	node_t *soused;
	node_t *dite;

	node_t(char pismeno = '\0', node_t *soused = NULL, node_t *dite = NULL)
	{
		this->pismeno = pismeno;
		this->soused = soused;
		this->dite = dite;
	}

	void insert(char *slovo);
};

node_t databaze[1000000];
int id = 0;

void node_t::insert(char *slovo)
{
	node_t *uzel = this;
	for (int i = 0; slovo[i]; i++) {
		char pismeno = slovo[i];
		if (uzel->dite == NULL) {
			uzel->dite = &databaze[id++];
			uzel = uzel->dite;
			uzel->pismeno = pismeno;
			uzel->soused = NULL;
			uzel->dite = NULL;
		} else {
			uzel = uzel->dite;
			while (uzel->pismeno != pismeno && uzel->soused != NULL) {
				uzel = uzel->soused;
			}
			if (uzel->pismeno != pismeno) {
				uzel->soused = &databaze[id++];
				uzel = uzel->soused;
				uzel->pismeno = pismeno;
				uzel->soused = NULL;
				uzel->dite = NULL;
			}
		}
	}
}

node_t *koreny[15];

void dfs(int slovo)
{
	if (slovo < M) {
		for (int i = 0; i < N; i++) {
			podmnozina[slovo] = i;
			dfs(slovo+1);
		}
	} else {
		for (int i = 0; i < N; i++) {
			pocet_v_podmnozine[i] = 0;
		}
		for (int i = 0; i < M; i++) {
			pocet_v_podmnozine[podmnozina[i]]++;
		}
		for (int i = 0; i < N; i++) {
			if (pocet_v_podmnozine[i] == 0) {
				return;
			}
		}
		id = 0;
		for (int i = 0; i < N; i++) {
			koreny[i] = &databaze[id++];
			koreny[i]->soused = NULL;
			koreny[i]->dite = NULL;
		}
		for (int i = 0; i < M; i++) {
			koreny[podmnozina[i]]->insert(slova[i]);
		}
		if (id > X) {
			X = id;
			Y = 1;
		} else if (id == X) {
			Y++;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &M, &N);
		for (int i = 0; i < M; i++) {
			scanf("%s", slova[i]);
		}
		X = 0;
		Y = 0;
		dfs(0);

		printf("Case #%d: %d %d\n", t, X, Y);
	}
	return 0;
}

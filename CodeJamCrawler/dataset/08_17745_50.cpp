#include <stdlib.h>
#include <stdio.h>

typedef struct lst_element lstElement;
struct lst_element {
	int departure, arrival;
	int tagged;

	lstElement *next;
};

#define BAHNHOF_A 0
#define BAHNHOF_B 1

int main(int argc, char *argv[]) {
	FILE *in, *out;
	in = fopen(argv[1], "r");
	out = fopen("output.out", "w");

	int N;
	fscanf(in, "%i\n", &N);
	printf("%i\n", N);

	int n;
	for (n = 0; n < N; n++) {
		int T;
		fscanf(in, "%i\n", &T);

		int NA, NB;
		fscanf(in, "%i %i\n", &NA, &NB);
	
		int d1, d2, a1, a2;
	
		lstElement *na_first = NULL;
		if (NA >= 1) {
			na_first = malloc(sizeof(lstElement));
			fscanf(in, "%d:%d %d:%d\n", &d1, &d2, &a1, &a2);
			na_first->departure = 100*d1+d2;
			na_first->arrival = 100*a1+a2;
			na_first->tagged = 0;
			na_first->next = NULL;
		}
		int na;
		for (na = 1; na < NA; na++) {
			fscanf(in, "%d:%d %d:%d\n", &d1, &d2, &a1, &a2);

			int d = d1*100+d2,
			    a = a1*100+a2;

			lstElement *tmp = na_first;
			lstElement *ins = na_first;
			while ((tmp) && (tmp->departure < d)) {
				ins = tmp;
				tmp = tmp->next;
			}

			lstElement *new = malloc(sizeof(lstElement));
			new->departure = d;
			new->arrival = a;
			new->tagged = 0;
			if (tmp == na_first) {
				new->next = na_first;
				na_first = new;
			} else if (tmp == NULL) {
				new->next = NULL;
				ins->next = new;
			} else {
				new->next = tmp;
				ins->next = new;
			}

		}

		lstElement *nb_first = NULL;
		if (NB >= 1) {
			nb_first = malloc(sizeof(lstElement));
			fscanf(in, "%d:%d %d:%d\n", &d1, &d2, &a1, &a2);
			nb_first->departure = 100*d1+d2;
			nb_first->arrival = 100*a1+a2;
			nb_first->tagged = 0;
			nb_first->next = NULL;
		}
		int nb;
		for (nb = 1; nb < NB; nb++) {
			fscanf(in, "%d:%d %d:%d\n", &d1, &d2, &a1, &a2);

			int d = d1*100+d2,
			    a = a1*100+a2;

			lstElement *tmp = nb_first;
			lstElement *ins = nb_first;
			while ((tmp) && (tmp->departure < d)) {
				ins = tmp;
				tmp = tmp->next;
			}

			lstElement *new = malloc(sizeof(lstElement));
			new->departure = d;
			new->arrival = a;
			new->tagged = 0;
			if (tmp == nb_first) {
				new->next = nb_first;
				nb_first = new;
			} else if (tmp == NULL) {
				new->next = NULL;
				ins->next = new;
			} else {
				new->next = tmp;
				ins->next = new;
			}
		}

/*		lstElement *tmp = na_first;
		printf("NA: %i\n", NA);
		while (tmp) {
			printf("%i -> %i\n", tmp->departure, tmp->arrival);
			tmp = tmp->next;
		}
		printf("----\n");
		tmp = nb_first;
		printf("NB: %i\n", NB);
		while (tmp) {
			printf("%i -> %i\n", tmp->departure, tmp->arrival);
			tmp = tmp->next;
		}
*/
		
		int a_zuege = 0,
		    b_zuege = 0;
		int tagged = 0;
		int bahnhof;
		while (tagged < NA+NB) {
			lstElement *e_a = na_first;
			lstElement *e_b = nb_first;
			lstElement *zug;

			while ((e_a) && (e_a->tagged))
				e_a = e_a->next;
			while ((e_b) && (e_b->tagged))
				e_b = e_b->next;

			if ((e_a) && (e_b)) {
				if (e_b->departure < e_a->departure) {
					zug = e_b;
					b_zuege++;
					bahnhof = BAHNHOF_B;
				} else {
					zug = e_a;
					a_zuege++;
					bahnhof = BAHNHOF_A;
				}
			} else if (e_a) {
				zug = e_a;
				a_zuege++;
				bahnhof = BAHNHOF_A;
			} else if (e_b) {
				zug = e_b;
				b_zuege++;
				bahnhof = BAHNHOF_B;
			} else {
				break;
			}

			while (zug) {
				zug->tagged = 1;
				tagged++;

				int abfahrt = zug->arrival;
				int stunden = (int) trunc((float) abfahrt / 100.0);
				int minuten = abfahrt - (stunden * 100) + T;
				if (minuten > 59) {
					minuten -= 60;
					stunden++;
				}
				abfahrt = stunden*100 + minuten;

				lstElement *tmp;
				if (bahnhof == BAHNHOF_A) {
					tmp = nb_first;
					bahnhof = BAHNHOF_B;
				} else {
					tmp = na_first;
					bahnhof = BAHNHOF_A;
				}
				while ((tmp) && ((tmp->departure < abfahrt) || (tmp->tagged))) {
					tmp = tmp->next;
				}
				zug = tmp;
			}
		}
		fprintf(out, "Case #%i: %i %i\n", n+1, a_zuege, b_zuege);
	}
}

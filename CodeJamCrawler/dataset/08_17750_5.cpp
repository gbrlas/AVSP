#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lst_element lstElement;
struct lst_element {
	int key_strokes;

	lstElement *next, *prev;
};

lstElement *first, *last;

void insert_element(lstElement *new) {
	if (first == NULL) {
		first = new;
		new->prev = NULL;
		new->next = NULL;
	} else {
		lstElement *tmp = first;
		lstElement *ins;
		while ((tmp) && (tmp->key_strokes > new->key_strokes)) {
			ins = tmp;
			tmp = tmp->next;
		}

		if (tmp == first) {
			new->prev = NULL;
			new->next = first;
			first = new;
		} else if (tmp == NULL) {
			new->next = NULL;
			new->prev = ins;
			ins->next = new;
		} else {
			new->next = tmp;
			new->prev = ins;
			ins->next = new;
		}
	}
}

void remove_element(lstElement *del) {
	if (del->prev == NULL)
		first = del->next;
	else
		del->prev->next = del->next;

	if (del->next == NULL)
		last = del->prev;
	else
		del->next->prev = del->prev;

	free(del);
}

int main(int argc, char *argv[]) {
	FILE *in, *out;
	in = fopen(argv[1], "r");
	out = fopen("output.out", "w");

	int N;
	fscanf(in, "%i\n", &N);
	
	int n;
	for (n = 0; n < N; n++) {
		int P, K, L;
		fscanf(in, "%i %i %i\n", &P, &K, &L);

		int l;
		for (l = 0; l < L; l++) {
			int tmp;
			fscanf(in, "%i ", &tmp);

			lstElement *new_element = (lstElement *) malloc(sizeof(lstElement));
			new_element->key_strokes = tmp;
			insert_element(new_element);
		}

//		lstElement *element;
//		printf("Key Strokes:\n");
//		for (element = first; element != NULL; element = element->next) {
//			printf("%d\n", element->key_strokes);
//		}

		int total_key = 0;
		int i = 0;
		int strokes = 1;
		lstElement *tmp;
		for (tmp = first; tmp != NULL; tmp = tmp->next) {
			i++;

			total_key += strokes * tmp->key_strokes;

			if (i == K) {
				i = 0;
				strokes++;
			}



//			if (i == 1)
//				total_key += 1;
//			total_key += i%K+1;
		}


		while (first != NULL)
			remove_element(first);

		first = last = NULL;

		fprintf(out, "Case #%i: %i\n", n+1, total_key);
	}
}

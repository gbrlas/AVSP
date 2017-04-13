#include <stdio.h>
#include <stdlib.h>

#define pos(n,w) ((n)->next[(w) - 'a'])
#define n_size 30
#define LMAX 15
#define DMAX 5000
#define NMAX 500

struct node {
  struct node *next[n_size];
};

struct node *new_node() {
  struct node *res = malloc(sizeof (struct node));
  int i;
  for(i = 0; i < n_size; i++) res->next[i] = NULL;
  return res;
}

void put_word(char *word, struct node *n) {
  while(*word) {
  #ifdef DEBUG
  printf("n = 0x%x\n", n);
  #endif
    if(!pos(n, *word)) {
      pos(n, *word) = new_node();
      #ifdef DEBUG
      puts("Allocated");
      #endif
    }
    n = pos(n, *word);
    word++;
  }
  #ifdef DEBUG
  puts("Inserted");
  #endif
}

int search_pat(char *pat, struct node *n) {
  if(!n) return 0;
  if(!*pat) return 1;
  if(*pat == '(') {
    char *prox = pat + 1;
    int count = 0;
    while(*prox++ != ')');
    for(pat++; *pat != ')'; pat++) {
      count += search_pat(prox, pos(n, *pat));
    }
  return count;
  } else return search_pat(pat + 1, pos(n, *pat));
}


int main() {
  int L, D, N, i;
  struct node *dict = new_node();
  char buf[28 * LMAX];
  scanf("%d%d%d", &L, &D, &N);
  for(i = 0; i < D; i++) {
    scanf("%s", buf);
    put_word(buf, dict);
  }
  for(i = 0; i < N; i++) {
    scanf("%s", buf);
    printf("Case #%d: %d\n", i + 1, search_pat(buf, dict));
  }
  return 0;  
}

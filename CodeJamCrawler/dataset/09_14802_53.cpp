#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie {
    struct trie *children[32];
} Trie;

void trie_insert(Trie *trie, char buf[], int index, int len) {
    Trie **next;

    if (index == len) {
        return;
    }

    next = &trie->children[buf[index] - 'a'];
    if (!(*next)) {
        *next = (Trie *) malloc(sizeof(**next));
        memset((*next)->children, 0, sizeof((*next)->children));
    }
    trie_insert(*next, buf, index + 1, len);
}

int trie_search(Trie *trie, char buf[], int idx, int len, int pos) {
    int nextpos, cur, score;

    if (idx == len) {
        return 1;
    }

    nextpos = pos;
    if (buf[nextpos] == '(') {
        while (buf[nextpos] != ')') nextpos++;
    }
    nextpos++;

    score = 0;

    cur = pos;
    if (buf[cur] == '(') {
        while (buf[++cur] != ')') {
            if (trie->children[buf[cur] - 'a']) {
                score += trie_search(trie->children[buf[cur] - 'a'], buf,
                                     idx + 1, len, nextpos);
            }
        }
    } else {
        if (trie->children[buf[cur] - 'a']) {
            score += trie_search(trie->children[buf[cur] - 'a'], buf, idx + 1,
                                 len, nextpos);
        }
    }

    return score;
}

int main(void) {
    int l, d, n, i, k;
    char buf[16], sbuf[16 * 18];
    Trie *trie;

    trie = (Trie *) malloc(sizeof(*trie));
    memset(trie->children, 0, sizeof(trie->children));

    scanf("%d %d %d", &l, &d, &n);

    for (i = 0; i < d; ++i) {
        scanf("%s", buf);
        trie_insert(trie, buf, 0, l);
    }

    for (i = 1; i <= n; ++i) {
        scanf("%s", sbuf);
        k = trie_search(trie, sbuf, 0, l, 0);
        printf("Case #%d: %d\n", i, k);
    }

    return 0;
}

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie trie;
struct trie
{
    trie *childs[26];
    int isWord;
};

trie root;
int N,L;

trie *reserveNode()
{
    trie *n;
    int i;
    n = (trie*)malloc(sizeof(trie));
    assert(n);
    for (i=0; i<26; i++)
    {
        n->childs[i] = NULL;
    }
    n->isWord = 0;
    return n;
}

void addWord(char *w)
{
    int i;
    trie *t;
    t = &root;
    for (i=0; w[i] != 0; i++)
    {
        if (t->childs[w[i] - 'a'] == NULL)
            t->childs[w[i] - 'a'] = reserveNode();
        t = t->childs[w[i] - 'a'];
    }
    t->isWord = 1;
}

void readWords()
{
    int D,i;
    char readWord[16];
    scanf("%d %d %d", &L, &D, &N);

    for (i=0; i<D; i++)
    {
        scanf("%s", readWord);
        addWord(readWord);
    }
}

int lstart[15];
char curWord[421];
int count;

void genWords(int i, trie *t)
{
    int j;
    if (i == L && t->isWord == 1)
    {
        count++;
        return;
    }
    if (curWord[lstart[i]] != '(')
    {
        if (t->childs[curWord[lstart[i]] - 'a'] != NULL)
            genWords(i+1, t->childs[curWord[lstart[i]] - 'a']);
        return;
    }
    for (j=1; curWord[lstart[i]+j] != ')'; j++)
    {
        if (t->childs[curWord[lstart[i] + j] - 'a'] == NULL)
            continue;
        genWords(i+1, t->childs[curWord[lstart[i]+j] - 'a']);
    }
}

int main()
{
    int i;
    int j,k;
    readWords();
    for (i=1; i<=N; i++)
    {
        scanf("%s", curWord);

        j=k=0;
        while (curWord[j] != 0)
        {
            lstart[k] = j;
            k++;
            if (curWord[j] == '(')
            {
                while (curWord[j] != ')')
                    j++;
            }
            j++;
        }
        count = 0;
        genWords(0, &root);
        printf("Case #%d: %d\n", i, count);
    }
    printf("\n");
    return 0;
}

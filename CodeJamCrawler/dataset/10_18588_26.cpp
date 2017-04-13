//
//	Google CodeJam 2010 - Round 1B, Problem A
//	DQuadros
//
//	Tested with Microsoft Visual C++ v6
//


// If the following defines are uncommented:
// - Uses test files instead of standard input/output
// - Enables debug printfs
//#define TEST
//#define DUMP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE   0
#define TRUE    1

#ifdef DUMP
int naloc, nfree;
#endif

typedef struct node
{
    char *name;
    struct node *next;
    struct node *son;
} TNODE;

TNODE root;

void InitTree()
{
    root.next = NULL;
    root.son = NULL;

    #ifdef DUMP
    naloc = nfree = 0;
    #endif
}

int Insert (char *diret)
{
    int i, j, n, tam;
    char *p;
    TNODE *tn1 = &root;
    TNODE *tn2;

    i = j = 0;
    n = 0;
    while (diret[i] != 0)
    {
        i = j = i+1;
        do
        {
            j++;
        } while ((diret[j] != 0) && (diret[j] != '/'));
        tam = j-i;
        p = (char *) malloc (tam+1);
        memcpy (p, diret+i, tam);
        p[tam] = 0;
        if (tn1->son == NULL)
        {
            tn2 = (TNODE *) malloc (sizeof (TNODE));
            tn2->name = p;
            tn2->next = tn2->son = NULL;
            #ifdef DUMP
            printf ("Aloc %s\n", p);
            naloc++;
            #endif
            tn1->son = tn2;
            tn1 = tn2;
            n++;
        }
        else
        {
            tn1 = tn1->son;
            while (TRUE)
            {
                if (strcmp (tn1->name, p) == 0)
                    break;
                if (tn1->next != NULL)
                    tn1 = tn1->next;
                else
                {
                    tn2 = (TNODE *) malloc (sizeof (TNODE));
                    tn2->name = p;
                    tn2->next = tn2->son = NULL;
                    #ifdef DUMP
                    printf ("Aloc %s\n", p);
                    naloc++;
                    #endif
                    tn1->next = tn2;
                    tn1 = tn2;
                    n++;
                    break;
                }
            }
        }
        i = j;
    }
    return n;
}

void FreeNode(TNODE *tn)
{
    #ifdef DUMP
    printf ("Free %s\n", tn->name);
    nfree++;
    #endif
    free (tn->name);
    if (tn->next != NULL)
        FreeNode (tn->next);
    if (tn->son != NULL)
        FreeNode (tn->son);
    free (tn);
}

void main (void)
{
	int iCase, nCases;
    int N, M;
    int i, nCmd;
    char diret [101];

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
    	scanf ("%d %d\n", &N, &M);
        InitTree ();
        for (i = 0; i < N; i++)
        {
            scanf ("%s\n", diret);
            Insert (diret);
        }
        for (i = nCmd = 0; i < M; i++)
        {
            scanf ("%s\n", diret);
            nCmd += Insert (diret);
        }
        if (root.son != NULL)
            FreeNode (root.son);
        #ifdef DUMP
        printf ("Aloc %d Free %d\n", naloc, nfree);
        naloc++;
        #endif
        printf ("Case #%d: %d\n", iCase, nCmd);
	}
}

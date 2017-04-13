#include<stdio.h>
#include<string.h>
#include<ctype.h>


int noPos(char*, int, int);
int has(char, char*);

char** lib;

main()
{
  int l, d, n;
  int i,j;
  char word[1000];
  char *w;
  scanf("%d%d%d", &l, &d, &n);
  getchar();
  lib = malloc(d*sizeof(char*));
  for(i=0; i<d; i++)
  	lib[d] = malloc((l+1)*sizeof(char));
  for(i=0; i<d; i++)
    { 
	  w = malloc(l*sizeof(char));
      gets(w);
      lib[i] = w;
    }

  for(i=0; i<n; i++)
    {
      gets(word);
      printf("Case #%d: %d\n", i+1, noPos(word,l,d));
    }
}


int noPos(char* word, int l, int d)
{
  int i,j,k=0;
  int count=0 , contain;

  char w[l][500];

  for(i=0; word[i]!='\0'; i++)
    {
      if(isalpha(word[i]))
	{
	  w[k][0]=word[i];
	  w[k][1]='\0';	  
	  k++;
	}
      else
	{
	  i++;
	  for(j=0;word[i]!=')';j++)
	    {		  
	      w[k][j]=word[i];
	      i++;
	    }
	  w[k][++j]='\0';
          k++;
	}
    }

  for(i=0; i<d; i++)
    {
      contain = 1;
      for(j=0; j<l; j++)
	{
	  if(has(lib[i][j], w[j])==0)
        contain=0;
	}
      if(contain ==1)
	count++;
    }
  return count;
}

int has(char c, char* cptr)
{
  int i=0;
  for(i=0; cptr[i]!='\0'; i++)
    {
      if(c==cptr[i])
	return 1;
    }
  return 0;
}

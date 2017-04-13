#include<stdio.h>

int** arr;
int a,b;
void ptit(int);
int isIn(int, int*);
int getBasin(int, int);

main()
{
  int noArs;
  int i;

  scanf("%d", &noArs);
   
  for(i=0; i<noArs; i++)
    {
      ptit(i);
    }
}


void ptit(int h)
{

  int i,j,k;
  int count=0;

  scanf("%d%d", &a, &b); getchar();
  arr=malloc(a*sizeof(int*));
  int* num;

  for(i=0; i<a; i++)
    {
      num = malloc(b*sizeof(int));
      for(j=0; j<b; j++)
	{
	  scanf("%d", num+j);
	}
      getchar();
      arr[i]=num;
    }

  int basin[a][b];
  
  for(i=0;i<a; i++)
    for(j=0;j<b;j++){
      basin[i][j]=getBasin(i,j);
    }
  int array[26]={0};
  printf("Case #%d:\n", h+1);
  for(i=0; i<a; i++)
    {
      for(j=0; j<b; j++)
        {
	  if(k=isIn(basin[i][j], array))
            printf("%c ", k);
	  else
	    {
              array[count]=basin[i][j];
	      printf("%c ", count+97);
	      count++;
	    }
        }
      printf("\n");
    }
}

int isIn(int number, int* array)
{
  int i=0;

  while(i<26)
    {
      if(number == array[i])
	return i+97;i++;
    }
  return 0;
}

int getBasin(int c, int d)
{
  long int store=99999;
  int s=0,l;
  if(c>0)
    {
      if(arr[c][d]>arr[c-1][d])
        {
	  s=1;
	  store = arr[c-1][d];
	}
         
    }
  if(d>0)
    {
      if(arr[c][d]>arr[c][d-1])
	{
	  if(arr[c][d-1]<store)
	    {
	      s=2;
	      store = arr[c][d-1];
	    }
	}
    
	 
    }
  if(d<b-1)
    {
      if(arr[c][d]>arr[c][d+1])
	{
	  if(arr[c][d+1]<store)
	    {
	      s=3;
	      store=arr[c][d+1];
	    }
	}
    } 
 if(c<a-1)
    {
      if(arr[c][d]>arr[c+1][d])
	{
	  if(arr[c+1][d]<store)
	    {
	      s=4;
	      store = arr[c+1][d];
	    }
	}

    }

 if(s==1){
   l= getBasin(c-1,d);
   return l;
 }
 if(s==2)
   {
     l= getBasin(c,d-1);
     return l;
   }
 if(s==3)
   {
     l= getBasin(c,d+1);
     return l;
   }
 if(s==4){
     l= getBasin(c+1,d);
     return l;
 }
 return (c+1)*b+(d+1);
}

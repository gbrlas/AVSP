#include<stdio.h>

int isin(char*, char);
int getval(char*, char);


main()
{
  int a,b,c,d,e,i,j;
  scanf("%d", &a);
  long long int p;
  for(b=0; b<a; b++)
    {
      char* arr = malloc(62*sizeof(char));
      char* arr1 = malloc(62*sizeof(char));
      scanf("%s", arr);
     
      arr1[1]=arr[0];
      for(i=0; arr[i]==arr1[1]; i++);
      if(arr[i]=='\0')
	{
	  p=1;
	  for(d=0; d<i; d++)
	    p=p*2;
	  printf("Case #%d: %lld\n", b+1, p-1);
	  continue;
	}
      arr1[0] = arr[i];
      j=2;
      for(;arr[i]!='\0'; i++)
	{
	  if(!isin(arr1,arr[i]))
	    arr1[j++]=arr[i];
	}
      p=0;
      for(i=0; arr[i]!='\0'; i++)
	{
	  p=j*p+getval(arr1, arr[i]);
	}
      printf("Case #%d: %lld\n", b+1, p);
    }
}

int isin(char* arr, char c)
{
  int i;
  for(i=0; arr[i]!='\0'; i++)
    if(c==arr[i])
      return 1;
  return 0;
}

int getval(char* arr, char c)
{
  int i;
  for(i=0; arr[i]!='\0'; i++)
    {
      if(c==arr[i])
	return i;
    }
}

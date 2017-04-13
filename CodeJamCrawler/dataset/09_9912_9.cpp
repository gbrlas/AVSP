#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    char str[51];
    char str2[51];
    int len;

int compareGede (const void * a, const void * b)
{
  return ( *(char*)b - *(char*)a );
}

int compareKecil (const void * a, const void * b)
{
  return ( *(char*)a - *(char*)b );
}

int plgGede(int index)
{
	 char temp[51];
	 int j=0;     
	 for(int i=index;i<len;i++)
	 {
	  		 temp[j++] = str[i];
	 }
	 temp[j]='\0';
		qsort(temp,strlen(temp),sizeof(char), compareGede);
j=0;
 for(int i=index;i<len;i++)
 {
  if(str[i] != temp[j++])
    return 0;
 }   
 return 1;  
}

char next(int index, char value)
{
	 char temp[51];
	 int j=0;     
	 for(int i=index;i<len;i++)
	 {
	  		 temp[j++] = str[i];
	 }
	 temp[j]='\0';
		qsort(temp,strlen(temp),sizeof(char), compareGede);

    char * pch = strchr(temp,value);
     pch--;
     return pch[0];
}

void buat(int index, char awal)
{
	 char temp[51];
	 int j=0;
	 for(int i=index;i<len;i++)
	 {
	  		 temp[j++] = str[i];
	 }
	 temp[j]='\0';
		
		qsort(temp,strlen(temp),sizeof(char), compareKecil);
	 j=0;
	 int ok=0;        
	 for(int i=index+1;i<len;i++)
	 {
			char a = temp[j++];
			
			if(a == awal && ok==0)
			{
				a = temp[j++];
				ok=1;
			}
				
	  		 str[i] = a;
	 }
     str[index]=awal;
}

void trim(char *s, const int len)
{
    int end = len - 1;
    int start = 0;
    int i = 0;

    while ((start < len) && (s[start] == '0'))
    {
        start++;
    }
/*
    while ((start < end) && (s[end] == '0'))
    {
        end--;
    }
*/
    if (start > end)
    {
        memset(s, '\0', len);
        return;
    }

    for (i = 0; (i + start) <= end; i++)
    {
        s[i] = s[start + i];
    }
    memset((s + i), '\0', len - i);
}
int main()
{
    int T;
    long long N;
    
    scanf("%lld", &T);
    for(int i=1;i<=T;i++)
    {
      scanf("%lld", &N);
      sprintf(str,"%lld",N);

			strrev(str);
      
      len = strlen(str);
      
      for(int j=0;j<50-len;j++)
      {
      	strcat(str,"0");
	 }
		
		strrev(str);
		
      len = strlen(str);
      strcpy(str2,str);
      
      qsort (str2, strlen(str2), sizeof(char), compareGede);  
      
      for(int j=len-1;j>=0;j--)
      {
//			printf("::%i\n",plgGede(j));
		if(!plgGede(j))
		{
//      printf("--%i %c\n", j,next(str[j]));
		 buat(j,next(j,str[j]));	
		 break;
		}
		//len++;
	//	j++;
	//	sprintf(str,"0%s",str);
	  }
	  trim(str,len);
      printf("Case #%i: %s\n", i, str );
    }
    
     return(0);
}

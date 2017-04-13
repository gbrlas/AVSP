#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int readdata(void);
void findmagicnum(int *first,int *second,int iter);
int main()
{
 int a;
 a = readdata(); 
}

void findmagicnum(int *first, int *second,int iter)
{
  int i=0,j=0,count=0,*temp1=first,*temp2=second,ele=0;
  char *out;
  for(i=0;i<4;i++)
  {
   for (j=0;j<4;j++)
   {
    if (*first == *second)
    {
     count++;
     ele = *first;
    }
    second++;    
   }
   first++;
   second = temp2;
  }
  if (count == 1)
  printf("Case #%d: %d\n",iter+1,ele);
  else if (count>1)
  printf("Case #%d: %s\n",iter+1,"Bad magician!");
  else if (count == 0)
  printf("Case #%d: %s\n",iter+1,"Volunteer cheated!");
}


int readdata(void)
{
 FILE *fp;
 char * line = NULL;
 size_t len = 0;
 ssize_t read;
 int tokcount=0,firstans=0,secondans=0;
 int i=0,j=0,k=0,numberOfLines=0;
 int a[4][4],b[4][4],*first,*second;
 char* token; 
 fp = fopen("./filename.txt" , "r");  
   read = getline (&line, &len,fp);
   numberOfLines = atoi(line);
   if (numberOfLines<=100 && numberOfLines>0)
  {
   for (i=0;i<numberOfLines;i++)
   {
     read = getline(&line, &len, fp);     
     token = strtok(line, " ");
     firstans = atoi(token);
    for (j=0;j<4;j++)
    {
     read = getline(&line, &len, fp);
     token = strtok(line, " ");
     a[j][0] = atoi(token);   
     for (k=1;k<4;k++)
     {
      token = strtok(NULL, " ");
      a[j][k] = atoi(token);
     }  
    }
    read = getline(&line, &len, fp);   
    token = strtok(line, " ");
    secondans = atoi(token);
    for (j=0;j<4;j++)
    {
     read = getline(&line, &len, fp);
     token = strtok(line, " ");
     b[j][0] = atoi(token);   
     for (k=1;k<4;k++)
     {
      token = strtok(NULL, " ");
      b[j][k] = atoi(token);
     }  
    }
    first = &a[firstans-1][0];
    second = &b[secondans-1][0];
    findmagicnum(first,second,i);
   }	 
  } 
 return 0;
}

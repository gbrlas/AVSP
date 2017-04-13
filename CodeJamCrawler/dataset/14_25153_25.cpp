#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
void readdata(void);
inline double fround(double n, unsigned d);
void gettime(double C, double F, double X, int iter)
{
 double curr=0.0,time=0.0, rate=2.0;
 while (curr<X)
 {
  if ((X/rate)> (C/rate)+ (X/(F+rate)))  
  {
   time = time+(C/rate);
  // curr = time*rate-C; 
   rate = rate+F;
  }
  else
  {
    curr = curr+rate*time;
    time = time+(X/rate);
    break;
  }  
 }
 printf("Case #%d: %f\n",iter,time);
}

int main()
{
 readdata();
 return 0;
}

void readdata(void)
{
 FILE *fp;
 char * line = NULL;
 size_t len = 0;
 ssize_t read;
 int i=0,j=0,numberOfLines=0;
 double C,F,X;
 char* token;
 
 fp = fopen("./filename.txt" , "r");
   if (fp == NULL)
      exit(EXIT_FAILURE);
    read = getline (&line, &len,fp);
   numberOfLines = atoi(line);
   if ((numberOfLines<=100) && (numberOfLines>0))
  {
   for (i=0;i<numberOfLines;i++)
   {
     read = getline(&line, &len, fp);
     token = strtok(line, " ");
     C = atof(token);
     C = fround(C,5);  
     token = strtok(NULL, " ");
     F = atof(token);
     F = fround(F,5);
     token = strtok(NULL, " ");
     X = atof(token);
     X = fround(X,5); 
    //printf("C:%f \tF:%f\tX:%f\n",C,F,X);
     gettime(C,F,X,i+1);    
   } 
  }
 fclose(fp);
}

inline double fround(double n, unsigned d)
{
return floor(n * pow(10., d) + .5) / pow(10., d);
}

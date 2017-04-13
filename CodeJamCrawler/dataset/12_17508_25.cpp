#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
FILE *fp1,*fp2;
fp1=fopen("A-small-attempt0.in","r");
fp2=fopen("probA.out","w");
char arr[30]="yhesocvxduiglbkrztnwjpfmaq";
char str[100];
int t,i,c,cc=1;
char ch;
fscanf(fp1,"%d",&t);
while (t--)
{
fscanf(fp1,"%c",&ch);
fscanf(fp1,"%[^\n]s",str);
fprintf(fp2,"Case #%d: ",(cc++));
for (i=0;str[i]!='\0';i++)
{
if (str[i]==' ')
{
fprintf(fp2," ");
//cout<<" ";
}
else
{
c=((int)str[i])-97;
//cout<<arr[c];
fprintf(fp2,"%c",arr[c]);
}
}
fprintf(fp2,"\n");
//cout<<endl;
}
fclose(fp1);
fclose(fp2);
return 0;
}


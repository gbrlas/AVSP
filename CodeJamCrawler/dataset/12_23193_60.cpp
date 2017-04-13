/*
a=y
b=h
c=e
d=s
e=o
f=c
g=v
h=x
i=d
j=u
k=i
l=g
m=l
n=b
o=k
p=r
q=z
r=t
s=n
t=w
u=j
v=p
w=f
x=m
y=a
z=q
*/
#include<stdio.h>
#include<string.h>
int main () {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,i,j;
	scanf("%d",&t);
	char temp[1000];
	gets(temp);
	for(i=1;i<=t;i++) {
		char s[150];
		gets(s);
		int len=strlen(s);
		for(j=0;j<len;j++) {
			if (s[j]=='a') s[j]='y';
			else if (s[j]=='b') s[j]='h';
			else if (s[j]=='c') s[j]='e';
			else if (s[j]=='d') s[j]='s';
			else if (s[j]=='e') s[j]='o';
			else if (s[j]=='f') s[j]='c';
			else if (s[j]=='g') s[j]='v';
			else if (s[j]=='h') s[j]='x';
			else if (s[j]=='i') s[j]='d';
			else if (s[j]=='j') s[j]='u';
			else if (s[j]=='k') s[j]='i';
			else if (s[j]=='l') s[j]='g';
			else if (s[j]=='m') s[j]='l';
			else if (s[j]=='n') s[j]='b';
			else if (s[j]=='o') s[j]='k';
			else if (s[j]=='p') s[j]='r';
			else if (s[j]=='q') s[j]='z';
			else if (s[j]=='r') s[j]='t';
			else if (s[j]=='s') s[j]='n';
			else if (s[j]=='t') s[j]='w';
			else if (s[j]=='u') s[j]='j';
			else if (s[j]=='v') s[j]='p';
			else if (s[j]=='w') s[j]='f';
			else if (s[j]=='x') s[j]='m';
			else if (s[j]=='y') s[j]='a';
			else if (s[j]=='z') s[j]='q';
		}
		printf("Case #%d: %s\n",i,s);
	}
	return 0;
}
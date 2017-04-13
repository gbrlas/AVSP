//SORU xx
//PROGRAM C++
/*
ID: abdulla12
PROG: test
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<ctype.h>
#include<iostream>
//#include<math.h>
#include<algorithm>
#define scn(x) fscanf(in,"%d",&x)
#define prn(x) fprintf(out,"%d\n",x)
#define prn2(x) fprintf(out,"%d",x)
#define prn3(x) fprintf(out,"%d ",x)
#define line fprintf(out,"\n")
#define wait system("PAUSE")
#define scn2(x,y) scn(x);scn(y)
using namespace std;
FILE *in,*out;
void dosya(){
		in=fopen("A-small-attempt0.in","r");//in=stdin;
		out=fopen("A-small-attempt0.out","w");//out=stdout;
}
int N;
void oku(){
	scn(N);
	int i,tut;
	char c;
	tut=0;
	fscanf(in," ");
	for(i=1; i<=N; i++){
		fprintf(out,"Case #%d: ",i);
		while(fscanf(in,"%c",&c)){
			if(c=='\n') break;
			switch(c){
				case 'a': fprintf(out,"y"); break;
				case 'b': fprintf(out,"h"); break;
				case 'c': fprintf(out,"e"); break;
				case 'd': fprintf(out,"s"); break;
				case 'e': fprintf(out,"o"); break;
				case 'f': fprintf(out,"c"); break;
				case 'g': fprintf(out,"v"); break;
				case 'h': fprintf(out,"x"); break;
				case 'i': fprintf(out,"d"); break;
				case 'j': fprintf(out,"u"); break;
				case 'k': fprintf(out,"i"); break;
				case 'l': fprintf(out,"g"); break;
				case 'm': fprintf(out,"l"); break;
				case 'n': fprintf(out,"b"); break;
				case 'o': fprintf(out,"k"); break;
				case 'p': fprintf(out,"r"); break;
				case 'q': fprintf(out,"z"); break;
				case 'r': fprintf(out,"t"); break;
				case 's': fprintf(out,"n"); break;
				case 't': fprintf(out,"w"); break;
				case 'u': fprintf(out,"j"); break;
				case 'v': fprintf(out,"p"); break;
				case 'w': fprintf(out,"f"); break;
				case 'x': fprintf(out,"m"); break;
				case 'y': fprintf(out,"a"); break;
				case 'z': fprintf(out,"q"); break;
				default : fprintf(out," "); break;
			}
		}
		line;
	}			
}
void coz(){
	int i;
}
int main(){
	dosya();
	oku();
	coz();
	return 0;
}

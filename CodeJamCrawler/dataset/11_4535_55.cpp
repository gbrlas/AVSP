#include <iostream>
#include <stdio.h>
#include <cstring>
#define MXN 50

using namespace std;

int t,c,d,n;
char A[MXN],B[MXN],C[MXN];
char RA[MXN],RB[MXN];
char Seq[110];

void cleanSeq(){
	int N(0),i(0);
	while (i<n){
		i++;
		if (Seq[i]!=' ') Seq[++N]=Seq[i];
	}
	n=N;
}

char GetCombine(char a,char b){
	for (int i=1;i<=c;i++) if ((A[i]==a&&B[i]==b)||(A[i]==b&&B[i]==a)) return C[i];
	return '!';
}

bool CanRemove(char a,char b){
	for (int i=1;i<=d;i++) if ((RA[i]==a&&RB[i]==b)||(RA[i]==b&&RB[i]==a)) return 1;
	return 0;
}

bool doSeq(){
	int ifdo(0);
	for (int i=2;i<=n;i++){
		if (Seq[i]==' ') continue;
		char tmp(GetCombine(Seq[i-1],Seq[i]));
		if (tmp!='!'){
			ifdo=1;
			Seq[i-1]=tmp;Seq[i]=' ';
		}
		for (int j=1;j<i;j++) for (int I=j+1;I<=i;I++){
			if (Seq[I]==' '||Seq[j]==' ') continue;
			if (CanRemove(Seq[I],Seq[j])){
				ifdo=1;
				for (int k=1;k<=I;k++) Seq[k]=' ';
				break;
			}
		}
	}
	cleanSeq();
	return ifdo;
}

int main(){
	scanf("%d",&t);
	for (int ti=1;ti<=t;ti++){
		for (int i=1;i<=100;i++) Seq[i]=' ';
		scanf("%d",&c);
		for (int i=1;i<=c;i++) scanf(" %c%c%c",&A[i],&B[i],&C[i]);
		scanf("%d",&d);
		for (int i=1;i<=d;i++) scanf(" %c%c",&RA[i],&RB[i]);
		scanf("%d ",&n);
		for (int i=1;i<=n;i++) scanf("%c",&Seq[i]);
		while (doSeq());
		printf("Case #%d: [",ti);
		for (int i=1;i<n;i++) cout << Seq[i] << ", ";
		if (n!=0) cout << Seq[n];
		cout << "]" << endl;
	}
	return 0;
}

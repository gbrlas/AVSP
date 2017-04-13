#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;
int chk(int a[100][100],int n,int m){
	for(int j=0;j<n;j++){
		for(int k=0;k<m;k++){
			int s=a[j][k],row=1,col=1;
			for(int x=0;x<n;x++){
				if(a[x][k]>a[j][k]){
					row=0;
				}
			}
			for(int x=0;x<m;x++){
				if(a[j][x]>a[j][k]){
					col=0;
				}
			}
			if(row==0&& col==0)
				return 0;
		}
	}
	return 1;
}
int main()
{
	FILE *fp,*out;
	if((fp=fopen("B-small-attempt1.in","r"))==NULL)
	{
		cout<<"NOT OPEN\n";
		exit(1);
	}
	if((out=fopen("br.txt","w"))==NULL)
	{
		cout<<"NOT OPEN\n";
		exit(1);
	}
	int no,res;
	fscanf(fp,"%d",&no);
	getc(fp);
	for(int i=0;i<no;i++){
		int n,m;
		fscanf(fp,"%d",&n);
		getc(fp);
		fscanf(fp,"%d",&m);
		getc(fp);
		int a[100][100];
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				fscanf(fp,"%d",&a[j][k]);
				getc(fp);
			}
		}
		int s=chk(a,n,m);
		fprintf(out,"Case #%d: ",i+1);
		if(s==1)
			fprintf(out,"%s\n","YES");
		else
			fprintf(out,"%s\n","NO");
	}
	//cin>>res;
}
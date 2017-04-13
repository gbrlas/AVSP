#include <iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

int main() {
	int T,b,n,N,S,p,tot,p1,p2;
	ofstream myfile;
	  myfile.open ("example.txt");
	scanf("%d",&T);


	for(b=0;b<T;b++)
	{
		scanf("%d %d %d",&N,&S,&p);
		int googlers[N];
		for(n=0;n<N;n++)
			scanf("%d",&googlers[n]);
		printf(" Case #%d: ",b+1);
		myfile << "Case #"<<b+1<<": ";
		tot=0;
		p1=p-1;
		p2=p-2;
		for(n=0;n<N;n++)
			if(googlers[n]/3 >=p || (googlers[n]/3==p-1 && googlers[n]%3>0))					tot++;
			else if(S>0 &&((googlers[n]/3==p2 && googlers[n]%3==2) || (googlers[n]/3==p1 && p1!=0)))
			{
				S--;
				tot++;
			}

		printf("%d\n",tot);
		myfile << tot<<"\n";
	}
	myfile.close();
	return 0;
}

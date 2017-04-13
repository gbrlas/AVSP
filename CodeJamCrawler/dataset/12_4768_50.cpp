#include<iostream>
using namespace std;
int main()
{
	int no_t=0,counter=0,N,S,P,Fi,Se,Th,Ti,count,flag=0;
	cin >> no_t;
	while(counter < no_t){
			cin >> N >> S >> P;
			count=0;flag=0;
		if(P==0)
		{
			//count=N;
			//cout<<"Case #"<<counter+1<<": "<<count<<endl;
			//counter++;
			flag=1;
			
		}
		else if(P==1)
		{
			Fi=1;Se=0;Th=0;
		}
		else
		{
			Fi=P+P-1+P-2;
			Se=Fi;Th=Fi-1;
		}

		for(int i=0;i<N;i++)
		{
			cin >> Ti;
			if(Ti > Fi)
				count++;
			else if(S && Ti==Se && Ti >= P){
				S--;count++;
			}
			else if(S && Ti==Th && Ti >= P){
				S--;count++;
			}
		}
		if(flag==0)		
			cout<<"Case #"<<counter+1<<": "<<count<<endl;
		else
			cout<<"Case #"<<counter+1<<": "<<N<<endl;
	
		counter++;
	}
	return 0;
}	

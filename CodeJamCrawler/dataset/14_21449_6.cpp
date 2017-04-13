#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
using namespace std;
int STI(string S)
{
	int x=0;
	int k=1;
	for (int i=S.size()-1;i>=0;i--){
		x+=(S[i]-'0')*k;
		k=k*10;
	}
	return x;
}
int main()
{
	int T; 
	
	ifstream cin ("A-small-attempt0.in");
	ofstream cout("output.txt");
	cin>>T;	
	for (int Q=0;Q<T;Q++){
		vector<vector<int>> V;
		vector<int> G;
		int X,ans1,ans2;
			cin>>ans1;	
			for (int i=0;i<4;i++){
				for (int j=0;j<4;j++){				
					cin>>X;
					G.push_back(X);
				}
				V.push_back(G);
				G.clear();
			}
			vector<int> res = V[ans1-1];
			 V.clear();	
			cin>>ans2;
			for (int i=0;i<4;i++){
				for (int j=0;j<4;j++){				
					cin>>X;
					G.push_back(X);
				}
				V.push_back(G);
				G.clear();
			}
			vector<int> test=V[ans2-1];
			vector<int> r;
			for (int i=0;i<4;i++){
				for (int j=0;j<4;j++){
					if (test[i]==res[j])	{
						r.push_back(test[i]);
					}
				}
			}
			if (r.size()==1){
				
				cout<<"Case #"<<Q+1<<": "<<r[0]<<endl;
			}
			else if (r.size()>1)
			{
				cout<<"Case #"<<Q+1<<": "<<"Bad magician!"<<endl;
			}
			else if (r.size()==0){
				cout<<"Case #"<<Q+1<<": "<<"Volunteer cheated!"<<endl;
			}
	}
	return 0;
}
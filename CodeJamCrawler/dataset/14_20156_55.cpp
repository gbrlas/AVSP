#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

vector< pair<double,int> > Naomi,Ken;

bool isGettingLowest(double num){

	for(int I=Ken.size()-1;I>=0;I--)
	{
		if(Ken[I].second == 0 && Ken[I].first < num)
		{
			Ken[I].second = 1;
			return true;
		}
	}


return false;
}


int main(){

	freopen("D-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);

	double value;
	int loss, WithCheatLossKen;
	int test,n;
	cin>>test;

	for(int I=0;I<test;I++){

		cin>>n;

		loss = 0;
		WithCheatLossKen = 0;
		Naomi.clear();
		Ken.clear();
		for(int J=0;J<n;J++)
		{
			cin>>value;
			Naomi.push_back(make_pair(value,0));
		}
		for(int J=0;J<n;J++)
		{
			cin>>value;
			Ken.push_back(make_pair(value,0));
		}

		sort(Naomi.begin(),Naomi.end());
		sort(Ken.begin(),Ken.end());

		//Without cheating
		for(int J=0;J<n;J++){
			for(int K=0;K<n;K++){
				if(Ken[K].second == 0){
					if(Ken[K].first > Naomi[J].first){
						//cout<<Ken[K].first<<" "<<Naomi[J].first<<endl;
						loss++;
						Naomi[J].second = 1;
						Ken[K].second = 1;
						break;
					}
				}
			}
		//cout<<endl;
		}

		///clear katakuti
		for(int J=0;J<n;J++){
			Naomi[J].second = 0;
			Ken[J].second = 0;
		}

		/*
		cout<<"print:\n";
		for(int J=0;J<Naomi.size();J++)
			cout<<Naomi[J].first<<" ";
		cout<<endl;

		for(int J=0;J<Ken.size();J++)
			cout<<Ken[J].first<<" ";
		cout<<"\n---"<<endl;
		*/

		//cheating answer
		for(int J=n-1;J>=0;J--){
			if(isGettingLowest(Naomi[J].first))
			{
				WithCheatLossKen++;
				Naomi[J].second = 1;
			}
		}

		//Cheating answer
		cout<<"Case #"<<I+1<<": "<<WithCheatLossKen<<" "<<(n-loss)<<endl;
		//optimal answer
		//cout<<(n-loss)<<endl;

	}

return 0;
}

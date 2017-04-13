#include<iostream>
#include<vector>

using namespace std;
void print(vector<bool> v)
{
	for(int i=1;i<v.size();++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int casos,N,K;
	cin>>casos;
	for(int k=1;k<=casos;++k)
	{
		cin>>N>>K;
		vector<bool> V(N+1,0);//todos en OFF
		V[0]=1;//
		for(int i=0;i<K;++i)
		{
			vector<bool> temp=V;
			for(int j=1;j<N+1;++j)
			{
				if(temp[j-1])
				{
					V[j]=1-V[j];
				}
				else break;
			}
		}
		//print(V);
		int cont=0;
		for(int i=1;i<N+1;++i)
		{
			if(V[i])cont++;
		}
		if(cont==N)cout<<"Case #"<<k<<": ON"<<endl;
		else cout<<"Case #"<<k<<": OFF"<<endl;
	}
	
	
}

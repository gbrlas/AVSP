// 2011Qual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "string"
#include "iostream"
#include "vector"
#include "algorithm"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
using namespace std;

int visited[1005]={};

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		cin>>N;
		vector<int> a;
		for(int i=0;i<N;i++)
		{
			int x;
			cin>>x;
			a.push_back(x-1);
		}
		double ans=0.0;
		memset(visited,0,sizeof(visited));
		for(int j=0;j<N;j++)
		{
			if(visited[j]) continue;
			int found=0;
			int cur=j;
			while(visited[cur]==0)
			{
				visited[cur]=1;
				found++;
				cur=a[cur];
			}
			if(found>1)
				ans+=found;
		}
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}

//Problem C
//int main()
//{
//	int T;
//	cin>>T;
//	for(int tc=0;tc<T;tc++)
//	{
//		int N;
//		cin>>N;
//		vector<int> a(N);
//		int s=0;
//		for(int i=0;i<N;i++)
//		{
//			cin>>a[i];
//			s^=a[i];
//		}
//		if(s!=0)
//		{
//			cout<<"Case #"<<tc+1<<": NO"<<endl;
//		}
//		else
//		{
//			sort(a.begin(),a.end());
//			int ans=0;
//			for(int j=1;j<a.size();j++)
//			{
//				ans+=a[j];
//			}
//			cout<<"Case #"<<tc+1<<": "<<ans<<endl;
//		}
//	}
//	return 0;
//}

//Problem B
//int g[30][30]={};
//int q[30][30]={};
//
//int main()
//{
//	int T;
//	cin>>T;
//	for(int tc=0;tc<T;tc++)
//	{
//		int C;
//		cin>>C;
//		memset(g,0,sizeof(g));
//		memset(q,0,sizeof(q));
//		for(int i=0;i<C;i++)
//		{
//			string combine;
//			cin>>combine;
//			char a=combine[0];
//			char b=combine[1];
//			char c=combine[2];
//			g[a-'A'][b-'A']=g[b-'A'][a-'A']=c;
//		}
//		int D;
//		cin>>D;
//		for(int i=0;i<D;i++)
//		{
//			string oppose;
//			cin>>oppose;
//			char a=oppose[0];
//			char b=oppose[1];
//			q[a-'A'][b-'A']=q[b-'A'][a-'A']=1;
//		}
//		int N;
//		cin>>N;
//		string str;
//		cin>>str;
//		string ans;
//		for(int i=0;i<N;i++)
//		{
//			char ch;
//			if(ans.size() && g[ans[ans.size()-1]-'A'][str[i]-'A']!=0)
//			{
//				ch=ans[ans.size()-1]=g[ans[ans.size()-1]-'A'][str[i]-'A'];
//			}
//			else
//			{
//				ch=str[i];
//				ans.push_back(str[i]);
//			}
//			for(int j=0;j<ans.size()-1;j++)
//			{
//				if(q[ans[j]-'A'][ch-'A'])
//				{
//					ans.clear();
//					break;
//				}
//			}
//		}
//		cout<<"Case #"<<tc+1<<": [";
//		for(int i=0;i<ans.size();i++)
//		{
//			if(i>0)
//				cout<<", ";
//			cout<<ans[i];
//		}
//		cout<<"]"<<endl;
//	}
//	return 0;
//}

//Problem A
//int main()
//{
//	int T;
//	cin>>T;
//	for(int tc=0;tc<T;tc++)
//	{
//		int N;
//		cin>>N;
//		int pos1=1, pos2=1;
//		int t1=0, t2=0;
//		for(int i=0;i<N;i++)
//		{
//			char ch;
//			int k;
//			cin>>ch>>k;
//			if(ch=='O')
//			{
//				t1+=abs(k-pos1)+1;
//				t1=max(t1,t2+1);
//				pos1=k;
//			}
//			else
//			{
//				t2+=abs(k-pos2)+1;
//				t2=max(t1+1,t2);
//				pos2=k;
//			}
//		}
//		cout<<"Case #"<<tc+1<<": "<<max(t1,t2)<<endl;
//	}
//	return 0;
//}
//

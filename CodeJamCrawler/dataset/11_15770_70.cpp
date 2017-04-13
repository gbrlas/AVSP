#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
int main()
{
int N,c,d,len;
string str;
map< pair< char , char > , char > p;
char ch;
cin>>N;
set < pair < char ,char > > r;
for(int g=1;g <= N; g++)
{
	cin>>c;
	p.clear(); r.clear();
	for(int i=0; i < c; i++)
		{
		cin>>str;
		if(str[0]<str[1])
		p[make_pair(str[0],str[1])]=str[2];
		else
		p[make_pair(str[1],str[0])]=str[2];
		}
	cin>>d;
	for(int i=0; i < d; i++)
		{
		cin>>str;
		if(str[0]<str[1])
		r.insert(make_pair(str[0],str[1]));
		else
		r.insert(make_pair(str[1],str[0]));
		}
	cin>>len;
	vector< char > v;
	char tab[8]={'Q', 'W', 'E','R', 'A', 'S', 'D', 'F'};
	map< char , int > mp;
	for(int i=0; i < 8; i++)
		mp[tab[i]]=i;
	int occurence[8];
	for(int i=0; i < 8; i++) occurence[i]=0;
	char prev=0;
	
	pair<char , char > pr;
	
	for(int i=0; i < len; i++)
	{
		cin>>ch;
		//cout<<g<<"\n";
		bool f=false;
		if(prev!=0){
				if(prev < ch)
				 pr=make_pair(prev,ch);
				else 
				 pr=make_pair(ch,prev);
				if(p.find(pr)!=p.end()){
					ch=p[pr];
					occurence[mp[prev]]--;
					prev=0;
					
					v[v.size()-1]=ch;
					f=true;
				}
				}
		//cout<<g<<"\n";
		if(!f)
		for(int i=0; i < 8; i++)
		{
				if(occurence[i]>0){
			 	if(tab[i] < ch)
			 	 pr=make_pair(tab[i],ch);
			 	else
			 	 pr=make_pair(ch,tab[i]);
			 	if(r.find(pr)!=r.end())
			 		{ v.clear();
			 		 f=true;
			 		 for(int i=0; i < 8; i++)
			 		 	occurence[i]=0;
			 		 prev=0;
			 		  break;
			 		 }
			}
		}
		//cout<<g<<"\n";
		if(!f){ 
		occurence[mp[ch]]++;
		v.push_back(ch);
		prev=ch;
		}
		//cout<<g<<"\n";
	}
//	cout<<w<<"\n";
	cout<<"Case #"<<g<<": "<<"[";
	for(int i=0; i < v.size(); i++)
	{
		if(i==0) cout<<v[i];
		else cout<<", "<<v[i]; 
	}
	cout<<"]\n";
}
return 0;
}

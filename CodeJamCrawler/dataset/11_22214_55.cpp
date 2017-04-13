#include<iostream>
#include<map>
#include<list>
using namespace std;

bool isBaseType(char t)
{
	char s[] = "QWERASDF";

	for(int i=0;i<8;i++){
		if(s[i]==t)
			return true;
	}
	return false;
}

string rev(string s)
{
	reverse(s.begin(),s.end());
	return s;
}

int main()
{
	int t;
	cin>>t;
	int cases = 1;
	while(t>0)
	{
		int c;
		cin>>c;
		map<string,char>p;
		for(int i=0;i<c;i++){
			string t;
			cin>>t;
			//cout<<t<<" "<<t[2]<<endl;
			p[t.substr(0,2)] = t[2];
		}
		int d;
		cin>>d;
		map<string,int>op;
		for(int i=0;i<d;i++){
			string t;
			cin>>t;
			op[t]=1;
		}

		int n;
		cin>>n;
		list<char>a;
		int count=0;
		for(int i=0;i<n;i++){
			char s;
			cin>>s;
			a.push_back(s);
			count++;
			if(count<=1)
				continue;
			string el;
			list<char>::iterator it;
			char e = a.back();
			char c1 = e;
			a.pop_back();
			e = a.back();
			char c2 = e;
			a.pop_back();
			el+=c1;
			el+=c2;
			//cout<<el<<endl;
			if(p.find(el)!=p.end() || p.find(rev(el))!=p.end())
			{
				count-=2;
				//cout<<"dwdwdwdw "<<el<<endl;
				a.push_back(p.find(el)!=p.end() ? p[el] : p[rev(el)]);
				count++;
				continue;
			}
			else
			{
			                a.push_back(el[1]);
							                a.push_back(el[0]);
			}
			string arr;
			for ( it=a.begin() ; it != a.end(); it++ )
			{
				arr+=(*it);
			}
			bool found = false;
			for(int i=0;i<arr.length();i++){
				for(int j=i+1;j<arr.length();j++){
					string cp;
					cp+=arr[i];
					cp+=arr[j];
					//cout<<cp<<" ff "<<endl;
					if((op.find(cp)!=op.end() || op.find(rev(cp))!=op.end()))
					{
						found = true;
						break;
					}
				}
			}
			//cout<<found<<" dwd"<<endl;
			if(found)
			{
				count = 0;
				a.clear();
			}
		}

		list<char>::iterator it;
		cout<<"Case #"<<cases++<<": ["; 
		for ( it=a.begin() ; it != a.end(); it++ )
		{
			if(count==1)
				cout<<*it;
			else
				cout<<*it<<", ";
			count--;
		}
		cout<<"]"<<endl;
		t--;
	}
	return 0;
}
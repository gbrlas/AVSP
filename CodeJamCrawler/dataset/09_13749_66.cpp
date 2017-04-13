#include <iostream>
#include <vector>
#include <string>
using namespace std;
int getlineof(string s)
{
	int r = 0;
	bool outbrek = true;
	for(int i = 0; i < (int)s.length();++i)
	{
		if(s[i]=='('){
			outbrek = false;
			r++;
		}
		else if(s[i]==')')
			outbrek = true;
		if(outbrek == true && s[i]!='(' && s[i]!=')')
			r++;
	}
	return r;
}
bool cmp_str_with_lex(string a,string b)
{
	bool flag = true;
	int itb = 0;
	for(int i = 0; i < (int)a.length() && flag; ++i)
	{
		if(a[i]!=b[itb])
		{
			if(b[itb]=='(')
			{
				flag = false;
				while(b[itb]!=')')
				{
				    itb++;
					if(b[itb]==a[i]) flag = true;
				}
				itb++;
			}
			else
				flag = false;
		}
		else 
			if(a[i]==b[itb]) itb++;
	}
	return flag;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int L,D,N;
	char ch = 10;
	//for(int i = 0; i < 10; ++i){ scanf("%c",&ch); printf("%d = %c ",ch,ch);}
	scanf("%d %d %d\n",&L,&D,&N);
	vector<string> Sets(D);
	for(int i = 0; i < D; i++) cin >> Sets[i];

	string str;
	for(int i = 0; i < N; i++){
		cin >> str;
		int Length = getlineof(str);
		if(Length == L)
		{
			int res = 0;
			for(int j = 0; j < (int)Sets.size(); j++)
				res += int(cmp_str_with_lex(Sets[j],str));
			cout <<"Case #"<<i+1<<": "<<res<<ch;
	  }
		else
			cout <<"Case #"<<i+1<<": 0"<<ch;
	}
	return 0;
}

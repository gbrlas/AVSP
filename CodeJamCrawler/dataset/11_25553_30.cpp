#include <iostream>
#include <cstdio>
#include <utility>
#include <memory>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define VI vector<int>
#define X first
#define Y second
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(i,a,b) for (int i(a); i<=(b); i++)
#define rep(i,a) FOR(i,1,a)
#define rept(i,a) FOR(i,0,a-1)
#define INF 999999999

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	rept(tst,t)
	{

		int n,m;
		scanf("%d%d",&n,&m);
		vector<string> dict;
		dict.resize(n);
		getline(cin,dict[0]);
		vector<string> lst;
		lst.resize(m);
		rept(i,n)
			getline(cin,dict[i]);
		rept(i,m)
			getline(cin,lst[i]);
		printf("Case #%d:",tst+1);
		rept(curl,sz(lst))
		{
			string list(lst[curl].begin(),lst[curl].end());
			pair<string,int> ans=mp("",-1);
			rept(i,sz(dict))
			{
				string word(dict[i].length(),'_');
				vector<string> possible(dict.begin(),dict.end());
				rept(j,sz(possible)) if (dict[i].length()!=possible[j].length()) possible.erase(possible.begin()+j),j--;
				vector<int> avail(26);
				int res=0;
				rept(j,list.length())
				{
					avail.assign(26,false);
					rept(q,sz(possible)) rept(w,possible[q].length()) avail[possible[q][w]-'a']=true;
					char say=list[j];
					if (avail[say-'a'])
					{
						bool f=true;
						rept(q,dict[i].length()) if (dict[i][q]==say) f=false,word[q]=say;
						if (f) res++;
						rept(q,sz(possible))
						{
							rept(w,possible[q].length())
							{
								if ((word[w]!='_' && (word[w]!=possible[q][w])) || (possible[q][w]==say && word[w]=='_'))
								{
									possible.erase(possible.begin()+q);
									q--;
									break;
								}
							}
						}
					}
				}
				if (res>ans.Y) ans=mp(dict[i],res);
			}
			cout<<" "<<ans.X;
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
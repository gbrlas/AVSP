#include <iostream>
#include <string>
#include <string.h>
#include <set>

using namespace std;

char s[101][101];
char q[1001][101];

int main()
{
	int num_s,num_q;
	int cases,curr_case;
	int i,j,ans;
	string query;
	set<string> used;
	set<string>::iterator pos;

	scanf("%d",&cases);
	curr_case=1;
	while(cases--)
	{
		scanf("%d%*c",&num_s);
		for(i=0;i<num_s;i++) gets(s[i]);
		scanf("%d%*c",&num_q);
		for(i=0;i<num_q;i++) gets(q[i]);
		
		for(i=0,ans=0;i<num_q;i++)
		{
			query=q[i];
			pos=used.find(query);
			if(pos==used.end()) 
			{
				used.insert(query);
				if(used.size()==num_s) ans++,used.clear(),i--;
			}
		}
		used.clear();
		printf("Case #%d: %d\n",curr_case++,ans);
	}

	return 0;
}
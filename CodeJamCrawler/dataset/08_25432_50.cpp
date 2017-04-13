#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string>rec;
int n, m;
char ch;

int main()
{
	int cases;
	char s[100000];
	
	scanf("%d",&cases);
	for (int i = 1; i <= cases; ++i)
	{
		scanf("%d",&n);
		ch = getchar();
	    for(int j=0;j<n;j++)	gets(s);
	    scanf("%d",&m);
	    rec.clear();
	    int tot = 0;
	    ch = getchar();
	    while (m --)
	    {
	    	gets(s);
	    	//printf("---%d\n",rec.size());
	    	if (rec.find(s) == rec.end())
	    	{
	    		if (rec.size() == n - 1)
	    		{
	    			++tot;
	    			rec.clear();
	    		}
	    		rec.insert(s);
	    	}
//	    	printf("%d:   %s %d\n",m, s,rec.size());
	    }
	    printf("Case #%d: %d\n",i, tot);
	}
	return 0;
}

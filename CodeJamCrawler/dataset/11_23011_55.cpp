#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

char arr[105];
char cmb[100][100];
int op[100][100];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		memset(cmb,0,sizeof(cmb));
		memset(op,0,sizeof(op));
		memset(arr,0,sizeof(arr));
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			char a,b,c;
			scanf(" %c%c%c",&a,&b,&c);
			cmb[a][b]=c;
			cmb[b][a]=c;
		}

		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			char a,b;
			scanf(" %c%c",&a,&b);
			op[a][b]=1;
			op[b][a]=1;
		}

		scanf("%d ",&n);
		for(int i=0;i<n;i++)
			scanf("%c",&arr[i]);

		vector<char> el;
		el.clear();

		for(int i=0;i<n;i++)
		{
			if( el.size() == 0 ) el.push_back(arr[i]);
			else
			{
				if( cmb[el[el.size()-1]][arr[i]] != 0 )
				{
					vector<char> tmp;
					tmp.clear();
					for(int j=0;j<el.size()-1;j++)
						tmp.push_back(el[j]);
					tmp.push_back(cmb[el[el.size()-1]][arr[i]]);
					el.clear();
					el = tmp;
				}
				else
				{
					int flag=0;
					for(int j=0;j<el.size();j++)
					{
						if( op[el[j]][arr[i]] == 1 )
						{
							flag=1;
							el.clear();
							break;
						}
					}
					if( flag == 0 ) el.push_back(arr[i]);
				}
			}
		}
		printf("Case #%d: [",t);
		if( el.size() > 0 )
		{
			printf("%c",el[0]);
			for(int i=1;i<el.size();i++)
				printf(", %c",el[i]);
		}
		printf("]\n");
	}

	return 0;
}
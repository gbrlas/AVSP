#include<stdio.h>
#include<vector>
using namespace std;
#define M 5001
#define W 16
#define S 1000
vector<vector<char> > pat;
int main(){
	char word[M][W],str[S];
	int i,j,k,L,D,N,l,count;
	gets(str);
    sscanf(str,"%d%d%d",&L,&D,&N);
	for(j=0;j<D;j++)
	gets(word[j]);
	for(i=1;i<=N;i++)
	{
		gets(str);
		count=0;
		j=0;
		pat.clear();
		pat.resize(L);
		for(k=0;j<L;k++)
		{
			if(str[k]=='(')
			{
				k++;
				while(str[k]!=')')
				pat[j].push_back(str[k++]);
			}
			else
				pat[j].push_back(str[k]);
			j++;
		}
		//for(k=0;k<L;k++)
//		for(l=0;l<pat[k].size();l++)
		//printf("%d %d %c\n",k,l,pat[k][l]);
		for(j=0;j<D;j++)
		{
			for(k=0;k<L;k++)
			{
                for(l=0;l<pat[k].size();l++)
				{
                //printf("%c %c\n",pat[k][l],word[j][k]);
                if(pat[k][l]==word[j][k])
				break;
                }
				if(l==pat[k].size())
				break;
			}
		    if(k==L)
			count++;
		}
		printf("Case #%d: %d\n",i,count);
	}
	return 0;
}

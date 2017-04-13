#include<iostream>
using namespace std;
int C,D,N;
int comb[50][50];
int opp[50][50];
int oppl[50];
char str[105];
char astr[105];
int alen;
int firin[50];
int main()
{
	//freopen("B-large.in","r",stdin);
	//freopen("B-large.out","w",stdout);
	int T,i,j,Case=0;
	char a,b,c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&C);
		memset(comb,-1,sizeof(comb));
		for(i=0;i<C;i++)
		{
			scanf(" %c%c%c",&a,&b,&c);
			comb[a-'A'][b-'A']=comb[b-'A'][a-'A']=c-'A';
		}
		scanf("%d",&D);
		memset(oppl,0,sizeof(oppl));
		//memset(opp,0,sizeof(opp));
		for(i=0;i<D;i++)
		{
			scanf(" %c%c",&a,&b);
			opp[a-'A'][oppl[a-'A']++]=b-'A';
			opp[b-'A'][oppl[b-'A']++]=a-'A';
			//opp[a-'A'][b-'A']=opp[b-'A'][a-'A']=1;
		}
		scanf("%d",&N);
		scanf(" %s",str);
		alen=0;
		memset(firin,0,sizeof(firin));
		for(j=0;j<N;j++)
		{
			if(alen==0)
			{
				astr[alen++]=str[j];
				firin[str[j]-'A']++;
			}
			else
			{
				astr[alen++]=str[j];
				firin[str[j]-'A']++;
				while(alen>=2&&comb[astr[alen-1]-'A'][astr[alen-2]-'A']!=-1)
				{
					firin[astr[alen-1]-'A']--;
					firin[astr[alen-2]-'A']--;
					astr[alen-2]=comb[astr[alen-1]-'A'][astr[alen-2]-'A']+'A';
					firin[astr[alen-2]-'A']++;
					alen--;
				}
				/*
				for(i=0;i<alen-1;i++)
					if(opp[astr[alen-1]-'A'][astr[i]-'A'])
					{
						alen=i;
						break;
					}*/
				
				//int mmf=-1;
				for(i=0;i<oppl[astr[alen-1]-'A'];i++)
				{
					if(firin[opp[astr[alen-1]-'A'][i]]!=0)
						break;
				}
				if(i<oppl[astr[alen-1]-'A'])
				{
					memset(firin,0,sizeof(firin));
					alen=0;
				}
			}
		}
		printf("Case #%d: [",++Case);
		if(alen==0)
		{
			printf("]\n");
			continue;
		}
		for(i=0;i<alen-1;i++)
			printf("%c, ",astr[i]);
		printf("%c]\n",astr[i]);
	}
	return 0;
}
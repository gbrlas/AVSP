#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000005];
char to[]="yhesocvxduiglbkrztnwjpfmaq";
int main()
{
	//freopen("out.txt","w",stdout);
	/*to['q'-'a']='z';
	to['y'-'a']='a';
	to['e'-'a']='o';
	to[25]='z';
	for(int j=0;j<3;j++)
	{
		char s1[1000];
		gets(s1);
		gets(s);
		for(int i=0;s1[i];i++)
		{
			if(s1[i]==' ') continue;
			to[s1[i]-'a']=s[i];
		}
	}
	for(int i=0;i<26;i++) printf("%c",to[i]);*/
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int _,cas=0;
	scanf("%d%*c",&_);
	while(_--)
	{
		gets(s);
		printf("Case #%d: ",++cas);
		for(int i=0;s[i];i++)
		{
			if(s[i]==' ') printf(" ");
			else printf("%c",to[s[i]-'a']);
		}
		printf("\n");
	}
	return 0;
}

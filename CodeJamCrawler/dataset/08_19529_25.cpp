#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool cmp(char * str1, char * str2)
{
	int a=strlen(str1), b=strlen(str2);
	if(a!=b)
		return false;
	for(int i = 0;i<a;i++)
		if(str1[i]!=str2[i])
			return false;
	return true;
}

int main()
{
	//ios_bast::sync_with_stdio(0);
	int n, s, q, w, wynik;
	cin >> n;
	char t[100][101];
	bool b[100];
	char in[101];
	for(int j = 1;j<=n;j++)
	{
		scanf("%d\n", &s);
		for(int i = 0;i<s;i++)
			cin.getline(t[i],110);
		scanf("%d\n", &q);
		w=s;
		for(int i = 0;i<s;i++)
			b[i]=0;
		wynik=0;
		while(q>0)
		{
			q--;
			cin.getline(in,110);
			for(int i = 0;i<s;i++)
				if(!b[i]&&cmp(in,t[i]))
				{
					w--;
					b[i]=1;
				}
			if(w==0)
			{
				wynik++;
				for(int i = 0;i<s;i++)
					if(!cmp(t[i],in))b[i]=0;
				w=s-1;
			}
		}
		cout << "Case #" << j << ": " << wynik << endl;
	}
}

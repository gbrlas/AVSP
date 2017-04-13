#include	<cstdio>
#include	<vector>
#include	<string>
#include	<iostream>
#include	<conio.h>
using namespace std;

int main()
{
	int n,m;
	int x,y;
	int c;
	vector <string> sl,in;
	vector <bool> f;
	string str;
	char buf[256];
	bool flag;


	scanf("%d",&n);
	for(m=0;m<n;m++)
	{
		x=0;
		c=0;
		str="";
		sl.clear();
		in.clear();
		f.clear();

		scanf("%d",&x);
		fgets(buf,256,stdin);
		while(x--)
		{
			fgets(buf,256,stdin);
			str=buf;
			sl.push_back(str);
			f.push_back(false);

//			cout << "list " <<str;
		}

		scanf("%d",&x);
		fgets(buf,256,stdin);
		while(x--)
		{
			fgets(buf,256,stdin);
			str=buf;
			in.push_back(str);
//			cout << "in " <<str;
		}


		for(x=0;x<in.size();x++)
		{
			for(y=0;y<sl.size();y++)
			{
				if(in[x]==sl[y])
				{
					f[y]=true;
				}
			}

			flag=true;
			for(y=0;y<f.size() && flag;y++)
				if(!f[y])
					flag=false;

			if(flag)
			{
				c++;
				x--;
				for(y=0;y<f.size();y++)	f[y]=false;
			}
		}
		cout << "Case #" << m+1 << ": " << c << endl;
//		getch();
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<iomanip>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<memory.h>
#include<iomanip>
#include<cmath>
using namespace std;

struct task
{
	int id;
	int button;
	task(): id(0), button(0) {};
	task(int id, int button): id(id), button(button) {};
};


vector<task> mas;

int main()
{
	int test_count;
	cin>>test_count;
	for(int test_num=0;test_num<test_count;test_num++)
	{
		int k;
		scanf("%d",&k);
		mas.resize(0);
		for(int i=0;i<k;i++)
		{
			char tmp[3];
			int x;
			scanf("%s%d",tmp,&x);
			mas.push_back(task((tmp[0]=='O')?0:1,x));
		}
		int x[2];
		x[0]=x[1]=1;
		int t=0;
		for(int i=0;i<k;i++)
		{
			int a = mas[i].id;
			int t2 = abs(mas[i].button-x[a]) + 1;
			for(int j=i+1;j<k;j++)
				if (mas[j].id==1-a)
				{
					if (abs(mas[j].button-x[1-a])<=t2)
						x[1-a]=mas[j].button;
					else
					{
						if (mas[j].button>x[1-a])
							x[1-a]+=t2;
						else
							x[1-a]-=t2;
					}

					break;
				}
			x[a]=mas[i].button;
			t+=t2;
		}
		printf("Case #%d: %d\n",test_num+1,t);

	}
	return 0;
}
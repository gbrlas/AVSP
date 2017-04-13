/*
Author          : MaShuo
Data            : 
*/

#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const	int			maxn	= 100;
const	int			maxna	= 100;
const	int			maxnb	= 100;
struct				datatype
{
	int			st , ed;
};

datatype			data1[maxna] , data2[maxnb];
int				n , q , t , na , nb , answer1 , answer2;

int				list1[24 * 60 + 10] , list2[24 * 60 + 10];

int				change(char s[])
{
	int			i = 0;
	i += (s[0] - '0') * 10 * 60;
	i += (s[1] - '0') * 60;
	i += (s[3] - '0') * 10;
	i += (s[4] - '0');
	return i;
}
bool				cmp(datatype u , datatype v)
{
	return u.st < v.st;
}
void				init()
{
	int			i;
	char			temp1[10] , temp2[10];

	answer1 = 0;  answer2 = 0;
	memset(data1 , 0 , sizeof(data1));
	memset(data2 , 0 , sizeof(data2));
	memset(list1 , 0 , sizeof(list1));
	memset(list2 , 0 , sizeof(list2));

	scanf("%d\n" , &t);
	scanf("%d %d\n" , &na , &nb);
	for (i = 0;i < na;i++)
	{
		scanf("%s %s\n" , temp1 , temp2);
		data1[i].st = change(temp1);
		data1[i].ed = change(temp2);
	}
	for (i = 0;i < nb;i++)
	{
		scanf("%s %s\n" , temp1 , temp2);
		data2[i].st = change(temp1);
		data2[i].ed = change(temp2);
	}
	sort(data1 , data1 + na , cmp);
	sort(data2 , data2 + nb , cmp);
}
void				work()
{
	int			i = 0, j = 0 , temp;
	bool			found;

	for (int time_ = 0;time_ <= 24 * 60;time_++)
	{
		while (i < na && data1[i].st == time_)
		{
			found = false;
			for (temp = 0;temp <= data1[i].st;temp++)
				if (list1[temp])
				{
					found = true;
					list1[temp]--;
					break;
				}
			if (!found) answer1++;
			list2[data1[i].ed + t]++;
			i++;
		}
		while (j < nb && data2[j].st == time_)
		{
			found = false;
			for (temp = 0;temp <= data2[j].st;temp++)
				if (list2[temp])
				{
					found = true;
					list2[temp]--;
					break;
				}		
			if (!found) answer2++;
			list1[data2[j].ed + t]++;
			j++;
		}
	}
}
void				print()
{
	printf("Case #%d: %d %d\n" , q , answer1 , answer2);
}
int				main()
{
	freopen("input.txt","r",stdin);
	freopen("output1.txt","w",stdout);

	for (scanf("%d\n" , &n) , q = 1;q <= n;q++)
	{
		init();	
		work();
		print();
	}
}
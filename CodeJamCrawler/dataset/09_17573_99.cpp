#include <iostream>
#include <string>
#include <vector>
using namespace std;

string cur;
string wcm;

void output(int x)
{
	if(x == 0)
		cout << "0000" << endl;
	else if(x < 10)
		cout << "000" << x << endl;
	else if(x < 100)
		cout << "00" << x << endl;
	else if(x < 1000)
		cout << "0" << x << endl;
	else cout << x << endl;
}

int tot;
int ln;

int pro[501][20];

vector <int> path;

int process(int str, int sub)
{
	if(sub == 19)
	{
		pro[str][sub] = 1;
		//if(tot == 10000) tot = 0;
		//cout << tot << ": ";
		//for(int i = 0; i < 19; i++)
		//	cout << path[i] << " ";
		//cout << endl;
		return 1;
	}
	if (pro[str][sub] != -1)
		return pro[str][sub];
	if(str == ln)
	{
		pro[str][sub] = 0;
		return 0;
	}
	pro[str][sub] = 0;
	//for(; str < ln; str++)
	//{
		if(cur[str] == wcm[sub])
		{
		//	path[sub] = str;
			pro[str][sub] = process(str+1, sub+1)+process(str+1, sub);
			//return pro[str][sub];
		}
		else
			pro[str][sub] = process(str+1, sub);
	//}
	pro[str][sub] %= 10000;
	if(pro[str][sub] == -1)
	cout << "str = " << str << " sub = " << sub << endl;
	return pro[str][sub];
}

int main()
{
	wcm = "welcome to code jam";
	//path.resize(19);
	int N;
	scanf("%d", &N);
	char c;
	scanf("%c", &c);
	int i;
	for(i = 1; i <= N; i++)
	{
		//scanf("%s", cur);
		cur = "";
		ln = 0;
		for(int abc = 0; abc < 501; abc++)
			for(int pqr = 0; pqr < 20; pqr++)
				pro[abc][pqr] = -1;
		
		do
		{
			scanf("%c", &c);
			if(c != '\n' && c != '\0')
			{
				cur += c;
				ln++;
			}
		}while (c!= '\n' && c != '\0');
//  		ln = strlen(cur);
		tot = process(0, 0);
		cout << "Case #" << i << ": ";
		output(tot);
	}
}

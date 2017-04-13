#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include <functional>
#include<vector>
#include<string>
#include <iostream>
#include <sstream>
#include<set>
#include<map>
#include<stdlib.h>
#include<queue>
//#include<cstdio>
//#include<cstdlib>
using namespace std;

#define fo(i,n) for(i=0;i<(n);++i)


typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

double truncate(double x,int n)
{
	return (floor(x*pow(10,n))*pow(10,-n));
}
int min(int x,int y) {return x<y ? 1:0;}
int max(int x,int y) {return x>y ? 1:0;}
int main(void)
{
	FILE *in, *out;
	in = fopen("B-small-attempt1.in", "r");
	out= fopen("aOutput.out","w");

	int i,j,t,c,d,n;
	char str[5];
	string s,res,temp2,temp1;
	map<string, string> combineMap;
	map<string, string> opposedMap;

	fscanf(in,"%d", &t);

	for(i=0;i<t;i++)
	{
		fscanf(in,"%d", &c);

		combineMap.erase(combineMap.begin(), combineMap.end());
		opposedMap.erase(opposedMap.begin(), opposedMap.end());
		for(j=0;j<c;j++)
		{
			fscanf(in,"%s", str);
			s = str;
			combineMap[s.substr(0,2)] = s[2];
			swap(s[0], s[1]);
			combineMap[s.substr(0,2)] = s[2];

			//printf("%s = %s\n", s.substr(0,2).c_str(), combineMap[s.substr(0,2)].c_str());
		}

		fscanf(in,"%d",&d);
		for(j=0;j<d;j++)
		{
			fscanf(in,"%s", str);
			s = str;
			opposedMap[s.substr(0,1)] = s[1];
			opposedMap[s.substr(1,1)] = s[0];
		}

		fscanf(in, "%d", &n);
		fscanf(in, "%s", str);
		s= str;
		res = "";
		for(j=0;j<s.size();j++)
		{
			res+=s[j];
			//printf("%s\n", res.c_str());
			if(res.size()>=2)
			{
				temp2 = res.substr(res.size()-2, 2);
				temp1 = res.substr(res.size()-1, 1);

				if(combineMap.find(temp2) != combineMap.end())
				{
					res.erase(res.size()-2, 2);
				//	printf("%s\n", res.c_str());
					res+=combineMap[temp2];
				//	printf("%s\n", res.c_str());
				}
				else if(opposedMap.find(temp1)!=opposedMap.end())
				{
					if(res.find(opposedMap[temp1])!= -1)
					{
						res.erase(res.begin(), res.end());
					//	printf("%s\n", res.c_str());
					}
				}
			}
		}

		fprintf(out,"Case #%d: [", i+1);

		if(res.size()==0)
			fprintf(out,"]\n");
		for(j=0;j<res.size();j++)
		{
			fprintf(out,"%c", res[j]);

			if(j+1 == res.size())
				fprintf(out,"]\n");
			else
				fprintf(out, ", ");
		}

	}

	return 0;
}

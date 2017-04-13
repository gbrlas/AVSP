#include<stdio.h>
#include<map>
#include<iostream>
#include<cstring>

using namespace std;

map<string, int> m;
map<string, int> :: iterator it, iit;

int main()
{
	int testnum, n, nn;
	string str;

	scanf("%ld",&testnum);
	for(int test = 1;test <= testnum;test++){
		m.clear();
		scanf("%ld",&n);
		getline(cin,str);
		for(int i = 0;i < n;i++){
			getline(cin,str);
			//cout << str << endl;
			m[str] = 0;
		}
		scanf("%ld",&nn);
		getline(cin,str);
		int ret = 0, unum = 0;
		for(int i = 0;i < nn;i++){
			getline(cin,str);
			if(n == 1)
				continue;
			it = m.find(str);
			(it->second) = (it->second) + 1;
			if((it->second) == 1){
				unum++;
				if(unum == n){
					for(iit = m.begin();iit != m.end();iit++){
						iit->second = 0;
					}
					ret++;
					unum = 1;
					(it->second) = 1;
				}
			}
		}
		printf("Case #%ld: %ld\n",test,ret);
	}
	return 0;
}

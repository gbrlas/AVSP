#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

bool sorting_func(long o,long t)
{
  return o<t;
}
int main()
{
    freopen("a1.in", "r", stdin);
    freopen("a1.out", "w", stdout);
	long tq=0;
	long c=0;
	cin>>tq;
	for(long i=1;i<=tq;++i){
		long zmiany=0;
		cin>>c;
		long q=0;
		cin>>q;
		std::list<long> tab;
		for(int x=0;x<q;++x){
			long temp=0;
			cin>>temp;
			tab.push_back(temp);
		}
		tab.sort(sorting_func);
		long fi=0,se=0;
		long was=0;
		std::list<long> wyniki;
		if(c==1){
			printf("Case #%ld: %d\n",i,tab.size());
			continue;
		}
		wyniki.push_back(tab.size());
		for(std::list<long>::iterator iter=tab.begin();iter!=tab.end();++iter){
			++was;
			if(*iter>=c){
				std::list<long>::iterator it=iter;
				if(++it==tab.end()){
				
				}
				while(*iter>=c){
					c+=c-1;
					zmiany+=1;
				}
			}
			wyniki.push_back(zmiany+tab.size()-was);
			c+=*iter;
		}
		wyniki.sort(sorting_func);

		printf("Case #%ld: %ld\n",i,wyniki.front());
	}
    
    return 0;
}

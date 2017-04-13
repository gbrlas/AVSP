/*
 * test.cpp
 *
 *  Created on: 2013-04-25
 *      Author: fudq
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("testin.txt","r",stdin);
  freopen("testout.txt","w",stdout);
#endif
    int n,T,r,ans,cas=1;
    scanf("%d",&T);
    while(T--)
    {
    	scanf("%d%d",&r,&n);
    	ans=0;
    	while(n)
    	{
    		int t=(r+1)*(r+1)-r*r;
    		if(n >= t)
    		{
    			ans++;
    			n-=t;
    			r+=2;
    		}
    		else
    			break;
    	}
    	printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}

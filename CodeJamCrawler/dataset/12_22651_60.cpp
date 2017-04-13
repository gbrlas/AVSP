#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef char obfused;
typedef char english;

int main()
{
	////freopen("in.in","r",stdin);
	//freopen("alphabet1.out","w",stdout);
	//string obfuse="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	//string normal="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	//map<obfused,english> alphabet;
	//for(int i=0;i!=obfuse.size();i++)
	//	alphabet.insert(make_pair(obfuse[i],normal[i]));
	//alphabet.insert(make_pair('q','z'));
	//alphabet.insert(make_pair('z','q'));
	//vector<char> temp;
	//for(auto i=alphabet.begin();i!=alphabet.end();i++)
	//	printf("alphabet['%c']='%c';\n",i->first,i->second);
	//	//temp.push_back(i->second);
	///*sort(temp.begin(),temp.end());
	//for(int i=0;i!=temp.size();i++)
	//	printf("%c\n",temp[i]);*/
	map<obfused,english> alphabet;
	alphabet[' ']=' ';
	alphabet['a']='y';
	alphabet['b']='h';
	alphabet['c']='e';
	alphabet['d']='s';
	alphabet['e']='o';
	alphabet['f']='c';
	alphabet['g']='v';
	alphabet['h']='x';
	alphabet['i']='d';
	alphabet['j']='u';
	alphabet['k']='i';
	alphabet['l']='g';
	alphabet['m']='l';
	alphabet['n']='b';
	alphabet['o']='k';
	alphabet['p']='r';
	alphabet['q']='z';
	alphabet['r']='t';
	alphabet['s']='n';
	alphabet['t']='w';
	alphabet['u']='j';
	alphabet['v']='p';
	alphabet['w']='f';
	alphabet['x']='m';
	alphabet['y']='a';
	alphabet['z']='q';
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	int n;
	cin>>n;
	string obf,ans="";
	getline(cin,obf);
	for(int i=1;i<=n;i++)
	{
		getline(cin,obf);
		ans.clear();
		for(int j=0;j!=obf.size();j++)
			ans+=alphabet[obf[j]];
		printf("Case #%d: %s\n",i,ans.c_str());
	}
	return 0;
}
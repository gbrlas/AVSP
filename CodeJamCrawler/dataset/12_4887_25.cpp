#include<iostream>
#include<stdio.h>
#include<fstream>
#include<map>

using namespace std;

int main()
{
	map<char,char> mymap;
	map<char,char>::iterator it;
	mymap['a']='y';
	mymap['b']='h';
	mymap['c']='e';
	mymap['d']='s';
	mymap['e']='o';
	mymap['f']='c';
	mymap['g']='v';
	mymap['h']='x';
	mymap['i']='d';
	mymap['j']='u';
	mymap['k']='i';
	mymap['l']='g';
	mymap['m']='l';
	mymap['n']='b';
	mymap['o']='k';
	mymap['p']='r';
	mymap['q']='z';
	mymap['r']='t';	
	mymap['s']='n';
	mymap['t']='w';
	mymap['u']='j';
	mymap['v']='p';
	mymap['w']='f';
	mymap['x']='m';
	mymap['y']='a';
	mymap['z']='q';
	mymap[' ']=' ';
	mymap['\n']='\n';
	char t,ch;
	int no,n = 0;
	ifstream file("A-small-attempt1.in");
	if(file==NULL)
		cout<<"error";
	ofstream f("output");
//	file>>t;
//	cout<<t<<endl;
	file>>no;
	cout<<no;
	ch = file.get();
	f<<"Case #"<<n+1<<": ";	
	while(!file.eof())
	{	
		it = mymap.find(ch);
		if(mymap.find(ch)->second!='\n')
		{
			f<<mymap.find(ch)->second;
		}
		ch = file.get();
		if(ch=='\n')
		{
			f<<endl;
			n++;
			if(n!=no)
				f<<"Case #"<<n+1<<": ";
		}
	}
	return 0;
	file.close();
	f.close();
}



#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


int palindrome(string word)
{
	do{
		string rev_word = word;
		reverse(rev_word.begin(), rev_word.end());

		if(word == rev_word)return 1;
			else return 0;

	}while (word != "END");
}

int main()
{
	ifstream in("entrada.in");
	ofstream out ("res_1000.txt");
	
	
	int pal[14]={1, 4, 9 ,121, 484, 10201, 12321, 14641, 40804, 44944 };
	int SIZE=9;
	
	int T=0, a=0,b=0;
	in>>T;
	for(int x=1; x<=T; x++)
	{
		int res=0;
		in>>a>>b;
		
		int i=0, j=SIZE;
		while(a>pal[i] && i<SIZE)	i++;
		while(b<pal[j] && j>=0)	j--;
	
		//cout<<"i: "<<i<<" ["<<pal[i]<<" ]"<<endl;
		//cout<<"j: "<<j<<" ["<<pal[j]<<" ]"<<endl;
		
		if(j<i)res=0;
		else res=j-i+1;
		
		out<<"Case #"<<x<<": "<<res<<endl;
		
	}
	
	/*
	string a;
	while(a!="-1")
	{
		cin>>a;
		if(palindrome(a)) out<<a<<endl;
	}
	*/
	return 0;
}



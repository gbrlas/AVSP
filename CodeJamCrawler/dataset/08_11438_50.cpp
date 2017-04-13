#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;
vector<string> qry(200);
char ch;
int tt=0;
int f=0;
int se,sq;
vector<string> eng(200);
char temp[110];

int cmp(string a,int max){
	for(int j=max;j<sq;j++){
		if(a.compare(qry[j])==0){
			cout<<"("<<qry[j]<<";"<<j<<")";
			return j;}
	}
	return sq-1;
}
void main(){
	// Read input from this file 
	ifstream inp("A-small.in",ios::in);
	// write output to this file 
	ofstream out("A-Ans-small.in",ios::out);

	vector<int> mark;
	int count=0;
	int result=0,max=0;
	inp>>count;
		for(int j=0;j<25;j++)
		mark.push_back(0);

	for(int i=0;i<count;i++)
	{
		
		eng.clear();
		qry.clear();
		inp>>se;
		inp.getline(temp,110);
		for(int j=0;j<se;j++){
			inp.getline(temp,110);
			eng.push_back(temp);
		}
		inp>>sq;
		inp.getline(temp,110);
		for(int j=0;j<sq;j++){
			inp.getline(temp,110);
			qry.push_back(temp);
		}

		for(int j=0;j<se;j++)
		cout<<eng[j]<<"\n";
		for(int j=0;j<sq;j++)
		cout<<qry[j]<<"\n";

        result=0;
		for(int j=0;j<se;j++)
		mark[j]=0;

		if(se>0&&sq>0)
		{
			for(int j=0;j<sq;j++){
				int cm=0;
				for(int k=0;k<se;k++){
					if(eng[k].compare(qry[j])==0){
						mark[k]=1;
					}
				}
				cout<<"[";
				for(int k=0;k<se;k++){
					cout<<mark[k]<<",";
					if(mark[k]==0) cm++;
				}
				cout<<"]";
				if(cm==0){
					result++;
					for(int k=0;k<se;k++){
						if(eng[k].compare(qry[j])==0)
						mark[k]=1;
						else mark[k]=0;
					}
				}

			}
		}	 
		cout<<"("<<result<<")\n";
		out<<"Case #"<<i+1<<":"<<" "<<result<<"\n";
	}
}

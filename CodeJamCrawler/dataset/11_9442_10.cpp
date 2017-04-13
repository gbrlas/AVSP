#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <set>

using namespace std;

#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

int main(void)
{
	freopen("input.magika.txt", "r", stdin);
	freopen("output.magika1.txt", "w+", stdout);

	int cases,C,D,N;
	vector <string> nonbase; 
	vector <string> oele;
	char nonb[36];

	cin>>cases;

	FOR(i,cases)
	{
		cin>>C;
		string nb;
		FOR(ii,C) { cin>>nb; nonbase.push_back(nb.substr(0,2)); nonb[ii]=nb[2]; }

		cin>>D;
		string oe;
		FOR(j,D) { cin>>oe; oele.push_back(oe); }

		string invoke;
		cin>>N;
		cin>>invoke;
		
		string temp;
		int oppose = 0,op=0,opp=0;
		int comb = 0,cb = 0,pb=0;
		FOR(j,invoke.size())
		{
			temp.push_back(invoke[j]);

				FOR(jj,nonbase.size())
				{
					FOR(k,temp.size())
					{
						if(k<=(int)(temp.size()-1))
					if(temp[k] == nonbase[jj][0])
						if((k-1)>=0)
							if(temp[k-1] == nonbase[jj][1])
							{
								string nbase;
								nbase.push_back(nonb[pb]);
								temp.erase(k-1,2);
								temp.insert(k-1,nbase);
							}
							if(k<=(int)(temp.size()-1))
					if(temp[k] == nonbase[jj][1])
						if((k-1)>=0)
							if(temp[k-1] == nonbase[jj][0])
							{
								string nbase;
								nbase.push_back(nonb[pb]);
								temp.erase(k-1,2);
								temp.insert(k-1,nbase);
							}
					}
				}
							
				FOR(k,oele.size())
				{
					FOR(jj,temp.size())
					{
						if(jj<=(int)(temp.size()-1))
						{
							if(jj<=(int)(temp.size()-1))
							if(temp[jj] == oele[k][0])
							{	
								int pos = 0;
								while(temp[pos]!=oele[k][1])
								{
									pos++;
									if(pos>(int)(temp.size()-1))break;
								}
								if(pos<=(int)(temp.size()-1))
								if(temp[pos]==oele[k][1])
								{
										temp.clear();
								}
							}

							if(jj<=(int)(temp.size()-1))
							if(temp[jj] == oele[k][1])
							{	
								int pos = 0;
								while(temp[pos]!=oele[k][0])
								{
								
									pos++;
									if(pos>(int)(temp.size()-1))break;
								}
								if(pos<=(int)(temp.size()-1))
								if(temp[pos]==oele[k][0])
								{
									temp.clear();
								}
							}
						}
					}
				}
		}//end for

		invoke = temp;
		/*
		FOR(j,nonbase.size())
		{
			string nbase,f,b;
			f = nonbase[j];
			b = nonbase[j].substr(1,2) + nonbase[j].substr(0,1);
			int pos = min(invoke.find(f),invoke.find(b));
			if(pos != -1){
				nbase.push_back(nonb[j]);
				invoke.erase(pos,2);
				invoke.insert(pos,nbase);
			}
		}*/

		cout<<"Case #"<<(i+1)<<": "<< "["; 
		FOR(ii,invoke.size()) if(ii!=invoke.size()-1) cout<<invoke[ii]<<", "; else cout<<invoke[ii];
		cout<<"]"<<endl;
		
		nonbase.clear();
		oele.clear();
    }

	return 0;
}
#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define fo(i,n) for(i=0;i<(n);++i) 
#define CL(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
typedef vector<int> vi ; 
typedef vector<string> vs ;

FILE *in = fopen("test2.in","r");
FILE *out= fopen("test.out","w");

string readline()
{
	char ch;
	string ret;

	while(fscanf(in,"%c",&ch)!=EOF)
	{
		if(ch=='\n') return ret;
		ret+=ch;
	}

	return ret;
}

vector<string> tokenize(string s, string ch) { 
  vector<string> ret; 
  for( int i = 0, j; i < s.size(); i = j+1 ) { 
    j = s.find_first_of(ch, i); 
    if( j == -1 ) j = s.size(); 
    if( j-i > 0 ) ret.push_back( s.substr(i, j-i) ); 
  } 
  return ret; 
} 

vector<int> tokint(string s, string ch) { 
  vector<int> ret; 
  vector<string> z = tokenize(s, ch); 
  for( int i = 0; i < z.size(); i++ ) 
    ret.push_back( atoi(z[i].c_str()) ); 
  return ret; 
} 

class node
{
public:
	int s,e,end_pos,start_pos,ind;
};


bool cmp(node u, node v)
{
	if(u.s!=v.s)
		return u.s<v.s;
	if(u.start_pos!=v.start_pos)
		return u.start_pos<v.start_pos;
	return u.ind<v.ind;
}



int main()
{
	int i,z,tests,t,j,na,nb,a,b,reta,retb;
	vi qa,qb;
	vector<node> trip;
	node temp;
	string str;
	vi vect;
	str=readline();
	sscanf(str.c_str(),"%d",&tests);

	fo(z,tests)
	{
		trip.clear();
		str=readline();
		sscanf(str.c_str(),"%d",&t);
		str=readline();
		sscanf(str.c_str(),"%d%d",&na,&nb);
		
		fo(i,na)
		{
			str=readline();
			vect=tokint(str," :");
			temp.s=vect[0]*60+vect[1];
			temp.e=vect[2]*60+vect[3];
			temp.start_pos=0;
			temp.end_pos=1;
			temp.ind=i;
			trip.push_back(temp);
		}

		fo(i,nb)
		{
			str=readline();
			vect=tokint(str," :");
			temp.s=vect[0]*60+vect[1];
			temp.e=vect[2]*60+vect[3];
			temp.start_pos=1;
			temp.end_pos=0;
			temp.ind=i;
			trip.push_back(temp);
		}

		sort(trip.begin(),trip.end(),cmp);
		qa.clear();
		qb.clear();
		a=0;
		b=0;
		reta=0;
		retb=0;

		fo(i,trip.size())
		{
			fo(j,qa.size())
				if(qa[j]<=trip[i].s)
					break;

			if(j!=qa.size())
				qa.erase(qa.begin()+j),a++;

			fo(j,qb.size())
				if(qb[j]<=trip[i].s)
					break;

			if(j!=qb.size())
				qb.erase(qb.begin()+j),b++;

			if(trip[i].start_pos==0)
			{
				if(a>0) a--;
				else reta++;
				qb.push_back(trip[i].e+t);
			}

			else
			{
				if(b>0) b--;
				else retb++;
				qa.push_back(trip[i].e+t);
			}
		}

		fprintf(out,"Case #%d: %d %d\n",z+1,reta,retb);
	}

	return 0;
}


#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
inline int compare_string(string s1, string s2)

{

  if(s1.length()<s2.length())

    return -1;

  else if(s1.length()>s2.length())

    return 1;

  else

  {

    for(int i=0; i<s1.length(); ++i)

    {

      if(s1[i]<s2[i])

        return -1;

      else if(s1[i]>s2[i])

        return 1;

    }

  }

 

  return 0;

}



inline string sub_string(string s1, string s2)

{

  int i;

  string s;

  bool positive=true;

 

  if(compare_string(s1,s2)<0)

  {

    positive=false;

    s1.swap(s2);

  }

 

  //add leading zero

  s2.insert(0,s1.length()-s2.length(),'0');

 

  //s1 - s2 

  for(i=s1.length()-1; i>=0; --i)

    if(s1[i]>=s2[i])

      s.insert(0,1,s1[i]-s2[i]+'0');

    else

    {

      s.insert(0,1,s1[i]-s2[i]+10+'0');

      s1[i-1]-=1;

    }

 

  //trim

  for(i=0; s[i]=='0'; ++i);

    s=s.substr(i);

   

  if(!s.length())

    s="0";

 

  //negative

  if(!positive)

    s.insert(0,1,'-');

   

  return s;

}



inline string add_string(string s1, string s2)

{

  int c=0,d;

  string s;

  int i,j;

 

  for(i=s1.length()-1, j=s2.length()-1;

    (s1.length()>=s2.length())?j>=0:i>=0; --i, --j)

    {

      d=(s1[i]-'0')+(s2[j]-'0')+c;

      if(d>=10)

        s.insert(0,1,(d-10)+'0');

      else

        s.insert(0,1,d+'0');

      c=d/10;

    }

  if(s1.length()>s2.length())

  {

    while(i>=0)

    {

      d=(s1[i]-'0')+c;

      if(d>=10)

        s.insert(0,1,(d-10)+'0');

      else

        s.insert(0,1,d+'0');

      c=d/10;

      --i;

    }

    if(c>0)

      s.insert(0,1,c+'0');

  }

  else if(s1.length()<s2.length())

  {

    while(j>=0)

    {

      d=(s2[j]-'0')+c;

      if(d>=10)

        s.insert(0,1,(d-10)+'0');

      else

        s.insert(0,1,d+'0');

      c=d/10;

      --j;

    }

    if(c>0)

      s.insert(0,1,c+'0');

  }

  else

  {

    if(c>0)

      s.insert(0,1,c+'0');

  }

 

  return s;

}



inline string mul_string(string s1, string s2)

{

  int i,j;

  int c=0,d;

  string s;

  vector<string> vs;

 

  vs.clear();

  for(j=s2.length()-1; j>=0; --j)

  {

    for(i=s1.length()-1; i>=0; --i)

    {

      d=(s2[j]-'0')*(s1[i]-'0')+c;

      c=d/10;

      d%=10;

      s.insert(0,1,d+'0');

    }

   

    if(c>0)

    {

      s.insert(0,1,c+'0');

      c=0;

    }

   

    for(i=0; i<s2.length()-1-j; ++i)

      s.append("0");



    vs.push_back(s);

    s.clear();

  }

 

  s=vs[0];

 

  for(i=1; i<vs.size(); ++i)

    s=add_string(s,vs[i]);

 

  return s;

}

bool pal( string cad1){
 int	tam=cad1.size();
	f(i,0,tam/2)if(cad1[i]!=cad1[tam-1-i])return false;
	return true;
}
vector < string > todos;
string cur;
string num;
void pasa(string &cad1){
	while(cad1.size() && cad1[0]=='0')
	cad1.erase(0,1);
	
}
string qq;
bool es(string cad1){
	//pasa(cad1);
	if(!pal(cad1))return false;
	qq=mul_string(cad1,cad1);
	//cout<<cad1<<endl;
	if(pal(qq)){
		//todos.pb(cad1);
		return true;
	}
	return false;
}
string num1,num2;
void go(int pos , int cant ){
	//cout<<pos<<" "<<cant<<endl;
	if(pos>=25){
		
		//doble
	//	if(cant==1)cout<<cur<<endl;
		num1=cur;
		num2=cur;
		pasa(num1);
		pasa(num2);
		reverse(all(num2));
		num=num1+num2;
		if(cant>0 && es(num))
			todos.pb(qq);

		num=num1+"0"+num2;
		if(cant>0 && es(num))
			todos.pb(qq);

		num[num1.size()]='1';
		if(es(num))
			todos.pb(qq);

		num[num1.size()]='2';
		if(es(num))
			todos.pb(qq);
		return;
	}
	
	if(cant<4){
		//pongo
		cur[pos]='1';
		go(pos+1,cant+1);
		cur[pos]='0';
	}
	
	go(pos+1,cant);
}
bool com(string cad1,string cad2){
	if(cad1.size()!=cad2.size())
		return cad1.size()<cad2.size();
	f(i,0,cad1.size())if(cad1[i]!=cad2[i])return cad1[i]<cad2[i];

}
bool mayor(string A,string B){
	if(A.size()!=B.size())return A.size() > B.size();
	f(i,0,A.size())if(A[i]!=B[i])return A[i]>B[i];
	return true;
}
int main(){
	int cases;
	
	cur="";
	f(i,0,25)cur+="0";
	go(0,0);
	//return 0;
	string dos="2";
	string aux1="";
	string numm;
	f(i,0,27){
		numm=dos+aux1+aux1+dos;
		todos.pb(mul_string(numm,numm));
		
		numm=dos+aux1+"1"+aux1+dos;
		todos.pb(mul_string(numm,numm));
				
		numm=dos+aux1+"0"+aux1+dos;
		todos.pb(mul_string(numm,numm));

		aux1+="0";
	}
	int tt=todos.size();
	todos.pb("9");
	sort(all(todos),com);
	//f(i,0,tt)cout<<todos[i]<<endl;
	//return 0;
	cin>>cases;
	string A,B;
	
	f(t,1,cases+1){
		cin>>A>>B;
		int res=0;
		f(i,0,tt)if(mayor(todos[i],A) && mayor(B,todos[i]))res++;
		cout<<"Case #"<<t<<": "<<res<<endl;
	}

	return 0;
}


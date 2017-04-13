# include <iostream>
# include <vector>
using namespace std;
int L,D,N;
vector <string> dic;
void input() {
string stri;
for(int i=0;i<D;i++)
{
cin>>stri;
dic.push_back(stri);
}
}
void result(int c,int cs)
{
     cout<<"Case #"<<cs<<": "<<c<<endl;
     }
int main()
{
int i=0;
cin>>L>>D>>N;
string str;
bool bracket=false;
int k=0,j=0,caseno=0,count;
for(int i=0;i<D;i++)
{
cin>>str;
dic.push_back(str);
}
while (N--)
{
caseno++;
cin>>str;
vector<string> table;
string sub;
int str_len =str.length();
i=0;
count=0;
while(i<str_len)
{
if (str[i]=='(')
{ bracket=true;
i++;
continue;
}
else if (str[i]==')')
{
bracket=false;
table.push_back(sub);
sub.erase(sub.begin(),sub.end());
i++;
continue;
}
else if (bracket==false)
{
string s;
s.push_back(str[i]);
table.push_back(s);
}
else if (bracket==true) sub.push_back(str[i]);
i++;
}

for (i=0;i<dic.size();i++)
{
k=0;
for ( j=0;j<dic[i].size();j++)
{
if (find(table[k].begin(),table[k].end(),dic[i][j])==table[k].end()) break;
k++;
}
if (j==dic[i].size()) count++;
}
result(count,caseno);
}
return 0;
}

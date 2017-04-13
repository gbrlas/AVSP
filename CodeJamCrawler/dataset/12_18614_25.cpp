#include<iostream>
using namespace std;

int main()
{
 int N;
 cin>>N;
 cin.ignore();
 for(int I=0;I<N;I++)
 {
  string linea;
  getline(cin,linea);
  string A="ynficwlbkuomxsevzpdrjgthaq";
  cout<<"Case #"<<I+1<<": ";
  for(int I=0;I<linea.size();I++)
   if(linea[I]==' ')
    cout<<" ";
   else if(isalpha(linea[I]))
   {
    for(int J=0;J<A.size();J++)
     if(linea[I]==A[J])
      cout<<(char)(J+'a');
   }
  cout<<endl;
 }
 return 0;
}

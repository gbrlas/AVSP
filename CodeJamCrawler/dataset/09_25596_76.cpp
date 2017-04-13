#include<string>
#include<map>
#include<cstdio>
#include<iostream>
#include<vector>


using namespace std;
map <string,int> mapa;

vector <string> resaca(vector <string> vx,vector <string> v,char c, int pos){
   int i;
//   cout<<v[0].length()<<endl;
  for( i=0;i<v.size();i++){
//     cout<<i<<" "<<pos<<" "<<v[i][pos]<<" "<<c<<endl;
           
     if(v[i][pos]==c)
       vx.push_back(v[i]);        
   }
   
   return vx;     
}
int main(){
int longi,npal,ncases,contador=1,i,j;
char c;
string s,s2;
vector<string> v1;
vector<string> v;

scanf("%d %d %d\n",&longi,&npal,&ncases);
while(npal--){
  getline(cin,s);
  v1.push_back(s);
}



while(contador<=ncases){
 vector<string> vec;
 vector<string> vx;
 v=v1;
 getline(cin,s);
 s2="";
 for(i=0;i<s.size();i++){
  s2="";
  if(s[i]=='('){
    i++;            
    while(s[i]!=')'){
      s2+=s[i++];                 
    }
  }
  else{
    s2+=s[i];     
  }
//  cout<<s2<<endl;
   vec.push_back(s2);                      
 }
 
// for(i=0;i<vec.size();i++)
//  cout<<vec[i]<<endl;
 s2="";
 //puts("va");
 //i vector de partes
 //j posiciones de la parte
 for(i=0;i<vec.size();i++){
//   cout<<v.size()<<endl;
   
   for(j=0;j<vec[i].length();j++){
      c=vec[i][j];
//      cout<<c<<i<<endl;
      vx=resaca(vx,v,c,i);
      if(v.size()==0)
        goto acaba;
   }
   v=vx;
   vx.clear();                          
 }
 acaba:
 printf("Case #%d: %d\n",contador++,v.size());
 
}    
    
}

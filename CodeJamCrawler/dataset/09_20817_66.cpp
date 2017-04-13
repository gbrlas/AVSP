#include<iostream>
#include<string>
#include<vector>
using namespace std;


bool IgetTheWord(string w, string s){
   int index=0;
   for(int i=0;i<w.length();i++){
     // Take first character of word and search it in first segment of s
	 bool found=false;
	 if(s[index]=='('){
	    
		for(int j=index+1;j<s.length();j++){
			if(s[j]==')'){index=j; break;}
			if(s[j]==w[i])found=true;
		index=j;
		}
		index++;
	}
	else if(s[index]==w[i]){index++;found=true;}
	//cout<<found<<" "<<s[index]<<" "<<s<<" "<<w<<endl;
	if(!found)return false;
}
return true;
}
		

int parse(vector<string> dict, string s){
int ans=0;

for(int i=0;i<dict.size();i++){
	if(IgetTheWord(dict[i],s))ans++;
}
return ans;
}
int main(){

int l,d,t;
cin>>l>>d>>t;

vector<string>dict;
string s;
for(int i=0;i<d;i++){
	cin>>s;
	dict.push_back(s);
}

int count=1;

for(int i=0;i<t;i++){
		cin>>s;
		int ans = parse(dict,s);
		cout<<"Case #"<<count<<":"<<" "<<ans<<endl;
		count++;
}
}

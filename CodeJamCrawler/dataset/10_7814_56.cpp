#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<assert.h>

using namespace std;

pair <string,string> cutstr(string str){
	string str1="",str2="";
	for(int x=1;x<str.length();x++){
		if(str[x]=='/'){
			str1=str.substr(0,x);
			str2=str.substr(x,str.length()-x);
			break;
		}
	}
	if(str1==""){
		str1=str;
		str2="";
	}
	return make_pair(str1,str2);
}

class p{
public:
	string name;
	vector <p*> son;

	p(string _name){
		name = _name;
		son.clear();
	}
	~p(){
		for(int x=0;x<son.size();x++){
			delete son[x];
		}
	}

	int make(string _name){
		p* s = new p(_name);
		son.push_back(s);
		return son.size()-1;
	}
	int have(string _name){
		int flag=-1;
		for(int x=0;x<son.size() && flag==-1;x++){
			if(son[x]->name==_name){
				flag=x;
			}
		}
		return flag;
	}
	p* getson(int x){
		if(x>son.size()){
			assert(false);
		}
		return son[x];
	}
};

int rtn;

void process(int f , string n,p* cur){
	int res;
	pair<string,string> pr =cutstr(n);
	res=cur->have(pr.first);
	if(res>=0){
		if(pr.second==""){
			return;
		}else{
			process(f,pr.second,cur->getson(res));
		}
	}else{
		res=cur->make(pr.first);
		rtn+=f;
		if(pr.second==""){
			return;
		}else{
			process(f,pr.second,cur->getson(res));
		}
	}
	return;
}

int main(){
	int t,u,n,m;
	cin >> t;
	for(u=1;u<=t;u++){
		cin >> n >> m;
		rtn=0;
		string temp;
		p* root = new p("root");
		for(;n--;){
			cin >> temp;
			process(0,temp,root);
		}
		for(;m--;){
			cin >> temp;
			process(1,temp,root);
		}
		delete root;
		cout << "Case #" << u << ": " << rtn << endl;
	}
	return 0;
}
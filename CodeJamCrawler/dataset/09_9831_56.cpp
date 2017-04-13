#include <iostream>
#include <string>
#include <set>

using namespace std;

struct node {
	double p;
	string f;
	node* s[2], *parent;
	node() {
		this->s[0]=NULL;
		this->s[1]=NULL;
		this->f="";
	}

	~node() {
		delete s[0];
		delete s[1];
	}

	void init(){
		char c=0;
		char s[2];
		s[1]=0;
		while(c!='(')
			cin >> c;
		c=' ';
		cin >> this->p;
		cin >> this->f;
		if(this->f == ")"){
			this->f="";
			return;
		}
		for(int i=0;i<2;i++){
			node* tmp = this->s[i] = new node();
			tmp->parent = this;
			tmp->init();
		}
		while(c!=')')
			cin >> c;

	}
	void write(){
		cout << this->p<< " " << this->f << "\n";
		if(s[0]!=NULL)
			for(int i=0;i<2;i++)
				s[i]->write();
		cout << "\n";
	}
	double dfs(double p, set<string>f){
		p*=this->p;
		if(s[0]==NULL)return p;
		if(f.find(this->f)!=f.end()){
			return s[0]->dfs(p,f);
		}else{
			return s[1]->dfs(p,f);
		}
	}
};


int main(){
	int c;
	cin >> c;
	for(int i=0;i<c;i++){
		node* root = new node();
		int n;
		cin >>n;
		root->init();
		cin >>n;
		cout << "Case #" << (i+1) << ":" << "\n";
		for(int j=0;j<n;j++){
			set<string>s;
			string tmp;
			cin >> tmp;
			int ff;
			cin >> ff;

			while(ff--){
				cin >> tmp;
				s.insert(tmp);
			}
			printf("%.7lf\n",root->dfs(1.0,s));
		}
		delete root;
	}
}

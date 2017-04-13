#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

int numl;
struct st{
	string name;
	double w;
};

st tree[1000];

void gettree(int n){
	//cerr<<"n= "<<n<<endl;
	char tmp=0;
	while(tmp=getchar()){
		if(tmp==' ')continue;
		if(tmp=='\n'){numl++;continue;}
			break;
	}//cout<<"tmp "<<tmp<<endl;
	double w=tmp-'0';
	//cout<<"w "<<endl;
	tmp=getchar();double ratio=0.1;
	while(tmp=getchar()){
		if(tmp==' ')break;
		if(tmp=='\n'){numl++;break;}
		if(tmp<'0' || tmp>'9')break;
		w+=(ratio*(tmp-'0'));
		ratio/=10;
		//cout<<"deb "<<tmp<<endl;
	}
	//cerr<<"deb w "<<w<<endl;
	tree[n].w=w;
	if(tmp==')'){
		string name="NULL";
		tree[n].name=name;
		//cout<<"NULL"<<endl;
		return; 
	}
	while(tmp=getchar()){
		if(tmp==' ')continue;
		if(tmp=='\n'){numl++;continue;}
			break;
	}
	//cout<<"hoge"<<tmp<<"hoge"<<endl;
	if(tmp==')'){
		string name="NULL";
		tree[n].name=name;
		//cout<<"NULL"<<endl;
		return; 
	}
	else{
		string name;name+=tmp;
		while(tmp=getchar()){
			if(tmp==' ')break;
			if(tmp=='\n'){numl++;break;}
			name+=tmp;
		}
		//cout<<"hoge "<<name<<" hoge"<<endl;
		tree[n].name=name;
		while(tmp=getchar()){
			if(tmp==' ')continue;
			if(tmp=='\n'){numl++;continue;}
			break;
		}
		gettree(n*2);
		while(tmp=getchar()){
			if(tmp==' ')continue;
			if(tmp=='\n'){numl++;continue;}
			if(tmp==')')continue;
			break;
		}
		//cout<<"ttmpt "<<tmp<<endl;
		gettree(n*2+1);
		while(tmp=getchar()){
			if(tmp==' ')continue;
			if(tmp=='\n'){numl++;continue;}
			break;
		}
	}
}

void getans(vector<string> bes,double ra,int now){
		//cout<<"now="<<now<<" "<<ra<<endl;
		//cout<<tree[now].name<<" "<<tree[now].w<<endl;
	if(tree[now].name=="NULL"){
		printf("%.7f\n",ra*tree[now].w);
		//cout<<(ra*tree[now].w)<<endl;
	}
	else{
		int t=0;
		for(int i=0;i<bes.size();i++)if(tree[now].name==bes[i]){t=1;}
		if(t){getans(bes,ra*tree[now].w,now*2);}
		else {getans(bes,ra*tree[now].w,now*2+1);}
	}
}

int main(){
	int tn=0;scanf("%d ",&tn);
	for(int ttt=0;ttt<tn;ttt++){
		int l=0;scanf("%d ",&l);char tmp=0;
		while(tmp=getchar()){
		//cerr<<"hoge"<<tmp<<endl;
			if(tmp==' ')continue;
			if(tmp=='\n'){numl++;continue;}
			break;
		}
		gettree(1);
		while(tmp=getchar()){
			if(tmp==' ')continue;
			if(tmp=='\n'){numl++;break;}
			break;
		}
		char str[10];
		//tmp=getchar();
		gets(str);
		//cout<<str<<endl;
		int A=atoi(str);
		//cout<<A<<endl;
		cout<<"Case #"<<(ttt+1)<<":"<<endl;
		for(int i=0;i<A;i++){
			char na[100];
			cin>>na;
			//cout<<"hoge"<<na<<endl;
			int ttn=0;cin>>ttn;
			//cout<<"ttn="<<ttn<<endl;
			vector<string> bes(ttn);
			for(int j=0;j<ttn;j++){
				cin>>na;
				bes[j]=na;
			}
			//cout<<ttn<<endl;
			getans(bes,1.0,1);
		}
	}
	return 0;
}

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int num,pos;
char afea[105][1000];
char input[105][1000],allin[100000];
char def[105][1000];


struct node{
	double p;
	node *left,*right;
	bool end;
	char fea[10000];
};



node * init(){
	node *now;
	double nowd;
	int cnt;
	char ch[10000];

	while(allin[pos]!='('&&pos<strlen(allin))pos++;
	pos++;

			now = new node;
			now->end = 0;
			nowd = 0; cnt = 0;
			while(allin[pos]==' ')pos++;
			cnt = 0;
			while( (allin[pos]>='0'&&allin[pos]<='9') || allin[pos]=='.'){
				if(cnt==0){
					nowd = allin[pos]-'0';
				}
				else if(cnt>1){
					nowd+= (allin[pos]-'0')*pow(10.0,-(cnt-1));
				}			
				cnt++;pos++;
			}
			now->p = nowd;
			while(allin[pos]==' ')pos++;
			if(allin[pos]==')'){
				now->end = 1;
				while(allin[pos]!='\n'&&allin[pos]!=' '&&allin[pos]!=')'&&allin[pos]!='(')pos++;
			}
			else
			{
				cnt = 0;
				while(allin[pos]!='\n'&&allin[pos]!=' '&&allin[pos]!=')'&&allin[pos]!='('){
					now->fea[cnt] = allin[pos];
					cnt++; pos++;
				}
				now->fea[cnt] = 0;
				now->left = init();
				now->right = init();

			}
			while(allin[pos]!=')')pos++;

		return now;
	
}

double dfs(node *now,double t){
	int i;
	bool ok;
	t *= now->p;
	if(now->end)
		return t;
	else{
		ok = 0;
		for(i=0;i<num;i++){
			if(strcmp(afea[i],now->fea)==0){
				ok = 1;
				break;
			}
		}
		if(ok)
			return dfs(now->left,t);
		else
			return dfs(now->right,t);

	}
}

int main(){
	int i,j,L,an,cs,CSN;
	char sin[100];
	
	freopen("out.out","w",stdout);
	
	
	node *root;

	scanf("%d\n",&CSN);
	for(cs=1;cs<=CSN;cs++){
		printf("Case #%d:\n",cs);
		scanf("%d\n",&L);

		for(i=0;i<L;i++)
			cin.getline(input[i],90,'\n');
		allin[0] = 0;
		for(i=0;i<L;i++)
			strcat(allin,input[i]);

		pos = 0;
		root = init();

		scanf("%d\n",&an);
		for(i=0;i<an;i++){
			scanf("%s%d",sin,&num);
			for(j=0;j<num;j++)
				scanf("%s",afea[j]);
			
			printf("%.7lf\n",dfs(root,1));
		}

	}

}
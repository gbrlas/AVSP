#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<map>

using namespace std;

char orig[20]="welcome to code jam";

char str[503];
int mp2[503];
int point[502];

int main(){
	int n;cin>>n;getchar();
	for(int t=0;t<n;t++){
		memset(str,0,sizeof(str));
		gets(str);
		int length=strlen(str);
		memset(mp2,-1,sizeof(mp2));
		vector<int> pt[27];
		for(int i=0;i<length;i++){
			//cout<<(int)str[i]<<" "<<str[i]<<" "<<i<<endl;
			if(str[i]==32){pt[26].push_back(i);}
			else{pt[(int)(str[i]-'a')].push_back(i);}
		}
		int p=18;
		for(int i=length-1;i>=0;i--){
			if(orig[p]==str[i]){mp2[i]=p;p--;}
			else{if(i!=length-1)mp2[i]=mp2[i+1];}
		}
		//for(int i=0;i<length;i++)cout<<mp[i]<<" ";cout<<endl;
		//for(int i=0;i<length;i++)cout<<mp2[i]<<" ";cout<<endl;
		//for(int i=0;i<27;i++){
		//	for(int j=0;j<pt[26].size();j++)cout<<pt[26][j]<<" ";cout<<endl;
		//}
		//cout<<(' '-0)<<endl;
		p=0;
		int ans=0;
		memset(point,0,sizeof(point));
		for(int j=pt[(int)('m'-'a')].size()-1;j>=0;j--)if(mp2[pt[(int)('m'-'a')][j]]<=18){
			point[pt[(int)('m'-'a')][j]]=1;
		}
		//cerr<<"hoge"<<endl;
		//for(int i=0;i<length;i++)cerr<<point[i]<<" ";cout<<endl;
		//cerr<<"hoge"<<endl;
		for(int i=17;i>=0;i--){
			int num=0;int num2=0;
			if(orig[i]==32){num=26;}
			else{num=(int)(orig[i]-'a');}
			if(orig[i+1]==32){num2=26;}
			else{num2=(int)(orig[i+1]-'a');}
			int tmp=0;
			int ptt=pt[num2].size()-1;
			//cerr<<orig[i+1]<<" "<<num2<<" "<<ptt<<endl;
			for(int j=pt[num].size()-1;j>=0;j--){
				if(mp2[pt[num][j]]<=i){
					//cerr<<i<<" "<<i+1<<" "<<pt[num][j]<<" "<<pt[num2][ptt]<<endl;
					while((ptt>=0)&&(pt[num2][ptt]>pt[num][j])){
						//cout<<i<<" "<<i+1<<" "<<mp2[pt[num2][ptt]]<<" "<<pt[num][j]<<" "<<pt[num2][ptt]<<endl;
						if(mp2[pt[num2][ptt]]<=i+1){
							tmp+=point[pt[num2][ptt]];
							tmp%=10000;
						}
						ptt--;
					}
					point[pt[num][j]]=tmp%10000;
				}
			}
		}
		//for(int i=0;i<length;i++)cerr<<point[i]<<" ";cout<<endl;
		for(int j=pt[22].size()-1;j>=0;j--)if(mp2[pt[22][j]]<=0){
			ans+=point[pt[22][j]];ans%=10000;
		}
		int ch[4]={0};
		for(int i=0;i<4;i++){
			ch[i]=ans%10;ans/=10;
		}
		cout<<"Case #"<<(t+1)<<": "<<ch[3]<<ch[2]<<ch[1]<<ch[0]<<endl;
	}
	return 0;
}

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

#define M 1e-10

double lengthda(double x,double y,double z){
	return sqrt(x*x+y*y+z*z);
}

int main(){
	int tn;cin>>tn;
	for(int ttt=0;ttt<tn;ttt++){
		int n;cin>>n;
		int mp[600][6]={{0}};
		for(int i=0;i<n;i++){
			cin>>mp[i][0]>>mp[i][1]>>mp[i][2]>>mp[i][3]>>mp[i][4]>>mp[i][5];
		}
		double total[6]={0};
		for(int i=0;i<n;i++){
			for(int j=0;j<6;j++)total[j]+=(double)mp[i][j];
		}
		
		for(int i=0;i<6;i++)total[i]/=n;
		
		//for(int i=0;i<6;i++)cout<<total[i]<<" ";cout<<endl;
		double s=(-(total[0]*total[3]+total[1]*total[4]+total[2]*total[5]));
		double dd=lengthda(total[3],total[4],total[5]);
		
		if((abs(dd-0.0)<M)||(s<=0.0)){
			double ans=lengthda(total[0],total[1],total[2]);
			printf("Case #%d: %.8f %.8f\n",ttt+1,ans,0.0);
			continue;
		}

		s/=dd*dd;
		double ans=lengthda(total[0]+s*total[3],total[1]+s*total[4],total[2]+s*total[5]);
		printf("Case #%d: %.8f %.8f\n",ttt+1,ans,s);
	}
	return 0;
}

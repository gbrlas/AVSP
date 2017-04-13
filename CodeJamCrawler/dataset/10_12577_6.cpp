#include <iostream>
#include <math.h>


using namespace std;
int m[1025];
int f[1025];

int a[11][513];
int s[11][513];

int main() {
	freopen("D:\\OJ\\jam\\20100605\\B-small-attempt0.in", "r", stdin);
	freopen("D:\\OJ\\jam\\20100605\\out.txt", "w", stdout);
	int t  , k ,p , ttt=0,index;
	int i , j;

	cin>>t;
 
	for(index=0;index<t;index++)
	{
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		memset(m,0,sizeof(m));
		memset(f,0,sizeof(f));
		cin>>p;
		int num = pow(2,p);
		for(i = 0; i<num;i++) cin>>m[i];
		for(i=0;i<p;i++){		
			for(j=0;j<num/pow(2,i+1);j++){
			cin>>a[i][j];
			//cout<<a[i][j];
			}
			//cout<<endl;
		}

	while(1){
		int min = p+2;
		int pos = -1;

	
			
		for(i=0;i<num && f[i] == 0;i++){//找到最小的

			//if(index==3)cout<<i<<":"<<m[i]<<endl;
			//if(m[i] == 0) {pos=i; min = 0;break;}
			if(m[i] < min) {pos=i;min = m[i];}
		}
			if(index==3)cout<<pos<<endl;
		if(pos==-1) break;
		f[pos]=1;//已经算过了
	
		j=pos/2;
		i=0;
		int k;
		for(k=min;k<p;k++)	{	
			
			if(s[k][j]==0) s[k][j]=1;//购买此票
			j=pos/2;
			k++;
		}
	}

	int mount = 0;
	for(i=0;i<p;i++){		
			for(j=0;j<num/pow(2,i+1);j++){		
				if(s[i][j] == 1) mount+=a[i][j];
			}			
		}
	cout<<"Case #"<<index+1<<": "<<mount<<endl;

	}    
	return 0;
} 


#include<iostream>
#include<vector>
using namespace std;
char a[105][105];
int inp[105][105],n,counter=97,m;
struct node{
	int xx;
	int yy;
};	
void fun(int x,int y){
	//cout<<"ffffffff"<<x<<" "<<y<<" "<<endl;;
	vector<node>vv;
	node nn;
	nn.xx=x;
	nn.yy=y;
	vv.push_back(nn);
	int flag=0;
	int min=inp[x][y];
	int x1,y1;
	while(a[x][y]=='-'){
	//	cout<<x<<" "<<y<<endl;
		min=inp[x][y];
		if(x-1>=0 && inp[x-1][y]<min){
			min=inp[x-1][y];
			x1=x-1;
			y1=y;
		}	
		if(y-1>=0 && inp[x][y-1]<min){
			min=inp[x][y-1];
			x1=x;
			y1=y-1;
		}
		
		if(y+1<m && inp[x][y+1]<min){
			min=inp[x][y+1];
			x1=x;
			y1=y+1;
		}
		if(x+1<n && inp[x+1][y]<min){
			min=inp[x+1][y];
			x1=x+1;
			y1=y;
		}
		if(min==inp[x][y]){
			flag=1;
			break;
		}
		nn.xx=x1;
		nn.yy=y1;
		vv.push_back(nn);
		x=x1;
		y=y1;
	}
	int i;
	char c=a[x][y];
	if(c!='-'){
		nn.xx=x;
		nn.yy=y;
		vv.push_back(nn);
	}	
		for(i=0;i<vv.size();i++){
			int p=vv[i].xx;
			int q=vv[i].yy;
			//cout<<p<<" "<<q<<" "<<char(counter);
			if(flag==1){
			//cout<<p<<" "<<q<<" "<<char(counter)<<" "<<flag<<endl;
				a[p][q]=char(counter);
			}else{
			//cout<<p<<" "<<q<<" "<<c<<" "<<flag<<endl;
				a[p][q]=c;
			}	
		}
		if(flag==1){
		counter++;
		}

}			
int main(){
	int i,j,k,t,no=0,i1,j1;
	cin>>t;
	while(t--){
		no++;
		cout<<"Case #"<<no<<":"<<endl;
		counter=97;
		cin>>n>>m;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>inp[i][j];
				a[i][j]='-';
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
					
					if(a[i][j]=='-'){
						fun(i,j);
					}
				}
		}
	
		//cout<<"hello"<<endl;;
		for(i=0;i<n;i++){
			for(j=0;j<m-1;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<a[i][j];
			cout<<endl;
		}
	}
	return 0;
}						

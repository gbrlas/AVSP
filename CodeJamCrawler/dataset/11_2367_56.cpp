#include<iostream>
#include<complex>
using namespace std;

typedef complex<double> point;

const int maxn = 510;
const double eps = 1e-8;

int r,c,d;
int board[maxn][maxn];
long long sum[maxn][maxn];
point center[maxn][maxn];

long long getwe(int i1,int j1,int i2,int j2) {
	return sum[i2][j2]- (i1>0?sum[i1-1][j2]:0)- (j1>0?sum[i2][j1-1]:0)+ ((i1>0 && j1>0)?sum[i1-1][j1-1]:0);
}

point getce(int i1,int j1,int i2,int j2) {
	return center[i2][j2]-(i1>0?center[i1-1][j2]:point(0,0))-(j1>0?center[i2][j1-1]:point(0,0))+((i1>0 && j1>0)?center[i1-1][j1-1]:point(0,0));
}

inline int isequal(const point &a,const point &b) {
	return abs(a.real()-b.real())<eps && abs(a.imag()-b.imag())<eps;
}

inline int isok(int i,int j, int k) {
	k--;
//	cerr<<i<<' '<<j<<' '<<k<<endl;
	point temp = getce(i,j,i+k,j+k)-getce(i,j,i,j)-getce(i,j+k,i,j+k)-getce(i+k,j,i+k,j)-getce(i+k,j+k,i+k,j+k);
//	cerr<< getwe(i,j,i+k,j+k)<<' '<<getwe(i,j,i,j)<<' '<<getwe(i,j+k,i,j+k)<<' '<<getwe(i+k,j,i+k,j)<<' '<<getwe(i+k,j+k,i+k,j+k)<<endl;
	double w = getwe(i,j,i+k,j+k)-getwe(i,j,i,j)-getwe(i,j+k,i,j+k)-getwe(i+k,j,i+k,j)-getwe(i+k,j+k,i+k,j+k);
	k++;
//	cerr<<temp<<' '<<w<<endl;
	temp/= w;
//	cerr<<temp<<' '<<point(i+0.5*k,j+0.5*k)<<' '<<isequal(temp,point(i+0.5*k,j+0.5*k))<<endl;
	return isequal(temp,point(i+0.5*k,j+0.5*k));
	
}

inline int getans() {
	for(int k=min(r,c);k>=3;k--)
		for(int i=0;i<=r-k;i++)
			for(int j=0;j<=c-k;j++) {
//				cerr<<k<<' '<<i<<' '<<j<<endl;
				if(isok(i,j,k))
					return k;
			}
	return -1;
}

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		cin>>r>>c>>d;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++) {
				char c;
				cin>>c;
				board[i][j] = c-'0';
			}
		sum[0][0] = board[0][0]+d;
		for(int i=1;i<r;i++)
			sum[i][0] = sum[i-1][0] + board[i][0]+d; 
		for(int j=1;j<c;j++)
			sum[0][j] = sum[0][j-1] + board[0][j]+d;
		for(int i=1;i<r;i++)
			for(int j=1;j<c;j++)
				sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+board[i][j]+d;
//		for(int i=0;i<r;i++,cerr<<endl)
//			for(int j=0;j<c;j++)
//				cerr<<sum[i][j]<<' ';
		
		center[0][0] = point(0.5,0.5)*double(sum[0][0]);
		for(int i=1;i<r;i++)
			center[i][0] = center[i-1][0] + point(i+0.5,0.5)*(double(board[i][0]+d)); 
		for(int j=1;j<c;j++)
			center[0][j] = center[0][j-1] + point(0.5,j+0.5)*(double(board[0][j]+d)); 
		for(int i=1;i<r;i++)
			for(int j=1;j<c;j++)
				center[i][j] = center[i][j-1]+center[i-1][j]-center[i-1][j-1]+point(i+0.5,j+0.5)*(double(board[i][j]+d));
	
//		for(int i=0;i<r;i++,cerr<<endl)
//			for(int j=0;j<c;j++)
//				cerr<<center[i][j]/double(sum[i][j]);
	
		int ans = getans();
		cout<<"Case #"<<tn+1<<": ";
		if(ans==-1)
			cout<<"IMPOSSIBLE";
		else
			cout<<ans;
		cout<<endl;

	}

}

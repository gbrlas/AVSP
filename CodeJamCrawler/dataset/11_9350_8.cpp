#line 3 "main.cpp"
#include  "iostream" 
#include  "vector"
#include  "string"
#include  "string.h"
#include  "algorithm" 
#include  "sstream"
#include  "set"
#include  "map"
#include  "queue"
#include  "deque"
#include  "stack"
#include "list"
#include  "bitset"
#include  "cstdio"
#include  "assert.h"
#include  "cmath"
#include  "cstdlib"
#include  "ctime"
#include  "cfloat"
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define INF 1<<28

double W[103],OWP[103],OOWP[103];
int n;
string cad[103];
double go(int mi,int ind){
      double res=0.0;
      int to=0;
      int w=0;
      for(int i=0;i<n;i++){
            if(cad[ind][i]!='.' && i!=mi)
            {
               to++;
               if(cad[ind][i]=='1')
                  w++;   
            }
      }
      res=1.0*w/to;
      return res;
   }
int main(){
	freopen ("C:\\Documents and Settings\\jpenam\\Mis documentos\\Downloads\\A-small-attempt0.in","r",stdin);
	freopen ("A1.out","w",stdout);
	int cases;
	cin>>cases;
	
	for(int t=1;t<=cases;t++){
		cin>>n;

		for(int i=0;i<n;i++)
			cin>>cad[i];

		
		
		for(int i=0;i<n;i++){
			int w=0;
			int to=0;
			for(int j=0;j<n;j++){
				if(cad[i][j]!='.'){
					to++;
					if(cad[i][j]=='1')
						w++;
				}
			}
			//cout<<to<<" "<<w<<endl;
			W[i]=1.0*w/to;
			//cout<<W[i]<<endl;
		}
   //cout<<endl;
		for(int i=0;i<n;i++){
			
			double ac=0.0;
			int to=0;
			for(int j=0;j<n;j++){
				if(cad[i][j]!='.'){
					to++;
					ac+=go(i,j);
				}
			}
			
			OWP[i]=1.0*ac/to;
		//cout<<ac<<" "<<to<<endl;
		//	cout<<OWP[i]<<endl;
		}
		for(int i=0;i<n;i++){
			
			double ac=0.0;
			int to=0;
			for(int j=0;j<n;j++){
				if(cad[i][j]!='.'){
					to++;
					ac+=OWP[j];
				}
			}
			OOWP[i]=1.0*ac/to;
		}
		printf("Case #%d:\n",t);
		for(int i=0;i<n;i++){
			double res=0.25 * W[i] + 0.50 * OWP[i] + 0.25 * OOWP[i];
			printf("%.12lf\n",res);
		}
	}
	//system("pause");
	return 0;
}

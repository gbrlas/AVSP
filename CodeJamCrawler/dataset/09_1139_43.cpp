#include "string"
#include "iostream"
#include "algorithm"
#include "stdlib.h"

using namespace std;

struct In { 
	int row;
	int column;
	int count;
}x[27];
 
int cmp( const void *a , const void *b ) 
{ 
    struct In *aa = (In *)a; 
    struct In *bb = (In *)b; 
   	if (aa->row != bb->row) return aa->row - bb->row;
	else return aa->column - bb->column;
} 


int t, h, w;
int m[103][103];//map
int isSink[103][103];
int c[103][103];//num code 
int cc[26];//cc[i]代表第i个basin的值
int basin[103][103];//存放i,j属于哪个basin


int min(int i, int j){//the minimum of the up down left right

	if (!isSink[i][j]) return -1;
	int minn = 10001;//min
	int direct=0;	
	if (i-1>=0)//i-1,j north
		if (m[i-1][j] < minn) {minn = m[i-1][j]; direct = 0;}	
	if (j-1>=0)//i,j-1 west
		if (m[i][j-1] < minn) {minn = m[i][j-1]; direct = 1;}
	if (j+1<w)//i,j+1 east
		if (m[i][j+1] < minn) {minn = m[i][j+1]; direct = 2;}
	if (i+1<h)//i+1,j south
		if (m[i+1][j] < minn) {minn = m[i+1][j]; direct = 3;}
	

	return direct;	
}

int traverse(int i, int j, int count){//从i, j点开始四处拉皮条

	basin[i][j] = count;//在count的basin中;count从0开始
	//if (cc[count] == -1) cc[count] = cc[count-1] + 1;
	if (i < x[count].row)
	{x[count].row = i;
	 x[count].column = j;	
	}
	if (j < x[count].column)	
	{x[count].row = i;
	x[count].column = j;	
	}	

	//cout<<"traverse: i j "<<i<<j<<endl;

	if (i+1 < h && !min(i+1,j))traverse(i+1,j,count);
	if (j+1 < w && min(i,j+1) == 1)traverse(i,j+1,count);
	if (j>0 && min(i,j-1) == 2)traverse(i,j-1,count);
	if (i>0 && min(i-1,j) == 3)traverse(i-1,j,count);
	return 0;
}

int main(){
	
	int i, j, k;
	//freopen("D:\\OJ\\B-small-attempt2.in", "r", stdin);
	//freopen("D:\\OJ\\out.txt", "w", stdout);
	
	cin>>t;	

	for(k=0;k<t;k++){
		cout<<"Case #"<<k+1<<":"<<endl;
		cin>>h>>w;		
		memset(isSink, 0, sizeof isSink);//all is sink
		memset(c, -1, sizeof c);
		memset(basin, -1, sizeof c);
		c[0][0] = 0; 
		

		for (i=0;i<h;i++)
		{
			for(j=0;j<w;j++){

				cin>>m[i][j];
				//Give the isSink value
				if (j-1 >= 0 && m[i][j] > m[i][j-1]) isSink[i][j] = -1;
				else if (j-1 >= 0 && !isSink[i][j-1] && m[i][j] != m[i][j-1]) isSink[i][j-1] = -1;
				if (i-1 >= 0 && m[i][j] > m[i-1][j]) isSink[i][j] = -1;
				else if (i-1 >= 0 && !isSink[i-1][j] && m[i][j] !=m[i-1][j]) isSink[i-1][j] = -1;				

			}
			
		}		

		int count=0;//basin的个数
		
		memset(cc, -1, sizeof cc);
		for (i=0;i<h;i++)		
			for(j=0;j<w;j++)

				if (!isSink[i][j])
				{
					//cout<<i<<j<<endl;
					x[count].row = h-1;
					x[count].column = w-1;					
					x[count].count = count;
					traverse(i, j, count);
					count++;
					
				}

		qsort(x, count, sizeof x[0], cmp);

		//for (i=0;i<count;i++) cout<<" x:::: "<<x[i].row<<" "<<x[i].column<<" "<<x[i].count<<endl;

	//	cout<<"回车"<<endl;
		for (i=0;i<count;i++) cc[x[i].count] = i;

		for (i=0;i<h;i++){
			
			for(j=0;j<w;j++){
				//cout<<" "<<isSink[i][j]<<" ";

				char ab = cc[basin[i][j]]+ 'a';
				cout<<ab<<" ";
			}
			cout<<endl;
		}

		//cout<<"min:"<<m[0][0]<<m[0][1]<<min(0,1);


	}
}
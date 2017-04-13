#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

char a[51][51];

char word[51];

int result;

int n, k;

int search(char a[51][51], char word[51], int x, int y, int w, int flag, int k){

	//cout<<strlen(a[1]);


	if(a[x][y] == word[w]){

		//cout<<"a[x][y],word[w]::"<<x<<y<<w<<flag<<"::"<<a[x][y]<<"::"<<word[w]<<endl;


		int	w_len = k;
		if(w_len==w+1) {

// 			if(100==flag)	cout<<x+1<<","<<y+1<<" "<<x+1<<","<<y+1<<endl;
// 			else if(0==flag) cout<<x+1<<","<<y+2-w_len<<" "<<x+1<<","<<y+1<<endl;
// 			else if(1==flag) cout<<x+2-w_len<<","<<y+1<<" "<<x+1<<","<<y+1<<endl;
// 			else if(2==flag) cout<<x+2-w_len<<","<<y+2-w_len<<" "<<x+1<<","<<y+1<<endl;		
// 			else if(7==flag) cout<<x+2-w_len<<","<<y+w_len<<" "<<x+1<<","<<y+1<<endl;
			result = 1;
			return 1;//OK
		};

		if(0==flag || 100==flag)
			//右边
			if((strlen(a[x])-y)>=(w_len-w)) search(a,word,x,y+1,w+1,0,k);

		if(1==flag ||  100==flag)
			//下边		
			if((n-x)>=(w_len-w)) search(a,word,x+1,y,w+1,1,k);
		

		if(2==flag ||  100==flag)
			//右下
			if((strlen(a[x])-y)>=(w_len-w) && (n-x)>=(w_len-w)) search(a,word,x+1,y+1,w+1,2,k);
		//左下
		if(7==flag || 100==flag)
			if((n-x)>=(w_len-w) && y>=(w_len-1-w)) search(a,word,x+1,y-1,w+1,7,k);


	}
	return 0;
};

int main(){
	
	int i,j,jj;

	int t;

	int rr,bb;
	freopen("D:\\My Documents\\Downloads\\A-large.in", "r", stdin);
	freopen("D:\\My Documents\\Downloads\\out.txt", "w", stdout);
	cin>>t;

	for(jj=0;jj<t;jj++){
    
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
	
	for (i=0;i<n;i++)//行
	{
		for (j=n-2;j>=0;j--)//列
		{
			int iii=i,jjj=j;
			while (jjj<n&&a[iii][jjj]!='.' && a[iii][jjj+1]=='.')
			{
				a[iii][jjj+1] = a[iii][jjj];
				a[iii][jjj] = '.';
				jjj++;
			}
		}
	}

// 	  	for(i=0;i<n;i++){
// 			for (j=0;j<n;j++)
// 			cout<<a[i][j];
// 			cout<<endl;
// 			}
	  		

		result = 0;
		for (i=0;i<k;i++) word[i] = 'B';		

		 		for(i=0;i<n;i++)
					for( j=0;j<n;j++)
					if(!result)search(a,word,i,j,0,100,k);
					//cout<<"result: "<<result<<endl;
					//if(!result) cout<<"Not found"<<endl;

        bb = result;
		result = 0;
		for (i=0;i<k;i++) word[i] = 'R';

					for(i=0;i<n;i++)
						for( j=0;j<n;j++)
							if(!result)search(a,word,i,j,0,100,k);
					//cout<<"result1: "<<result<<endl;
					//if(!result) cout<<"Not found"<<endl;
		rr = result;

		cout<<"Case #"<<jj+1<<": ";
		if(rr && bb) cout<<"Both"<<endl;
		else if(rr) cout<<"Red"<<endl;
		else if(bb) cout<<"Blue"<<endl;
		else cout<<"Neither"<<endl;
		
	}
	
	return 0;
}



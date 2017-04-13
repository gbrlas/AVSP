#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int cases =1;
	while(t>0)
	{
		int r,c;
		cin>>r>>c;
		char a[r][c];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++){
				cin>>a[i][j];
			}
		}
//		for(int i=0;i<r;i++){
//			for(int j=0;j<c;j++){
//				cout<<a[i][j];
//			}
//			cout<<endl;
//		}
		bool possible = true;
		char ans[r][c];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				ans[i][j]='.';
			}
		}
	//	cout<<r<<" "<<c<<endl;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(a[i][j]=='#' && ans[i][j]=='.')
				{
					int  c1 = 0;
					if(i+1<r)
					{
						if(a[i+1][j] == '#')
						{
	//						cout<<"help"<<endl;
							c1++;
						}
						if(j+1<c && a[i+1][j+1]=='#')
						{
							//cout<<"help2"<<endl;
							c1++;
						}
					}
					if(j+1<c)
					{
						if(a[i][j+1] =='#')
							c1++;
					}
					//cout<<c<<" "<<i<<" "<<j<<endl;
					if(c1==3)
					{
						ans[i][j]='/';
						ans[i][j+1]='\\';
						ans[i+1][j+1]='/';
						ans[i+1][j]='\\';
					}
				}
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(a[i][j]=='#' && ans[i][j]=='.')
				{
					possible = false;
					break;
				}
			}
		}
	//	for(int i=0;i<r;i++){
	//		for(int j=0;j<c;j++){
	//			cout<<ans[i][j];
	//		}
	//		cout<<endl;
	//	}
		cout<<"Case #"<<cases++<<":"<<endl;
		if(!possible)
		{
			cout<<"Impossible"<<endl;
		}
		else
		{
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					cout<<ans[i][j];
				}
				cout<<endl;
			}
		}
		t--;
	}
	return 0;
}

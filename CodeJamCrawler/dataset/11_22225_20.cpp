#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int cases =1;
	while(t>0)
	{
		int n;
		cin>>n;
		char a[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
	//	for(int i=0;i<n;i++){
	//		for(int j=0;j<n;j++){
	//			cout<<a[i][j];
	//		}
	//		cout<<endl;
	//	}
		vector<double>wp;
		for(int i=0;i<n;i++){
			int tot = 0;
			int loss = 0;
			for(int j=0;j<n;j++){
				if(a[i][j]=='1')
					tot++;
				else if(a[i][j]=='0')
					loss++;				
			}
			if(tot+loss==0)
				wp.push_back(0.0);
			else	
				wp.push_back((double)tot/(double)(tot+loss));
		}
		//for(int i=0;i<wp.size();i++){
		//	cout<<wp[i]<<" "<<endl;
	//	}
		vector<double>p;

		for(int i=0;i<n;i++){
			vector<double>op(n);
			for(int j=0;j<n;j++){
				int tot = 0;
				int loss =0;
				if(j==i)
					continue;
				for(int k=0;k<n;k++){
					if(k==i)
						continue;
					if(a[j][k]=='1')
						tot++;
					else if(a[j][k]=='0')
						loss++;
				}
				if(tot+loss==0)
					op[j]=0.0;
				else 
					op[j] = (double)tot/(double)(tot+loss);
			}
			int tot=0;
			double t = 0.0;
			for(int j=0;j<n;j++){
				if(a[i][j]=='1' || a[i][j]=='0')
				{
					tot++;
					t+=op[j];
				}
			}
			if(tot==0)
				p.push_back(0.0);
			else
				p.push_back((double)t/(double)tot);	
		}

		//for(int i=0;i<p.size();i++){
		//	cout<<p[i]<<endl;
	//	}
		vector<double>owp;
		for(int i=0;i<n;i++){
			int tot = 0;
			double ans = 0.0;
			for(int j=0;j<n;j++){
				if(a[i][j]=='1' || a[i][j]=='0'){
					tot++;
					ans+=p[j];
				}
			}
			if(tot==0)
				owp.push_back(0.0);
			else
				owp.push_back(ans/(double(tot)));
		}
		//for(int i=0;i<owp.size();i++){
		//	cout<<owp[i]<<endl;
		//}
		cout<<"Case #"<<cases++<<":"<<endl;
		for(int i=0;i<wp.size();i++){
			double ans = 0.25*(wp[i])+ 0.50*p[i] + 0.25*owp[i];
			cout<<ans<<endl;
		}
		t--;
	}
	return 0;
}
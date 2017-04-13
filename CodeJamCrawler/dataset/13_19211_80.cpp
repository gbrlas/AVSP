
#include<iostream> 
using namespace std; 
long long int rev(long long int x)
{
	int a=0;
	while(x>0){
		a*=10;
		a+=x%10;
		x/=10;
	}
	return a;
}


int main()
{
	freopen("file.in","r",stdin);
	freopen("file.out","w",stdout);
	int t,i,ans,n1,n2;
	long long int ns[100000];
	int nsc=0;
	//cout<<"::"<<rev(100);
	for(i=0;i<10000000;i++)
		if(i == rev( i))
			if(i*i == rev(i*i))
				ns[nsc++] = i*i;
	cin>>t;
	cout<<nsc;
	for(i=1;i<=t;i++){
		cin>>n1>>n2;
		ans = 0;
		int ii = -1;
		while(ii<nsc && ns[++ii] < n1);
		while(ii<nsc && ns[ii++] <= n2){
				ans++;
				//cout<<ns[ii-1]<<endl;
		}
		printf("Case #%d: %d\n",i,ans);
	}

	return 0;
}

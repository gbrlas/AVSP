#include<iostream> 
using namespace std; 

int main()
{
	freopen("file.in","r",stdin);
	freopen("file.out","w",stdout);
	int i=1,te,count;
	cin>>te;
	long long int R,T,size;
	for(;i<=te;i++){
		count = 0;
		cin>>R>>T;
		size = (R+1)*(R+1) - R*R;
		while(size <= T){
			//cout<<size<<"\n";
			count++;
			T-=size;
			size = size+4;
		}
		printf("Case #%d: %d\n",i,count);
	}

	return 0;
}


/*
(x+1)(s+2x)

*/
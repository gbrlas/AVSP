#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;
long double fun(long int r[],int tam)
{
	int rpta=0;
	for(int i=0;i<tam;i++)
	{
		rpta=rpta+r[i]*pow(2,i);
	}
	return rpta;
}
int main()
{
    //freopen("C-large.in","r",stdin);
    //freopen("C-large.out","w",stdout);

    int cas,cp,m;
    cin>>cas;
    for(int c=0;c<cas;c++)
    {
        cin>>cp;
        long int *val=new long int[cp];
		long int br[10000]={0};
		long int res2[10000]={0};
        for(int i=0;i<cp;i++)
        {
            cin>>val[i];
        }
        sort(val,val+cp);
        int ib=0;
        long int sum=0;
        for(int i=1;i<cp;i++)
        {
            sum=sum+val[i];
            ib=0;
            while(val[i]!=0)
            {
                br[ib]=val[i]%2;
                val[i]=val[i]/2;
                res2[ib]=res2[ib]+br[ib];
                if(res2[ib]>1)
                {
                    res2[ib]=0;
                }
                ib++;
            }
        }
        cout<<"Case #"<<c+1<<": ";
        if(val[0]==fun(res2,ib))
            printf("%ld\n",sum);
            //cout<<sum<<endl;
        else
            printf("NO\n");
            //cout<<"NO\n";
    }
    return 0;
}

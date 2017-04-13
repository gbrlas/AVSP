#include<iostream>
#include<fstream>
using namespace std;
main()
{
    ofstream outputfile("lottery.txt");
    int a,n=1,t,b,i,j,c,k,counter;
    cin>>t;
    while(n!=t+1)
    {
        counter=0;
        cin>>a>>b>>k;
        for(i=0;i<a;i++)
        for(j=0;j<b;j++)
        {
            c=i&j;
            if(c<k)
            {
                counter++;
            }

        }

       outputfile<<"Case #"<<n<<": "<<counter<<endl;
        n++;
    }
    return 0;
}

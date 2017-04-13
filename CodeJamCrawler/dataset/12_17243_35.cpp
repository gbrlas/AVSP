#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

int main()
{
    int test;
    cin>>test;
    int str,j;
    int a,b,c;
    for(j=1;j<=test;j++)
    {
        int i;
        cin>>a>>b>>c;
        str=0;

        for(i=1;i<=a;i++)
        {
            int inp;
            cin>>inp;

            if(inp>3*c-1)
                    {
                        str=str+1;
                        continue;
                    }
                    else
                    {
                        if(c>=1)
                        {
                            if(inp==(3*c-1))
                            {
                                str=str+1;
                                continue;
                            }
                    else if(inp==(3*c-2))
                    {
                        str=str+1;
                        continue;
                    }
                            else if(c>=2)
                            {
                                if(inp==(3*c-3) && b)
                                {
                                    str=str+1;
                                    b--;
                                    continue;
                                }
                                else if(inp==(3*c-4) && b)
                                {
                                    str=str+1;
                                    b--;
                                    continue;
                                }

                            }
                }
            }
        }
        cout<<"Case #"<<j<<": "<<str<<"\n";

    }
}

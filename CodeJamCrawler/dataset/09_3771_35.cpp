using namespace std;
#include<iostream>
string c;
int main()
{
    string zero="0";
    int temp,cases,k;
    bool flg;
    char *c1;
    scanf("%d\n",&cases);
    for(int no=1;no<=cases;no++)
    {
            getline(cin,c);
            flg=true;
            if(next_permutation(c.begin(),c.end()))
            flg=false;
            if(!flg)
            {printf("Case #%d: ",no);cout<<c<<endl;}
            else
            {
            prev_permutation(c.begin(),c.end());
            c.insert(0,zero);
            next_permutation(c.begin(),c.end());
            printf("Case #%d: ",no);cout<<c<<endl;
            }
    }
    return 0;
}

using namespace std;
#include<iostream>
long long unsigned square(long n) { return n*n; }
long long unsigned fastexp(long base,long power) {
if (power == 0)
return 1;
else if (power%2 == 0)
return square(fastexp(base,power/2));
else
return base * (fastexp(base,power-1));
}

int main()
{
    int cases,cnt,tmp;
    char rep[125];
    char s[70];
    bool point;
    long long unsigned int sum;
    scanf("%d",&cases);
    for(int no=1;no<=cases;no++)
    {
            
            scanf("%s",s);
            tmp=0;
            for(int i=0;i<125;i++) {rep[i]=' ';}
            for(int i=0;i<strlen(s);i++)
            {
                    //cout<<rep[s[i]]<<s[i]<<endl;
                    if(rep[s[i]]!=' ')
                    {s[i]=rep[s[i]];}
                    else
                    {
                        rep[s[i]]=(char)('0'+tmp);
                        s[i]=rep[s[i]];
                        tmp++;
                    }
            }
            //printf("%s",s);
            int m=0;
            for(int i=0;i<strlen(s);i++)
            {if(s[i]=='0') s[i]='1';
            else if(s[i]=='1') s[i]='0';
            m=max(m,s[i]-'0');
            }
            m++;
            sum=0;
            for(int i=strlen(s)-1,j=0;i>=0;i--,j++)
            {
                    //cout<<s[i]-'0'<<" "<<fastexp(m,j)<<endl;
                    sum=sum+fastexp(m,j)*(s[i]-'0');}
            cout<<"Case #"<<no<<": "<<sum<<endl;
    }
    return 0;
}        

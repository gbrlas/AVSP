using namespace std;
#include<iostream>
int str[102][2]; 
int label[102][102];
int inp[102][102];
int plabel;
int at;
void calc(int i,int j)
{
//cout<<"i="<<i<<" j = "<<j<<endl;getchar();
bool f=false;
int t,m[4],minimum=10000,tmpi,tmpj,ft=-1;
if(label[i][j]==-1)
     {
     
     m[0]=inp[i-1][j];
     m[1]=inp[i][j-1];
     m[2]=inp[i][j+1];
     m[3]=inp[i+1][j];
     //cout<<m[0]<<" "<<m[1]<< " "<<m[2]<<" "<<m[3]<< " " <<endl;
     ft=-1;
     for(int k=0;k<4;k++)
     {
             if(m[k]<minimum && m[k]<inp[i][j])
             {
             minimum=m[k];
             ft=k;
             f=true;
             }
     }//for
     //cout<<ft<<endl;
     if(f)
     {
             at++;
             if(ft==0)      {str[at][1]=(i-1);str[at][2]=(j);}
             else if(ft==1) {str[at][1]=(i);str[at][2]=(j-1);}
             else if(ft==2) {str[at][1]=(i);str[at][2]=(j+1);}
             else if(ft==3) {str[at][1]=(i+1);str[at][2]=(j);}
     }
     else
     {
     //x.pop();y.pop();
     bool fl=false;
     //cout<<"plabel="<<plabel<<endl;
     while(at>=0)
     {
          //cout<<"yes";
          label[str[at][1]][str[at][2]]=plabel;
          at--;
          fl=true;
     }//while
     at=0;
     if(fl) plabel++;
     return;
     }      //if f
     calc(str[at][1],str[at][2]);
     
     }
     else
     {
         
         t=label[i][j];
         //cout<<"t = "<<t<<endl;
         while(at>=0)
         {
             label[str[at][1]][str[at][2]]=t;
             at--;
         }
         at=0;
     }//else
}//calc ends
     
         
             
              
             
     

int main()
{
    int t,h,w;
    cin>>t;
    
    
    for(int l=0;l<t;l++)
    {
            cin>>h>>w;
            plabel=1;
            for(int i=0;i<102;i++)
            for(int j=0;j<102;j++)
            {inp[i][j]=10000; }
            for(int i=0;i<102;i++)
            for(int j=0;j<102;j++)
            label[i][j]=-1;
            for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
            cin>>inp[i][j];
            for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
            {
            
            if(label[i][j]==-1)
            {
            at=0;
            str[at][1]=i;
            str[at][2]=j;
            calc(i,j);}
            }
            /*for(int i=1;i<4;i++)
            {for(int j=1;j<4;j++)
            cout<<label[i][j]<<" ";
            cout<<endl;
            }*/
            cout<<"Case #"<<l+1<<":"<<endl;
            for(int i=1;i<=h;i++)
            {
            printf("%c",char('a'-1+label[i][1]));
            for(int j=2;j<=w;j++)
            printf(" %c",char('a'-1+label[i][j]));
            cout<<endl;
            }
    }
    return 0;
}

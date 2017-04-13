#include<iostream>
#include<string>
using namespace std;
int main()
{
    int TT;
     freopen ("output.txt","w",stdout);
     freopen ("A-small-attempt0.in","r",stdin);
     
    cin>>TT;
    int count =0;
    
    while(TT--)
    {
        count++;
       
        bool xflag=false,yflag=false;
        char status[4][4];
        string flagd="undecided";
        int Ti=-1,Tj=-1;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
            {
                cin>>status[i][j];
                if(status[i][j]=='.'){
                    flagd="Game has not completed";
                    }
                else if(status[i][j]=='T'){
                    Ti=i;
                    Tj=j;
                }
                }
        //for X won
        if(Ti!=-1)
        status[Ti][Tj]='X';
        for(int i=0;i<4;++i)
        {
        if((status[i][0]=='X' && status[i][1]=='X' && status[i][2]=='X' && status[i][3]=='X') || (status[0][i]=='X' && status[1][i]=='X' && status[2][i]=='X'  && status[3][i]=='X'))
        {
            xflag=true;
            cout<<"Case #"<<count<<": "<<"X won"<<endl;
            break;            
        }
              
        }
        if(xflag==true)
            continue;
        if((status[0][0]=='X' && status[1][1]=='X' && status[2][2]=='X' && status[3][3]=='X') || status[3][0]=='X' && status[2][1]=='X' && status[1][2]=='X' && status[0][3]=='X')
        {
        yflag=true;
            cout<<"Case #"<<count<<": "<<"X won"<<endl;
            continue;
        }
        
        if(xflag==true)
            continue;
        //for checking O won
        if(Ti!=-1)
        status[Ti][Tj]='O';
        for(int i=0;i<4;++i)
        {
        if(status[i][0]=='O' && status[i][1]=='O' && status[i][2]=='O' && status[i][3]=='O')
        {
            yflag=true;
            cout<<"Case #"<<count<<": "<<"O won"<<endl;
            break;            
        }
        else if(status[0][i]=='O' && status[1][i]=='O' && status[2][i]=='O' && status[3][i]=='O')
        {
            yflag=true;
            cout<<"Case #"<<count<<": "<<"O won"<<endl;
            break;
        }
        
        }
        if(yflag==true)
            continue;
         if(status[0][0]=='O' && status[1][1]=='O'  && status[2][2]=='O' && status[3][3]=='O')
        {
        yflag=true;
            cout<<"Case #"<<count<<": "<<"O won"<<endl;
            continue;
                    }
        else if(status[3][0]=='O' && status[2][1]=='O' && status[1][2]=='O' && status[0][3]=='O')
        {
            yflag=true;
            cout<<"Case #"<<count<<": "<<"O won"<<endl;
            continue;
        }
        if(yflag==true)
            continue;
        else if(flagd=="Game has not completed")
            cout<<"Case #"<<count<<": "<<"Game has not completed"<<endl;
        else {
            cout<<"Case #"<<count<<": "<<"Draw"<<endl;
        }
        
            }
  fclose(stdin);    
    fclose (stdout);
    
        return 0;
    }
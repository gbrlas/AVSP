#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool Xwin(string s)
{
    int i;
    int numT = 0;
    int numX = 0;
    for(i=0;i<s.length();i++)
    {
        if(s[i] == 'T')
          numT++;
        if(s[i] == 'X')
          numX++;
    }
    if((numX+numT)==4 && numT<=1)
      return true;
  
    return false;
}
bool Owin(string s)
{
    int i;
    int numT = 0;
    int numO = 0;
    for(i=0;i<s.length();i++)
    {
        if(s[i] == 'T')
          numT++;
        if(s[i] == 'O')
          numO++;
    }
    if((numO+numT)==4 && numT<=1)
      return true;
  
    return false;
}
int main()
{

    int t;
    scanf("%d",&t);
    
    int count = 1;
    while(t--)
    {
        vector<string> board;
        int i,j;
        
        bool XW = false;
        bool OW = false;
        bool dr = true; 

        for(i=0;i<4;i++)
        {
          string s;
          cin>>s;
          board.push_back(s);
          
            for(j=0;j<s.length();j++)
            {
                if(s[j]=='.')
                  dr = false;
            
            }
        }
                
        for(i=0;i<4;i++)
        {
            XW = XW || Xwin(board[i]);  
            OW = OW || Owin(board[i]);  
        
        }
        for(i=0;i<4;i++)
        {
            string s;
            for(j=0;j<4;j++)
              s.push_back(board[j][i]);
            
            XW = XW || Xwin(s);  
            OW = OW || Owin(s);  
        }
        string s;
        for(i=0;i<4;i++)
        {
            s.push_back(board[i][i]); 
        }
        XW = XW || Xwin(s);  
        OW = OW || Owin(s);
        s.clear();
        for(i=0;i<4;i++)
        {
            s.push_back(board[i][4-i-1]); 
        }
        XW = XW || Xwin(s);  
        OW = OW || Owin(s);
        
        cout<<"Case #"<<count<<": ";
        if(XW)
          cout<<"X won"<<endl;
        else if(OW)
          cout<<"O won"<<endl;
        else if(dr)
          cout<<"Draw"<<endl;
        else
          cout<<"Game has not completed"<<endl;
        count++;
    }
}

#include<iostream>


using namespace std;

int main()
{
    int t;
    cin>>t;
    
    
    for(int i=0;i<t;i++)
    {
            
            int flag=0;
                    
            string str[4];
            
            for(int j=0;j<4;j++)cin>>str[j];
            
            for(int j=0;j<4;j++)
            {
                    
                    if(str[j].find(".")!=-1)
                    {
                            flag=4;
                    }
                    
                    if(str[j].find("O")==-1 && str[j].find(".")==-1){flag=1;break;}
                                       
                    if(str[j].find("X")==-1 && str[j].find(".")==-1){flag=2;break;}
                           
                    
            }
            
            for(int j=0;j<4;j++)
            {
                    if(flag==1 || flag==2)break;
                    
                    string temp="";
                    for(int k=0;k<4;k++)
                    {
                            temp+=str[k][j];
                    }
                    
                    if(temp.find("O")==-1 && temp.find(".")==-1){flag=1;break;}
                                       
                    if(temp.find("X")==-1 && temp.find(".")==-1){flag=2;break;}
            }
            
            string templd="",temprd="";
            
            for(int j=0;j<4;j++)
            {
                    if(flag==1 || flag==2)break;
                    
                    
                    templd+=str[j][j];
                    temprd+=str[j][3-j];
            }
            if(flag!=1 && flag!=2)
            {
            if(templd.find("O")==-1 && templd.find(".")==-1){flag=1;}
                                       
            if(templd.find("X")==-1 && templd.find(".")==-1){flag=2;}
            
            if(temprd.find("O")==-1 && temprd.find(".")==-1){flag=1;}
                                       
            if(temprd.find("X")==-1 && temprd.find(".")==-1){flag=2;}
            }                
                     
            if(flag==1)cout<<"Case #"<<i+1<<": X won"<<endl;
            
            else if(flag==2)cout<<"Case #"<<i+1<<": O won"<<endl;
            
            else if(flag==4)cout<<"Case #"<<i+1<<": Game has not completed"<<endl;
            
            else cout<<"Case #"<<i+1<<": Draw"<<endl;
                              
    }
    
    
    return 0;
}

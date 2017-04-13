#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int matrix[100][100];
vector<int> bbc (int a,int b,int i,int j)
{
              int k,min,flag,x,y;
              pair<int,int>temp,top;
              queue< pair<int,int> >q,q1;
              q1.push(make_pair(i,j));
              if(a==1){
                    while(!q1.empty()){
                        top=q1.front();q1.pop();j=top.second;i=top.first;             
                        min=matrix[i][j];  
                        flag=0;
                        if(j==0){
                          if(matrix[i][j+1]<min){
                                   x=i;y=j+1;flag=1;
                           }      
                           if(flag==1) q1.push(make_pair(x,y));
                        }
                        else{
                             if(j==b-1){
                                  if(matrix[i][j-1]<min){
                                   x=i;y=j-1;flag=1;
                                  }
                                  if(flag==1) q1.push(make_pair(x,y));      
                             }      
                             else{
                                  if(matrix[i][j-1]<min){
                                    min=matrix[i][j-1];                     
                                   x=i;y=j-1;flag=1;
                                  }
                                  if(matrix[i][j+1]<min){
                                   x=i;y=j+1;flag=1;
                                  }
                                  if(flag==1) q1.push(make_pair(x,y));   
                             }
                        }     
                    }
              }   
              else{
                    if(b==1){
                            while(!q1.empty()){ 
                               top=q1.front();q1.pop();j=top.second;i=top.first;             
                               min=matrix[i][j];  
                               flag=0;
                               if(i==0){
                                    if(matrix[i+1][j]<min){x=i+1;y=j;flag=1;if(flag==1) q1.push(make_pair(x,y));}
                               }
                               else{
                                    if(i==a-1){if(matrix[i-1][j]<min){x=i-1;y=j;flag=1;if(flag==1) q1.push(make_pair(x,y));}
                                    }
                                    else{
                                         if(matrix[i-1][j]<min){x=i-1;y=j;flag=1;min=matrix[i-1][j];if(flag==1) q1.push(make_pair(x,y));}
                                         if(matrix[i+1][j]<min){x=i+1;y=j;flag=1;if(flag==1) q1.push(make_pair(x,y));}
                                    }
                               }
                            }
                    }
                    else{
              q.push(make_pair(i,j));         
              while(!q.empty()){
                   top=q.front();
                   q.pop();
                   i=top.first;
                   j=top.second;flag=0;
                   //cout<<i<<" "<<j<<endl;
                   min=matrix[i][j];x=i;y=j;
                   if(i==0){
                      if(j==0){
                           if(matrix[i][j+1]<min){
                                   min=matrix[i][j+1];                          
                                   x=i;y=j+1;flag=1;
                           }
                           if(matrix[i+1][j]<min){
                                   x=i+1;y=j;flag=1;
                           }
                           if(flag==1) q.push(make_pair(x,y));
                      }
                      else{
                           if(j==b-1){
                                if(matrix[i][j-1]<min){
                                   min=matrix[i][j-1];                          
                                   x=i;y=j-1;flag=1;
                                }
                                if(matrix[i+1][j]<min){
                                   x=i+1;y=j;flag=1;
                                }
                                if(flag==1) q.push(make_pair(x,y));
                          }      
                          else{
                               if(matrix[i][j-1]<min){
                                   min=matrix[i][j-1];                          
                                   x=i;y=j-1;flag=1;
                                }
                                if(matrix[i][j+1]<min){
                                   min=matrix[i][j+1];                          
                                   x=i;y=j+1;flag=1;
                                }
                                if(matrix[i+1][j]<min ){
                                   x=i+1;y=j;flag=1;
                                }
                                if(flag==1) q.push(make_pair(x,y));
                          }      
                      }
                   }
                   else{if(i==a-1){
                            if(j==0){
                                 if(matrix[i-1][j]<min){
                                     min=matrix[i-1][j];                          
                                     x=i-1;y=j;flag=1;
                                 }
                                 if(matrix[i][j+1]<min){
                                    x=i;y=j+1;flag=1;
                                 }
                                 if(flag==1) q.push(make_pair(x,y));
                             }
                             else{
                                 if(j==b-1){
                                   if(matrix[i-1][j]<min){
                                     min=matrix[i-1][j];                          
                                     x=i-1;y=j;flag=1;
                                   }
                                   if(matrix[i][j-1]<min){
                                     x=i;y=j-1;flag=1;
                                   }
                                   if(flag==1) q.push(make_pair(x,y));
                                 }      
                             else{
                                 if(matrix[i-1][j]<min){
                                    min=matrix[i-1][j];                          
                                    x=i-1;y=j;flag=1;
                                  }
                                 if(matrix[i][j-1]<min){
                                    min=matrix[i][j-1];                          
                                    x=i;y=j-1;flag=1;
                                 }
                                 if(matrix[i][j+1]<min){
                                   x=i;y=j+1;flag=1;
                                 }
                                 if(flag==1) q.push(make_pair(x,y));
                              }}}
                          else{
                               if(j==0 && i!=0 && i!=a-1){
                                    if(matrix[i-1][j]<min){
                                    min=matrix[i-1][j];                          
                                    x=i-1;y=j;flag=1;
                                    }
                                    if(matrix[i][j+1]<min){
                                    min=matrix[i][j+1];                          
                                    x=i;y=j+1;flag=1;
                                    }
                                    if(matrix[i+1][j]<min){
                                     x=i+1;y=j;flag=1;
                                    }     
                                    if(flag==1) q.push(make_pair(x,y));
                               }
                               else{
                                    if(j==b-1 && i!=0 && i!=a-1){
                                           if(matrix[i-1][j]<min){
                                           min=matrix[i-1][j];                          
                                           x=i-1;y=j;flag=1;
                                           }
                                           if(matrix[i][j-1]<min){
                                           min=matrix[i][j-1];                          
                                           x=i;y=j-1;flag=1;
                                           }
                                           if(matrix[i+1][j]<min){
                                           x=i+1;y=j;flag=1;
                                           }     
                                           if(flag==1) q.push(make_pair(x,y));
                                    }                    
                                    else{
                                           if(matrix[i-1][j]<min){
                                           min=matrix[i-1][j];                          
                                           x=i-1;y=j;flag=1;
                                           }
                                           if(matrix[i][j-1]<min){
                                           min=matrix[i][j-1];                          
                                           x=i;y=j-1;flag=1;
                                           }
                                           if(matrix[i][j+1]<min){
                                           min=matrix[i][j+1];                          
                                           x=i;y=j+1;flag=1;
                                           }
                                           if(matrix[i+1][j]<min){
                                           x=i+1;y=j;flag=1;
                                           }
                                           if(flag==1) q.push(make_pair(x,y));
                                       }
                                     }
                               }
                          }
                   }
              }
              }
                   vector<int>v;
                   v.push_back(top.first);v.push_back(top.second);                   
                   return v;
}             
                        
int main(){
    int n,k,z=1,a,b,i,j;
    cin>>n;
    while(z<=n){
               cin>>a>>b;
               int mapped[a][b];
               for(i=0;i<a;i++){
                                for(j=0;j<b;j++){
                                                 cin>>matrix[i][j];
                                                 mapped[i][j]=-1;
                                }
                                } 
               
                vector<int> p;
                k=97;
               char c[a][b];
               if(a==1 && b==1){
                       cout<<"Case #"<<z<<":\n";
                       cout<<"a"<<endl;
               }
               else{
               for(i=0;i<a;i++){
                                for(j=0;j<b;j++){
                                       p=bbc(a,b,i,j);
                                       //cout<<p[0]<<" "<<p[1]<<endl;
                                       if(mapped[p[0]][p[1]]==-1){
                                               mapped[p[0]][p[1]]=k;
                                               c[i][j]=char(k);
                                               k++;
                                       }
                                       else
                                               c[i][j]= char(mapped[p[0]][p[1]]);
                                }
               }            
              cout<<"Case #"<<z<<":\n";
              for(i=0;i<a;i++){
                                for(j=0;j<b;j++){
                                                 cout<<c[i][j]<<" ";
                                }
                                cout<<endl;
              }
              }
              z++;
    }
    //system("pause");
}                     

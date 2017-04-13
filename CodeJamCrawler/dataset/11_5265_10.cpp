using namespace std;
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
int main()
{
    int T,C,D,N,cases=1;
    vector<char> ans;
    vector<char>::iterator it;
    scanf("%d",&T);
    while (T--)
    {
          char combine[257][257]={'\0'},opposed[257]={'\0'};
          scanf("%d",&C);
          char temp[10],el[100];
          for (int i=0;i<C;i++)
          {
              scanf("%s", &temp);
              combine[int(temp[0])][int(temp[1])]=temp[2];
              combine[int(temp[1])][int(temp[0])]=temp[2];
          }
          scanf("%d",&D);
          for (int i=0;i<D;i++)
          {
              scanf("%s", &temp);
              //printf("%s",&temp);
              opposed[int(temp[0])]=temp[1];
              opposed[int(temp[1])]=temp[0];
          }    
          scanf("%d",&N);
          scanf("%s",&el);
          for (int i=0;i<N;i++)
          {
              ans.push_back(el[i]);
              if ( ans.size()>=2)
              {
                   char temp1=combine[int(ans[ans.size()-1])][int(ans[ans.size()-2])];
                   while (temp1 != '\0')
                   {
                         ans.pop_back();
                         ans.pop_back();
                         ans.push_back(temp1);
                         if(ans.size()>=2)
                         temp1=combine[int(ans[ans.size()-1])][int(ans[ans.size()-2])];
                         else temp1='\0';
                   }
              }
              if( ans.size()>=2)
              {
                  if( opposed[int(ans.back())] != '\0')
                  {
                      it=find (ans.begin(), ans.end(), opposed[int(ans.back())]);
                      //cout<<"it "<< opposed[int(ans.back())]<<*it<<endl;
                      //cin>>temp[0];
                      if(it!=ans.end())
                      ans.clear();
                      //for(int i=0;i<ans.size();i++)
//                      cout<<ans[i]<<", ";
//                      cout<<"cleared\n";
                  }
              }
          }
          cout<<"Case #"<<cases++<<": [";
          if(ans.size()!=0)
          for(int i=0;i<ans.size()-1;i++)
          cout<<ans[i]<<", ";
          if(ans.size()>=1) cout<<ans.back();
          cout<<"]\n";
          ans.clear();
    }
    return 0;
}
    

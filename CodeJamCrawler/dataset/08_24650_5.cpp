#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<sstream>
#include<fstream>
#include<stack>
#include<queue>

using namespace std;

class abc
{
      vector<int> keyid;
      vector<int> listvig;
      public:
             int maxperkey,totkeys,totlets;
             int calcMinPress(vector<int>);
             
      
};

int abc :: calcMinPress(vector<int> l)
{
    listvig = l;
    int minPress = 0;
    
    if(maxperkey * totkeys < totlets)
                 return -1;
    sort(listvig.begin(),listvig.end());
    
    int keynum = 1;
    for(int i = listvig.size()-1 ;i>=0 ;i--)
    {
            keyid.push_back(keynum);
            keynum++;
            if(keynum>totkeys)
                 keynum = 1;
    }
    for(keynum = 1;keynum<= totkeys;keynum++)
    {
               int count = 1;
               for(int i = listvig.size()-1;i>=0;i--)
               {
                       if(keyid[i] == keynum)
                       {
                                   minPress += listvig[i]*count;
                                   count++;
                        }
               }
    }
    return minPress;
}
    
    



int main()
{
    int cases,num;
    ifstream ifile("c:\\abc.in");
    ofstream ofile("c:\\abc.out");
    ifile>>cases;
    cout<<cases;
    cin.get();
    for(int i = 0;i<cases;i++)
    {
            vector<int> temp;
            abc obj;
            ifile>>obj.maxperkey;
            ifile>>obj.totkeys;
            ifile>>obj.totlets;
            for(int j = 0;j<obj.totlets;j++)
            {
                    ifile>>num;
                    temp.push_back(num);
            }
            ofile<<"Case #"<<i+1<<": ";  //newline to be inserted
            num = obj.calcMinPress(temp);
            if(num == -1)
                   ofile<<"impossible"<<"\n";
            else
                ofile<<num<<"\n";
    }
    cin.get();
    cin.get();
    return(0);
}

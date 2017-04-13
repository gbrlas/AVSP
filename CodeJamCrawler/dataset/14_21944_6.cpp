// Google Code Jam 2014 - Qualification Round
// A. Magic Trick

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solveTestcase();

int main()
{
  int testcase,result;
  cin>>testcase;
  for(int n=1;n<=testcase;n++)
  {
    result = solveTestcase();
    switch(result)
    {
      case -1:
        cout<<"Case #"<<n<<": Bad magician!"<<endl;
        break;
      case 0:
        cout<<"Case #"<<n<<": Volunteer cheated!"<<endl;
        break;
      default:
        cout<<"Case #"<<n<<": "<<result<<endl;
    }
  }
  return 0;
}

int solveTestcase()
{
  int a,b,tmp,ia=0,ib=0,r=0;
  vector<int> arr[4],brr[4];
  cin>>a;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
      cin>>tmp;
      arr[i].push_back(tmp);
    }
  cin>>b;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
      cin>>tmp;
      brr[i].push_back(tmp);
    }
  sort(arr[a-1].begin(),arr[a-1].end());
  sort(brr[b-1].begin(),brr[b-1].end());
  while(ia<4 && ib<4)
  {
    //cout<<arr[a-1].at(ia)<<" "<<brr[b-1].at(ib)<<endl;
    if(arr[a-1].at(ia)==brr[b-1].at(ib))
    {
      if(r>0)
        return -1;
      r=arr[a-1].at(ia);
      ia++;
      ib++;
    }
    else if(arr[a-1].at(ia)<brr[b-1].at(ib))
      ia++;
    else
      ib++;
  }
  return r;
}

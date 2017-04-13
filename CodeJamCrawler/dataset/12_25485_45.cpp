#include <iostream>
#include <set>


using namespace std;

bool getnextrecycle(string& nowrecycle)
{
  if(nowrecycle.size()<2) return false;
  char temp = nowrecycle[nowrecycle.size()-1];
  nowrecycle = temp+nowrecycle.substr(0,nowrecycle.size()-1);
  if(nowrecycle[0] !='0')
    return true;

  return false;
}

string increment(string no)
{
    int c=1;
    string inc;
    for(int i=no.size()-1;i >=0; --i)
    {
        if(no[i] == '9' && c==1)
        {
           inc = '0' + inc;
           c=1;
        }
        else
        {
            inc = char(no[i]+c) +inc;
            c=0;
        }
    }
    if(inc[0] =='0')
    {
        inc = '1'+inc;
    }
    return inc;
}

int main()
{
    int T,c;
    cin>> T;
    while(c++<T)
    {
        long res =0;

        string A, B;
        cin >> A >> B;
        string inc = A;
        while(A!=B && (B.size()>inc.size() || (inc.compare(B) !=1 && inc.size() == B.size()) ))
        {
            string recycle = inc;
            set<string> adds;
            int size =1;
            while(size < inc.size())
            {
                ++size;
                if(getnextrecycle(recycle) &&
                   strcmp(recycle.c_str(), inc.c_str()) ==1 &&
                   ((B.size()> recycle.size()) || (B.size() == recycle.size() &&strcmp(B.c_str(), recycle.c_str())!=-1) ))
                {
                    if(adds.insert(inc+recycle).second)
                    res++;
                }
            }
            //cout <<"inc = "<<inc<<endl;
            inc = increment(inc);
        }
        cout<<"Case #" <<c <<": "<< res<<endl;

    }
    return 0;
}


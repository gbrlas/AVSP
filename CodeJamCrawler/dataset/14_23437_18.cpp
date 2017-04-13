#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

vector<pair<char, int> > divide(string x);

int main()
{
    int T;
    
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
            cout << "Case #" << i+1 << ": ";
            int N;
            int overallSum = 0;
            cin >> N;
            
            vector<vector<pair<char, int> > > brokenArray;
            
            for(int j = 0; j < N; j++)
            {
                    string x;
                    
                    cin >> x;
                    
                    brokenArray.push_back(divide(x));
            }
            
            for(int j = 1; j < N; j++)
            {
                    if(brokenArray[j].size() != brokenArray[0].size())
                    {
                         goto end;
                    }
                    for(int k = 0; k < brokenArray[j].size(); k++)
                    {
                            if(brokenArray[j][k].first != brokenArray[0][k].first) goto end;
                                                       
                    }
            }
            
            for(int j = 0; j < brokenArray[0].size(); j++)
            {
                    int sum = 0;
                    
                    for(int k = 0; k < N; k++) sum += brokenArray[k][j].second;
                    
                    sum = sum / N  + (2*(sum % N) > N);
                    
                    int optimal = 0;
                    
                    for(int k = 0; k < N; k++) optimal += abs(brokenArray[k][j].second - sum);
                    
                    overallSum += optimal;
                    
            }
            
            cout << overallSum << endl;
            
            continue;
            
            end:
            cout << "Fegla Won" << endl;
    }
    return 0;
}

vector<pair<char, int> > divide(string x)
{
     vector< pair<char, int> > result;
     int licznik = 1;
     for(int k = 0; k < x.size(); k++)
     {
          if(k < x.size()-1 && x[k] == x[k+1])
          {
               licznik++;
          }
          else
          {
               result.push_back(make_pair(x[k], licznik)); 
               licznik = 1;
          }            
     }             
     return result;
}
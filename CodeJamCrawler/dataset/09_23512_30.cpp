#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;
#define NDEF 100

bool isValid(int i, int j, int h, int w)
{
     return (i>=0 && i < h) && (j>=0 && j<w);
}


int findlexNext(int i, int j, int h, int w)
{
    if(j==w-1)
    {
       if(i==h-1)
       {
          return -1;
       }
       else
       {
          return (i+1)*w;
       }
    }
    return i*w+j+1;
}


int findFlowIndex(vector< vector<int> > & terrain, int i, int j, int h, int w)
{
    int val = terrain[i][j];
    int north = NDEF, south = NDEF, east = NDEF, west = NDEF;
    int min = val, choose = -1;
    if(isValid(i-1,j,h,w)) //north
    {
        north = terrain[i-1][j];
        if(north < min) 
        {
           min = north;
           choose= (i-1)*w+j;
        }   
    }
    if(isValid(i,j-1,h,w)) //west
    {
        west = terrain[i][j-1];
        if(west < min) 
        {
           min = west;
           choose=i*w+j-1;
        }   
    }
    if(isValid(i,j+1,h,w)) //east
    {
        east = terrain[i][j+1];
        if(east < min) 
        {
           min = east;
           choose=i*w+j+1;
        }   
    }
    if(isValid(i+1,j,h,w)) //south
    {
        south = terrain[i+1][j];
        if(south < min) 
        {
           min = south;
           choose=(i+1)*w+j;
        }
    }
    return choose;
}

int main()
{
    int t;
    cin >> t;
    for(int k=0; k<t; ++k)
    {
            vector< vector<int> >  terrain;
            int h,w;
            cin >> h >> w;
            for(int i=0; i< h; ++i)
            {
                    vector<int> tempvec;
                    for(int j=0; j<w; ++j)
                    {
                        int temp;    
                        cin >>  temp;
                        tempvec.push_back(temp);
                    }
                    terrain.push_back(tempvec);
            }
            set<int> a, b;
            a.insert(0);
            int count =0;
            while(count<h*w)
            {
              ++count;            
              for(int i=0; i< h; ++i)
              {
                    for(int j=0; j<w; ++j)
                    {
                        int index = i*w+j;
                        //int nextInd = findlexNext(i, j, h, w);
                        int flowInd = findFlowIndex(terrain, i, j, h, w);
                        //cout << index << " " << flowInd<<"\n";
                        if(flowInd != -1)
                        {
                           if(a.find(index)!=a.end())
                           {   
                               //cout << "inserting " <<flowInd<<" to a\n";
                               a.insert(flowInd);
                           }
                           else if(a.find(flowInd)!=a.end())
                           {
                               //cout << "inserting " <<index<<" to a\n";
                               a.insert(index);
                           }
                       }  
                    }
               }
            }
            cout<<"Case #"<<k+1<<":\n";
            for(int i=0; i< h; ++i)
            {
                    for(int j=0; j<w; ++j)
                    {
                        int index = i*w+j;
                        if(a.find(index) != a.end())
                        {
                          cout << "a ";               
                        }
                        else //if(b.find(index) != b.end())
                        {
                          cout << "b ";
                        }
                    }
                    cout <<"\n";
            }
    }
}

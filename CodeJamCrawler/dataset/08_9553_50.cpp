#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    ifstream fin("B.in");
    ofstream fout("B.out");
    int N, NA, NB, T, casenum, atot, btot;
    int aarr[150], adep[150], barr[150], bdep[150];
    string t1, t2;
    fin >> N;
    casenum = 1;
    while (casenum <= N)
    {
        fin >> T >> NA >> NB;
        atot = 0; btot = 0;
        for (int i = 0; i < NA; i++)
        {
            fin >> t1 >> t2;
            adep[i] = atoi(t1.substr(0,2).c_str())*60 + atoi(t1.substr(3,2).c_str());
            aarr[i] = atoi(t2.substr(0,2).c_str())*60 + atoi(t2.substr(3,2).c_str()) + T;
        }    
        for (int i = 0; i < NB; i++)
        {
            fin >> t1 >> t2;
            bdep[i] = atoi(t1.substr(0,2).c_str())*60 + atoi(t1.substr(3,2).c_str());
            barr[i] = atoi(t2.substr(0,2).c_str())*60 + atoi(t2.substr(3,2).c_str()) + T;
        }    
        /*for (int i = 0; i < NA; i++)
            fout << adep[i] << " " << aarr[i] << endl;
        for (int i = 0; i < NB; i++)
            fout << bdep[i] << " " << barr[i] << endl; */
        sort(adep, adep+NA);
        sort(aarr, aarr+NA);
        sort(bdep, bdep+NB);
        sort(barr, barr+NB);
            
        int arrnum = 0, depnum = 0, left = 0;
        while ((arrnum < NB) && (depnum < NA))
        {
            if (adep[depnum] < barr[arrnum])
            {
                if (left > 0)
                    left--;
                else  
                    atot++;
                depnum++;
            }
            else
            {
                left++;
                arrnum++;
            }        
        }
        if (depnum < NA)
            atot += max(0, NA - depnum - left);
        arrnum = 0; depnum = 0, left = 0;
        while ((arrnum < NA) && (depnum < NB))
        {
            if (bdep[depnum] < aarr[arrnum])
            {
                if (left > 0)
                    left--;
                else  
                    btot++;
                depnum++;
            }
            else
            {
                left++;
                arrnum++;
            }        
        }   
        if (depnum < NB)
            btot += max(0, NB - depnum - left); 
        fout << "Case #" << casenum << ": " << atot << " " << btot << endl;
        casenum++;
    }    
}    

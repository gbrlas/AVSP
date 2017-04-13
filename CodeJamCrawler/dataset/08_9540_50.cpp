#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    ifstream fin("A.in");
    ofstream fout("A.out");
    int N, S, Q, casenum, total, numused, next;
    string use;
    fin >> N;
    casenum = 1;
    string names[100];
    string query[1000];
    bool used[100];
    while (casenum <= N)
    {
        total = 0;
        fin >> S;
        getline(fin, use);
        for (int i = 0; i < S; i++)
                getline(fin, names[i]);
        //for (int i = 0; i < S; i++)
          //      fout << names[i] << endl;
        fin >> Q;
        getline(fin, use);
        for (int i = 0; i < Q; i++)
            getline(fin, query[i]);
        next = 0;
        use = "";

        while (true)
        {        
            numused = 0;
            for (int i = 0; i < S; i++)
                    used[i] = false;
            //fout << "Test"<< next << Q << endl;
            while (next < Q)
            {

                if (((numused >= S - 1) && (use != "")) || (numused >= S))
                    break;

                if (query[next] == use)
                {
                    next++;
                    continue;
                }    
                for (int i = 0; i < S; i++)
                {
                    if ((names[i] == query[next]) && !used[i])
                    {
                        used[i] = true;
                        //fout << "Used " << names[i] << ' '<< numused << endl;
                        numused++;
                        break;
                    }    
                }  
                next++;
            } 
            if ((numused < S - 1) || ((use == "") && (numused < S)))
                break;
        
            use = query[next-1];   
            //fout << next << endl;  
            total++;       
        }    
        
        fout << "Case #" << casenum << ": " << total << endl;
        casenum++;
    }    
}
    

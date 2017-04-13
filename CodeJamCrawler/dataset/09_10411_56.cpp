#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
    ifstream fin("A.in");
    FILE * fout;
    fout = fopen("A.out", "w");
    int N, L, A;
    fin >> N;
    bool isnum = false, isyes = true;
    for (int casenum = 1; casenum <= N; casenum++)
    {
        fin >> L;
        vector<double> prob;
        vector<int> yes;
        vector<int> no;
        vector<string> feat;
        string s = "", next, num;
        getline(fin, next);
        for (int i = 0; i < L; i++)
        {
            getline(fin, next);
            s += next;
        }
        
        int parent = -2, prcount = -1;
        stack<int> par;
        
        for (int j = 0; j < s.length(); j++)
        {
            if (isdigit(s[j]))
            {
                int last = j;
                while (isdigit(s[last]) || (s[last] == '.'))
                      last++;
                num = s.substr(j, last - j);
                stringstream ss;
                ss << num;
                double pr;
                ss >> pr;
                prob.push_back(pr);
                prcount++;
                yes.push_back(-1);
                no.push_back(-1);
                if (isyes)
                {
                   if (!par.empty())
                   {
                      yes[par.top()] = prcount;
                   }
                }
                else
                {
                   if (!par.empty())
                      no[par.top()] = prcount;
                }
                par.push(prob.size()-1);
                j = last;
                isnum = true;
                isyes = false;
            }
            if (isalpha(s[j]))
            {
               int last = j;
               string desc;
               while (isalpha(s[last]))
                      last++;
               desc = s.substr(j, last - j);
               feat.push_back(desc);
               j = last; 
               isnum = false;
               isyes = true;
            }
            //if (s[j] == '(')
               //parent++;
            if (s[j] == ')')
            {
              // parent--;
               if (isnum)
               {
                  feat.push_back("#");
                  isnum = false;
               }
               par.pop();
            }
        }
        /*for (int i = 0; i < prob.size(); i++)
            fout << prob[i] << ' ';
        fout << endl;
        for (int i = 0; i < feat.size(); i++)
            fout << feat[i] << ' ';
        fout << endl;
        for (int i = 0; i < yes.size(); i++)
            fout << yes[i] << ' ';
        fout << endl;
        for (int i = 0; i < no.size(); i++)
            fout << no[i] << ' ';
        fout << endl;*/
        
        //fout << "Case " << casenum << ": " << endl;
        fprintf(fout, "Case #%d:\n", casenum);
        fin >> A;
        for (int i = 0; i < A; i++)
        {
            int n;
            double p = 1;
            vector<string> ani;
            string ss;
            fin >> ss >> n;
            for (int j = 0; j < n; j++)
            {
                fin >> ss;
                ani.push_back(ss);
            }
            sort(ani.begin(), ani.end());
            //for (int j = 0; j < ani.size(); j++)
            //    fout << ani[j] << ' ';
            //fout << endl;
            int curr = 0;
            while (true)
            {
              p *= prob[curr];
              if (yes[curr] == -1)
                 break;
              if (binary_search(ani.begin(), ani.end(), feat[curr]))
              {
                 //fout << feat[curr] << endl;
                 curr = yes[curr];
              }
              else
                  curr = no[curr];
             }
             //fout << p << endl;
             fprintf(fout, "%.7f\n", p); 
        }      
    }
    fclose(fout);
    return 0;   
}

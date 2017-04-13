#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<math.h>
#include<time.h>
#include <sstream>

using namespace std;

int main()
{    
    int t;
    string inp, inp2, outp;

    std::ifstream finsm("A-small-attempt0.in");
    std::ifstream fin("input.in"); // sample input
    std::ifstream fin2("input2.in"); // sample output
    std::ofstream fout("output.out");

    map<char,char> repl;
    map<char,char> inv_repl; 

    repl['a'] = 'y';
    repl['e'] = 'o';
    repl['q'] = 'z';     

    inv_repl['y'] = 'a';
    inv_repl['o'] = 'e';
    inv_repl['z'] = 'q'; 
    

    fin >> t;
    getline(fin,inp);

    for(int i = 0; i < t; i++)
    {
        getline(fin,inp);
        getline(fin2,inp2);
        for(int k = 0; k < inp.length(); k++)
        {
            if(repl.count(inp[k]) == 0)
            {
                repl[inp[k]] = inp2[k];
                inv_repl[inp2[k]] = inp[k];
            }
        }
    } 
    
    //from debug - all the letters are now in the map except 1.
    // find it!
    char mkey, mval;
    bool fk = false, fv = false;
    for(int i = 97; i <= 122; i++)
    {
        if(repl.count(i) == 0)
        {
            mkey = i;
            fk = true;            
        }
        if(inv_repl.count(i) == 0)
        {
            mval = i;
            fv = true;
        }   
        if(fk && fv)
        {
            repl[mkey] = mval;
            inv_repl[mval] = mkey;
            break;   
        } 
    }
       

    // now solve small input
    finsm >> t;
    getline(finsm,inp);
    
    for(int i = 1; i <= t; i++)
    {        
        getline(finsm,inp);
       
       stringstream ss;//create a stringstream
       ss << i;//add number to the stream
       ss.str();
       outp = "Case #";
        outp += ss.str();
        outp = outp.append(": ");
        for(int k = 0; k < inp.length(); k++)
        { 
            outp += repl[ inp[k] ];            
        }        
       
        fout << outp << "\n";
    }

    fout << flush;

    fout.close();


    return 0;
}
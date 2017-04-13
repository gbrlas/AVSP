#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

using namespace std;

int main()
{
    int L, D, N;
    cin >> L >> D >> N;

    set<string> dict;
    for(int i = 0 ; i < D ; ++i){
        string word;
        cin >> word;
        dict.insert(word);
    }

    for(int X = 1 ; X <= N ; ++X){
        string line;
        cin >> line;
        
        vector<string> pattern;
        bool ambiguous = false;
        
        foreach(char c, line){
            switch(c){
            case '(':
                ambiguous = true;
                pattern.push_back(string());
                break;
            case ')':
                ambiguous = false;
                break;
            default:
                if(ambiguous)
                    pattern.back().push_back(c);
                else
                    pattern.push_back(string(1, c));
                break;
            }
        }

        set<const string *> matchs1;
        set<const string *> matchs2;
        set<const string *> *prev = &matchs1;
        set<const string *> *next = &matchs2;

        foreach(const string &word, dict){
            matchs1.insert(&word);
        }

        foreach(string &token, pattern){
            //cerr << '(' << token << ')';
        }
        //cerr << endl;
        
        for(int i = 0 ; i < L ; ++i){
            foreach(const string *word, *prev){
                //cerr << *word << ' ';
            }
            //cerr << endl;
                
            string &token = pattern[i];
            foreach(const string *word, *prev){
                foreach(char c, token){
                    if((*word)[i] == c){
                        next->insert(word);
                        break;
                    }
                }
            }
            swap(prev, next);
            next->clear();
            if(prev->empty())
                break;

        }

        cout << "Case #" << X << ": " << prev->size() << endl;
    }

    return 0;
}
                
                
            
        

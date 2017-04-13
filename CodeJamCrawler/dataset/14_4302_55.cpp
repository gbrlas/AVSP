#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <set>
using namespace std;

int main()
{
    int testcases, N, i, j, score_deceit, score_war;
    double block, block_naomi, block_ken, delta = 0.0000001;
    vector<double> naomi, ken;
    stack<double> ken_ord, naomi_war;
    list<double> naomi_ord, ken_war;
    set<double> naomi_set, ken_set;
    
    cin >> testcases;
    for(i = 1; i <= testcases; i++)
    {
        cin >> N;
        for(j = 1; j <= N; j++)
        {
            cin >> block;
            naomi.push_back(block);
            naomi_set.insert(block);
        }
        
        for(j = 1; j <= N; j++)
        {
            cin >> block;
            ken.push_back(block);
            ken_set.insert(block);
        }
        
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());
        
        for(j = 0; j < ken.size(); j++)
        {
            ken_ord.push(ken[j]);
            naomi_war.push(naomi[j]);
            ken_war.push_back(ken[j]);
            naomi_ord.push_back(naomi[j]);
        }
        
        score_deceit = 0;
        score_war = 0;
        
        while(!naomi_ord.empty())
        {
            block_naomi = naomi_ord.back();
            block_ken = ken_ord.top();

            if(block_naomi < block_ken)
            {
                do
                {
                    block = block_ken - delta;
                    if(block_naomi - block < delta) break;
                } while( ken_set.find(block) != ken_set.end());

                if(naomi_set.find(block) == naomi_set.end())
                    naomi_ord.pop_front();
                else
                    naomi_ord.pop_back();
            }
            else
            {
                score_deceit++;
                naomi_ord.pop_back();
            }
                
            ken_ord.pop();
            
            block_naomi = naomi_war.top();
            block_ken = ken_war.back();
            
            if(block_ken > block_naomi)
                ken_war.pop_back();
            else
            {
                score_war++;
                ken_war.pop_front();
            }
            
            naomi_war.pop();
        }
        
        naomi.clear();
        naomi_set.clear();
        ken.clear();
        ken_set.clear();
        
        cout << "Case #" << i << ": " << score_deceit << " " << score_war << endl;
    }
}

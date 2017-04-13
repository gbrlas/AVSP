#include <iostream>
#include <vector>
using namespace std;

int num_cases;
int num_trees;
int a, b, c, d;
long long x, y;
int m;
int mod;

pair<int, int> tree;
vector< pair<int, int> > trees;

int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("a-small.out", "w", stdout);
    
    cin >> num_cases;
    for (int curr_case = 1; curr_case <= num_cases; curr_case++) {
        cin >> num_trees;
        cin >> a >> b >> c >> d >> x >> y >> m;
        
        trees.clear();
        
        tree.first = x;
        tree.second = y;
        trees.push_back(tree);
        for (int i = 0; i < num_trees - 1; i++) {
            x = (a * x + b) % m;
            y = (c * y + d) % m;
            
            tree.first = x;
            tree.second = y;
            
            bool found = false;
            for (int j = 0; j < trees.size(); j++) {
                //cout << trees[j].first << "," << trees[j].second << endl <<
                //        tree.first << "," << tree.second << endl << endl;
                
                if (trees[j].first == tree.first && 
                    trees[j].second == tree.second) {
                        
                    //cout << "pelation";
                    found = true;
                    break;
                }
            }
            
            if (!found) trees.push_back(tree);
        }
        
        num_trees = trees.size();
        //for (int j = 0; j < num_trees; j++)
        //    cout << trees[j].first << "," << trees[j].second << endl;
        
        int count = 0;
        for (int i = 0; i < num_trees; i++) {
            for (int j = i + 1; j < num_trees; j++) {
                for (int k = j + 1; k < num_trees; k++) {
                    
                    mod = (trees[i].first + trees[j].first + trees[k].first) % 3;
                    if (mod != 0) continue;
                    
                    mod = (trees[i].second + trees[j].second + trees[k].second) % 3;
                    if (mod != 0) continue;
                    
                    count++;
                }
            }
        }
        
        cout << "Case #" << curr_case << ": " << count << endl;
    }
}

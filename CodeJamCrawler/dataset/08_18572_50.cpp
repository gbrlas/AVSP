#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int num_cases;
int num_engines;
int num_queries;
string engine_name;
bool visited[200];
map<string, int> engines;
vector<int> queries;

int find_furthest() {
    int total_visited;
    
    int changes = 0;
    int index = 0;
    
    while (index < queries.size()) {
        total_visited = 0;
        for (int i = 0; i < 200; i++) visited[i] = false;
        
        for (; index < queries.size(); index++) {
            if (!visited[ queries[index] ]) {
                total_visited++;
                visited[ queries[index] ] = true;
            }
            if (total_visited == num_engines) break;
        }
        
        if (total_visited == num_engines) changes++;
    }
    
    return changes;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("out", "w", stdout);
    
    cin >> num_cases;
    for (int num_case = 1; num_case <= num_cases; num_case++) {
        engines.clear();
        queries.clear();
        
        cin >> num_engines;
        getline(cin, engine_name);
        for (int i = 0; i < num_engines; i++) {
            getline(cin, engine_name);
            engines[engine_name] = i;
        }
        
        cin >> num_queries;
        getline(cin, engine_name);
        for (int i = 0; i < num_queries; i++) {
            getline(cin, engine_name);
            queries.push_back(engines[engine_name]);
        }
        
        cout << "Case #" << num_case << ": " << find_furthest() << endl;
    }
}

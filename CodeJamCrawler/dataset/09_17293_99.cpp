#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

using namespace std;

typedef pair<int, int> cell;

int main()
{
    int T;
    cin >> T;

    for(int t = 0 ; t < T ; ++t){
        int H, W;
        cin >> H >> W;

        vector< vector<int> > altitudes(H, vector<int>(W));
        for(int r = 0 ; r < H ; ++r){
            for(int c = 0 ; c < W ; ++c){
                cin >> altitudes[r][c];
            }
        }

        vector< vector<cell> >
            basin(H, vector<cell>(W, make_pair(-1, -1)));

        vector<cell> dirs;
        dirs.push_back( make_pair(-1, 0) );
        dirs.push_back( make_pair(0, -1) );
        dirs.push_back( make_pair(0, 1) );
        dirs.push_back( make_pair(1, 0) );

        for(int r = 0 ; r < H ; ++r){
            for(int c = 0 ; c < W ; ++c){
                int cr = r;
                int cc = c;

                while(1){
                    //cerr << cr << " " << cc << endl;
                    if(basin[cr][cc].first != -1){
                        cell b = basin[cr][cc];
                        cr = b.first;
                        cc = b.second;
                        break;
                    }
                    
                    int cr2 = cr;
                    int cc2 = cc;
                    foreach(cell &d, dirs){
                        int nr = cr + d.first;
                        int nc = cc + d.second;
                        if(0 <= nr && nr < H && 0 <= nc && nc < W){
                            if(altitudes[nr][nc] < altitudes[cr2][cc2]){
                                cr2 = nr;
                                cc2 = nc;
                            }
                        }
                    }
                    if(cr == cr2 && cc == cc2)
                        break;
                    cr = cr2;
                    cc = cc2;
                }

                basin[r][c] = make_pair(cr, cc);

                //cerr << "(" << r << ", " << c << ") -> (" << cr << ", " << cc << ")" << endl;

            }
        }

        map<cell, char> labels;
        char label = 'a';
        cout << "Case #" << t + 1 << ":" << endl;
        for(int r = 0 ; r < H ; ++r){
            for(int c = 0 ; c < W ; ++c){
                map<cell, char>::iterator it = labels.find(basin[r][c]);
                if(it == labels.end()){
                    cout << label;
                    labels[basin[r][c]] = label++;
                }else{
                    cout << it->second;
                }
                if(c != W - 1)
                    cout << ' ';
                else
                    cout << endl;
            }
        }
    }

    return 0;
}


                
                        
        

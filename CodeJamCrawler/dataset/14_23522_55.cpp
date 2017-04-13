#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<vector<char> > &v, int R, int C)
{
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

int main__()
{
    int T, R, C, M, div, rem;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        cin >> R >> C >> M;
        cout << "Case #" << i + 1 << ":" << endl;

        vector<vector<char> >v(R, vector<char>(C, '.'));
        bool good = false;
        if(M == 0) {
            v[0][0] = 'c';
            print_vector(v, R, C);
            continue;
        }

        if(M == R * C - 1) {
            for(int j = 0; j < R; ++j) {
                for(int k = 0; k < C; ++k) {
                    v[j][k] = '*';
                }
            }
            v[0][0] = 'c';
            print_vector(v, R, C);
            continue;
        }

        while(1) {
            //case for R
            div = M / R;
            rem = M % R;
            int tmp1, tmp2;
            if(C - div > 1) {
                bool flag_r = false, flag_c = false;
                //as row
                if((rem == 0 && C - div > 1) || (rem != 0 && C - div - 1 > 1 && R - rem > 1)) {
                    flag_r = true;
                } else {
                    tmp1 = rem / (C - div);
                    tmp2 = rem % (C - div);
                    if(tmp2 == 0 && tmp1 < R - 1) {
                        flag_c = true;
                    } else if(tmp2 && tmp1 < R - 2 && C - tmp2 - div > 1) {
                        flag_c = true;
                    }
                }
                //none of the two method work
                if(!flag_c && !flag_r) {
                    break;
                }
                for(int j = 0; j < R; j++) {
                    for(int k = 0; k < div; ++k) {
                        v[j][k] = '*';
                    }
                }
                if(flag_r == true) {
                    for(int j = 0; j < rem; ++j) {
                        v[j][div] = '*';
                    }
                } else {
                    for(int j = 0; j < tmp1; ++j) {
                        for(int k = div; k < C; ++k) {
                            v[j][k] = '*';
                        }
                    }
                    for(int j = 0; j < tmp2; ++j) {
                        v[tmp1][div + j] = '*';
                    }
                }
                v[R - 1][C - 1] = 'c';
                print_vector(v, R, C);
                good = true;
            }
            break;
        }
        if(good == true) {
            continue;
        }
        while(1) {
            //case for C
            div = M / C;
            rem = M % C;
            if(R - div > 1) {
                bool flag_r = false, flag_c = false;
                int tmp1, tmp2;
                //as col
                if((rem == 0 && R - div > 1) || (rem != 0 && R - div - 1 > 1 && C - rem > 1)) {
                    flag_c = true;
                } else {
                    tmp1 = rem / (R - div);
                    tmp2 = rem % (R - div);
                    if(tmp2 == 0 && tmp1 < C - 1) {
                        flag_r = true;
                    } else if(tmp2 && tmp1 < C - 2 && (R - tmp2 - div > 1)) {
                        flag_r = true;
                    }
                }
                //none of the two method work
                if(!flag_c && !flag_r) {
                    break;
                }

                for(int j = 0; j < div; ++j) {
                    for(int k = 0; k < C; ++k) {
                        v[j][k] = '*';
                    }
                }
                if(flag_c) {
                    for(int j = 0; j < rem ; ++j) {
                        v[div][j] = '*';
                    }
                } else {  
                    for(int j = div; j < R; ++j) {
                        for(int k = 0; k < tmp1; ++k) {
                            v[j][k] = '*';
                        }
                    }
                    for(int j = 0; j < tmp2; ++j) {
                        v[div + j][tmp1] = '*';
                    }
                }
                v[R - 1][C - 1] = 'c';
                print_vector(v, R, C);
                good = true;
            }
            break;
        }
        if(good == true) {
            continue;
        }
        //case for one row or col
        if(R == 1) {
            for(int j = 0; j < M; ++j) {
                v[0][j] = '*';
            }
            v[0][C - 1] = 'c';
            print_vector(v, R, C);
            continue;
        }

        if(C == 1) {
            for(int j = 0; j < M; ++j) {
                v[j][0] = '*';
            }
            v[R - 1][0] = 'c';
            print_vector(v, R, C);
            continue;
        }

        //other condition.
        cout << "Impossible" << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void print_matrix(vector<vector<char> > &m, bool deb = false){
    for (int i = 0; i < m.size(); ++i){
        for (int j = 0; j < m[i].size(); ++j){
            if (deb && (i == 0) && (j == 0)){
                cout<<'c';
            }
            else
                cout<<m[i][j];
        }
        cout<<endl;
    }
}

bool mfind (vector<vector <char> > &mat, int i, int j, char c, bool deb = false){
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    for (int x = 0; x < 8; ++x){
        for (int y = 0; y < 8; ++y){
            if (i+dx[x] >= 0 && i+dx[x] < mat.size() && j+dy[y] >= 0 && j+dy[y] < mat[0].size()) {
                if (mat[i+dx[x]][j+dy[y]]==c)
                    return true;
                if (deb)
                    cout<<mat[i+dx[x]][j+dy[y]]<<endl;
            }
        }
    }
    return false;
}

bool solvable(vector<vector <char> > mat,int r,int c,bool deb = false) {
    bool can = true;
    if (mfind(mat,0,0,'*')){
        return false;
    }
    mat[0][0] = '-';
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if (mat[i][j] == '.'){
                if (mfind(mat,i,j,'-')){
                    if (mfind(mat,i,j,'*')){
                        mat[i][j] = '_';
                    }
                    else {
                        mat[i][j] = '-';
                    }
                }
                if (deb && c-j<3){
                    mfind(mat,i,j,'-',true);
                }
            }
        }
    }
    if (deb) {
        print_matrix(mat);
    }
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if (mat[i][j] == '.') return false;
        }
    }
    return true;
}

bool can (int r, int c, int n) {
    vector<int> v(r*c,1);
    for (int i = 0; i < r*c-n; ++i) {
        v[i] = 0;
    }
    int cant = 0;
    do {
        vector<vector <char> > mat(r);
        for (int i = 0; i < r; ++i){
            mat[i] = vector<char>(c);
            for (int j = 0; j < c; ++j){
                if (v[i*c+j]){
                    mat[i][j] = '*';
                }
                else {
                    mat[i][j] = '.';
                }
            }
        }
//        if (r == 4 && c == 7 && (++cant)<5){            print_matrix(mat);            cout<<"--"<<endl;            solvable(mat,r,c,true);            cout<<"--"<<endl;}
        if (solvable(mat,r,c)){
            print_matrix(mat,true);
            return true;
            break;
        }
    }while(next_permutation(v.begin(),v.end()));
    return false;
}

void solve () {
    int r,c,n;
    cin>>r>>c>>n;
    if (n == r*c-1){
        for (int i = 0; i < r-1; ++i){
            for (int j = 0; j < c; ++j)
                cout<<"*";
            cout<<endl;
        }
        for (int i = 0; i < c-1; ++i){
            cout<<"*";
        }
        cout<<"c"<<endl;
        return;
    }
    if (n == 0){
        for (int i = 0; i < r-1; ++i){
            for (int j = 0; j < c; ++j)
                cout<<".";
            cout<<endl;
        }
        for (int i = 0; i < c-1; ++i){
            cout<<".";
        }
        cout<<"c"<<endl;
        return;
    }
    if (can(r,c,n)){
        
    }
    else {
        cout<<"Impossible"<<endl;
    }
}

int main () {
    int t;
    cin>>t;
    for (int cas = 1; cas <= t; ++cas){
        cout<<"Case #"<<cas<<":"<<endl;
        solve();
    }
}
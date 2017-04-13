#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char check_row(char (*matrix)[4], int row)
{
    char ret = 'O';
    for(int j = 0; j<4; j++){
        if(matrix[row][j] != 'O' && matrix[row][j] != 'T'){
            ret = 0;
            break;
        }
    }

    if(ret != 0)
        return ret;

    ret = 'X';
    for(int j = 0; j<4; j++){
        if(matrix[row][j] != 'X' && matrix[row][j] != 'T'){
            ret = 0;        
            break;
        }
    }
    return ret;
}

char check_col(char (*matrix)[4], int col)
{
    char ret = 'O';
    for(int i = 0; i<4; i++){
        if(matrix[i][col] != 'O' && matrix[i][col] != 'T'){
            ret = 0;
            break;
        }
    }
    if(ret != 0)
        return ret;

    ret = 'X';
    for(int i = 0; i<4; i++){
        if(matrix[i][col] != 'X' && matrix[i][col] != 'T'){
            ret = 0;        
            break;
        }
    }

    return ret;
}

char check_diag(char (*matrix)[4])
{
    char ret = 'O';
    for(int i = 0; i<4; i++){
        if(matrix[i][i] != 'O' && matrix[i][i] != 'T'){
            ret = 0;
            break;
        }
    }
    if(ret != 0)
        return ret;

    ret = 'X';
    for(int i = 0; i<4; i++){
        if(matrix[i][i] != 'X' && matrix[i][i] != 'T'){
            ret = 0;        
            break;
        }
    }

    return ret;
}

char check_diag_2(char (*matrix)[4])
{
    char ret = 'O';
    for(int i = 0; i<4; i++){
        if(matrix[i][3-i] != 'O' && matrix[i][3-i] != 'T'){
            ret = 0;
            break;
        }
    }
    if(ret != 0)
        return ret;

    ret = 'X';
    for(int i = 0; i<4; i++){
        if(matrix[i][3-i] != 'X' && matrix[i][3-i] != 'T'){
            ret = 0;        
            break;
        }
    }

    return ret;
}

char check(char (*matrix)[4])
{
    char ret = 0; 
    for(int row = 0; row<4; row++){
        ret = check_row(matrix, row);
        if(ret != 0)
            return ret;
    }

    for(int col = 0; col<4; col++){
        ret = check_col(matrix, col);
        if(ret != 0)
            return ret;
    }

    ret = check_diag(matrix);
    if(ret != 0)
        return ret;

    ret = check_diag_2(matrix);
    if(ret != 0)
        return ret;

    return ret;
}

bool check_completed(char (*matrix)[4])
{
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
            if(matrix[i][j] == '.')
                return false;
    return true;
}

int main()
{
    int t;
    cin>>t;
    for(int k = 1; k<=t; k++){
        char matrix[4][4];
        for(int i = 0; i<4; i++)
            for(int j = 0; j<4; j++)
                cin>>matrix[i][j];

        char ret = check(matrix);
        if(ret == 'X')
            cout<<"Case #"<<k<<": X won"<<endl;
        if(ret == 'O')
            cout<<"Case #"<<k<<": O won"<<endl;
        if(ret == 0){
            if(check_completed(matrix))
                cout<<"Case #"<<k<<": Draw"<<endl;
            else 
                cout<<"Case #"<<k<<": Game has not completed"<<endl;
        }
    }

    return 0;
}

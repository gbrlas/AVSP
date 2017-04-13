#include <iostream>
#include <fstream>

using namespace std;

string Problem_A(char arr[4][4])
{
    bool not_completed = false;
    for(int i=0; i<4; i++)
    {
        if(arr[i][0] == '.' || arr[i][1] == '.' || arr[i][2] == '.' || arr[i][3] == '.')
        {
            not_completed = true;
        }
        if((arr[i][0] == 'X' || arr[i][0] == 'T') && (arr[i][1] == 'X' || arr[i][1] == 'T') &&
           (arr[i][2] == 'X' || arr[i][2] == 'T') && (arr[i][3] == 'X' || arr[i][3] == 'T'))
        {
            return "X won";
        }
        if((arr[i][0] == 'O' || arr[i][0] == 'T') && (arr[i][1] == 'O' || arr[i][1] == 'T') &&
           (arr[i][2] == 'O' || arr[i][2] == 'T') && (arr[i][3] == 'O' || arr[i][3] == 'T'))
        {
            return "O won";
        }
    }
    for(int i=0; i<4; i++)
    {
        if((arr[0][i] == 'X' || arr[0][i] == 'T') && (arr[1][i] == 'X' || arr[1][i] == 'T') &&
           (arr[2][i] == 'X' || arr[2][i] == 'T') && (arr[3][i] == 'X' || arr[3][i] == 'T'))
        {
            return "X won";
        }
        if((arr[0][i] == 'O' || arr[0][i] == 'T') && (arr[1][i] == 'O' || arr[1][i] == 'T') &&
           (arr[2][i] == 'O' || arr[2][i] == 'T') && (arr[3][i] == 'O' || arr[3][i] == 'T'))
        {
            return "O won";
        }
    }
    // diagonals
    if((arr[0][0] == 'X' || arr[0][0] == 'T') && (arr[1][1] == 'X' || arr[1][1] == 'T') &&
       (arr[2][2] == 'X' || arr[2][2] == 'T') && (arr[3][3] == 'X' || arr[3][3] == 'T'))
    {
        return "X won";
    }
    if((arr[0][3] == 'X' || arr[0][3] == 'T') && (arr[1][2] == 'X' || arr[1][2] == 'T') &&
       (arr[2][1] == 'X' || arr[2][1] == 'T') && (arr[3][0] == 'X' || arr[3][0] == 'T'))
    {
        return "X won";
    }
    if((arr[0][0] == 'O' || arr[0][0] == 'T') && (arr[1][1] == 'O' || arr[1][1] == 'T') &&
       (arr[2][2] == 'O' || arr[2][2] == 'T') && (arr[3][3] == 'O' || arr[3][3] == 'T'))
    {
        return "O won";
    }
    if((arr[0][3] == 'O' || arr[0][3] == 'T') && (arr[1][2] == 'O' || arr[1][2] == 'T') &&
       (arr[2][1] == 'O' || arr[2][1] == 'T') && (arr[3][0] == 'O' || arr[3][0] == 'T'))
    {
        return "O won";
    }
    if(not_completed)
    {
        return "Game has not completed";
    }
    else
    {
        return "Draw";
    }
}

int main()
{
    char arr[4][4];
    int N , numb = 1;
    char c;
    ifstream infile("A-large.in");
    ofstream outfile("A-large.out");
    infile>>N;
    while(N != 0)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                infile>>c;
                arr[i][j] = c;
            }
        }
        outfile << "Case #" << numb << ": " << Problem_A(arr) << endl;
        N--;
        numb++;
    }
    infile.close();
    outfile.close();
    return 0;
}

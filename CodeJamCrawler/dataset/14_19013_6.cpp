#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

void populate_cards(int card[4][4], ifstream &filename, int &number)
{
    for(int i =0; i< 16; i++)
    {
        filename >> number;
        card[0][i] = number;
    }
}

void printArray(int card[4][4])
{
    for(int i=0; i < 4; i++)
    {
        for(int j =0; j <4; j++)
        {
            cout << card[i][j] << " ";
        }
        cout << endl;
    }
}

void getCardInRow(int row[2][4], int card[4][4], int position, int choice)
{
    for(int i=0; i < 4; i++)
    {
        row[choice][i] = card[position-1][i];
    }
}

void randomize(int card[4][4])
{
    int random_row;
    int random_col;

    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {
            random_row = rand()%4;
            random_col = rand()%4;
            std::swap(card[random_row][random_col], card[i][j]);
        }
    }
}
void badMagician(int card[4][4], int card_rows[2][4], int case_num, ofstream& filename)
{
    bool found = false;
    int count = 0;
    int answer;
    for(int i =0; i < 4; i++)
    {
        for(int j=0; j < 4; j++)
        {
            if(card_rows[0][i] == card_rows[1][j])
            {
                found = true;
                count++;
                answer = card_rows[0][i];
            }
        }
    }
    if(found ==false)
    {
        filename << "Case #" << (case_num+1) << ": " <<"Volunteer cheated!" << endl;
    }
    else if(count > 1)
    {
        filename <<  "Case #" << (case_num+1) << ": "<< "Bad magician!" << endl;
    }
    else
    {
        filename<< "Case #" << (case_num+1) << ": " << answer <<endl;
    }
}
int main ()
{
    srand(time(0));
    int test_cases;
    int cards[4][4];
    int card_row[2][4];
    int row1;
    int row2;
    int next;


    ifstream theFile;
    ofstream results;
    theFile.open("A-small-attempt2.txt");
    results.open("Case#1.txt");
    theFile >> test_cases;
    cout << test_cases << endl;
    if(test_cases < 1 || test_cases > 100)
    {
        cerr << "Not a valid test case, must range between 1 and 100" << endl;
        exit(1);
    }

    for(int i=0; i < test_cases; i++)
    {
        //first question asked
        theFile >> row1;
        cout << row1 << endl;

        if(row1 < 1 || row1 > 4)
        {
            cout << "Not a valid row" <<endl;
            exit(1);
        }
        populate_cards(cards, theFile, next);
        printArray(cards);
        getCardInRow(card_row, cards, row1, 0);
        //For second question asked
        theFile >> row2;
        cout << row2 << endl;
        if(row2 < 1 || row2 > 4)
        {
            cout << "Not a valid row" <<endl;
            exit(1);
        }
        populate_cards(cards, theFile, next);
        getCardInRow(card_row, cards, row2, 1);
        printArray(cards);
        badMagician(cards, card_row, i, results);

    }
    return 0;
}

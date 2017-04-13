#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_row(vector<char> board, int prefix, int  win_score){
    int idx = prefix*4;
    if((board[idx] * board[idx+1] * board[idx+2] * board[idx+3])==win_score){
	return true;
    }
    return false;
}

bool check_col(vector<char> board, int prefix, int win_score){
    if((board[prefix] * board[4 + prefix] * board[8+prefix] * board[12+prefix])==win_score){
	return true;
    }
    return false;
}

bool check_dia(vector<char> board, int win_score){
    if(((board[0] * board[5] * board[10] * board[15]) == win_score)||
       ((board[3] * board[6] * board[9] * board[12]) == win_score)){
	return true;
    }
    return false;
}

int answering(vector<char> boardx, vector<char> boardo, int cnt){
    const int x_win = 1;
    const int o_win = 16;
    for(int i=0; i<4; ++i){
	if(check_row(boardx, i, x_win) ||
	   check_col(boardx, i, x_win)){
	    cout << "Case #" << cnt << ": X won" << endl;
	    return 0;
	}
	if(check_row(boardo, i, o_win) ||
	   check_col(boardo, i, o_win)){
	    cout << "Case #" << cnt << ": O won" << endl;
	    return 0;
	}
    }
    if(check_dia(boardx, x_win)){
	cout << "Case #" << cnt << ": X won" << endl;
	return 0;
    }
    if(check_dia(boardo, o_win)){
	cout << "Case #" << cnt << ": O won" << endl;
	return 0;
    }
    //Each player doesn't win.
    int mul = 1;
    for(int i=0; i<16; ++i){
	mul *= boardx[i];
    }
    if(mul == 0){
	cout << "Case #" << cnt << ": Game has not completed" << endl;
    }else{
	cout << "Case #" << cnt << ": Draw" << endl;
    }
}

int main(){
    int cnt_problem = 1;
    int row = 0;
    string line;
    vector<char> board1(16);
    vector<char> board2(16);
    getline(cin,line);
    while(getline(cin,line)){
	if(line.size() == 0){
	    //cnt_problem++;
	    row = 0;
	    /*
	    //check
	    for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
		    cout << board[i*4 + j];
		}
		cout << endl;
	    }
	    cout << endl;
	    */
	    answering(board1,board2,cnt_problem++);
	    continue;
	}
	for(int i=0; i<4; ++i){
	    char c = line.c_str()[i];
	    int idx = row*4 + i;
	    switch(c){
	    case 'T':
		board1[idx] = 1;
		board2[idx] = 2;
		break;
	    case 'X':
		board1[idx] = board2[idx] = 1;
		break;
	    case 'O':
		board1[idx] = board2[idx] = 2;
		break;
	    case '.':
		board1[idx] = board2[idx] = 0;
		break;
	    }
	}
	row++;
    }
    
    return 0;
}

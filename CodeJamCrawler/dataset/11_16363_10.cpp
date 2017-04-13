#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>

//#define __DEBUG

using namespace std;

int count(vector<int> route_O, vector<int> route_B, vector<int> turns)
{
	const int STAY = 0;
	const int MOVE = 1;
	const int PUSH = 2;

	const int TURN_O = 0;
	const int TURN_B = 1;

	int state_O;
	int state_B;
	int current_turn;	// どっちのターンか 0/1

	int clock = 0;
	int pos_O = 1;
	int pos_B = 1;

	int turn_num = 0;
	int dest_O = 0;
	int dest_B = 0;

	bool finish_O = false;
	bool finish_B = false;

	// initialize state
	current_turn = turns[turn_num];
	if(route_O.size() > 0)
		state_O = (route_O[dest_O] == pos_O)? STAY: MOVE;
	else
		state_O = STAY;
	if(route_B.size() > 0)
		state_B = (route_B[dest_B] == pos_B)? STAY: MOVE;
	else
		state_B = STAY;

	for(; turn_num < turns.size(); ++clock){
#ifdef __DEBUG
		cout << "pos_O:\t\t" << pos_O << endl;
		cout << "state_O:\t" << state_O << endl;
		cout << "dest_O:\t\t" << dest_O << endl;
		cout << "pos_B:\t\t" << pos_B << endl;
		cout << "state_B:\t" << state_B << endl;
		cout << "dest_B:\t\t" << dest_B << endl;
		cout << "turn:\t\t" << turns[turn_num] << endl;
#endif

		// Oの状態を更新
		if(route_O.size() == 0)
		;
		else if(route_O[dest_O] > pos_O){
			++pos_O;
			state_O = MOVE;
		}
		else if(route_O[dest_O] < pos_O){
			--pos_O;
			state_O = MOVE;
		}
		else if(route_O[dest_O] == pos_O){
			state_O = STAY;
		}

		// Bの状態を更新
		if(route_B.size() == 0)
		;
		if(route_B[dest_B] > pos_B){
			++pos_B;
			state_B = MOVE;
		}
		else if(route_B[dest_B] < pos_B){
			--pos_B;
			state_B = MOVE;
		}
		else if(route_B[dest_B] == pos_B){
			state_B = STAY;
		}
	
		// 順番の入れ替え
		// 方向転換
		// 状態をPUSHへ
		if(current_turn == TURN_O){
			if(state_O == STAY){
				current_turn = turns[++turn_num];
				++dest_O;
				state_O = PUSH;
			}
			else if(state_O == PUSH){
				if(pos_O == route_O[++dest_O])
					state_O = STAY;
				else
					state_O = MOVE;
			}
		}
		else if(current_turn == TURN_B){
			if(state_B == STAY){
				current_turn = turns[++turn_num];
				++dest_B;
				state_B = PUSH;
			}
			else if(state_B == PUSH){
				if(pos_B == route_B[++dest_B])
					state_B = STAY;
				else
					state_B = MOVE;
			}
		}
	}

	return clock;
}

vector<int> solve(int N, vector<int> problems)
{
	vector<int> ret;
	int pos = 0;

	const int TURN_O = 0;
	const int TURN_B = 1;

#ifdef __DEBUG
	int cnt = 0;
#endif

	for(int line = 0; line < N; ++line){
		vector<int> route_O;
		vector<int> route_B;
		vector<int> turns;

		int n = problems[pos];
		for(int i = 0; i < n; ++i){
			turns.push_back(problems[++pos]);
			switch(problems[pos]){
			case TURN_O:
				route_O.push_back(problems[++pos]);
				break;
			case TURN_B:
				route_B.push_back(problems[++pos]);
				break;
			default:
				cout << "invalid data" << endl;
				exit(1);
			}
		}

		ret.push_back(count(route_O, route_B, turns));

		++pos;
#ifdef __DEBUG
		cout << ++cnt << "\tstart" << endl;
		cout << "route_O: " << endl;
		for(int i = 0; i < route_O.size(); ++i)
			cout << route_O[i] << " ";
		cout << endl;

		cout << "route_B: " << endl;
		for(int i = 0; i < route_B.size(); ++i)
			cout << route_B[i] << " ";
		cout << endl;

		cout << "turns: " << endl;
		for(int i = 0; i < turns.size(); ++i)
			cout << turns[i] << " ";
		cout << endl;
		cout << "end" << endl;
#endif
	}

	return ret;
}

vector<int> solve3(int N, vector<int> problems)
{
	vector<int> ret;
	const int O = 0;
	const int B = 1;
	const int start = 1;
	for(int cnt = 0, i = 0; cnt < N; ++cnt){
		vector<int> o_move;
		vector<int> b_move;
		int num = problems[i];	// 問題1個の数
		++i;
		int moved_o = 0, moved_b = 0;
		for(; num > 0; --num){
			switch(problems[i]){
				case O:
					o_move.push_back(problems[++i]);
					break;
				case B:
					b_move.push_back(problems[++i]);
					break;
				default:
					cout << "invalid data" << endl;
					exit(0);
			}
			++i;
		}
	}
	return ret;
}

vector<int> solve4(int N, vector<int> problems)
{
	vector<int> ret;
	const int O = 0;
	const int B = 1;
	bool firstO = true, firstB = true;
	for(int cnt = 0, i = 0; cnt < N; ++cnt){
		vector<int> o_move;
		vector<int> b_move;
		int num = problems[i];
		bool startO_1 = false;
		bool startB_1 = false;
		++i;
		for(; num > 0; --num){
			switch(problems[i]){
				case O:
					o_move.push_back(problems[++i]);
					if(firstO && (problems[i] == 1)){
						startO_1 = true;
						firstO = false;
					}						
					break;
				case B:
					b_move.push_back(problems[++i]);
					if(firstB && (problems[i] == 1)){
						startB_1 = true;
						firstB = false;
					}						
					break;
				default:
					cout << "invalid data" << endl;
					exit(0);
			}
			++i;
		}

		int costA = 0, costB = 0;
		for(int i = 0; i < o_move.size(); ++i)
			costA+=o_move[i];
		for(int i = 0; i < b_move.size(); ++i)
			costB+=b_move[i];

		if(costA==0){
			ret.push_back((startB_1)?costB:costB+1);
		}
		else if(costB==0){
			ret.push_back((startO_1)?costA:costA+1);
		}
		else
			ret.push_back((costA > costB) ? costA : costB);

	}
	return ret;
}

vector<int> solve2(int N, vector<int> problems)
{
	vector<int> out;
	const int O = 0;
	const int B = 1;
	const int start_o = 1;
	const int start_b = 1;
	bool firststep = true;
	for(int cnt = 0, i = 0; cnt < N; ++cnt){
		int cost = 0;
		int num = problems[i];
		++i;

#ifdef __DEBUG
		cout << "num: " << num << endl;
#endif

		// main
		int before_o = 0, before_b = 0;
		int moved_o = 0, moved_b = 0;
		int last_move;
		bool first_step = true;
		bool o_moved = false, b_moved = false;
		for(; num > 0; --num){
#ifdef __DEBUG
			cout << "problems[" << i << "]: " << problems[i] << endl;
#endif
			switch(problems[i]){
			case O:
				moved_o = problems[++i] - moved_o + 1 - (first_step ? start_o : 0);
				o_moved = true;
				break;
			case B:
				moved_b = problems[++i] - moved_b + 1 - (first_step ? start_b : 0);
				b_moved = true;
				break;
			default:
				cout << "invalid data" << endl;
				exit(0);
			}
			last_move = problems[i-1];
			first_step = false;
			++i;

#ifdef __DEBUG
			cout << "last move: " << last_move << endl;
			if(num > 1)
				cout << "next move: " << problems[i+2] << endl;
			else
				cout << "next move: " << -1 << endl;
#endif
			if((num != 0) && (last_move == problems[i+2]))
				continue;

			if((o_moved && b_moved) || ((num == 1) && (o_moved || b_moved))){
				if(moved_o > moved_b){
					cost += abs(moved_o);
				}
				else{
					cost += abs(moved_b);
				}
				o_moved = b_moved = false;
			}
		}
		// per problem
		out.push_back(cost);
	}
	return out;
}

int main(int argc, char* argv[])
{
	if(argc != 2){
		cout << *argv << " <filename>" << endl;
		exit(1);
	}

	int N;
	vector<int> problems;

	FILE* fp;
	fp = fopen(*(argv+1), "r");
	rewind(fp);
	fscanf(fp, "%d\n", &N);
	while(!feof(fp)){
		char buf[0xff];
		fscanf(fp, "%s", buf);
		if(buf[0] == 'O')
			problems.push_back(0);
		else if(buf[0] == 'B')
			problems.push_back(1);
		else
			problems.push_back(atoi(buf));
	}
	fclose(fp);

	vector<int> out = solve(N, problems);

#ifdef __DEBUG
	for(int i = 0; i < problems.size(); ++i)
		cout << problems[i] << endl;
#endif

	char* filename = new char[strlen(*(argv+1))+4];
	sprintf(filename, "%s.out", *(argv+1));
	fp = fopen(filename, "w");
	for(int n = 0; n < out.size(); ++n)
		fprintf(fp, "Case #%d: %d\n", n+1, out[n]);
	delete [] filename;
	fclose(fp);

	exit(0);
}

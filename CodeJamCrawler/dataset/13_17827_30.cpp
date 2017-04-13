//============================================================================
// Name        : file.cpp
// Author      : nabil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


ifstream myinfile;
ofstream myoutfile;

/*
struct char_arr_2d{
	char a [4][4];
};
*/

char global_test_case[5][5];

int  getTestCase();
int checkTestCase();
void checkEntry(char a[]);
void output(int result, int test_num);



int x_won=0;
int y_won=0;
int dot_found=0;//free cell found


int test_c_num=0;
int main() {
	myinfile.open("A-large.in");//read from
	myoutfile.open ("A-large.out");//write to

	string line;
	int t_c_count;

	//set the end of the strings
	for(int l=0;l<4;l++){
		global_test_case[4][l]='\0';
		global_test_case[l][4]='\0';
	}
	if (myinfile.is_open()){

		//get the first line (# of test cases)
		getline (myinfile,line);
		t_c_count=atoi(line.c_str());
		cout<<t_c_count<<endl;
		//loop on all tests]
		for(int i=0;i<t_c_count;i++){
			//filled_cells=0; //to know finished drawn or not
			output(getTestCase(),i+1);
			test_c_num=i;
			//get the line between each 2 t_c's
			getline (myinfile,line);
		}

		myoutfile.close();
		myinfile.close();
		}
		cout << "Done";

	return 0;
}

int getTestCase(){

	//reading from file

	string line;

	for(int i=0;i<4;i++){
		string s;
		//getline (myinfile,line)>>s;
		getline (myinfile,s);
		cout<<s<<endl;
		//convert string to char array
		for (int k=0;k<4;k++){
			global_test_case[i][k]=s[k];
		}
	}
	cout<<endl;
//	char_arr_2d test_case_struct;
/*
	//copy 2d arr to struct
	for(int i;i<4;i++)
		for(int j;j<4;j++)
			test_case_struct.a[i][j]=test_case[i][j];
*/

	//global_test_case
	return checkTestCase();

}



////global filled cells needed to know if finished

void checkEntry(char a[] ){
	int x_count=0;
	int y_count=0;
	int empty_count=0;
	for(int i=0;i<4;i++){
		if(a[i]=='X'||a[i]=='T')
			x_count++;
		if(a[i]=='O'||a[i]=='T')
			y_count++;
		if(a[i]=='.')
			empty_count++;
	}
	if(x_count==4)
		x_won=1;
	else if(y_count==4)
		y_won=1;
	else if(empty_count>0)
		dot_found=1;

	cout<<"////////"<<endl;
	string s(a);
	cout<<"flags of test"<<test_c_num<<"Entry:"<<s<<endl;

	cout<<"x_won="<<x_won<<endl;
	cout<<"o_won="<<y_count<<endl;
	cout<<"o_won="<<y_won<<endl;
	cout<<"dot found="<<dot_found<<endl;




}

int checkTestCase(){

	/*
		 * d1-make additional 2 diagonal 4 arrays
		 * d2-make function to check each entry
		 * d3-call it for each col
		 * 4-call it for each row
		 * 5-call it for each diag
		 * 6-check global flags to return results
		 * */


	x_won=0;
	y_won=0;
	dot_found=0;

	int result=0; //what is the best init?
	//check procedure

	//create diags
	char diags[2][5];
	diags[0][4]='\0';
	diags[1][4]='\0';
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
				if(i==j)
					diags[0][i]=global_test_case[i][j];//fill in 1st diag
				if(j==(3-i))//(i==((j+3)%3))
					diags[1][i]=global_test_case[i][j];//fill in 2nd diag

			}

	}



	string ss22(diags[0]);
		cout<<"diag "<<test_c_num<<",0"<<": "<<ss22<<endl;

		string ss21(diags[1]);
				cout<<"diag "<<test_c_num<<",1"<<": "<<ss21<<endl;


	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	string ss0(global_test_case[0]);
	cout<<"test "<<test_c_num<<": "<<ss0<<endl;

	string ss1(global_test_case[1]);
	cout<<"test "<<test_c_num<<": "<<ss1<<endl;
	string ss2(global_test_case[2]);
	cout<<"test "<<test_c_num<<": "<<ss2<<endl;
	string ss3(global_test_case[3]);
	cout<<"test "<<test_c_num<<": "<<ss3<<endl;
	//check rows
	for (int i=0;i<4;i++){
		checkEntry(global_test_case[i]);
	}

	//check cols
	for (int j=0;j<4;j++){
		char col[]={global_test_case[0][j],global_test_case[1][j],global_test_case[2][j],global_test_case[3][j],'\0'};
		checkEntry(col);

	}

	//check daigs
	for(int d=0;d<2;d++){
		checkEntry(diags[d]);


	}


	//checking global flags:
	if(x_won==1)
		result=0;   	//0: "X won" (the game is over, and X won)
	else if (y_won==1)
		result=1;		//1: "O won" (the game is over, and O won)
	else if (dot_found!=1)
		result=2;		//2: "Draw" (the game is over, and it ended in a draw)
	else
		result=3;		//3: "Game has not completed" (the game is not over yet)




	return result;
}

void output(int result,int test_num){
	switch (result){
	//Case #1: X won
	case 0:
		myoutfile <<"Case #"<<test_num<<": "<<"X won\n";
		break;
	case 1:
		myoutfile <<"Case #"<<test_num<<": "<<"O won\n";
			break;
	case 2:
		myoutfile <<"Case #"<<test_num<<": "<<"Draw\n";
			break;
	case 3:
		myoutfile <<"Case #"<<test_num<<": "<<"Game has not completed\n";
			break;
	}
	//writing to file finished


}

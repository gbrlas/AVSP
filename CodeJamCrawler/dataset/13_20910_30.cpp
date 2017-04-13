#include <iostream>
#include <fstream>
using namespace std;
#define L 4
int main(){
	ifstream myfile;
	myfile.open("input.txt");
	int N;
	myfile>>N;
	char M[L][L];
	bool over=false;
	freopen("output.txt","w",stdout);
	for(int k=0;k<N;k++){
		cout<<"Case #"<<k+1<<": ";
		for(int i=0;i<L;i++){
			for(int j=0;j<L;j++){
				myfile>>M[i][j];
//				cout<<M[i][j];
			}
//			cout<<endl;
		}
//		cout<<endl;
	
		char C='T';
		int count=0;
		over=false;
		//row
		for(int i=0;i<L;i++){
			C='T';
			count=0;
			for(int j=0;j<L;j++){
				char T=M[i][j];
//				cout<<C<<"?="<<T<<"\t";
				if((C==T || C=='T'||T=='T')&& T!='.'){
					count++;
//					cout<<T<<count;
					if(T!='T')
						C=T;
				}
				else{
					count=0;
				}
//				cout<<endl;
			}
			if(count==4){
				over=true;
				break;
			}
		}
		if(over && C=='X'){
//			cout<<"Over==true"<<count<<endl;
			cout<<"X won"<<endl;
			continue;
		}
		else if(over && C=='O'){
			cout<<"O won"<<endl;
			continue;
		}

		//column
		over=false;
		for(int i=0;i<L;i++){
			C='T';
			count=0;
			for(int j=0;j<L;j++){
				char T=M[j][i];
//				cout<<C<<"?="<<T<<"\t";
				if((C==T || C=='T'||T=='T')&& T!='.'){
					count++;
//					cout<<T<<count;
					if(T!='T')
						C=T;
				}
				else{
					count=0;
				}
//				cout<<endl;
			}
			if(count==4){
				over=true;
				break;
			}
		}
		if(over && C=='X'){
			cout<<"X won"<<endl;
			continue;
		}
		else if(over && C=='O'){
			cout<<"O won"<<endl;
			continue;
		}
		//diag1
		over=false;
		C='T';
		count=0;
		for(int j=0;j<L;j++){
			char T=M[j][L-j-1];
//			cout<<C<<"?="<<T<<"\t";
			if((C==T || C=='T'||T=='T')&& T!='.'){
				count++;
//				cout<<T<<count;
				if(T!='T')
					C=T;
			}
			else{
				count=0;
			}
//			cout<<endl;
		}
		if(count==4){
			over=true;
		}
		if(over && C=='X'){
			cout<<"X won"<<endl;
			continue;
		}
		else if(over && C=='O'){
			cout<<"O won"<<endl;
			continue;
		}
		//diag2
		C='T';
		count=0;
		over=false;
		for(int j=0;j<L;j++){
			char T=M[j][j];
//			cout<<C<<"?="<<T<<"\t";
			if((C==T || C=='T'||T=='T')&& T!='.'){
				count++;
//				cout<<T<<count;
				if(T!='T')
					C=T;
			}
			else{
				count=0;
			}
//			cout<<endl;
		}
		if(count==4){
			over=true;
		}
		if(over && C=='X'){
			cout<<"X won"<<endl;
			continue;
		}
		else if(over && C=='O'){
			cout<<"O won"<<endl;
			continue;
		}
		//to judge if end of game.
		over=true;
		for(int i=0;i<L;i++){
			for(int j=0;j<L;j++){
				if(M[i][j]=='.')
					over=false;
			}
		}
		if(over)
			cout<<"Draw"<<endl;
		else
			cout<<"Game has not completed"<<endl;
	}
	myfile.close();
	
	return 0;
}
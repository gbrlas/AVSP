#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
    ifstream fin;
    ofstream fout;
    fin.open("C:\\Documents and Settings\\VIBHAJ RAJAN\\Desktop\\test.txt");
    fout.open("C:\\Documents and Settings\\VIBHAJ RAJAN\\Desktop\\out1.txt");
    int ln,dw,nt;
    fin>>ln>>dw>>nt;
    cout<<ln<<"\t"<<dw<<"\t"<<nt<<endl;
    string words[dw];
    for(int i=0;i<dw;i++){
    fin>>words[i];
    cout<<words[i]<<endl;
    }
    int count=0;
    int number=0;
	string expr;
	int j=0;
	bool isit=true;
	bool isany = false;

    while(count++<nt){
	    number=0;
	     vector<char> partstr[ln];
	 	fin>>expr;
	 	cout<<expr<<endl;
	 	char *str=const_cast<char *>(expr.c_str());
	 	cout<<str<<endl;
	 	j=0;
	 	for(char *p=str;(*p)!='\0';p++){
		 		//cout<<"OK"<<endl;
			 	switch(*p){
				 	case '(':{
					 	while(*(++p)!=')'){
						 	partstr[j].push_back(*p);
					 	}
					 	j++;
					 	break;}

					default: {
						partstr[j].push_back(*p);
						j++;
					}

			 	}

		 	}
		 for(int i=0;i<ln;i++){
				for(int j=0;j<partstr[i].size();j++)
				cout<<partstr[i][j];
				cout<<endl;
		 }
		 cout<<endl;


		 for(int i=0;i<dw;i++){
			 isit=true;


			const char *word=(words[i].c_str());
			for(int j=0;j<ln;j++){
				isany=false;
				for(int k=0;k<partstr[j].size();k++){
						cout<<word[j]<<"\t"<<partstr[j][k]<<endl;
						if(word[j]==partstr[j][k]){
							cout<<"OK\n";
							isany = true;
							break;
						}
				}
				if(isany==false){
					cout<<"NOT OK\n";
				isit=false;
				break;}
			}
			if(isit)
			number++;
			cout<<number<<endl;
		 }
		cout<<count<<"\t"<<number<<endl;
		fout<<"Case #"<<count<<": "<<number<<endl;
	 	}
	 	cout<<endl;


}


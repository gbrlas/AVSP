#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

typedef long long int64;
typedef vector< int > vi;
typedef vector< string >::iterator vis;
typedef vector<string> vs;
typedef vector<double> vd;
int complete=0;

void match_pattern(string);

vector<string> results;

int main()
{
	string temp,tempX,tempO;
	char buff[10];
	string cross_1="", cross_2="";
	string col_1="",col_2="",col_3="",col_4="";
	int num_test_cases=0,intI=0,intJ=0,intK=0;
	bool found_empty=false;
	vector< string> matrix;
	vector< vector<string> > transpose_matrix;
	vis s;
	
	string filename="A-small-attempt0.in",filename_write="small.out";
	freopen(filename.data(), "r",stdin);
	freopen(filename_write.data(), "w",stdout);

	fgets(buff,sizeof (buff),stdin);
//	getline(cin,temp);
	temp=string(buff);
	num_test_cases=atoi(temp.c_str());
	
	for(intI=0;intI<num_test_cases;intI++)
	{
		cross_1="";
		cross_2="";
		complete=0;
		col_1="";col_2="";col_3="";col_4="";
		matrix.clear();
		found_empty=false;

		for(intJ=0;intJ<4;intJ++)
		{
			//getline(cin,temp);
			fgets(buff,sizeof (buff),stdin);
			//	getline(cin,temp);
			temp=string(buff);
			matrix.push_back(temp);
		}

		for(s=matrix.begin(),intJ=0;s!=matrix.end();s++,intJ++)
		{
			if((*s).find(".")!=std::string::npos)
				found_empty=true;
			if(complete==0)
			{
						col_1.push_back((*s)[0]);
						col_2.push_back((*s)[1]);
						col_3.push_back((*s)[2]);
						col_4.push_back((*s)[3]);


					if(intJ==0)
						{
						cross_1.push_back((*s)[0]);
						cross_2.push_back((*s)[3]);
						}
					else if(intJ==1)
						{
						cross_1.push_back((*s)[1]);
						cross_2.push_back((*s)[2]);
						}
					else if(intJ==2)
						{
						cross_1.push_back((*s)[2]);
						cross_2.push_back((*s)[1]);
						}
					else if(intJ==3)
						{
						cross_1.push_back((*s)[3]);
						cross_2.push_back((*s)[0]);
						}
					match_pattern((*s));			
			}
			else if(complete==1)
				break;
		}

		if(complete==0)
		{
				if(complete==0)
					match_pattern(cross_1);
				if(complete==0)
					match_pattern(cross_2);
				if(complete==0)
					match_pattern(col_1);
				if(complete==0)
					match_pattern(col_2);
				if(complete==0)
					match_pattern(col_3);
				if(complete==0)
					match_pattern(col_4);
				if(complete==0)
					{
						if(found_empty)
						{
							//cout<<"Game has not completed";
							results.push_back("Game has not completed");
						}
						else
						{
							//cout<<"Draw";
							results.push_back("Draw");
						}
					}
		}
		//getline(cin,temp);			
		fgets(buff,sizeof (buff),stdin);
	//	temp=string(buff);
	}

	for(s=results.begin(),intI=1;s!=results.end();s++,intI++)
	{
		cout<<"Case #"<<intI<<": "<<*s<<endl;
		//stdout<<"Case #"<<intI<<": "<<*s<<endl;
		
	}
	 
	return(100);
}

void match_pattern(string str)
{
	string tempX=str;
	string tempO=str;
	string x="XXXX\n";
	string o="OOOO\n";
	string x1="XXXX";
	string o1="OOOO";
	
	replace(tempX.begin(), tempX.end(), 'T', 'X');
	replace(tempO.begin(), tempO.end(), 'T', 'O');
	
	if(str.compare(o)==0 || tempO.compare(o)==0 || str.compare(o1)==0 || tempO.compare(o1)==0)
	{
	//	cout<<"O wins";
		results.push_back("O won");
		complete=1;
	}
	else if (str.compare(x)==0 || tempX.compare(x)==0 || str.compare(x1)==0 || tempX.compare(x1)==0) //if(str.compare("XXXX")==0 || tempX.compare("XXXX")==0)
	{
		//cout<<"X wins";
		results.push_back("X won");
		complete=1;
	}
}

/*
tempX=temp;
			tempO=temp;
			replace(tempX.begin(), tempX.end(), 'T', 'X');
			replace(tempO.begin(), tempO.end(), 'T', 'O');
			if(temp=="XXXX"){
				cout<<"X won";}
			else if(temp=="OOOO"){
				cout<<"O Won";}
			else if(tempX=="XXXX"){
				cout<<"X won";}
			else if(tempO=="OOOO"){
				cout<<"O won";}
*/
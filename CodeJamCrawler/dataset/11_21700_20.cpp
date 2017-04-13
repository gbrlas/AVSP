#include <iostream>
#include <fstream>
#include <string>
#define debug_
using namespace std;
int main()
{
	ifstream infile;
	infile.open("A-small-attempt1.in");//open input
	ofstream outfile;
	outfile.open("test.txt");
	int numCase=0;
	int posO,posB;
	int targetO,targetB;
	int opO,opB;
	int waitForPush=0;
	//int idxO=0,idxB=0;
	if(infile.is_open())
	{
		string s_;
		getline(infile,s_);
		numCase=atoi(s_.c_str());
		for(int i=0;i<numCase;i++)
		{//calculate each case here
			outfile<<"Case #"<<(i+1)<<": ";
			posO=1;
			posB=1;
	targetO=0;targetB=0;
	opO=0;opB=0;
			//init ok
			getline(infile,s_);
#ifdef debug_
			cout<<"s_="<<s_<<endl;
#endif
			//init idx
			int endO=0,endB=0;
			int idxO_=s_.find('O');
			opO=idxO_;
			int idxO_2;
			if(idxO_>=0)
			{
				idxO_2=s_.find(' ',idxO_+2);
				if(idxO_>0)
					targetO=atoi(s_.substr(idxO_+2,idxO_2-1-idxO_).c_str());
				else
				{
					targetO=atoi(s_.substr(idxO_+2,s_.length()-idxO_-2).c_str());
					endO=1;
				}
				idxO_=idxO_2;
			}
			else if(idxO_<0)
			{
				endO=1;
			}
			int idxB_=s_.find('B');
			opB=idxB_;
			int idxB_2;
			if (idxB_>=0)
			{
				idxB_2=s_.find(' ',idxB_+2);
				if(idxB_>0)
					targetB=atoi(s_.substr(idxB_+2,idxB_2-1-idxB_).c_str());
				else
				{
					targetB=atoi(s_.substr(idxB_+2,s_.length()-idxB_-2).c_str());
					endB=1;
				}
				idxB_=idxB_2;
			}
			else if(idxB_<0)
			{
				endB=1;
			}
			int clock=0; 
			waitForPush=0;
			while((!endO||!endB))
			{
				int pushed=0;
				//process B
				if(!endB)
				{
					if(posB>targetB)
					{
						posB--;
					}
					else if(posB<targetB)
					{
						posB++;
					}
					else if((opB<opO)||(opO<0))//go push and next
					{
						waitForPush=waitForPush|1;
						if(pushed==0)
						{//push to next
							idxB_=s_.find('B',idxB_2);
							opB=idxB_;
							if(idxB_>0)
							{
								idxB_2=s_.find(' ',idxB_+2);
								if(idxB_2>0)
								{
									targetB=atoi(s_.substr(idxB_+2,idxB_2-1-idxB_).c_str());
								}
								else
								{
									targetB=atoi(s_.substr(idxB_+2,s_.length()-idxB_-2).c_str());
								}
								idxB_=idxB_2;
							}
							else
								endB=1;
							pushed=1;						
							cout<<"why="<<waitForPush<<endl;
							waitForPush=waitForPush&2;
							cout<<"B pushed"<<endl;
						}
					}
				}
				//process O
				if(!endO)
				{
					if(posO>targetO)
					{
						posO--;
					}
					else if(posO<targetO)
					{
						posO++;
					}
					else if(((opO<opB)||(opB<0))&&!endO)//go push and next
					{
						waitForPush=waitForPush|2;
						if(pushed==0)
						{//push to next
							idxO_=s_.find('O',idxO_2);
							opO=idxO_;
							if(idxO_>0)
							{
								idxO_2=s_.find(' ',idxO_+2);
								if(idxO_2>0)
								{
									targetO=atoi(s_.substr(idxO_+2,idxO_2-1-idxO_).c_str());
								}
								else
								{
									targetO=atoi(s_.substr(idxO_+2,s_.length()-idxO_-2).c_str());
								}
								idxO_=idxO_2;
							}
							else
								endO=1;
							pushed=1;
							cout<<"why="<<waitForPush<<endl;
							waitForPush=waitForPush&1;
							cout<<"O pushed"<<endl;
						}
					}
				}
				clock++;
				//cout<<"pos=["<<posB<<","<<posO<<"]"<<endl;
				//cout<<"tar=["<<targetB<<","<<targetO<<"]"<<endl;
				//cout<<"end=["<<endB<<","<<endO<<"]"<<endl;
				//cout<<"waitforPush="<<waitForPush<<endl;
				//cout<<"clock="<<clock<<endl;
				//cout<<"-----------"<<endl;
			}
			cout<<clock<<endl;
			outfile<<clock<<endl;
		}
	}
	outfile.close();
	infile.close();
	return 0;
}

#include<iostream>
#include<list>
using namespace std;

int a[102];
int b[102];

int main()
{
	int t;
	cin>>t;
	int cases=1;
	while(t>0)
	{
		int n;
		cin>>n;
		int posA=1,posB=1;
		int tot = 0;
		int prevTotalA = 0,prevTotalB=0;
		for(int i=0;i<n;i++){
			int pos;
			char bot;
			cin>>bot>>pos;
			//cout<<bot<<" posA is "<<posA<<" pos B is "<<posB<<" "<<tot<<" "<<prevTotalA<<" "<<prevTotalB<<endl;
			if(bot=='O')
			{
		//		if(tot-prevTotalA>abs(pos-posA))
		//		{
		//			prevTotalA+=abs(pos-posA)+1;
		//			posA=pos;
		//			continue;
		//		}
		//		else
//				{
				    int elapsedTime = tot-prevTotalA;
					//cout<<elapsedTime<<endl;
					if(pos>=posA)
					{
						if(posA+elapsedTime>=pos)
							posA=pos;
						else
							posA+=elapsedTime;
					}
					else
					{
						if(posA-elapsedTime<=pos)
							posA=pos;
						else
							posA-=elapsedTime;

					}
					tot+=abs(posA-pos)+1;
					prevTotalA = tot;
					posA=pos;
		//		}
			}
			else if(bot=='B')
			{
		//		if(tot-prevTotalB>abs(pos-posB))
		//		{
		//			prevTotalB+=abs(pos-posB)+1;
		//			posB=pos;
		//			continue;
		//		}
		//		else
		//		{
					int elapsedTime = tot-prevTotalB;
					//cout<<elapsedTime<<endl;
                    if(pos>=posB)
					                    {
										                        if(posB+elapsedTime>=pos)
																                            posB=pos;
																							                        else
																													                            posB+=elapsedTime;
																																				                    }
																																									                    else
																																														                    {
																																																			                        if(posB-elapsedTime<=pos)
																																																									                            posB=pos;
																																																																                        else
																																																																						                            posB-=elapsedTime;

																																																																													                    }   
					tot+=abs(posB-pos)+1;
					prevTotalB = tot;
					posB=pos;
				}
		//	}
		}
		cout<<"Case #"<<cases++<<":"<<" "<<tot<<endl;
		t--;
	}
	return 0;
}

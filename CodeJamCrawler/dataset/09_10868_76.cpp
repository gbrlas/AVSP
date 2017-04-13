#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <stack>

using namespace std;




class position
{
public:
	int x;
	int y;

};


int main(int argc, char* argv[])
{

	int t=0,h=0,w=0;
	int l=0;
	int i=0,j=0,i1=0,j1=0;

	int *map;
	char *map_shadow;

	bool sink=true;


	char index_c='a'-1,index_c_temp;


	const int max=10001;//because 1 ¡Ü H, W ¡Ü 100



	position p_temp,p_n,p_w,p_e,p_s,p_min;
	


	stack<position> stack_temp;





	ifstream infile;
	ofstream outfile;


	infile.open("B-large.in");
	assert(infile);

	outfile.open("B-large-result.txt");
	assert(outfile);







	infile>>t;
	


	for(i=1;i<=t;++i)
	{



		infile>>h>>w;
		


		l=(h+2)*(w+2);
		map = new int[l];
		map_shadow = new char[l];


		for(j=0;j<l;++j)
		{
			map[j] = max;
			map_shadow[j] = '\n';

		}

		for(j1=1;j1<=h;++j1)
		{
			for(i1=1;i1<=w;++i1)
			{
				infile>>map[(j1)*(w+2)+i1];



			}



		}






		for(j1=1;j1<=h;++j1)
		{

			for(i1=1;i1<=w;++i1)
			{

				p_temp.x = i1;
				p_temp.y = j1;




loop1:		index_c_temp = map_shadow[(p_temp.y)*(w+2)+p_temp.x];

				if( index_c_temp == '\n' )
				{


					p_n.x = p_temp.x;
					p_n.y = p_temp.y-1;

					p_w.x = p_temp.x-1;
					p_w.y = p_temp.y;

					p_e.x = p_temp.x+1;
					p_e.y = p_temp.y;

					p_s.x = p_temp.x;
					p_s.y = p_temp.y+1;

					p_min.x = p_n.x;
					p_min.y = p_n.y;



					if(    map[ (p_min.y)*(w+2) + p_min.x  ] > map[ (p_w.y)*(w+2) + p_w.x  ]     )
					{
						p_min.x = p_w.x;
						p_min.y = p_w.y;

					}


					if(    map[ (p_min.y)*(w+2) + p_min.x  ] > map[ (p_e.y)*(w+2) + p_e.x  ]     )
					{
						p_min.x = p_e.x;
						p_min.y = p_e.y;
					}


					if(    map[ (p_min.y)*(w+2) + p_min.x  ] > map[ (p_s.y)*(w+2) + p_s.x  ]     )
					{
						p_min.x = p_s.x;
						p_min.y = p_s.y;
					}








					if(    map[ (p_temp.y)*(w+2) + p_temp.x  ] > map[ (p_min.y)*(w+2) + p_min.x  ]     )
					{
						sink = false;
						stack_temp.push(p_temp);

						p_temp.x = p_min.x;
						p_temp.y = p_min.y;

						goto loop1;


					}
					else
					{
						sink = true;

						map_shadow[(p_temp.y)*(w+2) + p_temp.x] = (++index_c);

						goto loop1;



					}





				}
				else
				{
					while( stack_temp.empty() != true )
					{

						p_temp = stack_temp.top();
						stack_temp.pop();
						map_shadow[(p_temp.y)*(w+2) + p_temp.x] = index_c_temp;
					}




				}





			}





		}



		outfile<<"Case #"<<i<<":"<<endl;


		for(j1=1;j1<=h;++j1)
		{
			for(i1=1;i1<=w;++i1)
			{
				outfile<<map_shadow[(j1)*(w+2) + i1]<<" ";


			}

			outfile<<endl;




		}


		index_c='a'-1;


		delete []map;
		delete []map_shadow;






	}




	infile.close();
	outfile.close();





	return 0;





}
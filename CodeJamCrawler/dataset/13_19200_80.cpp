#include<iostream> 
using namespace std; 


int main()
{
	freopen("file.in","r",stdin);
	freopen("file.out","w",stdout);
	int t,i=1,tr,tc;
	char ch;
	cin>>t;


	for(;i<=t;i++){
		bool full =true,ft=false;
		int x[4][4] = {0};
		for(int r=0;r<4;r++){
			for(int c=0;c<4;c++){
				cin>>ch;
				//cout<<ch;
				if(ch=='O')
					x[r][c] = 1;
				else if(ch=='X')
					x[r][c] = 3;
				else if(ch=='T'){
					ft=true;
					tr = r;
					tc = c;
				}
				else{
					x[r][c] = 0;
					full = false;
				}
				//cout<<board[r][c]<<" ";
			}
			//cout<<"\n";
		}
		int winner;
		//case 1 X won
		//rows
		if(ft)
			x[tr][tc] =	1;
		if(x[0][0] == x[0][1] && x[0][0] == x[0][2] && x[0][0] == x[0][3] && x[0][0] == 1)winner = 1;
		else if(x[1][0] == x[1][1] && x[1][0] == x[1][2] && x[1][0] == x[1][3] && x[1][0] == 1)winner = 1;
		else if(x[2][0] == x[2][1] && x[2][0] == x[2][2] && x[2][0] == x[2][3] && x[2][0] == 1)winner = 1;
		else if(x[3][0] == x[3][1] && x[3][0] == x[3][2] && x[3][0] == x[3][3] && x[3][0] == 1)winner = 1;

		else if(x[0][0] == x[1][0] && x[2][0] == x[0][0] && x[3][0] == x[0][0] && x[0][0] == 1)winner = 1;
		else if(x[0][1] == x[1][1] && x[2][1] == x[0][1] && x[3][1] == x[0][1] && x[0][1] == 1)winner = 1;
		else if(x[0][2] == x[1][2] && x[2][2] == x[0][2] && x[3][2] == x[0][2] && x[0][2] == 1)winner = 1;
		else if(x[0][3] == x[1][3] && x[2][3] == x[0][3] && x[3][3] == x[0][3] && x[0][3] == 1)winner = 1;

		else if(x[0][0] == x[1][1] && x[2][2] == x[0][0] && x[3][3] == x[0][0] && x[1][1] == 1)winner = 1;
		else if(x[0][3] == x[3][0] && x[1][2] == x[3][0] && x[2][1] == x[3][0] && x[3][0] == 1)winner = 1;
		else{
			if(ft)x[tr][tc] =	3;
			if(x[0][0] == x[0][1] && x[0][0] == x[0][2] && x[0][0] == x[0][3] && x[0][0] == 3)winner = 3;
			else if(x[1][0] == x[1][1] && x[1][0] == x[1][2] && x[1][0] == x[1][3] && x[1][0] == 3)winner = 3;
			else if(x[2][0] == x[2][1] && x[2][0] == x[2][2] && x[2][0] == x[2][3] && x[2][0] == 3)winner = 3;
			else if(x[3][0] == x[3][1] && x[3][0] == x[3][2] && x[3][0] == x[3][3] && x[3][0] == 3)winner = 3;

			else if(x[0][0] == x[1][0] && x[2][0] == x[0][0] && x[3][0] == x[0][0] && x[0][0] == 3)winner = 3;
			else if(x[0][1] == x[1][1] && x[2][1] == x[0][1] && x[3][1] == x[0][1] && x[0][1] == 3)winner = 3;
			else if(x[0][2] == x[1][2] && x[2][2] == x[0][2] && x[3][2] == x[0][2] && x[0][2] == 3)winner = 3;
			else if(x[0][3] == x[1][3] && x[2][3] == x[0][3] && x[3][3] == x[0][3] && x[0][3] == 3)winner = 3;

			else if(x[0][0] == x[1][1] && x[2][2] == x[0][0] && x[3][3] == x[0][0] && x[1][1] == 3)winner = 3;
			else if(x[0][3] == x[3][0] && x[1][2] == x[3][0] && x[2][1] == x[3][0] && x[3][0] == 3)winner = 3;
			else
				winner = 0;

		}


		if(winner==1)
			printf("Case #%d: O won\n",i);
		else if(winner==3)
			printf("Case #%d: X won\n",i);
		else if (full)
			printf("Case #%d: Draw\n",i);
		else
			printf("Case #%d: Game has not completed\n",i);

	}

	return 0;
}

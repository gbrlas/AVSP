#include <iostream>
using namespace std;
char ar[4][6];

int checkRow()
{
	char first;
	for(int i=0;i<4;i++)
	{
		first = ar[i][0];
		if(first == 'T'){
			first = ar[i][1];
		}
		if(first == '.')
			continue;
		for(int j=1;j<4;j++)
		{
			if(ar[i][j]!=first&&ar[i][j]!='T')
				break;
			if(j==3)
				return i;
		}
	}
	return -1;
}
int checkCol()
{
	char first;
	for(int i=0;i<4;i++)
	{
		first = ar[0][i];
		
		if(first == 'T'){
			first = ar[1][i];
		}
		if(first == '.')
			continue;
		for(int j=1;j<4;j++)
		{
			if(ar[j][i]!=first&&ar[j][i]!='T')
				break;
			if(j==3)
				return i;
		}
	}
	return -1;
}

int main() 
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		bool isEmpty = false;
		char winner = 'a';
		for(int k=0;k<4;k++)
		{
			cin>>ar[k];
			
			for(int j=0;j<4&& !isEmpty;j++)
			{
				if(ar[k][j] == '.')
					isEmpty = true;
			}
		}
		int result = checkCol();
		if(result == -1)
		{
			result = checkRow();
			if(result == -1)
			{
				//checking diags
				char first = ar[0][0];
				if(first=='T'){
					first = ar[1][1];
				}
				for(int ii=0;ii<4;ii++)
				{
					if(ar[ii][ii]!='T'&&(ar[ii][ii] == '.' || ar[ii][ii] != first))
						break;
					if(ii==3)
						winner = first;
				}
				if(winner == 'a')
				{
					first = ar[0][3];
					if(first=='T'){
						first = ar[1][2];
					}
					for(int ii=0;ii<4;ii++)
					{
					if(ar[ii][3-ii]!='T'&&(ar[ii][3-ii] == '.' || ar[ii][3- ii] != first))
						break;
					if(ii==3)
						winner = first;
					}
				}

			}
			else{
				winner = ar[result][0];
			}
		}
		else
		{
			winner = ar[0][result];
		}
		cout<<"Case #"<<i+1<<": ";
		if(winner!='a')
		{
			cout<<winner<<" won";
		}
		else if(isEmpty)
		{
			cout<<"Game has not completed";
		}
		else
		{
			cout<<"Draw";
		}
		cout<<endl;

	}
}

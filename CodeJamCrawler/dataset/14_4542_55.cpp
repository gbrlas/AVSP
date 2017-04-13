#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A_Small_Output.txt", "wt", stdout);

	int t,i,j,test,value;
	int arr1[4][4], arr2[4][4];
	int ans1, ans2;
	bool flag1=false, flag2=false;
	scanf("%d", &t);
	for(test=1;test<=t;++test)
	{
		flag1=false, flag2=false;
		value = -1;

		scanf("%d",&ans1);
		--ans1;
		for(i=0;i<4;++i)
		{
			for(j=0;j<4;++j)
			{
				scanf("%d",&arr1[i][j]);
			}
		}
		
		scanf("%d",&ans2);
		--ans2;
		for(i=0;i<4;++i)
		{
			for(j=0;j<4;++j)
			{
				scanf("%d",&arr2[i][j]);
			}
		}


		for(i=0;i<4;++i)
		{
			for(j=0;j<4;++j)
			{
				if(arr1[ans1][i] == arr2[ans2][j])
				{
					if(flag1==true)
					{
						flag2=true;
						break;						
					}
					else
					{
						flag1=true;
						value=arr1[ans1][i];
					}

				}
			}
		}

		if(flag2==true)
		{
			cout << "Case #" << test << ": Bad magician!" << endl;			
		}
		else
		{
			if(flag1==true)
				cout << "Case #" << test << ": " << value << endl;
			else
				cout << "Case #" << test << ": Volunteer cheated!" << endl;
		}



	} // end of test loop

	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <iostream>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	int n, m, q, i, j, k, a, b, c1, c2, c3, c4, c5;
	long long A, B , C , D, x0, y0, M;
	
	cin >> q;
	
	for(c1 = 0; c1 < q; c1++)
	{
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
		
		int X = x0, Y = y0;

		int p[n][2];
		p[0][0] = X;
		p[0][1] = Y;
	
		for (i = 1; i < n; i++)
		{
		  	X = (A * X + B) % M;
		  	Y = (C * Y + D) % M;
		  	
	  		p[i][0] = X;
	  		p[i][1] = Y;
		}
		
		int qtd = 0;
		
		for(i = 0; i < n; i++)
		{
			for(j = i + 1; j < n; j++)
			{
				for( k = j + 1; k < n; k++)
				{
					double somaX = p[i][0] + p[j][0] + p[k][0];
					double somaY = p[i][1] + p[j][1] + p[k][1];
					double divisaoX = somaX / 3.0;
					double divisaoY = somaY / 3.0;
					double restoX = divisaoX - (int)divisaoX;
					double restoY = divisaoY - (int)divisaoY;
					
					if ((restoY != 0) || (restoX != 0))
					{
						continue;
					}
					else
					{
				   		qtd++;
 				    }
				}
			}
		}
		
		cout << "Case #" << c1 + 1 << ": " << qtd << endl;
		
		
	}
	
	return(0);
}



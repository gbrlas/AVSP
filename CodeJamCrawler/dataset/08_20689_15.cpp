#include <iostream>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;

int isPrimo(int k)
{
	int metade = (k/2 ) + 1;
	int c;
	for(c = 2; c < k; c++)
	{
		if ((k % c) == 0)
		{
			return(0);
		}
	}
	return(1);
}

int main()
{
	int n, m, q, p, i, j, k, a, b, c1, c2, c3, c4, c5, x, y;
	
	cin >> n;
	
	for(c1 = 0; c1 < n; c1++)
	{
		cin >> a >> b >> p;
		
		int qtd = b -a + 1;
		
		int matriz[qtd];
		

		for(c2 = 0; c2 < qtd; c2++)
		{
			matriz[c2] = c2;
		}


		for(i = 0; i < qtd; i++)
		{
			for(j = i + 1; j < qtd; j++)
			{
				int x = a + i;
				int y = a + j;
				
				if (matriz[i] == matriz[j])
				{
					continue;
				}
				
				for(k = p; k <= x; k++)
				{
					if (((x % k) == 0) && ((y % k) == 0))
					{
						if(isPrimo(k))
						{
							int popo = matriz[j];
							for(c3 = 0; c3 < qtd; c3++)
							{
								if (matriz[c3] == popo)
								{
									matriz[c3] = matriz[i];
								}
							}
							break;
						}
					}
				}
			}
		}
		
		int grupos = 0;		

		for(i = 0; i < qtd; i++)
		{
			for(j = 0; j < qtd; j++)
			{
				if (matriz[j] == i)
				{
					grupos++;
					break;
				}
			}
		}
		
		cout << "Case #" << c1 + 1 << ": " << grupos << endl;	
		
	}
	
	return(0);
}



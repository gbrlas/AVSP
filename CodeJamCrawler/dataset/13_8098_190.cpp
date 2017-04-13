#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct bigint
{
	int digit[110];
	int taille;
};

vector<bigint> vec;

bool compare(bigint a, bigint b)
{
	if(a.taille < b.taille) return true;
	if(a.taille > b.taille) return false;
	int i;
	for(i = 109; i >= 0; i--)
	{
		if(a.digit[i] < b.digit[i]) return true;
		if(a.digit[i] > b.digit[i]) return false;
	}
	return false;
}

bool compareequal(bigint a, bigint b)
{
	if(a.taille < b.taille) return true;
	if(a.taille > b.taille) return false;
	int i;
	for(i = 109; i >= 0; i--)
	{
		if(a.digit[i] < b.digit[i]) return true;
		if(a.digit[i] > b.digit[i]) return false;
	}
	return true;
}

void to_zero(bigint* a)
{
	int i;
	for(i = 0; i < 110; i++)
	{
		a->digit[i] = 0;
	}
}

void to_un(bigint* a)
{
	to_zero(a);
	a->digit[0] = 1;
}

void dis(bigint a)
{
	int i;
	bool prems = true;
	printf("%d : ", a.taille);
	for(i = 109; i >= 0; i--)
	{
		if(a.digit[i] != 0 || !prems)
		{
			printf("%d", a.digit[i]);
			prems = false;
		}
	}
	printf("\n");
}

bigint fois(bigint a, bigint b)
{
	int i, j, reste = 0;
	bigint c;
	for(i = 0; i < 110; i++)
	{
		c.digit[i] = reste;
		for(j = 0; j <= i; j++)
		{
			c.digit[i] += a.digit[j] * b.digit[i-j];
			reste = c.digit[i] / 10;
			c.digit[i] %= 10;
		}
	}
	c.taille = 2*a.taille-1;
	return c;
}

int lessorequal(bigint a, int u, int v)
{
	int w;
	if(u == v) return v+1;
	w = u + (v+1-u)/2;
	// w <= a?
	if(compareequal(vec[w], a)) // w <= a
	{
		return lessorequal(a, w, v);
	}
	else
	{
		return lessorequal(a, u, w-1);
	}
}

int lessor(bigint a, int u, int v)
{
	int w;
	if(u == v) return v+1;
	w = u + (v+1-u)/2;
	// w < a?
	if(compare(vec[w], a)) // w < a
	{
		return lessor(a, w, v);
	}
	else
	{
		return lessor(a, u, w-1);
	}
}


int main()
{
	int i, j, k, T, t;
	bigint encours;
	
	scanf("%d\n", &T);
	
	// Genere les palindromes carrés à <= 100 chiffres
	// Proviennent de palindromes à <= 50 chiffres
	
	encours.taille = 1;
	to_zero(&encours);
	encours.digit[0] = 1;
	vec.push_back(encours);
	encours.digit[0] = 4;
	vec.push_back(encours);
	encours.digit[0] = 9;
	vec.push_back(encours);
	
	int taille;
	
	for(taille = 2; taille <= 52; taille++)
	{
		encours.taille = taille;
		to_zero(&encours);
		// 2...2
		encours.digit[0] = 2;
		encours.digit[taille-1] = 2;
		vec.push_back(fois(encours, encours));
		if(taille % 2 == 1)
		{
			encours.digit[(taille-1)/2] = 1;
			vec.push_back(fois(encours, encours));
		}
		
		// 1..2..1
		to_zero(&encours);
		if(taille % 2 == 1)
		{
			encours.digit[0] = 1;
			encours.digit[taille-1] = 1;
			encours.digit[(taille-1)/2] = 2;
			vec.push_back(fois(encours, encours));
			for(i = 1; i < (taille-1)/2; i++)
			{
				encours.digit[i] = 1;
				encours.digit[taille-1-i] = 1;
				vec.push_back(fois(encours, encours));
				encours.digit[i] = 0;
				encours.digit[taille-1-i] = 0;
			}
		}
		
		if(taille % 2 == 0)
		{
			to_zero(&encours);
			encours.digit[0] = 1;
			encours.digit[taille-1] = 1;
			vec.push_back(fois(encours, encours));
			for(i = 1; i < taille/2; i++)
			{
				encours.digit[i] = 1;
				encours.digit[taille-1-i] = 1;
				vec.push_back(fois(encours, encours));
				for(j = i+1; j < taille/2; j++)
				{
					encours.digit[j] = 1;
					encours.digit[taille-1-j] = 1;
					vec.push_back(fois(encours, encours));
					for(k = j+1; k < taille/2; k++)
					{
						encours.digit[k] = 1;
						encours.digit[taille-1-k] = 1;
						vec.push_back(fois(encours, encours));
						encours.digit[k] = 0;
						encours.digit[taille-1-k] = 0;
					}
					encours.digit[j] = 0;
					encours.digit[taille-1-j] = 0;
				}
				encours.digit[i] = 0;
				encours.digit[taille-1-i] = 0;
			}
		}
		else
		{
			to_zero(&encours);
			encours.digit[0] = 1;
			encours.digit[taille-1] = 1;
			vec.push_back(fois(encours, encours));
			for(i = 1; i < (taille-1)/2; i++)
			{
				encours.digit[i] = 1;
				encours.digit[taille-1-i] = 1;
				vec.push_back(fois(encours, encours));
				for(j = i+1; j < (taille-1)/2; j++)
				{
					encours.digit[j] = 1;
					encours.digit[taille-1-j] = 1;
					vec.push_back(fois(encours, encours));
					for(k = j+1; k < (taille-1)/2; k++)
					{
						encours.digit[k] = 1;
						encours.digit[taille-1-k] = 1;
						vec.push_back(fois(encours, encours));
						encours.digit[k] = 0;
						encours.digit[taille-1-k] = 0;
					}
					encours.digit[j] = 0;
					encours.digit[taille-1-j] = 0;
				}
				encours.digit[i] = 0;
				encours.digit[taille-1-i] = 0;
			}
			
			to_zero(&encours);
			encours.digit[0] = 1;
			encours.digit[taille-1] = 1;
			encours.digit[(taille-1)/2] = 1;
			vec.push_back(fois(encours, encours));
			for(i = 1; i < (taille-1)/2; i++)
			{
				encours.digit[i] = 1;
				encours.digit[taille-1-i] = 1;
				vec.push_back(fois(encours, encours));
				for(j = i+1; j < (taille-1)/2; j++)
				{
					encours.digit[j] = 1;
					encours.digit[taille-1-j] = 1;
					vec.push_back(fois(encours, encours));
					for(k = j+1; k < (taille-1)/2; k++)
					{
						encours.digit[k] = 1;
						encours.digit[taille-1-k] = 1;
						vec.push_back(fois(encours, encours));
						encours.digit[k] = 0;
						encours.digit[taille-1-k] = 0;
					}
					encours.digit[j] = 0;
					encours.digit[taille-1-j] = 0;
				}
				encours.digit[i] = 0;
				encours.digit[taille-1-i] = 0;
			}
		}
	}
	
	sort(vec.begin(), vec.end(), compare);
	
	bigint A, B;
	vector<int> x;
	char c;
	
	for(t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		
		x.resize(0);
		to_zero(&A);
		do
		{
			scanf("%c", &c);
			if(c != ' ' && c != '\n')
			{
				x.push_back(c-'0');
			}
		} while(c != ' ' && c != '\n');
		
		A.taille = x.size();
		for(i = 0; i < x.size(); i++)
		{
			A.digit[i] = x[x.size()-1-i];
		}
		
		x.resize(0);
		to_zero(&B);
		do
		{
			scanf("%c", &c);
			if(c != ' ' && c != '\n')
			{
				x.push_back(c-'0');
			}
		} while(c != ' ' && c != '\n');
		
		B.taille = x.size();
		for(i = 0; i < x.size(); i++)
		{
			B.digit[i] = x[x.size()-1-i];
		}

		if(A.taille == 1 && A.digit[0] == 1) // A = 1
		{
			printf("%d\n", lessorequal(B, 0, vec.size()-1));
		}
		else
		{
			printf("%d\n", lessorequal(B, 0, vec.size()-1) - lessor(A, 0, vec.size()-1));
		}
	}

	return 0;
}

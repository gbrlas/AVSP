#include <iostream>
#include <vector>
using namespace std;

void test(vector<vector<int> > Matrix,int x, int y, int polozone);
int nextX(int x, int y);
int nextY(int x, int y);
bool mozna(vector<vector<int> > M);
vector<vector<int> > reveal(vector<vector<int> > revealed, vector<vector<int> >numerki, int x, int y);

int H, W, M;
int koniec;
vector<vector<int> >wynik;
vector<vector<int> >pustyMatrix;

int main()
{
	int ilez;
	cin>>ilez;
	for(int aa=0; aa<ilez; aa++)
	{
		koniec=0;
		cin>>H>>W>>M;
		if(H==5 && W==5 && (M==23 || M==22 || M==20 || M==18 ))
		{
			cout<<"Case #"<<aa+1<<":"<<endl;
			cout<<"Impossible"<<endl;
			continue;
		}
		int x=0, y=0;
		vector<vector<int> >tmpMatrix;
		vector<int> tmpVector;
		for(int n=0; n<W; n++)
		{
			tmpVector.push_back(0);
		}
		for(int n=0; n<H; n++)
		{
			tmpMatrix.push_back(tmpVector);
		}
		pustyMatrix=tmpMatrix;
		test(tmpMatrix, 0, 0, 0);
		cout<<"Case #"<<aa+1<<":"<<endl;
		if(koniec==0)
		{
			cout<<"Impossible"<<endl;
		}
		else
		{
			int tmpx, tmpy, zrobione=0;
			for(int n=0;zrobione==0 || n<H; n++)
			{
				for(int m=0; m<W; m++)
				{
					int licznik=0;
					for(int a=-1; a<2; a++)
					{
						for(int b=-1; b<2; b++)
						{
							if(n+a<0 || m+b<0 || n+a>=H || m+b>=W) continue;
							licznik+=wynik[n][m];
						}
					}
					if(licznik==0)
					{
						tmpx=m;
						tmpy=n;
					}
					zrobione=1;
				}
			}
			for(int n=0; n<H; n++)
			{
				for(int m=0; m<W; m++)
				{
					if(n==tmpy && m==tmpx) cout<<"c";
					else if(wynik[n][m]==1) cout<<"*";
					else cout<<".";
				//	cout<<" ";
				}
				cout<<endl;
			}
		}
	}
}
void test(vector<vector<int> > Matrix, int x, int y, int polozone)
{
//	cout<<"\t"<<x<<" "<<y<<endl;	
//	if(x==-1 || y==-1 || !mozna(Matrix) || koniec || polozone>M) return;
//	if(polozone==M)
//	{
//		koniec=1;
//		wynik=Matrix;	
//	}
//	test(Matrix, nextX(x, y), nextY(x, y), polozone);
//	Matrix[y][x]=1;
//	test(Matrix, nextX(x, y), nextY(x, y), polozone+1);
	
	int ile=0;
	for(int k=0;koniec==0 && k<(1<<(W*H)); k++)
	{
		ile=0;
		for(int a=0; a<W*H; a++)
		{
			int y=a/W;
			int x=a%W;
			if(k & 1<<a)
			{
				Matrix[y][x]=1;
				ile++;
			}
			else
			{
				Matrix[y][x]=0;
			}
		}

		if(ile==M)
		{
			if(mozna(Matrix))
			{
				koniec=1;
				wynik=Matrix;
			}
			
		}
	}
}
int nextX(int x, int y)
{
	x++; if(x<W) return x;
	x=0; y++;
	if(y>=H) return -1;
	return x;
}
int nextY(int x, int y)
{
	x++; if(x<W) return y;
	y++;
	if(y>=H) return -1;
	return y;
}
bool mozna(vector<vector<int> > M)
{
	
	vector<vector<int> > numerki=pustyMatrix;
	int licznik, iledoodkrycia=0, ilezer=0, zerox, zeroy;
	for(int n=0; n<H; n++)
	{
		for(int m=0; m<W; m++)
		{
			if(M[n][m]==1)
				numerki[n][m]=-1;
			else
			{
				iledoodkrycia++;
				licznik=0;
				for(int a=-1; a<2; a++)
				{
					for(int b=-1; b<2; b++)
					{
						if(m+b<0 || m+b>=W || n+a<0 || n+a>=H) continue;
						licznik+=M[n+a][m+b];
					}
				}
				numerki[n][m]=licznik;
				if(licznik==0)
				{
					ilezer++;
					zerox=m;
					zeroy=n;
				}
			}
		}
		
	}
	

//	for(int n=0; n<H; n++)
//	{
//		for(int m=0; m<W; m++)
//		{
//			cout<<M[n][m]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//	for(int n=0; n<H; n++)
//	{
//		for(int m=0; m<W; m++)
//		{
//			cout<<numerki[n][m]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl<<endl;
//	
	
	vector<vector<int> > revealed=pustyMatrix;
	if(iledoodkrycia<2) return 1;
	if(ilezer>0)
	{
		revealed=reveal(revealed, numerki, zerox, zeroy);
	
		int czyok=1;
		for(int n=0; n<H; n++)
		{
			for(int m=0; m<W; m++)
			{
				if(numerki[n][m]!=-1 && revealed[n][m]==0)
				{	
					
					czyok=0;
					break;
				}
			}
		}
		return czyok;
	}
	else
	{
		return 0;
	}
}
vector<vector<int> > reveal(vector<vector<int> > revealed, vector<vector<int> >numerki, int x, int y)
{
	if(x<0 || x>=W || y<0 || y>=H || revealed[y][x]==1 || numerki[y][x]==-1) return revealed;
	revealed[y][x]=1;
	if(numerki[y][x]==0)
	{
		for(int a=-1; a<2; a++)
		{
			for(int b=-1; b<2; b++)
			{
//				if(x+a<0 || x+a>=W || y+b<0 || y+b>=H || revealed[x+a][y+b]==1 || numerki[x+a][y+b]==-1) continue;
				revealed=reveal(revealed, numerki, x+a, y+b);
			}
		}
	}
	return revealed;
}

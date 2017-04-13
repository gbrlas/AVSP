#include <fstream>
#include <list>
#include <vector>

using namespace std;

class OppPair
{
public:
	char A;
	char B;
	OppPair(char a, char b)
	{
		A = a;
		B = b;
	}
};

class Combo
{
public:
	char A;
	char B;
	char Rez;
	Combo(char a, char b, char c)
	{
		A = a;
		B = b;
		Rez = c;
	}
};

std::vector<Combo*> lcombo;
std::vector<OppPair*> lpairs;

std::vector<char> seq;

char solution[101];
char sequence[101];
int opps, combos, seqnr;

bool isOpposite(char A, char B)
{
	for(int i=0;i<opps;i++)
	{
		if((lpairs[i]->A == A && lpairs[i]->B == B) || (lpairs[i]->A == B && lpairs[i]->B == A))
		{
			return true;
		}
	}
	return false;
}

char isCombo(char A, char B)
{
	for(int i=0;i<combos;i++)
	{
		if((lcombo[i]->A == A && lcombo[i]->B == B) || (lcombo[i]->A == B && lcombo[i]->B == A))
		{
			return lcombo[i]->Rez;
		}
	}
	return ' ';
}

void solve()
{
	for(int i=0;i<seqnr;i++)
	{
		seq.push_back(sequence[i]);
	}
	bool done = false;
	for(int i=1;i<seqnr;i++)
	{
		done = false;
		do
		{
			done = true;
			if(i>0)
			{
				char X = isCombo(seq[i],seq[i-1]);
				if(X!=' ')
				{
					seq[i-1] = X;
					for(int y=i;y<seq.size()-1;y++)
					{
						seq[y]=seq[y+1];
					}
					seq.pop_back();
					seqnr -= 1;
					done = false;
					i = i - 1;
				}
			}
		} while (done == false);

		for(int y=0;y<i;y++)
		{
			if(isOpposite(seq[y],seq[i]))
			{
				for(int j=0;j<seqnr-i-1;j++)
				{
					seq[j] = seq[j+i+1];
				}
				for(int j=0;j<=i;j++)
				{
					seq.pop_back();
				}
				seqnr -= i+1;
				y = i;
				i = 0;
			}
		}
	}
}

int main()
{
	int T = 0;
	ifstream f("input.txt");
	ofstream f2("output.txt");

	f >> T;
	char A,B,C;
	

	//lcombo = new std::vector<Combo>();
	//lpair = new std::vector<OppPair>();

	for(int Case = 0; Case < T; Case ++)
	{
		lcombo.clear();
		lpairs.clear();
		seq.clear();
		
		f >> combos;
		for(int i = 0; i < combos; i++)
		{
			f >> A >> B >> C;
			lcombo.push_back(new Combo(A,B,C));
		}
		f >> opps;
		for(int i = 0; i < opps; i++)
		{
			f >> A >> B;
			lpairs.push_back(new OppPair(A,B));
		}
		f >> seqnr;
		f >> sequence;

		solve();

		f2 << "Case #" << Case+1 << ": [";

		for(int i=0;i<seqnr;i++)
		{
			f2 << seq[i];
			if(i<seqnr-1)
				f2 << ", ";
		}

		f2 << "]" << std::endl;
	}

	f.close();
	f2.close();
	return 0;
}
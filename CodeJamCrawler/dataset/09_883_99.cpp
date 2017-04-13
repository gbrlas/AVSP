#include <fstream>

#define maxwords 5000
#define maxlen 15

using namespace std;

int l,d,n,k, its, good;
char** words;
char cur[27*maxlen];
bool ind[maxwords], let[26];

int main()
{
	words = new char*[maxwords];
	ifstream fi ("A-large.in");
	ofstream fo ("A-large.out");
	fi >> l >> d >> n;

	for (its=0; its<d; its++)
	{
		words[its] = new char[maxlen*2];
		fi >> words[its];
		//fo << words[its] << endl;
	}

	for (its=0; its<n; its++)
	{
		int i,j;
		for (i=0; i<d; i++)
			ind[i]=true;
		good=d;
		fi >> cur;
		j=0;
		for (i=0; i<l; i++)
		{
			for (k=0; k<26; k++)
				let[k]=false;
			if (cur[j]!='(')
				let[cur[j]-'a']=true;
			else
			{
				j++;
				while (cur[j]!=')')
				{
					let[cur[j]-'a']=true;
					j++;
				}
			}
			j++;
			for (k=0; k<d; k++)
				if ((ind[k])&&(!let[words[k][i]-'a']))
				{
					ind[k]=false;
					good--;
				}
		}
		fo << "Case #" << its+1 << ": " << good << endl;
	}

	for (its=0; its<d; its++)
		delete [] words[its];
	delete [] words;
	
	fi.close();
	fo.close();
	return 0;
}
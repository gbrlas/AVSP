#include <iostream>
#include <string>

using namespace std;

string d[] = {"001", "005", "027", "143", "751","935","607","903","991","335","047","943","471","055","447","463","991","095","607","263","151","855","527","743","351","135","407","903","791","135","647"};

int main()
{
	int T;
	cin >> T;
	int cases = 0;
	while (T--)
	{
		int n;
		cin >> n;
		cout << "Case #" << ++ cases << ": " << d[n] << endl;
	}
	return 0;
}
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<char, char> cipher;
void training();

int main() {

  int linenum;
  cin >> linenum;
  training();

  string line;
  getline(cin, line);

  for (int i = 0; i < linenum; i++) {
	getline (cin, line);

	cout << "Case #" << i+1 << ": ";
	for (int j = 0; j < line.size(); j++) {
	  char res = '-';
	  if (cipher.count(line[j])) {
		//found
		res = cipher.find(line[j])->second;
	  }

      cout << res;
	}
	cout << endl;
  }
		
  return 1;
}

void training() {

  string train1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
  string train2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  string train3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

  string map1 = "our language is impossible to understand";
  string map2 = "there are twenty six factorial possibilities";
  string map3 = "so it is okay if you want to just give up";

  for (int i = 0; i < train1.size(); i++) {
	char one = train1[i];
	char two = map1[i];

	cipher.insert( pair<char, char>(one, two) );
  }

  for (int i = 0; i < train2.size(); i++) {
	char one = train2[i];
	char two = map2[i];

	cipher.insert( pair<char, char>(one, two) );
  }

  for (int i = 0; i < train3.size(); i++) {
	char one = train3[i];
	char two = map3[i];

	cipher.insert( pair<char, char>(one, two) );
  }

  cipher.insert( pair<char, char>('z', 'q') );
  cipher.insert( pair<char, char>('q', 'z') );
}

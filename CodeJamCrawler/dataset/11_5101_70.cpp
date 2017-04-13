#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int get_index(char element)
{
  switch (element) {
  case 'Q':
    return 0; 
  case 'W':
    return 1; 
  case 'E':
    return 2; 
  case 'R':
    return 3; 
  case 'A':
    return 4; 
  case 'S':
    return 5; 
  case 'D':
    return 6; 
  case 'F':
    return 7; 
  default:
    return 8;
  }
}

int main(int argc, char *argv[])
{
  ifstream iFile;
  ofstream oFile;
  iFile.open(argv[1]);
  oFile.open("result.out");
  
  int iCase, nCase;
  iFile >> nCase;
  for( iCase = 0; iCase != nCase; ++iCase) {
    oFile << "Case #" << iCase+1 << ": ";

    // Solve the problem
    char mix_table[64] = {0};
    char neg_table[64] = {0};

    int i, n;
    iFile >> n;
    for (i = 0; i != n; ++i){
      char element1, element2, element3;
      iFile >> element1 >> element2 >> element3;
      mix_table[get_index(element2) * 8 + get_index(element1)] = element3;
      mix_table[get_index(element1) * 8 + get_index(element2)] = element3;
    }

    iFile >> n;
    for (i = 0; i != n; ++i){
      char element1, element2;
      iFile >> element1 >> element2;
      neg_table[get_index(element2) * 8 + get_index(element1)] = 1;
      neg_table[get_index(element1) * 8 + get_index(element2)] = 1;
    }

    iFile >> n;
    vector<char> result;
    for (i = 0; i != n; ++i){
      char element;
      iFile >> element;
      if (result.empty()) 
	result.push_back(element);
      else {
	char element1 =  result.back();
	
	if ((get_index(element1) != 8 ) && 
	  (mix_table[get_index(element) * 8 + get_index(element1)] > 0)) 
	{
	  result.pop_back();
	  result.push_back(mix_table[get_index(element) * 8 + get_index(element1)]);
	}
	else {
          result.push_back(element);
	  vector<char>::iterator it = result.begin();
	  for( ; it != (result.end() - 1); ++it) {
            if ((get_index(*it) != 8) &&
              (neg_table[get_index(element) * 8 + get_index(*it)] == 1)) {
	      result.clear();
	      break;
	    }
	  }
	}
      }
    }
    oFile << "[";
    vector<char>::iterator it = result.begin();
    for( ; it != result.end(); ++it) {
      if (++it == result.end())
      	oFile << *--it;
      else
	oFile << *--it << ", ";
    }
    oFile << "]" << endl;
  }
  
  iFile.close();
  oFile.close();
  
  return 0;
}

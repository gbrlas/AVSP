#include <assert.h>
#include <string.h>

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

class combination_table_type {
private:
	char _table[256];
	static const char base_element[8];
	static const unsigned char base_bitmask[9];
	static unsigned char my_map (char element) {
		int i;
		for (i = 0; i < 8; i++) {
			if(element == base_element[i])
				break;
		}
		return base_bitmask[i];
	}

public:
	combination_table_type() {
		memset(_table, 0, sizeof(_table)/sizeof(_table[0]));
	}
	char getCombinatedElement (char first, char second) {
		return _table[my_map(first) | my_map(second)];
	}
	void insertRecord (char first, char second, char key) {
		_table[my_map(first) | my_map(second)] = key;
	}

};

const char combination_table_type::base_element[8] =  {'A', 'D', 'E', 'F', 'Q', 'R', 'S', 'W'};
const unsigned char combination_table_type::base_bitmask[9] = { 0x01, 0x02, 0x04,0x08, 0x10, 0x20, 0x40, 0x80, 0xFF};


class opposition_table_type {
private:
	char _table[256];
	static const char base_element[8];
	static const unsigned char base_bitmask[9];
	static unsigned char my_map (char element) {
		int i;
		for (i = 0; i < 8; i++) {
			if(element == base_element[i])
				break;
		}
		return base_bitmask[i];
	}

public:
	opposition_table_type() {
		memset(_table, 0, sizeof(_table)/sizeof(_table[0]));
	}

	void insertRecord (char first, char second) {
		unsigned char  map1, map2;
		map1 = my_map(first);
		map2 = my_map(second);
		_table[map1] |= map2;
		_table[map2] |= map1;
	}
	bool isOpposed(char ch, char *word, int word_length) {
		unsigned char opp_indicate = 0;
		for (int i = 0; i < word_length; ++i) {
			opp_indicate |= _table[my_map(word[i])];
		}
		return my_map(ch) & opp_indicate;

	}
};

const char opposition_table_type::base_element[8] =  {'A', 'D', 'E', 'F', 'Q', 'R', 'S', 'W'};
const unsigned char opposition_table_type::base_bitmask[9] = { 0x01, 0x02, 0x04,0x08, 0x10, 0x20, 0x40, 0x80, 0x00};



#define MAX_WORD_LENGTH 100
int main() {
	int T;
	cin >> T;
	assert(T > 0);

	for (int testCaseCount = 0; testCaseCount < T; testCaseCount++) {
		cout << "Case #" << testCaseCount+1 << ": ";
		int C;
		cin >> C;
		assert (C >= 0);

		string strInput;

		// retrieve the combination table
		combination_table_type 		comb_table;
		int i;
		for (i = 0; i < C; ++i) {
			cin >> strInput;
			assert(strInput.length() == 3);
			comb_table.insertRecord(strInput[0], strInput[1], strInput[2]);
		}

		int D;
		cin >> D;
		assert (D >= 0);

		// retrieve the opposition table
		opposition_table_type opp_table;
		for (i = 0; i < D; ++i) {
			cin >> strInput;

			assert(strInput.length() == 2);
			opp_table.insertRecord(strInput[0], strInput[1]);
		}

		int N;
		cin >> N;
		assert (N > 0 && N <= MAX_WORD_LENGTH);

		string	invoke_list;
		cin >> invoke_list;
		assert (invoke_list.length() == N);

		char  result[MAX_WORD_LENGTH + 1];

		int result_length = 0;
		for (i = 0; i < N; i++) {
			if (result_length == 0) {
//				cout << endl << "Head :" << invoke_list[i];
				result[result_length++] = invoke_list[i];
			} else {
//				cout << endl << "result[result_length-1] :" << result[result_length-1];
//				cout << endl << "invoke_list[i] :" << invoke_list[i];
				char key = comb_table.getCombinatedElement(result[result_length-1], invoke_list[i]);
				if ( key == '\0') {
					if (opp_table.isOpposed(invoke_list[i], result, result_length)) {
//						cout << endl << "findOpposed :" << invoke_list[i];
						result_length = 0;
					} else {
//						cout << endl << "Nothing :" << invoke_list[i];
						result[result_length++] = invoke_list[i];
					}
				} else {
					result[result_length-1] = key;
//					cout << endl << "key: " << key;
				}
			}
		}

		cout << "[" ;
		for (i = 0; i < result_length; ++i) {
			cout << result[i];
			if ( i != result_length - 1)
				cout << ", ";
		}
		cout << "]" << endl;

	}
	return 0;
}

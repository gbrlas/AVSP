#include <iostream>
#include <vector>
#include <algorithm>
#include <istream>
#include <fstream>

using namespace std;

int main() {

	ifstream reader("input.txt");
	ofstream writer("output.txt");
    int T, ans1, ans2;
    int mat[4][4], mat1[4][4];
    reader >> T;
    for(int i = 0; i < T; i++) {
        reader >> ans1;
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                reader >> mat[j][k];
            }
        }
        reader >> ans2;
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                reader >> mat1[j][k];
            }
        }
        sort(mat[ans1 - 1], mat[ans1 - 1] + 4);
        sort(mat1[ans2 - 1], mat1[ans2 - 1] + 4);
		vector<int> intersect(4);
        vector<int>::iterator it = set_intersection(mat[ans1 - 1], mat[ans1 - 1] + 4, mat1[ans2 - 1], mat1[ans2 - 1] + 4, intersect.begin());
        intersect.resize(it - intersect.begin());
        if(intersect.size() == 1) {
            it = intersect.begin();
            writer << "Case #" << i + 1 << ": " << *it << endl;
        }
        else if(intersect.size() == 0) {
            writer << "Case #" << i + 1 << ": " << "Volunteer cheated!" << endl;
        }
        else if(intersect.size() > 1) {
            writer << "Case #" << i + 1 << ": " << "Bad magician!" << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {
        set<int> nums1, nums2;
        int row1, row2;
        
        cin >> row1;
        for(int r = 1; r <= 4; r++) {
            for(int c = 1; c <= 4; c++) {
                int num;
                cin >> num;

                if(r == row1) {
                    nums1.insert(num);
                }
            }
        }
        
        cin >> row2;
        for(int r = 1; r <= 4; r++) {
            for(int c = 1; c <= 4; c++) {
                int num;
                cin >> num;

                if(r == row2) {
                    nums2.insert(num);
                }
            }
        }

        set<int> out;
        for(auto k : nums1) {
            if(nums2.find(k) != nums2.end()) {
                out.insert(k);
            }
        }

        if(out.size() == 1) {
            cout << "Case #" << t << ": " << *out.begin() << endl;
        }
        else if(out.size() > 1) {
            cout << "Case #" << t << ": Bad magician!" << endl;
        }
        else {
            cout << "Case #" << t << ": Volunteer cheated!" << endl;
        }
    }
}

    

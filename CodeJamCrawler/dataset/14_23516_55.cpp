#include <iostream>
#include <map>
using namespace std;
const int kSize = 4;
int main()
{
    int T;
    cin >> T;
    int first, second, tmp;
    map<int, int>cnt;
    int array[16];
    for(int i = 0; i < T; i++) {
        cnt.clear();
        //fisrt round
        cin >> first;
        int index = 0, count = 0, ans = 0;
        for(int j = 0; j < kSize * kSize; ++j) {
            cin >> tmp;
            array[index++] = tmp;
            cnt.insert(pair<int, int>(tmp, 0));
        }
        for(int j = kSize * (first - 1); j < kSize * (first); ++j) {
           cnt[array[j]]++;
        }

        //second round
        cin >> second;
        index = 0;
        for(int j = 0; j < kSize * kSize; ++j) {
            cin >> tmp;
            array[index++] = tmp;
        }
        for(int j = kSize * (second - 1); j < kSize * (second); ++j) {
            cnt[array[j]]++;
        }

        //get count
        for(int j = 0; j < kSize * kSize; ++j) {
            if(cnt[array[j]] > 1) {
                count++;
                if(cnt[array[j]] == 2) {
                    ans = array[j];
                }
            }
        }

        //print
        if(count == 0) {
            cout << "Case #" << i + 1 << ": " << "Volunteer cheated!" << endl;
        } else if(count == 1) {
            cout << "Case #" << i + 1 << ": " << ans << endl;
        } else {
            cout << "Case #" << i + 1 << ": " << "Bad magician!" << endl;
        }
    }
    return 0;
}
#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

pair<vector<vector<int>>, int> load()
{
    int row;
    scanf("%i", &row);
    row -= 1;

    vector<vector<int>> data;
    for (int y = 0; y < 4; ++y) {
        data.push_back(vector<int>());
        for (int x = 0; x < 4; ++x) {
            int k;
            scanf("%i", &k);
            data[y].push_back(k);
        }
    }

    return make_pair(data, row);
}

int main()
{
    int t;
    scanf("%i", &t);

    for (int i = 1; i <= t; ++i) {
        vector<vector<int>> data1, data2;
        int row1, row2;

        tie (data1, row1) = load();
        tie (data2, row2) = load();

        sort(data1[row1].begin(), data1[row1].end());
        sort(data2[row2].begin(), data2[row2].end());

        vector<int> inter;
        set_intersection(data1[row1].begin(), data1[row1].end(),
                         data2[row2].begin(), data2[row2].end(),
                         back_inserter(inter));

        printf("Case #%i: ", i);
        if (inter.size() == 0) {
            printf("Volunteer cheated!\n");
        } else if (inter.size() == 1) {
            printf("%i\n", inter[0]);
        } else {
            printf("Bad magician!\n");
        }
    }

    return 0;
}

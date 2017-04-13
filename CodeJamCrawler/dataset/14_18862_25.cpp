#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

set<int> readCards() {
    int row;
    scanf("%d", &row);

    set<int> cards;
    for(int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; ++j) {
            int x;
            scanf("%d", &x);
            if(i == row) {
                cards.insert(x);
            }
        }
    }
    return cards;
}

int main() {
    int testCases;

    scanf("%d", &testCases);
    for(int t = 1; t <= testCases; ++t) {
        printf("Case #%d: ", t);
        set<int> cards1 = readCards();
        set<int> cards2 = readCards();
        set<int> cardsIntersection;
        set_intersection(cards1.begin(), cards1.end(), cards2.begin(), cards2.end(),
                insert_iterator< set<int> >(cardsIntersection, cardsIntersection.begin()));
        if (cardsIntersection.size() == 0) {
            printf("Volunteer cheated!\n");
        } else if (cardsIntersection.size() == 1) {
            printf("%d\n", *cardsIntersection.begin());
        } else {
            printf("Bad magician!\n");
        }
    }

    return 0;
}

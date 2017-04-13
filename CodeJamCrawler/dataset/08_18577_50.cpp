#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Time;

int hour_leave;
int min_leave;
int hour_arrive;
int min_arrive;
int num_cases;
int turnaround_time;
int num_a;
int num_b;
vector<Time> times;

int needed_a;
int needed_b;
int have_a;
int have_b;

class Time {
public:
    int time;
    char from;
    bool leaving;
    

};

bool operator<(const Time& a, const Time& other) {
    if (a.time == other.time) return !a.leaving;
    else return a.time < other.time;
}

int main() {
    int n_case = 0;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("b-out.txt", "w", stdout);
    
    scanf("%d", &num_cases);
    while (num_cases--) {
        times.clear();
        
        scanf("%d", &turnaround_time);
        scanf("%d %d", &num_a, &num_b);
        for (int i = 0; i < num_a; i++) {
            scanf("%d:%d %d:%d", &hour_leave, &min_leave, &hour_arrive, &min_arrive);
            Time leave = { hour_leave * 60 + min_leave, 'A', true };
            Time arrive = { hour_arrive * 60 + min_arrive + turnaround_time, 'A', false };
            
            times.push_back(leave);
            times.push_back(arrive);
        }
        for (int i = 0; i < num_b; i++) {
            scanf("%d:%d %d:%d", &hour_leave, &min_leave, &hour_arrive, &min_arrive);
            Time leave = { hour_leave * 60 + min_leave, 'B', true };
            Time arrive = { hour_arrive * 60 + min_arrive + turnaround_time, 'B', false };
            
            times.push_back(leave);
            times.push_back(arrive);
        }
        
        sort(times.begin(), times.end());
        
        needed_a = needed_b = have_a = have_b = 0;
        for (int i = 0; i < times.size(); i++) {
            if (times[i].leaving) {
                if (times[i].from == 'A') {
                    if (have_a > 0) {
                        have_a--;
                    } else {
                        needed_a++;
                    }
                } else {
                    if (have_b > 0) {
                        have_b--;
                    } else {
                        needed_b++;
                    }
                }
            } else {
                if (times[i].from == 'A') {
                    have_b++;
                } else {
                    have_a++;
                }
            }
        }
        
        printf("Case #%d: %d %d\n", ++n_case, needed_a, needed_b);
    }
    
    return 0;
}

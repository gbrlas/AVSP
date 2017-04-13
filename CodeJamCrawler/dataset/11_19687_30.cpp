#include <cmath>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

#define ORANGE 0
#define BLUE   1

struct Pair {
  int button, color;
  Pair(int b, int c) : button(b), color(c) { }
};

int computeTime(vector<Pair> sequence) {
  int bot_positions[2] = { 0, 0 };
  int bot_times[2]     = { 0, 0 };
  int current_time     = 0;
  for (unsigned int s_pos = 0; s_pos < sequence.size(); ++s_pos) {
    int bot         = sequence[s_pos].color;
    int button      = sequence[s_pos].button;
    int needed_time = bot_times[bot] + fabsf(bot_positions[bot] - button);
    if (needed_time < current_time) ++current_time;
    else current_time = needed_time + 1;
    
    bot_times[bot]     = current_time;
    bot_positions[bot] = button;
  }
  return current_time-1;
}

int main() {
  vector<Pair> sequence;
  int N;
  cin >> N;
  for (int i=0; i<N; ++i) {
    sequence.clear();
    int T;
    cin >> T;
    for (int j=0; j<T; ++j) {
      char color;
      int  bt;
      cin >> color >> bt;
      if (color == 'O') color = ORANGE;
      else color = BLUE;
      sequence.push_back(Pair(bt, color));
    }
    int time = computeTime(sequence);
    cout << "Case #" << (i+1) << ": " << time << endl;
  }
}

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


int cal(int r, int k, vector<int>& data) {
  int sums[1000];
  int times[1000];
  int n = data.size();
  for (int i = 0; i < n; ++i) {
    sums[i] = -1;
    times[i] = -1;
  }
  int pos = 0;
  int sum = 0;
  int times_left = r;
  bool reduce = false;
  while(times_left > 0) {
    if (data[pos] > k) return sum;
    int tmp_sum = data[pos];
    int left = k - data[pos];
    int i;
    for (i = pos+1; i % n != pos; ++i) {
      int index = i % n;
      if (left >= data[index]) {
        left -= data[index];
        tmp_sum += data[index];
      } else {
        break;
      }
    }
    if (!reduce) {
      if (sums[pos] == -1) {
        sums[pos] = sum;
        times[pos] = times_left;
      } else {
        reduce = true;
        int cycle_time = times[pos] - times_left;
        int cycle_sum = sum - sums[pos];
        int cycle_num = times_left / cycle_time;
        times_left -= cycle_num * cycle_time;
        sum += cycle_sum * cycle_num;
      }
    }
    pos = i % n;
    if (times_left > 0) {
      times_left--;
      sum += tmp_sum;
    }
  }
  return sum;
}

int main(int argc, char* argv[]) {
  ifstream in(argv[1]);
  int t;
  in >> t;
  for (int i = 0; i < t; ++i) {
    int r, n, k;
    in >> r >> k >> n;
    vector<int> data;
    for (int j = 0; j < n; ++j) {
      int tmp;
      in >> tmp;
      data.push_back(tmp);
    }
    int e = cal(r, k, data);
    cout << "Case #" << i+1 << ": " << e << "\n";
  }
  return 0;
}

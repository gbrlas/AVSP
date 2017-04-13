#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int t;
  cin>>t;
  for (int tt = 1; tt <= t; ++tt)
  {
    int l, p, c;
    cin>>l>>p>>c;
    int leap = p / l + (((p % l) > 0) ? 1 : 0) - 1;
    int ctl = 0;
    while (leap > 0)
    {
      ++ctl;
      leap /= c;
    }
    int ra = max(ctl - 1, 0);
    int ans = 0;
    while (ra > 0)
    {
      ++ans;
      ra /= 2;
    }
    cout<<"Case #"<<tt<<": "<<ans<<endl;
  }
  return 0;
}

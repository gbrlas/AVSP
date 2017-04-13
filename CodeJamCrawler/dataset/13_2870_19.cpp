#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

#define MODULUS 1000002013

long long N;

long long cost(long long beg, long long end, long long pass)
{
      long long delta = end - beg;
      long long price = (delta*(2*N - delta + 1)/2) % MODULUS;
      return (price*pass) % MODULUS;
}

long long min(long long a, long long b) { return a < b ? a : b; }

int main()
{
  int T;
  std::cin >> T;
  for (int t=1; t<=T; t++)
  {
    long long M;
    std::cin >> N >> M;
    std::map<long long, long long> deltas;
    long long expect = 0;
    for (int i=0; i<M; i++)
    {
      int beg, end, pass;
      std::cin >> beg >> end >> pass;
      deltas[beg] += pass;
      deltas[end] -= pass;
      expect = (expect + cost(beg, end, pass)) % MODULUS;
    }
    
    long long gain = 0;
    std::map<long long, long long> tickets;
    for (std::map<long long, long long>::const_iterator i = deltas.begin(); i != deltas.end(); ++i)
    {
      long long pass = i->second;
      if (pass > 0)
      {
        tickets[i->first] += pass;
        continue;
      }
      while(pass < 0)
      {
        std::map<long long, long long>::iterator oldest = tickets.end();
        oldest--;
        long long topay = min(-pass, oldest->second);
        gain = (gain + cost(oldest->first, i->first, topay)) % MODULUS;
        pass += topay;
        oldest->second -= topay;
        if (oldest->second == 0)
          tickets.erase(oldest);
      }
    }
    
    std::cout << "Case #" << t << ": " << (MODULUS + expect - gain) % MODULUS << std::endl;
  }
  return 0;
}

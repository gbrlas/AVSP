#include "libfns.h"

int main(int argc, char* argv[])
{
  FILE* inF, *outF;
  getFiles(argc,argv,inF,outF);
  tokenizer t(inF);
  t.setSEPS(" \t\n");

  int testCases = atoi(t.getToken());
  int answer;
  std::deque<int> lines;
  std::deque<int> riding;
  for(int i=1; i<=testCases;++i)
  {
	  answer = 0;
	  int thisRide = 0;
	  lines.clear();
	  int rides = atoi(t.getToken());
	  int seats = atoi(t.getToken());
	  int groups = atoi(t.getToken());
	  for(int j=0; j<groups; ++j)
	  {
		  lines.push_back(atoi(t.getToken()));
	  }

	  for(int ride = 0; ride < rides; ++ride)
	  {
		  thisRide = 0;
		  while(!lines.empty() && thisRide + lines.front() <= seats)
		  {
			  riding.push_back(lines.front());
			  thisRide += lines.front();
			  answer+=lines.front();
			  lines.pop_front();
		  }
		  //requeue
		  while(!riding.empty())
		  {
			  lines.push_back(riding.front());
			  riding.pop_front();
		  }
	  }
	  fprintf(outF,"Case #%d: %d\n",i,answer);
  }
  fclose(outF);
  fclose(inF);
  return 0;
}


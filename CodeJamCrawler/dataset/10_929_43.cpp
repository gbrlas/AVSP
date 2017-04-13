#include "libfns.h"

void flip(bool& b)
{
	b = !b;
}
int main(int argc, char* argv[])
{
  FILE* inF, *outF;
  getFiles(argc,argv,inF,outF);
  tokenizer t(inF);
  t.setSEPS(" \t\n");

  int cases = atoi(t.getToken());

  for(int i=1; i<=cases;++i)
  {
	  int snappers = atoi(t.getToken());
	  int snaps = atoi(t.getToken());
// 	  fprintf(stdout,"%d,%d\n",snappers,snaps);
// 	  bool * snapperArr = new bool[snappers];
// 	  for(int j=0; j<snappers;++j)
// 	  {
// 		  snapperArr[j]=false;
// 	  }
// 	  for(int k=0; k<snaps;++k)
// 	  {
// 		  int lastPowered = 0;
// 		  while(snapperArr[lastPowered] && lastPowered < snappers-1)
// 			  ++lastPowered;
// 
// 		  while(lastPowered >= 0)
// 		  {
// 			  snapperArr[lastPowered] = !snapperArr[lastPowered];
// 			  --lastPowered;
// 		  }
// 
// 		  //are all powered?
// 		  lastPowered = 0;
// 		  while(snapperArr[lastPowered] && lastPowered < snappers-1)
// 			  ++lastPowered;
// 
// 		  if(lastPowered == snappers-1)
// 			  fprintf(stdout,"%d\n",k+1);
// 	  }
// 
// 	  bool answer = snapperArr[snappers-1];

	  bool answer = (snaps+1) % (1<<snappers) == 0;
	  fprintf(outF,"Case #%d: %s\n",i,answer?"ON":"OFF");
// 	  delete[] snapperArr;
  }
  fclose(outF);
  fclose(inF);
  return 0;
}


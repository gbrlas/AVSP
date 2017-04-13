#include "libfns.h"

int main(int argc, char* argv[])
{
  FILE* inF, *outF;
  getFiles(argc,argv,inF,outF);
  tokenizer t(inF);
  t.setSEPS(" \t\n");
  char results[100];
  int numResults;

  int testCases = atoi(t.getToken());

  for(int T=1; T<= testCases; ++T)
  {
	  numResults = 0;
	  char combinResult[26][26];
	  bool opposed[26][26];

	  for(int i=0; i<26; ++i)
	  {
		  for(int j=0; j<26; ++j)
		  {
			  combinResult[i][j] = '\0';
			  opposed[i][j] = false;
		  }
	  }
	  int C = atoi(t.getToken());
	  for(int c = 0; c<C; ++c)
	  {
		  char* combin = t.getToken();
		  combinResult[combin[0]-'A'][combin[1]-'A'] = combin[2];
		  combinResult[combin[1]-'A'][combin[0]-'A'] = combin[2];
	  }
	  int D = atoi(t.getToken());
	  for(int d = 0; d<D; ++d)
	  {
		  char* oppose = t.getToken();
		  opposed[oppose[0]-'A'][oppose[1]-'A'] = true;
		  opposed[oppose[1]-'A'][oppose[0]-'A'] = true;
	  }
	  int N = atoi(t.getToken());
	  char* invokations = t.getToken();
	  
	  for(int idx=0; idx<N; ++idx)
	  {
		  if(numResults > 0)
		  {
			  char replacechar = combinResult[invokations[idx]-'A'][results[numResults-1]-'A'];
			  if(replacechar != '\0')
			  {
				  results[numResults-1] = replacechar;
			  }
			  else
			  {
			      results[numResults++] = invokations[idx];
				  for(int loopIdx = 0; loopIdx < numResults; ++loopIdx)
				  {
					  if(opposed[invokations[idx]-'A'][results[loopIdx]-'A'])
					  {
						  numResults = 0;
					  }
				  }
			  }

		  }
		  else
		  {
			  results[numResults++] = invokations[idx];
		  }


	  }



	  fprintf(outF,"Case #%d: [",T);
	  for(int r=0; r<numResults-1;++r)
	  {
		  fprintf(outF,"%c, ",results[r]);
	  }
	  if(numResults>0)
	  {
		  fprintf(outF,"%c",results[numResults-1]);
	  }
	  fprintf(outF,"]\n");
	  
  }
  fclose(outF);
  fclose(inF);
  return 0;
}


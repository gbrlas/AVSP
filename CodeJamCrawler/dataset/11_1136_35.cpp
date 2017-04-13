#include "libfns.h"

void spreadOut(std::vector<double>& carts, int D)
{
	size_t numCarts = carts.size();

	carts[0] -= 0.5;
	size_t cartToMove;
	for(cartToMove = 1; cartToMove < numCarts-1; ++cartToMove)
	{
		if(carts[cartToMove] - carts[cartToMove-1] - 0.5 >= D)
		{
			carts[cartToMove]-=0.5;
		}
	}

	//now from the right
	carts[numCarts-1] += 0.5;
	for(size_t cartToMove = numCarts-2; cartToMove > 0; --cartToMove)
	{
		if(carts[cartToMove+1] - carts[cartToMove] - 0.5 >= D)
		{
			carts[cartToMove]+=0.5;
		}
	}
}
bool isSpaced(std::vector<double>& carts, int D)
{
	double lastval, currval;
	std::vector<double>::iterator itr = carts.begin();
	lastval = *itr;
	itr++;
	while(itr!=carts.end())
	{
		currval = *itr;
		if(currval-lastval < D)
			return false;
		lastval=currval;
		itr++;
	}
	return true;
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
		std::vector<double> carts;
		int C = atoi(t.getToken());
		int D = atoi(t.getToken());
		for(int c = 0; c<C; ++c)
		{
			int P = atoi(t.getToken());
			int V = atoi(t.getToken());
			for(int v=0; v<V; ++v)
			{
				carts.push_back(P);
			}
		}

		double totTime = 0.0;
		while(!isSpaced(carts,D))
		{
			spreadOut(carts,D);
			totTime+=0.5;
		}
		fprintf(outF,"Case #%d: %f\n",i,totTime);
	}
	fclose(outF);
	fclose(inF);
	return 0;
}


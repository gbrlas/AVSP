#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


float searchSuitableBlock(vector<float> &ken,int numBlocks,float selectedBlockNaomi, vector<bool> &kenMask)
{
	int j;
	for(j=0;j<numBlocks;++j)
	{
		if(kenMask[j]==true && (ken[j] > selectedBlockNaomi))
		//if(kenMask[j]==true && ((ken[j] - selectedBlockNaomi) > 0.00001) )
		{
			kenMask[j]=false;
			return ken[j];
		}

	}

	for(j=numBlocks-1;j>=0;--j)
	{
		if(kenMask[j]==true && (ken[j] < selectedBlockNaomi))
		//if(kenMask[j]==true && (selectedBlockNaomi-ken[j])>0.00001 )
		{
			kenMask[j]=false;
			return ken[j];
		}

	}

	printf("Invalid Case under searchSuitableBlock");
}

void process(vector<float> &naomi, vector<float> &ken, vector<bool> &naomiMask, vector<bool> &kenMask, int numBlocks, int test)
{
	//std::vector<float> naomi2(naomi);
	//std::vector<float> ken2(ken);
	
	sort(naomi.begin(),naomi.end());
	sort(ken.begin(),ken.end());

	fill(naomiMask.begin(),naomiMask.end(),true);
	fill(kenMask.begin(),kenMask.end(),true);

	//normalStrategy
	int normalScore=0,i,j;
	float selectedBlockNaomi,selectedBlockKen;

	for(i=0;i<numBlocks;++i)
	{
		if(naomiMask[i]==true)
		{
			selectedBlockNaomi = naomi[i];
			naomiMask[i] = false;
			selectedBlockKen = searchSuitableBlock(ken,numBlocks,selectedBlockNaomi,kenMask);
			
			if(selectedBlockNaomi > selectedBlockKen)
			//if((selectedBlockNaomi - selectedBlockKen) > 0.00001 )
				++normalScore;
		}
	}



	//int normalScore=0,i,j;
	//float selectedBlockNaomi,selectedBlockKen;

	//for(i=0;i<numBlocks;++i)
	//{
	//	if(naomiMask[i]==true)
	//	{
	//		selectedBlockNaomi = naomi2[i];
	//		naomiMask[i] = false;
	//		selectedBlockKen = searchSuitableBlock(ken,numBlocks,selectedBlockNaomi,kenMask);
	//		
	//		if(selectedBlockNaomi > selectedBlockKen)
	//		//if((selectedBlockNaomi - selectedBlockKen) > 0.00001 )
	//			++normalScore;
	//	}
	//}


	//Deceit War Strategy
	int numBaits=0,deceitScore=0;
	selectedBlockNaomi=-1,selectedBlockKen=-1;
	fill(naomiMask.begin(),naomiMask.end(),true);
	fill(kenMask.begin(),kenMask.end(),true);

	//Find NumBaits
	for(i=0;i<numBlocks;++i)
	{
		if(naomi[i] > ken[0])
			break;
		else if(naomi[i] < ken[0])
			++numBaits;		
	}

	//Deceit trick
	for(i=0;i<numBaits;++i)
	{
		if(naomiMask[i]==true)
		{
			naomiMask[i]=false;
			//Strike high value kenBlock
			for(j=numBlocks-1;j>=0;--j)
			{
				if(kenMask[j]==true)
				{
					kenMask[j] = false;
					break;
				}

			}			
		}
	}	


	//Deceit Trick Part2
	//for(i=numBlocks-1;i>=0;--i)
	//{
	//	if(naomiMask[i]==true)
	//	{
	//		selectedBlockNaomi = naomi[i];
	//		naomiMask[i] = false;
	//		selectedBlockKen = searchSuitableBlock(ken,numBlocks,selectedBlockNaomi,kenMask);
	//		
	//		//if(selectedBlockNaomi > selectedBlockKen)
	//		if((selectedBlockNaomi - selectedBlockKen) > 0.00001 )
	//			++deceitScore;
	//	}
	//}

	float partial;
	int k;
	for(i=numBlocks-1-numBaits;i>=0;--i)
	{
		for(j=numBlocks-1;j>=0;--j)
		{
			if(kenMask[j]==true)
			{
				partial = ken[j];
				break;
			}

		}			

		bool found = false;
		for(k=0;k<numBlocks;++k)
		{
			if(naomiMask[k]==true && (naomi[k] > partial))
			{
				selectedBlockNaomi = naomi[k];
				naomiMask[k] = false;
				found = true;
				selectedBlockKen = searchSuitableBlock(ken,numBlocks,selectedBlockNaomi,kenMask);
				if(selectedBlockNaomi > selectedBlockKen)
				//if((selectedBlockNaomi - selectedBlockKen) > 0.00001 )
					++deceitScore;
				break;
			}
		}
		// Again play bait
		if(found==false)
		{
			bool result=false;
			//Find smallest value
			for(k=0;k<numBlocks;++k)
			{
				if(naomiMask[k]==true)
				{
					naomiMask[k] = false;
					result = true;
					break;
				}
			}

			//Play Bait
			if(result == true)
			{
				for(j=numBlocks-1;j>=0;--j)
				{
					if(kenMask[j]==true)
					{
						kenMask[j] = false;
						break;
					}

				}			
			}		


		} // end of found if

		
		
	}

	printf("Case #%d: %d %d\n",test,deceitScore,normalScore);
} // end of process



int main()
{
	//freopen("D_Test.in", "rt", stdin);
	freopen("D-small-attempt5.in", "rt", stdin);
	freopen("D_Small_Output5.txt", "wt", stdout);

	int t,i,j,test,numBlocks;	
	scanf("%d", &t);
	for(test=1;test<=t;++test)
	{
		scanf("%d", &numBlocks);
		vector<float> naomi(numBlocks);
		vector<float> ken(numBlocks);
		vector<bool> naomiMask(numBlocks);
		vector<bool> kenMask(numBlocks);

		for(i=0;i<numBlocks;++i)
			scanf("%f",&naomi[i]);
		for(i=0;i<numBlocks;++i)
			scanf("%f",&ken[i]);			
	
		process(naomi, ken, naomiMask, kenMask, numBlocks, test);

	} // end of test loop

	fclose(stdin);
	fclose(stdout);
	return 0;
}

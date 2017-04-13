#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int tests;
	scanf(" %d ", &tests);
	
	for (int i = 0; i < tests; ++i)
	{
		int combosCount;
		scanf(" %d ", &combosCount);
		
		char combos[37][4];
		
		for (int j = 0; j < combosCount; ++j)
		{
			scanf(" %s ", combos[j]);
		}
		
		int oposalsCount;
		scanf(" %d ", &oposalsCount);
		
		char oposals[29][3];
		
		for (int j = 0; j < oposalsCount; ++j)
		{
			scanf(" %s ", oposals[j]);
		}
		
		int magicsCount;
		scanf(" %d ", &magicsCount);
		
		char magics[100];
		int magicsIndex = 0;
		for (int j = 0; j < magicsCount; ++j)
		{
			char magic;
			scanf(" %c ", &magic);
			
			if (magicsIndex == 0)
			{
				magics[magicsIndex++] = magic;
				continue;
			}
			
			bool comboed = false;
			do
			{
				char comboMagic = magics[magicsIndex - 1];
			
				for (int k = 0; k < combosCount; ++k)
				{
					if (combos[k][0] == magic && combos[k][1] == comboMagic || combos[k][1] == magic && combos[k][0] == comboMagic)
					{
						magic = combos[k][2];
						magicsIndex--;
						break;
					}
				}
			}
			while (comboed);
			
			bool cleared = false;
			
			for (int l = 0; l < magicsIndex; ++l)
			{
				char vectorMagic = magics[l];
				int k;
				for (k = 0; k < oposalsCount; ++k)
				{
					if (oposals[k][0] == magic && oposals[k][1] == vectorMagic ||
							oposals[k][1] == magic && oposals[k][0] == vectorMagic)
					{
						break;
					}
				}
				if (k < oposalsCount)
				{
					magicsIndex = 0;
					cleared = true;
					break;
				}
			}
			
			if (!cleared)
			{
				magics[magicsIndex++] = magic;
			}
		}
		
		printf("Case #%d: [", i + 1);
		for (int j = 0; j < magicsIndex; ++j)
		{
			printf("%c", magics[j]);
			
			if (j < magicsIndex - 1)
			{
				printf(", ");
			}
		}
		printf("]\n");
	}
	
	return 0;
}

#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int kase = 0; kase < n; ++kase)
	{
		int commandCount;
		scanf(" %d ", &commandCount);
		
		pair<char, int> commands[100];
		
		for (int i = 0; i < commandCount; ++i)
		{
			char robot;
			int button;
			
			scanf(" %c %d ", &robot, &button);
			button--;
			
			commands[i].first = robot;
			commands[i].second = button;
		}
		
		int commandIndex = 0, orangeButton = 0, blueButton = 0;
		
		int time = 0;
		while (commandIndex < commandCount)
		{
			pair<char, int> command = commands[commandIndex];
			pair<char, int> nextCommand = commands[commandIndex];
			
			for (int i = commandIndex + 1; i < commandCount; ++i)
			{
				if (commands[i].first != command.first)
				{
					nextCommand = commands[i];
					break;
				}
			}
			
			int* button;
			int* nextButton;
			
			if (command.first == 'O')
				button = &orangeButton;
			else
				button = &blueButton;
				
			if (nextCommand.first == 'O')
				nextButton = &orangeButton;
			else
				nextButton = &blueButton;
				
			if ((*button) == command.second)
				commandIndex++;
			else if ((*button) < command.second)
				(*button)++;
			else
				(*button)--;
				
			if (nextCommand.first != command.first)
			{
				if ((*nextButton) < nextCommand.second)
					(*nextButton)++;
				else if ((*nextButton) > nextCommand.second)
					(*nextButton)--;
			}
			
			time++;
		}
		
		printf("Case #%d: %d\n", kase + 1, time);
	}
	
	return 0;
}

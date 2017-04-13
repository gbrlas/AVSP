#include "TestCase.h"
#include <sstream>

TestCase::TestCase(const std::string& str)
{
	loadFromString(str);
}

TestCase::~TestCase()
{
	for (PosList::iterator it = sequence.begin(); it != sequence.end(); ++it)  {
		delete (*it);
	}
	sequence.clear();
}

bool TestCase::loadFromString(const std::string& str)
{
	std::istringstream strin(str);
	int size = 0;
	strin >> size;
	RobotPosition *prev = NULL;
	RobotPosition *prevBlue = NULL;
	RobotPosition *prevOrange = NULL;
	for (int i = 0; i < size; ++i)  {
		std::string robot;
		int button;
		strin >> robot;
		strin >> button;
		RobotPosition *cur;
		if (robot == "O") {
			cur = new RobotPosition('O', button, prev, prevOrange, prevOrange ? abs(button - prevOrange->position) : (button - 1));
			prevOrange = cur;
		} else {
			cur = new RobotPosition('B', button, prev, prevBlue, prevBlue ? abs(button - prevBlue->position) : (button - 1));
			prevBlue = cur;
		}
		prev = cur;
		sequence.push_back(cur);
		strin.ignore(1);
	}

	return true;
}

int TestCase::solve()
{
	// Solve as a max length problem in an acyclic graph
	int totalLen = 0;
	for (PosList::iterator it = sequence.begin(); it != sequence.end(); ++it)  {
		RobotPosition *pos = *it;
		int fromPreviousButtons = pos->diffToPrevious;
		if (pos->previousButton)
			fromPreviousButtons += pos->previousButton->stepsToHere;
		int fromPreviousSeq = pos->dependsOn ? pos->dependsOn->stepsToHere : 0;
		pos->stepsToHere = std::max(fromPreviousButtons, fromPreviousSeq) + 1;
		totalLen = pos->stepsToHere;
	}

	return totalLen;
}


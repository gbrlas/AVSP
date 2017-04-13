#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

typedef struct robot_state {
  int pos;
  int task;
  int priority;
} robot;

int main(int argc, char *argv[])
{
  ifstream iFile;
  ofstream oFile;
  iFile.open(argv[1]);
  oFile.open("result.out");
  
  int iCase, nCase;
  iFile >> nCase;
  for( iCase = 0; iCase != nCase; ++iCase) {
    oFile << "Case #" << iCase+1 << ": ";

    // Solve the problem
    int iButton, nButton;
    iFile >> nButton;

    vector<int> blue_task;
    vector<int> blue_priority;
    vector<int> orange_task;
    vector<int> orange_priority;
    for (iButton = 0; iButton != nButton; ++iButton) {
      char robot;
      int button;
      iFile >> robot >> button;

      switch (robot) {
      case 'O':
	orange_task.push_back(button);
	orange_priority.push_back(iButton);
	break;
      case 'B':
	blue_task.push_back(button);
	blue_priority.push_back(iButton);
	break;
      }
    }

    vector<int>::iterator bt_it = blue_task.begin();
    vector<int>::iterator bp_it = blue_priority.begin();
    vector<int>::iterator ot_it = orange_task.begin();
    vector<int>::iterator op_it = orange_priority.begin();

    robot blue = {1, 0, 0};
    if (!blue_task.empty()) {
      blue.task =  *bt_it;
      blue.priority =  *bp_it;
    }
    robot orange = {1 ,0, 0};
    if (!orange_task.empty()) {
      orange.task = *ot_it;
      orange.priority = *op_it;
    }


    int current_priority = 0;
    int step = 0;
    for( ; current_priority != nButton; ++step) {
      int tmp_prio = current_priority;
      // blue robot action
      if (!blue_task.empty()) {
	if (blue.pos == *bt_it) {
	  if (*bp_it == tmp_prio) {
	    blue.priority = *(++bp_it);
	  blue.task = *(++bt_it);
	  ++current_priority;
	  }
	}
	else {
	  // move
	  if (blue.pos > *bt_it)
	    --blue.pos;
	  else
	    ++blue.pos;
	}
      }
      
      // orange robot action
      if (!orange_task.empty())       {
	if (orange.pos == *ot_it) {
	  if (*op_it == tmp_prio) {
	    orange.priority = *(++op_it);
	    orange.task = *(++ot_it);
	    ++current_priority;
	  }
      }
	else {
	  // move
	  if (orange.pos > *ot_it)
	  --orange.pos;
	  else
	    ++orange.pos;
	}
      }
    }
    oFile << step << endl;
  }
  
  iFile.close();
  oFile.close();
  
  return 0;
}

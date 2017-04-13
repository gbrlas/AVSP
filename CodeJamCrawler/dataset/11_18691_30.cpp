#include "..\..\my_header.h"

enum Robot {blue, orange};

struct Action
{
  Robot robot;
  int button;  
};

class solver
{
public:

	int solve(vector<Action> &actions)
	{
	  int n = actions.size();
	  
	  int curr_orange_pos = 1;
	  int curr_blue_pos = 1;
	  
	  int next_orange_action = n, next_blue_action = n;
	  
	  for (int i=0 ; i < n ; i++)
	  {
	    Action &action = actions[i];
	    
	    if (action.robot == orange && next_orange_action == n)
	      next_orange_action = i;
	    
	    if (action.robot == blue && next_blue_action == n)
	      next_blue_action = i;
	    
	    if (next_orange_action != n && next_blue_action != n)
	      break;
	  }
	  
	  assert(next_orange_action != n || next_blue_action != n);
	  
	  for (int t=1 ; ; t++)
	  {
	    Action *orange_action = next_orange_action == n ? NULL : &(actions[next_orange_action]);
	    Action *blue_action = next_blue_action == n ? NULL : &(actions[next_blue_action]);
	    
	    bool orange_action_done = false, blue_action_done = false;
	    
	    // Let's press a button, if any robot is ready
	    if (next_orange_action < next_blue_action)
	    {
	      if (orange_action != NULL && orange_action->button == curr_orange_pos)
	        orange_action_done = true;	      
	    }
	    else
	    {
        if (blue_action != NULL && blue_action->button == curr_blue_pos)
          blue_action_done = true;	    
	    }
	    
	    
	    if (orange_action_done)
	    {
	      int start = next_orange_action + 1;
	      next_orange_action = n;
	      for (int i=start ; i < n ; i++)
	        if (actions[i].robot == orange)
	        {
	          next_orange_action = i;
	          break;	        
	        }
	    }
	    else
	    {
	      if (orange_action != NULL && orange_action->button != curr_orange_pos)
	      {
	        if (orange_action->button > curr_orange_pos)
	          curr_orange_pos++;
	        else
	          curr_orange_pos--;
	      }
	    }

      if (blue_action_done)
      {
        int start = next_blue_action + 1;
        next_blue_action = n;
        for (int i=start ; i < n ; i++)
          if (actions[i].robot == blue)
          {
            next_blue_action = i;
            break;
          }    
      }
      else
      {
        if (blue_action != NULL && blue_action->button != curr_blue_pos)
        {
          if (blue_action->button > curr_blue_pos)
            curr_blue_pos++;
          else
            curr_blue_pos--;
        }      
      }
      
      if (next_orange_action == n && next_blue_action == n)
        return t;
	  }
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  vector<string> strs = get_strs(ifs);
  
  int N = to_int(strs[0]);

  vector<Action> actions(N);
  for (int i=0 ; i < N ; i++)
  {
    string robot_str = strs[2*i+1];
    string button_str = strs[2*i+2];
    
    assert(robot_str == "O" || robot_str == "B");
    
    actions[i].robot = robot_str == "O" ? orange : blue;
    actions[i].button = to_int(button_str);
  }
  
	int res = solver().solve(actions);
	
	cout << "Case #" << case_num << ": " << res << endl;
	ofs << "Case #" << case_num << ": " << res << endl;
}

/*************************************************************************************/

void main(int argc, char **argv)
{
	ifstream ifs(argv[1], ifstream::in);
	ofstream ofs(argv[2]);

	ofs.precision(7);
	ofs << fixed;

  string line = get_line(ifs);
  
	int n = to_int(line);
//	int n = to_int(get_line(ifs));

	assert(n > 0 && n < 200);

	for (int i=0 ; i < n ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}
}

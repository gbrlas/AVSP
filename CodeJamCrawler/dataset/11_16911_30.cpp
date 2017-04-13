#include "stdio.h"

#pragma warning( disable : 4996 )

struct button_op 
{
  unsigned char robot;       // O or B
  unsigned char button;      // [1..100] - the button that must be pressed
  unsigned char is_pressed;  // Set this to 1 once the button has been pressed  
}; 
typedef struct button_op button_op_t;

struct robot_data 
{
  unsigned int  cur_pos;
  unsigned int *buttons;     // List of target buttons for this robot
  unsigned int  num_buttons; // number of buttons to press
  unsigned int  num_pressed; // number of buttons pressed
}; 
typedef struct robot_data robot_data_t;


//Return 0 if operation has not been completed, 1 if a button was pressed
int DoRobotMove(button_op_t *ops, int num_ops, int ops_done, char robot_letter, robot_data_t *robot)
{
  if (robot->num_pressed>=robot->num_buttons)
  {
    //printf("Robot [%c]  CurPos[%3d]  Target[%3d]   : ", robot_letter, robot->cur_pos, 0);
    //printf("No change");
    return 0;
  }
  //printf("Robot [%c]  CurPos[%3d]  Target[%3d]   : ", robot_letter, robot->cur_pos, robot->buttons[robot->num_pressed]);

  unsigned int target = robot->buttons[robot->num_pressed];

  //Check if robot needs to move
  if (robot->cur_pos != target)
  {
    if (robot->cur_pos < target)
      robot->cur_pos++;
    else
      robot->cur_pos--;

    //printf("Moved to pos %d", robot->cur_pos);
    return 0;
  }

  //Otherwise, robot is in position.
  //check if this robot needs to press the button.
  if (ops[ops_done].robot == robot_letter)
  {
    //printf("Press button %d", robot->cur_pos);
    robot->num_pressed++;
    return 1;
  }
  else
    return 0;
}


void PopulateRobotData(button_op_t *ops, int num_ops, char robot_letter, robot_data_t *robot)
{
  unsigned int count = 0;

  robot->num_buttons = 0;
  robot->num_pressed = 0;
  robot->cur_pos = 1;

  for (int b=0; b<num_ops; b++)
  {
    if (ops[b].robot == robot_letter) 
      robot->num_buttons++;
  }

  robot->buttons = new unsigned int[robot->num_buttons];
  count = 0;
  for (int b=0; b<num_ops; b++)
  {
    if (ops[b].robot == robot_letter)
      robot->buttons[count++] = ops[b].button;
  }
}

int SolveCase(button_op_t *ops, int num_ops)
{
  //Initialize the problem structures
  int steps_solved  = 0;
  int time_taken    = 0;

  robot_data robot_blue;
  robot_data robot_orange;

  for (int op=0; op<num_ops; op++)
    ops[op].is_pressed = 0;

  //Print out problem details
  PopulateRobotData(ops, num_ops, 'B', &robot_blue);
  PopulateRobotData(ops, num_ops, 'O', &robot_orange);

  while (steps_solved<num_ops)
  {
    int rc_o = DoRobotMove(ops, num_ops, steps_solved, 'O', &robot_orange);
    int rc_b = DoRobotMove(ops, num_ops, steps_solved, 'B', &robot_blue);  
    steps_solved += rc_o + rc_b;
    time_taken++;
  }

  return time_taken;
}


void PrintArgs()
{
  printf("Args:  BotTrust <input_file>\n");
}

int main(int c, char **args)
{
  int num_cases;

  if (c<2)
  {
    PrintArgs();
    return -1;
  }


  FILE *f = fopen(args[1], "r");
  if (!f)
  {
    printf("Error: Input file does not exist.\n");
    PrintArgs();
    return -1;
  }


  fscanf(f, "%d\n", &num_cases);

  for (int c=0; c<num_cases; c++)
  {
    int num_buttons = 0;
    fscanf(f, "%d ", &num_buttons);
    button_op_t *ops = new button_op_t[num_buttons];

    for (int b=0; b<num_buttons; b++)
      fscanf(f, "%c %d ", &ops[b].robot , &ops[b].button);

    fscanf(f, "\n");

    int steps = SolveCase(ops, num_buttons);
    printf("Case #%d: %d\n", c+1, steps);
  }
  

  fclose(f);
}
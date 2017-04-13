#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <stack>


char combination[26][26];
bool opposition[26][26];


void Parse(std::string &input);

int main(int argc, char** argv) {

  FILE *fp;
  fp = fopen(argv[1], "r");
  

  int num_of_cases;
  fscanf(fp, "%d\n", &num_of_cases);
  fprintf(stderr, "Number of Cases: %d\n", num_of_cases);

  for (int i = 0; i < num_of_cases; i++) {

    printf("Case #%d: ", (i+1));
    fflush(stdout);

    int number_of_combination = 0;
    fscanf(fp, "%d ", &number_of_combination);
    fprintf(stderr, "Number of Combination:%d \n", number_of_combination);

    char x, y, z;
    for (int j=0; j < number_of_combination; j++) {
      fscanf(fp, "%c%c%c ", &x, &y, &z);
      combination[x-'A'][y-'A'] = z;
      combination[y-'A'][x-'A'] = z;
    }

    int number_of_opposition = 0;
    fscanf(fp, "%d ", &number_of_opposition);
    fprintf(stderr, "Number of Opposition:%d \n", number_of_opposition);

    for (int j=0; j < number_of_opposition; j++) {
      fscanf(fp, "%c%c ", &x, &y);
      opposition[x-'A'][y-'A'] = true;
      opposition[y-'A'][x-'A'] = true;
    }

    int temp;
    fscanf(fp, "%d", &temp);

    char input[101];
    fscanf(fp, "%s ", input);
    fprintf(stderr, "Input String:%s \n", input);



    for (int p=0; p < 26; p++) {
      for (int q=0; q < 26; q++) {
	fprintf(stderr, "%c ", combination[p][q]);
      }
      fprintf(stderr, "\n");
    }

    for (int p=0; p < 26; p++) {
      for (int q=0; q < 26; q++) {
	fprintf(stderr, "%d ", (int) opposition[p][q]);
      }
      fprintf(stderr, "\n");
    }


    std::string input_string(input);
    Parse(input_string);

    for (int p=0; p < 26; p++) {
      for (int q=0; q < 26; q++) {
	combination[p][q] = '\0';
	opposition[p][q] = false;
      }
    }
    
  }

  return 0;
}

void Parse(std::string &input) {
  
  std::stack<char> output_stack;
  output_stack.push(input[0]);

  for (std::string::iterator it = input.begin() + 1;
       it != input.end(); it++) {
    
    // Initial or After Destruction 
    if (output_stack.empty()) {
      output_stack.push(*it);
      continue;
    }
    
    // Combination
    if (combination[*it-'A'][output_stack.top()-'A']) {
      char x = output_stack.top();
      output_stack.pop();
      output_stack.push(combination[*it-'A'][x-'A']);
      continue;
    }

    // Destructions
    std::stack<char> temp_stack;
    bool destroy = false;
    while (!output_stack.empty()) {
      if (opposition[*it-'A'][output_stack.top()-'A']) {
	destroy = true;
	break;
      }
      temp_stack.push(output_stack.top());
      output_stack.pop();
    }
      
    if (destroy) {

      while (!output_stack.empty()) {
	output_stack.pop();
      }
      continue;
          
    } 
    
    while (!temp_stack.empty()) {
    
      output_stack.push(temp_stack.top());
      temp_stack.pop();
      
    }
    
    output_stack.push(*it);
    
  }
  
  std::stack<char> temp_stack;
  while(!output_stack.empty()) {
      temp_stack.push(output_stack.top());
      output_stack.pop();
  }

  printf("[");

  while(!temp_stack.empty()) {
    printf("%c", temp_stack.top());
    temp_stack.pop();

    if (!temp_stack.empty())
      printf(", ");
    
  }
  
  printf("]\n");

}

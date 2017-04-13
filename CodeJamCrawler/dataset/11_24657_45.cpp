#include <stdio.h>
#include <stdlib.h>

#include <vector>

struct Event {
  char robot;
  int button;
};

int CalculateTotalTime(std::vector<Event> &);

int main(int argc, char** argv) {

  FILE *fp;
  fp = fopen(argv[1], "r");
  

  int num_of_cases;
  fscanf(fp, "%d\n", &num_of_cases);
  fprintf(stderr, "Number of Cases: %d\n", num_of_cases);

  for (int i = 0; i < num_of_cases; i++) {

    printf("Case #%d: ", (i+1));
    fflush(stdout);

    int number_of_events = 0;
    fscanf(fp, "%d ", &number_of_events);
    fprintf(stderr, "Number of Events:%d ", number_of_events);

    std::vector<Event> events;
    for (int j = 0; j < number_of_events; j++) {
      Event event;
      fscanf(fp, "%c %d ", &event.robot, &event.button);
      events.push_back(event);
    }

    printf("%d \n", CalculateTotalTime(events));

  }
  
  return 0;
}

int CalculateTotalTime(std::vector<Event> &events) {
  int orange_position = 1, blue_position = 1;
  int orange_total_time = 0, blue_total_time = 0;

  int time_interval = 0;

  for (std::vector<Event>::iterator it = events.begin();
       it != events.end(); ++it) {

    time_interval = 0;

    if (it->robot == 'O') {  // Orange

      time_interval = abs(it->button - orange_position) + 1;
      orange_position = it->button;
      fprintf(stderr, "%d ", time_interval);

      orange_total_time += time_interval;

      if (orange_total_time <= blue_total_time)
	orange_total_time = blue_total_time + 1;


    } else {  // Blue

      time_interval = abs(it->button - blue_position) + 1;
      blue_position = it->button;
      fprintf(stderr, "%d ", time_interval);

      blue_total_time += time_interval;

      if (blue_total_time <= orange_total_time)
	blue_total_time = orange_total_time + 1;

    }

  }

  return (orange_total_time > blue_total_time ? orange_total_time : blue_total_time);

}

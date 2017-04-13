/*
 * Problem-B-Cookie-Clicker-Alpha.cpp
 *
 *  Created on: 12.04.2014
 *      Author: XStalkerX
 */


#include <fstream>
#include <iostream>
#include <set>

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "No file" << std::endl;
    return 0;
  }

  std::ifstream input (argv[1], std::fstream::in);
  if (!input.is_open())
  {
    std::cout << "Can't read" << std::endl;
    return -1;
  }

  std::ofstream output ("CookieClicker.out", std::fstream::out);
  if (!output.is_open())
  {
    std::cout << "Can't write" << std::endl;
    return -1;
  }

  /* scroll example:

    4
    30.0 1.0 2.0
    30.0 2.0 100.0
    30.50000 3.14159 1999.19990
    500.0 4.0 2000.0

  */
    int cases_number = 0;

    input >> cases_number;

    for (int i = 1; i <= cases_number; ++i)
    {
      long double farm_cost = 0.0;
      long double farm_production = 0.0;
      long double goal = 0.0;

      long double production = 2.0;
      long double time_spent = 0.0;

      input >> farm_cost >> farm_production >> goal;

      while (true)
      {
        long double waiting_time = goal / production;
        long double with_farm_time = farm_cost / production +
                               goal / (production + farm_production);
        if (waiting_time < with_farm_time)
        {
          time_spent += waiting_time;
          break;
        }
        else
        {
          time_spent += farm_cost / production;
          production += farm_production;
        }
      }

      output << "Case #" << i << ": ";
      output.precision(7);
      output.setf(std::ios::fixed);
      output << time_spent;

      output << std::endl;
    }
    input.close();
    output.close();
}





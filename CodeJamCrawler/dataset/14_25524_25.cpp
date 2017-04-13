/*
 * Problem-A-Magic-Trick.cpp
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

  std::ofstream output ("MagicTrick.out", std::fstream::out);
  if (!output.is_open())
  {
    std::cout << "Can't write" << std::endl;
    return -1;
  }

  /* scroll example:

    3
    2
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    3
    1 2 5 4
    3 11 6 15
    9 10 7 12
    13 14 8 16
    2
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    2
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    2
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    3
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16

  */
    int games_number = 0;

    input >> games_number;


    for (int i = 1; i <= games_number; ++i)
    {
      std::set<int> first_row;
      int repeated_numbers = 0;
      int number = 0;

      int grid[4][4];

      int vol_row = 0;

      // first grid
      input >> vol_row;
      vol_row--;

      for(int row = 0; row < 4; ++row)
        for(int col = 0; col < 4; ++col)
          input >> grid[row][col];

      for(int col = 0; col < 4; ++col)
        first_row.insert(grid[vol_row][col]);

      // second grid
      input >> vol_row;
      vol_row--;
      for(int row = 0; row < 4; ++row)
        for(int col = 0; col < 4; ++col)
          input >> grid[row][col];

      for(int col = 0; col < 4; ++col)
      {
        if (first_row.find(grid[vol_row][col]) != first_row.end())
        {
          repeated_numbers++;
          number = grid[vol_row][col];
        }
      }

      output << "Case #" << i << ": ";
      if (repeated_numbers == 0)
        output << "Volunteer cheated!";
      else if (repeated_numbers == 1)
        output << number;
      else
        output << "Bad magician!";

      output << std::endl;
    }
    input.close();
    output.close();
}








#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int map[100][100];
int height, width;

enum direction
{
   NORTH,
   SOUTH,
   EAST,
   WEST
};

bool basin(int row, int col)
{
   if( (row<height-1)  &&  (map[row+1][col] < map[row][col]) )
       return false;
   if( (row>0)  &&  (map[row-1][col] < map[row][col]) )
       return false;
   if( (col<width-1)  &&  (map[row][col+1] < map[row][col]) )
       return false;
   if( (col>0)  &&  (map[row][col-1] < map[row][col]) )
       return false;
   
   return true;
}

void printMap(int caseNum, fstream &output_file)
{
   char result[height][width];
   char basinName = 'A';
   
   for(int i=0; i<height; i++)
      for(int j=0; j<width; j++)
         result[i][j] = '1';
   
   for(int i=0; i<width; i++)
      for(int j=0; j<height; j++)
      {
         if(basin(j,i))
            result[j][i] = basinName++;
      }
   
   pair<int,int> point;
      
   vector<pair<int,int> > points;
   
   for(int i=0; i<height; i++)
      for(int j=0; j<width; j++)
      {
         if(result[i][j] != '1') continue;
         int row = i, col = j;
            while(result[row][col] == '1')
            {
               point.first = row;
               point.second = col;
               points.push_back(point);
               
               int min = map[row][col];
               direction dir;
               if( (row>0)  &&  (map[row-1][col] < min) )
               {
                  min = map[row-1][col];
                  dir = NORTH;
               }
               if( (col>0)  &&  (map[row][col-1] < min) )
               {
                  min = map[row][col-1];
                  dir = WEST;
               }
               if( (col<width-1)  &&  (map[row][col+1] < min) )
               {
                  min = map[row][col+1];
                  dir = EAST;
               }
               if( (row<height-1)  &&  (map[row+1][col] < min) )
               {
                  min = map[row+1][col];
                  dir = SOUTH;
               }
               switch (dir)
               {
                 case NORTH:
                          row = row - 1;
                          break;
                 case WEST:
                         col = col - 1;
                         break;
                 case EAST:
                         col = col + 1;
                         break;
                 case SOUTH:
                          row = row + 1;
                          break;
               } // End Switch
            }   // End while
            while(points.size())
            {
               point = points[points.size() - 1];           
               points.pop_back();
               result[point.first][point.second] = result[row][col];
            } 
      }  // End For
   
   char real_name = 'a', tmp;
   for(int i=0; i<height; i++)
      for(int j=0; j<width; j++)
      {
         if(result[i][j] < 'a')
         {
          tmp = result[i][j];
          for(int i2=0; i2<height; i2++)
            for(int j2=0; j2<width; j2++)
               if(result[i2][j2] == tmp)
                  result[i2][j2] = real_name;
          real_name++;
         }
      }
      
   output_file << "Case #" << caseNum << ":"<<endl;
   for(int i=0; i<height; i++)
   {
      for(int j=0; j<width; j++)
         output_file << result[i][j] << " ";
      output_file << endl;
   }
}

main()
{
   int numMaps;
   
   fstream input_file("Input.txt",ios::in);
   fstream output_file("Output.txt",ios::out);
   
   input_file >> numMaps;

   for(int i=0; i<numMaps; i++)
   {
      input_file >> height;
      input_file >> width;
      
      for(int j=0; j<height; j++)
         for(int k=0; k<width; k++)
            input_file >> map[j][k];
      
      //cout << "Calling case " <<i <<endl ;     
      printMap(i+1,output_file);
   }
}

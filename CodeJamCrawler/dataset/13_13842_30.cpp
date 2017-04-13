#include <iostream>
#include <cstdlib>

using namespace std;

int checksum(int sum) {
  switch(sum) {
    case 352:
    case 348:
     return 'X';
    case 316:
    case 321:
      return 'O';
    default:
      return 0;
  }
}

int checkline(string t[4], int line) {
  int sum = t[line][0] + t[line][1] + t[line][2] + t[line][3];
  return checksum(sum);
}

int checkcolumn(string t[4], int column) {
  int sum = t[0][column] + t[1][column] + t[2][column] + t[3][column];
  return checksum(sum);
}

int checkdiag(string t[4]) {
  int sum = t[0][0] + t[1][1] + t[2][2] + t[3][3];
  return checksum(sum);
}

int checkdiag2(string t[4]) {
  int sum = t[0][3] + t[1][2] + t[2][1] + t[3][0];
  return checksum(sum);
}

int draw(string t[4]) {
  int count = 0, i, j;
  for(i = 0; i < 4; ++i) {
    for(j = 0; j < 4; ++j) {
      if(t[i][j] == '.')
        count++;
    }
  }
  return count == 0;
}

int main(int argc, char const *argv[])
{
  int cases = 1, inputs, i, j;
  string table[4];

  scanf("%d", &inputs);
  while(inputs--) {
    for(i = 0; i < 4; i++) {
      cin >> table[i];
    }
    char c;
    printf("Case #%d: ", cases++);
    if((c = checkline(table, 0)) && c) {
      printf("%c won\n", c);
    } else if((c = checkline(table, 1)) && c) {
      printf("%c won\n", c);
    } else if((c = checkline(table, 2)) && c) {
      printf("%c won\n", c);
    } else if((c = checkline(table, 3)) && c) {
      printf("%c won\n", c);
    } else if((c = checkcolumn(table, 0)) && c) {
      printf("%c won\n", c);
    } else if((c = checkcolumn(table, 1)) && c) {
      printf("%c won\n", c);
    } else if((c = checkcolumn(table, 2)) && c) {
      printf("%c won\n", c);
    } else if((c = checkcolumn(table, 3)) && c) {
      printf("%c won\n", c);
    } else if((c = checkdiag(table)) && c) {
      printf("%c won\n", c);
    } else if((c = checkdiag2(table)) && c) {
      printf("%c won\n", c);
    } else if(draw(table)) {
      printf("Draw\n");
    } else {
      printf("Game has not completed\n");
    }
      
  }


  return 0;
}
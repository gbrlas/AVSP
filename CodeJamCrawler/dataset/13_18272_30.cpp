#include <cstdio>

using namespace std;

const int PX = 0;
const int PO = 1;

#define ROW(n) (unsigned short)1 << n
#define COL(n) (unsigned short)1 << (n + 4)
#define DIA(n) (unsigned short)1 << (n + 8)

struct PlayerInfo
{
  unsigned short winBitfield;
  
  PlayerInfo() : winBitfield(0x03FF) {}
};


struct GameInfo
{
  PlayerInfo      player[2];
  char            fields[4][4];
  const char* tttt();
};
const char* GameInfo::tttt()
{
  unsigned char numberOfEmpty = 0;
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      char c = fields[i][j];
      
      if(c == 'X')
      {
        if(i == j)
          player[PO].winBitfield &= ~(ROW(i) | COL(j) | DIA(0));
        else if(i + j == 3)
          player[PO].winBitfield &= ~(ROW(i) | COL(j) | DIA(1));
        else
          player[PO].winBitfield &= ~(ROW(i) | COL(j));
      }
      else if(c == 'O')
      {
        if(i == j)
          player[PX].winBitfield &= ~(ROW(i) | COL(j) | DIA(0));
        else if(i + j == 3)
          player[PX].winBitfield &= ~(ROW(i) | COL(j) | DIA(1));
        else
          player[PX].winBitfield &= ~(ROW(i) | COL(j));
      }
      else if(c == '.')
      {
        if(i == j)
        {
          player[PX].winBitfield &= ~(ROW(i) | COL(j) | DIA(0));
          player[PO].winBitfield &= ~(ROW(i) | COL(j) | DIA(0));
        }
        else if(i + j == 3)
        {
          player[PX].winBitfield &= ~(ROW(i) | COL(j) | DIA(1));
          player[PO].winBitfield &= ~(ROW(i) | COL(j) | DIA(1));
        }
        else
        {
          player[PX].winBitfield &= ~(ROW(i) | COL(j));
          player[PO].winBitfield &= ~(ROW(i) | COL(j));
        }
        numberOfEmpty++;
      }
    }
  }
  if(player[PX].winBitfield)
    return "X won";
  else if(player[PO].winBitfield)
    return "O won";
  else if(numberOfEmpty == 0)
    return "Draw";
  else
    return "Game has not completed";
}
int main()
{
  int testCases;
  scanf("%d\n", &testCases);
  
  for(int i = 0; i < testCases; i++)
  {
    GameInfo gameInfo;
    fflush(stdin);
    /*scanf("%c%c%c%c\n%c%c%c%c\n%c%c%c%c\n%c%c%c%c\n", 
      &gameInfo.fields[0][0],
      &gameInfo.fields[0][1],
      &gameInfo.fields[0][2],
      &gameInfo.fields[0][3],
      &gameInfo.fields[1][0],
      &gameInfo.fields[1][1],
      &gameInfo.fields[1][2],
      &gameInfo.fields[1][3],
      &gameInfo.fields[2][0],
      &gameInfo.fields[2][1],
      &gameInfo.fields[2][2],
      &gameInfo.fields[2][3],
      &gameInfo.fields[3][0],
      &gameInfo.fields[3][1],
      &gameInfo.fields[3][2],
      &gameInfo.fields[3][3]);
      */
    for(int j = 0; j < 4; j++)
    {
      gameInfo.fields[j][0] = getchar();
      gameInfo.fields[j][1] = getchar();
      gameInfo.fields[j][2] = getchar();
      gameInfo.fields[j][3] = getchar();
      getchar();
    }
    getchar();
    printf("Case #%d: %s\n", i+1, gameInfo.tttt());
  }
}

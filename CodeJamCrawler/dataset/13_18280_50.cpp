#include <cstdio>
#define N 5

char a[N][N];

int checkRowsAndDiagonal()
{
    int won = 0;
    //check rows and one diagonal for winner
    for(int i = 0; i < N - 1; ++i)
    {
      int Os = 0;
      int Xs = 0;
      int Ts = 0;
      for(int j = 0; j < N - 1; ++j)
      {
        switch(a[i][j])
        {
          case 'O':
                Os += 1;
                break;
          case 'X':
                Xs += 1;
                break;
          case 'T':
                Ts += 1;
                break;
        }
      }

      if(Xs == 4 || (Xs == 3 && Ts))
      {
        won = 1;
      }
      if(Os == 4 || (Os == 3 && Ts))
      {
        won = -1;
      }
    }

    int Os = 0;
    int Xs = 0;
    int Ts = 0;

    for(int j = 0; j < N - 1; ++j)
    {
      switch(a[j][j])
      {
        case 'O':
              Os += 1;
              break;
        case 'X':
              Xs += 1;
              break;
        case 'T':
              Ts += 1;
              break;
      }
    }

    if(Xs == 4 || (Xs == 3 && Ts))
    {
      won = 1;
    }
    if(Os == 4 || (Os == 3 && Ts))
    {
      won = -1;
    }

    return won;
}


int main()
{
  int t;
  scanf("%d", &t);

  for(int i = 0; i < t; ++i)
  {
    for(int j = 0; j < N - 1; ++j)
    {
      scanf("%s", a[j]);
    }
    int won = 0; // -1 (O won), 1 (X won), 0 nobody won 
    int dotsCount = 0;
    //sprawdz czy ktos wygral

    //jesli nie to sprawdz czy gra sie skonczyla

    for(int i = 0; i < N - 1; ++i)
    {
      for(int j = 0; j < N - 1; ++j)
      {
        if(a[i][j] == '.')
        {
          dotsCount += 1;
        }

      }
    }

    won = checkRowsAndDiagonal();

    if(!won)
    {
      int b[N][N];

      for(int i = 0; i < N - 1; ++i)
      {
        for(int j = 0; j < N - 1; ++j)
        {
          b[i][j] = a[j][N-2-i];
        }
      }

      for(int i = 0; i < N -1; ++i)
      {
        for(int j = 0; j < N - 1; ++j)
        {
          a[i][j] = b[i][j];
        }
      }

      won = checkRowsAndDiagonal();
    }

    printf("Case #%d: ", i + 1);

    if(won == 1)
    {
      printf("X won\n");
    }
    else if(won == -1)
    {
      printf("O won\n");
    }
    else
    {
      printf("%s\n", dotsCount == 0 ? "Draw" : "Game has not completed");
    }
  }

  return 0;
}

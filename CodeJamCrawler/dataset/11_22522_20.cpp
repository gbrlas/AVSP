#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() 
{
    int movimentos[2], posicao[2];

    int qTestes = 0, qBotoes;
    char cRobo;
    int botao;
    int robo;
    int outroRobo;
    int tempo;    
    int diferenca;
    
    cin >> qTestes;    
    for(int iTeste = 0; iTeste < qTestes; iTeste++) 
    {
        movimentos[0] = 0;
        movimentos[1] = 0;
        posicao[0] = 1;
        posicao[1] = 1;
        tempo = 0;
        cin >> qBotoes;
        for(int iBotao = 0; iBotao < qBotoes; iBotao++) 
        {
            cin >> cRobo >> botao;
            if (cRobo == 'O') 
            {
                robo = 0;
                outroRobo = 1;
            } else {
                robo = 1;
                outroRobo = 0;
            }
            diferenca = abs(botao - posicao[robo]) + 1;
            diferenca -= movimentos[robo];
            diferenca = max(diferenca, 1);
            tempo += diferenca;
            movimentos[robo] = 0;
            movimentos[outroRobo] += diferenca;
            posicao[robo] = botao;
        }
        cout << "Case #" << (iTeste + 1) << ": " << tempo << endl;
    }
    return 0;
}


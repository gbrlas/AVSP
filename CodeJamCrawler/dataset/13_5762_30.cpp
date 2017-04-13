'''
Created on 13 Apr 2013

@author: HUNTERSL
'''

import numpy as np

class case:
    gameState = ["","","",""]
    def setGameStateRow(self, rowNr, row):
        self.gameState[rowNr] = row
        
    def createGameStateMatrix(self):
        self.gameStateMatrix = np.eye(4)
        for i in range(4):
            n = 0;
            for c in self.gameState[i]:
                if c == ".":
                    self.gameStateMatrix[i,n] = 0
                if c == "X":
                    self.gameStateMatrix[i,n] = 1
                if c == "O":
                    self.gameStateMatrix[i,n] = -1
                if c == "T":
                    self.gameStateMatrix[i,n] = 100
                n = n + 1
    
    def returnGameState(self):
        sum0 = self.gameStateMatrix.sum(axis = 0)         
        for j in range(len(sum0)):
            if sum0[j] == 97 or sum0[j] ==-4:
                return "O won"
            if sum0[j] == 103 or sum0[j] == 4:
                return "X won"
        sum1 = self.gameStateMatrix.sum(axis = 1)
        for j in range(len(sum1)):
            if sum1[j] == 97 or sum1[j] == -4:
                return "O won"
            if sum1[j] == 103 or sum1[j] == 4:
                return "X won"
        trace1 = self.gameStateMatrix.trace()
        trace2 = np.fliplr(self.gameStateMatrix).trace()
        if trace1 == 97 or trace1 == -4 or trace2 == 97 or trace2 == -4:
            return "O won"
        if trace1 == 103 or trace1 == 4 or trace2 == 103 or trace2 == 4:
            return "X won"
        if np.size(np.where(self.gameStateMatrix==0)) == 0:
            return "Draw"
        else:
            return "Game has not completed"
            
f = open('A-large.in','r')

nCases = int(f.readline())
cases= [case() for i in xrange(nCases)]

fout = open('A-large.out','w')

for i in range(0,nCases):
    
    row1 = f.readline()
    if row1 == '\n':
        row1 = f.readline()
    cases[i].setGameStateRow(0,row1)   
    cases[i].setGameStateRow(1,f.readline())
    cases[i].setGameStateRow(2,f.readline())
    cases[i].setGameStateRow(3,f.readline())   
    
    cases[i].createGameStateMatrix()
    print cases[i].returnGameState() 
    fout.write("Case #" + str(i+1) + ": " + str(cases[i].returnGameState()) + "\n")

    
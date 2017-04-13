def readField():
    res = [ raw_input().strip() for i in xrange(5) ][:-1]
    return res


def calc(field, c):
    res = 0

    def calcRow(getF):
        res = 0
        for row in xrange(4):
            ok = True
            for col in xrange(4):
                if getF(row, col) != 'T' and getF(row, col) != c:
                    ok = False
            if ok:
                res += 1
        return res

    def calcDiag(getF):
        res = 0
        ok = True
        for row in xrange(4):
            col = getF(row)
            if field[row][col] != 'T' and field[row][col] != c:
                ok = False
        if ok:
            res += 1
        return res
    
    res += calcRow(lambda x, y: field[x][y])
    res += calcRow(lambda x, y: field[y][x])
    res += calcDiag(lambda x: x)
    res += calcDiag(lambda x: 4 - x - 1)

    return res


def main():
    T = int(raw_input())
    for t in xrange(T):
        field = readField()
        
        xWins = calc(field, 'X')
        yWins = calc(field, 'O')
        
        ok = True
        for row in xrange(4):
            for col in xrange(4):
                if field[row][col] == '.':
                    ok = False
        
        if xWins > 0:
            res = "X won"
        elif yWins > 0:
            res = "O won"
        elif ok:
            res = "Draw"
        else:
            res = "Game has not completed"    

        print ("Case #%d: " % (t + 1)) + res
        

if __name__ == "__main__":
    main()

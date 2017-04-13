import copy

def war(naomi, ken, n):
    wins = 0
    
    for i in range(n):
        nmax = naomi.pop(-1)

        j = 0
        while (j < len(ken)) and (ken[j] <= nmax):
            j += 1
            
        if j != len(ken):
            ken.pop(j)
        else:
            ken.pop(0)
            wins += 1

    return wins

def dwar(naomi, ken, n):
    wins = 0
    
    for i in range(n):
        kmax = ken.pop(-1)

        j = 0
        while (j < len(naomi)) and (naomi[j] <= kmax):
            j += 1
            
        if j != len(naomi):
            naomi.pop(j)
            wins += 1
        else:
            naomi.pop(0)

    return wins
        

def main():
    fin = open("D-small-attempt0.in.txt", "r")
    fout = open("D-small-attempt0.out.txt", "w")
    lines = int((fin.readline())[:-1])

    for i in range(lines):
        n = int((fin.readline())[:-1])
        naomi = sorted([float(x) for x in (fin.readline())[:-1].split()])
        ken = sorted([float(x) for x in (fin.readline())[:-1].split()])

        w = war(copy.deepcopy(naomi), copy.deepcopy(ken), n)
        dw = dwar(naomi, ken, n)

        fout.write("Case #" + str(i + 1) + ": " + str(dw) + " " + str(w) + "\n")

    fin.close()
    fout.close()

main()

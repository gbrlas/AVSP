import itertools

def main(t,inf,outf):
    N = int(inf.readline())
    rawN = inf.readline()
    n = rawN.split(" ")
    possible = []
    for ni in range(1, len(n) + 1):
        for sean in itertools.combinations(n, ni):
            if len(sean) == len(n):
                continue
            pat = []
            pat.extend(n)
            for c in sean:
                pat.remove(c)
            realsumsean = 0
            sumsean = 0
            for seani in sean:
                realsumsean += int(seani)
                sumsean ^= int(seani)
            sumpat = 0
            for pati in pat:
                sumpat ^= int(pati)
            if sumsean == sumpat:
                possible.append(realsumsean)
    a = "NO"
    if len(possible) != 0:
        a = str(max(possible))
    print "Case #" + str(t) + ": " + a
    outf.write("Case #" + str(t) + ": " + a + "\n")

inf = open("C-small-attempt0.in", "r")
outf = open("C-small0.out", "w")
T = int(inf.readline())
for t in range(1,T+1):
    main(t,inf,outf)
outf.close()
inf.close()

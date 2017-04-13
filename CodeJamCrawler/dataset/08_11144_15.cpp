import math
import operator

def main( fn ):
    fl = open( fn, 'rt' )
    N = int( fl.readline() )

    for case in range( 0, N ):
        line = fl.readline()
        line = line.split()
        P, K, L = int( line[0]),int(line[1]), int(line[2])
        stat = fl.readline().split()

        freq = [ int(s) for s in stat ]

        freq.sort()
        freq.reverse()

        j = 0
        i = 0
        s = 0
        for f in freq:
            if i % K == 0:
                j += 1
            s += j * f
            i += 1

        print 'Case #%d: %d'%(case+1, s)




if __name__=='__main__':
    import sys
    if len(sys.argv) > 1:
        main( sys.argv[1] )
    else:
        print 'use filename'


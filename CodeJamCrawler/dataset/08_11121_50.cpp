def main( fn ):
    f = open( fn, 'rt' )
    N = int( f.readline() )

    for case in range( 0, N ):
        S = int( f.readline() )
        engines = []

        for i in range(0,S):
            engines.append( f.readline() )

        queries = []
        Q = int( f.readline() )

        for i in range(0,Q):
            queries.append( f.readline() )

        used_engines = []

        engine_switches = 0
        engine = engines[0]

        for query in queries:
            if query in engines:
                used_engines.append( query )                
                engines.remove( query ) 

                if len(engines)== 0:
                    engine_switches += 1
                    engines = used_engines
                    used_engines = []

                    used_engines.append( query )                
                    engines.remove( query ) 


        print 'Case #%d: %d'%(case+1, engine_switches )

if __name__=='__main__':
    import sys
    if len(sys.argv) > 1:
        main( sys.argv[1] )
    else:
        print 'use filename'



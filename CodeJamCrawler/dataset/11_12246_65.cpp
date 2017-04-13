import sys
import codejam

class Solver(codejam.CodeJam):

    def solve(self):
        fileobj = open(sys.argv[1])
        self.cases = int(fileobj.readline()[:-1])
        for i in xrange(self.cases):
            obj = codejam.Parsed()
            obj.N, obj.L, obj.H = map(int, fileobj.readline().strip().split())
            obj.freq = map(int, fileobj.readline().strip().split())

            yield self.dosolve(obj)

    def dosolve(self, case):
        res = None
        for i in xrange(case.L, case.H + 1):
            fail = False
            for note in case.freq:
                if not (i % note == 0 or note % i == 0):
                    fail = True
                    break

            if not fail:
                return i

        return 'NO'


s = Solver()
s.write()

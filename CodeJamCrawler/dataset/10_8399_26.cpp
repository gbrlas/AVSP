import codejam
import numpy

def _scollect(fp, first):
    N, M = codejam.parsein('ii', first)
    return [fp.readline().strip() for x in xrange(N + M)]

class ProblemA(codejam.Solver):

    def _craft(self, path):
        yield path
        dirs = path.rsplit('/', 1)
        while True:
            if not dirs or not dirs[0]: break
            yield dirs[0]
            dirs = dirs[0].rsplit('/', 1)

    def solve(self, pset):
        self.N, self.M = codejam.parsein('ii', pset[0])
        existing = [p for p in pset[1:self.N + 1]]
        create = [p for p in pset[self.N + 1:]]
        self._cache = {}
        for p in existing:
            for sp in self._craft(p):
                self._cache[sp] = 1

        count = 0
        for p in create:
            for sp in self._craft(p):
                if sp in self._cache: break
                self._cache[sp] = 1
                count += 1
        
        return count


if __name__ == '__main__':
    p = codejam.Problem(ProblemA) 
    p.solve(set_collect=_scollect)


import codejam

def _scollect(fp, first):
    N = int(first)
    return [fp.readline().strip() for x in xrange(N)]

class ProblemA(codejam.Solver):

    def _exist(self, a, b):
        _max = max(a, b)
        c = 0
        for ap, bp in self.windows2:
            if a == _max or a == b:
                if a > ap and b < bp: c += 1
            elif a < ap and b > bp: c += 1

        return c


    def solve(self, pset):
        N = int(pset[0])
        self.windows = [codejam.parsein('ii', ps) for ps in pset[1:]]
        self.windows2 = []
        count = 0
        for A, B in self.windows:
            if self._exist(A, B):
                count += 1
            self.windows2.append((A, B))
        return count


if __name__ == '__main__':
    p = codejam.Problem(ProblemA) 
    p.solve(set_collect=_scollect)


import codejam
import math

class ProblemA(codejam.Solver):

    def solve(self, pset):
        snappers, snaps = codejam.parsein('ii', pset[0])
        return "ON" if (snaps + 1) % (2 ** snappers) == 0 else "OFF"


if __name__ == '__main__':
    p = codejam.Problem(ProblemA) 
    p.solve()

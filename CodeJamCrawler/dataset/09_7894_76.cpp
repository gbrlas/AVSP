import codejam
import re

def collect(fp):
    L, D, N = codejam.parsein('iii', fp.readline())
    ret = []
    for i in xrange(D):
        pset = fp.readline().strip()
        ret.append(pset)
    return (L, D, N), ret

        
class Solution(codejam.Solver):

    def solve(self, pset):
        regex = pset
        matches = 0
        for word in self.collection:
            if re.match(regex.replace('(', '[').replace(')', ']'), word):
                matches += 1
        return matches


if __name__ == '__main__':
    cj = codejam.Problem(solver=Solution)
    cj.solve(collect)

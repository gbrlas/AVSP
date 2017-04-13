import codejam
import itertools

def collect(fp, first):
    P, Q = codejam.parsein('ii', first)
    numbers = map(int, fp.readline().strip().split(' '))
    yield (P, Q, numbers)

class Solution(codejam.Solver):

    def release_prisioners(self, pr, n):
        pr[n] = None
        i = 0
        golds = 0
        first = end = False
        while not first or not end:
            i += 1
            first = first or ((n - i < 0) or pr[n - i] == None)
            end = end or ((n + i >= self.P) or pr[n + i] == None)
            if not end:
                golds += 1

            if not first:
                golds += 1

        return golds

    def solve(self, pset):
        self.P, self.Q, numbers = pset[1]
        golds = -1
        for p in itertools.permutations(numbers):
            prisioners = [0] * self.P
            agolds = 0
            for n in p:
                agolds += self.release_prisioners(prisioners, n-1)
            golds = min(agolds, golds) if golds != -1 else agolds

        return golds
        

if __name__ == '__main__':
    cj = codejam.Problem(solver=Solution)
    cj.solve(collect)

import codejam
import os

class Solution(codejam.Solver):

    def solve(self, lines):
        in_, out, err = os.popen3('perl regex.pl "%s"' % lines[0])
        out = out.read() or '0'
        return str(out)[-4:].zfill(4)


if __name__ == '__main__':
    cj = codejam.Problem(solver=Solution)
    cj.solve()

import codejam
import numpy

def _scollect(fp, first):
    R, K = codejam.parsein('ii', first)
    return [fp.readline().strip() for x in xrange(R)]

class ProblemA(codejam.Solver):

    def _move(self, list_):
        j = -1
        for i in xrange(self.R - 1, -1, -1):
            if list_[i] == '.': 
                j = max(j, i)
                continue
            elif j != -1: 
                list_[j] = list_[i]
                list_[i] = '.'
                j -= 1

    def solve(self, pset):
        self.R, self.K = codejam.parsein('ii', pset.pop(0))
        bstr = 'B' * self.K
        rstr = 'R' * self.K
        matrix = [list(e) for e in pset]
        for elem in matrix:
            if ''.join(elem) != '.' * len(elem):
                self._move(elem)

        red = blue = False
        for line in matrix:
            line = ''.join(line)
            if bstr in line: blue = True
            if rstr in line: red = True

        ar = numpy.array(matrix)
        for i in xrange(self.R):
            line = ''.join(ar.diagonal(offset=i))
            line1 = ''.join(ar.diagonal(offset=-i))

            if bstr in line or bstr in line1: blue = True
            if rstr in line or rstr in line1: red = True

            if red and blue: break

        if not (red and blue):
            rotated = zip(*matrix[::-1])
            for line in rotated:
                line = ''.join(line)
                if bstr in line: blue = True
                if rstr in line: red = True

                if red and blue: break

            ar = numpy.array(rotated)
            for i in xrange(self.R):
                line = ''.join(ar.diagonal(offset=i))
                line1 = ''.join(ar.diagonal(offset=-i))

                if bstr in line or bstr in line1: blue = True
                if rstr in line or rstr in line1: red = True

                if red and blue: break

        if red and blue: return 'Both'
        elif red: return 'Red'
        elif blue: return 'Blue'
        else: return 'Neither'


if __name__ == '__main__':
    p = codejam.Problem(ProblemA) 
    p.solve(set_collect=_scollect)


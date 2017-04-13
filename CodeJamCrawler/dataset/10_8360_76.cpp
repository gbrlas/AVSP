import codejam
import decimal

class ProblemB(codejam.Solver):

    def _mcd(self, a, b):
        return a if b == 0 else self._mcd(b, a % b)

    def divceil(self, a, b):
        a = decimal.Decimal(str(a))
        b = decimal.Decimal(str(b))
        div = a / b
        if int(a / b) < div:
            div += 1

        return int(div)

    def solve(self, pset):
        digits = map(int, pset[0].split(' '))
        count = digits.pop(0)
        digits.sort(reverse=True)
        if len(digits) == 3:
            _mcd = self._mcd(digits[0] - digits[1], digits[1] - digits[2])
        else:
            _mcd = digits[0] - digits[1]

        distance = self.divceil(digits[-1], float(_mcd)) * _mcd
        return int(distance - digits[-1])



if __name__ == '__main__':
    p = codejam.Problem(ProblemB) 
    p.solve()

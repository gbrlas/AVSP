import codejam
import string

BIG = '1023456789' + string.ascii_lowercase * 2

class Solution(codejam.Solver):

    def get_alphabet(self, base):
        return BIG[:base]

    def solve(self, pset):
        word = pset[0]
        base = len(set(word))
        if base < 2:
            base = 2
        alphabet = self.get_alphabet(base)
        eq = {}
        i = 0
        num = []
        for l in word:
            if l not in eq:
                eq[l] = alphabet[i]
                i += 1

            num.append(eq[l])
        num = ''.join(num)
        return int(num, base)
        

if __name__ == '__main__':
    cj = codejam.Problem(solver=Solution)
    cj.solve()

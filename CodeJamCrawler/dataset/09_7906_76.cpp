import codejam

MAX = 10000

def collect(fp, first):
    W, H = codejam.parsein('ii', first)
    for i in xrange(W):
        yield map(int, fp.readline().strip().split(' '))

class Solution(codejam.Solver):

    def replaceletters(self, old, new):
        for r, cols in self.solution.iteritems():
            for c, letter in cols.iteritems():
                if letter == old:
                    self.solution[r][c] = new

    def solve_maze(self, r, c, letter):
        letter = chr(letter)
        actual = self.matrix[r][c]
        if r in self.solution:
            if c in self.solution[r]:
                self.replaceletters(letter, self.solution[r][c])
                self.actual_letter = ord(letter) - 1
                letter = self.solution[r][c]
                return
            self.solution[r][c] = letter
        else:
            self.solution[r] = {c: letter}

        letter = ord(letter)
        north = self.matrix[r - 1][c] if r - 1 >= 0 else MAX
        south = self.matrix[r + 1][c] if self.rows > r + 1 else MAX
        west = self.matrix[r][c - 1] if c - 1 >= 0 else MAX
        east = self.matrix[r][c + 1] if self.cols > c + 1 else MAX        

        min_ = min(actual, north, south, west, east)
        if min_ == actual:
            return
        if north == min_:
            self.solve_maze(r - 1, c, letter)
        elif west == min_:
            self.solve_maze(r, c - 1, letter)
        elif east == min_:
            self.solve_maze(r, c +1, letter)
        elif south == min_:
            self.solve_maze(r + 1, c, letter)

    def solve(self, lines):
        self.matrix = lines[1:]
        self.solution = {}
        self.rows, self.cols = map(int, lines[0].split(' '))
        self.actual_letter = 96
        self._solve()

        all = []
        for r, cols in self.solution.iteritems():
            lines = []
            for c, letter in cols.iteritems():
                lines.append(letter)
            all.append(' '.join(lines))
        return '\n' + '\n'.join(all)

    def _solve(self):
        for r in xrange(self.rows):
            for c in xrange(self.cols):
                if not (r in self.solution and c in self.solution[r]):
                    self.actual_letter += 1
                    self.solve_maze(r, c, self.actual_letter)
                    self._solve()
                else:
                    continue


if __name__ == '__main__':
    cj = codejam.Problem(solver=Solution)
    cj.solve(collect)

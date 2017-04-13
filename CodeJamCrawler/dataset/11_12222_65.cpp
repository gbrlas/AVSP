import sys


class Parsed: pass


class Parser(object):

    @classmethod
    def parse_tuple(klass, fileobj, other):
        size = int(fileobj.readline().strip('\n'))
        return map(other, fileobj.readline().strip('\n').split())

    @classmethod
    def parse_set(klass, fileobj, other):
        s1, s2 = map(int, fileobj.readline().strip('\n').split())
        first = [other(fileobj.readline().strip('\n')) for w in xrange(s1)]
        second = [other(fileobj.readline().strip('\n')) for w in xrange(s2)]
        return first, second


class CodeJam(object):
    
    data = None
    cast = {
        int: lambda x, y: int(x.readline().strip('\n')),
        str: lambda x, y: str(x.readline().strip('\n')),
        tuple: Parser.parse_tuple,
        set: Parser.parse_set,
        list: lambda x, y: map(y, x.readline().strip('\n').split())
    }

    def dosolve(self):
        return NotImplementedError

    def solve(self):
        fileobj = open(sys.argv[1])
        self.cases = int(fileobj.readline()[:-1])
        self.parsed = []
        while True:
            obj = Parsed()
            for var, type_, extra in self.data:
                try:
                    data = self.cast[type_](fileobj, extra)
                except ValueError:
                    data = None
                    break

                setattr(obj, var, data)

            if not data: break

            yield self.dosolve(obj)

    def write(self):
        res = open('%s.sol' % sys.argv[1], 'w')
        for i, solution in enumerate(self.solve()):
            line = 'Case #%d: %s\n' % (i + 1, solution)
            print line
            res.write(line)

        res.close()

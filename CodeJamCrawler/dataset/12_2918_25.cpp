
import sys


def main(data):
    m, n = data.split()
    m, n = int(m), int(n)
    nums = range(m, n+1)
    recs = []
    count = 0

    for i in nums:
        if i > 9:
            recs = []
            for p in range(1, len(str(i))):
                r = int(str(i)[p:] + str(i)[:p])
                if r > i and r in nums and r not in recs:
                    count += 1
                    recs.append(r)

    return str(count)

data = """
4
1 9
10 40
100 500
1111 2222
"""

data = """
3
1 9
10 40
100 500
1111 2222
"""

if __name__ == '__main__':
    if len(sys.argv) > 1:
        data = open(sys.argv[1], 'r').read()
    
    lines = data.strip().split('\n')
    case = 0
    for line in lines[1:]:
        case += 1
        print "Case #" + str(case) + ": " + main(line)

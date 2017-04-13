
# ejp mysljylc kd kxveddknmc re jsicpdrysi
# our language is impossible to understand
#
# rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
# there are twenty six factorial possibilities
#
# de kr kd eoya kw aej tysr re ujdr lkgc jv
# so it is okay if you want to just give up


import sys

input = """
3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
"""

mapping = {
    'a': 'y', 
    'b': 'h',
    'c': 'e',
    'd': 's',
    'e': 'o',
    'f': 'c',
    'g': 'v',
    'h': 'x',
    'i': 'd',
    'j': 'u',
    'k': 'i',
    'l': 'g',
    'm': 'l',
    'n': 'b',
    'o': 'k',
    'p': 'r',
    'q': 'z',
    'r': 't',
    's': 'n',
    't': 'w',
    'u': 'j',
    'v': 'p',
    'w': 'f',
    'x': 'm',
    'y': 'a',
    'z': 'q',
    ' ': ' '
}

def ungooglify(s):
    out = ""
    for c in s:
        if c in mapping:
            out += mapping[c]
        else:
            out += c
    return out

def main(input):
    case = 0
    for line in input[1:]:
        case += 1
        print "Case #" + str(case) + ": " + ungooglify(line)


if __name__ == '__main__':
    if len(sys.argv) > 1:
        input = open(sys.argv[1], 'r').read()
    main(input.strip().split('\n'))

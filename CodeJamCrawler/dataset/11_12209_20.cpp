import codejam

class Solver(codejam.CodeJam):

    data = (('V1', set, str),)

    def dosolve(self, case):
        teams = []
        for i, row in enumerate(case.V1):
            played = len(row.replace('.', ''))
            win = row.count('1')
            wp = win / float(played)

            opponents_wps = 0
            matches = 0
            for j, op in enumerate(case.V1):
                if case.V1[i][j] == '.': continue
                if j == i: continue

                op = list(op)
                del op[i]

                op = ''.join(op)
                played = len(op.replace('.', ''))
                win = op.count('1')
                opponents_wps += win / float(played)
                matches += 1


            teams.append({
                'owp': opponents_wps / matches,
                'wp': wp,
                'oowp': 0
            })
        
        res = ""
        for i, row in enumerate(case.V1):
            matches = 0
            team = teams[i]
            for j, op in enumerate(case.V1):
                if case.V1[i][j] == '.': continue
                if i == j: continue

                team['oowp'] += teams[j]['owp']
                matches += 1

            team['oowp'] = team['oowp'] / matches
            team['rpi'] = 0.25 * team['wp'] + 0.50 * team['owp'] + 0.25 * team['oowp']


            res += '\n%.12f' % team['rpi']
            
        return res

s = Solver()
s.write()


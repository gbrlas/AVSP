import codejam

def _scollect(fp, first):
    return [fp.readline().strip()]

class ProblemC(codejam.Solver):

    def solve(self, pset):
        R, k, count = codejam.parsein('iii', pset[0])
        groups = codejam.parsein('i' * count, pset[1])
        total_people = sum(groups)
        if total_people < k:
            return R * total_people

        occuped = money = 0
        _cache = {}
        limbo = []
        cache_enabled = True
        while True:
            if len(groups) == 0 or groups[0] + occuped > k:
                R -= 1
                if R == 0: break

                for elm in limbo: groups.append(elm)
                limbo = []

                key = hash("".join(map(str, groups)))
                if key in _cache and cache_enabled:
                    last_money, last_R = _cache[key]
                    total_money = money - last_money
                    total_R = last_R - R - 1

                    spines = R / total_R

                    R -= (spines * total_R)
                    money += spines * total_money
                    cache_enabled = False

                else:
                    _cache[key] = (money, R + 1)

                occuped = 0
                if R == 0: break
                
            occuped += groups[0]
            money += groups[0]
            limbo.append(groups.pop(0))

        return money


if __name__ == '__main__':
    p = codejam.Problem(ProblemC) 
    p.solve(set_collect=_scollect)

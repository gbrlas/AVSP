package r014

class DeceitWar {
    public static void main(String[] args) {
        //def name = "war.txt"
        def name = "D-small-attempt0.in"
        def file = new File("inputs/${name}")
        def out = new File(file.getParent(), "${file.name[0..-5]}_out.txt")
        out.delete()

        def answers = []
        def lines = file.readLines().reverse()
        def T = lines.pop().toInteger()
        T.times {
            lines.pop()
            def blocks1 = lines.pop().split(" ").collect { it.toDouble() }
            def blocks2 = lines.pop().split(" ").collect { it.toDouble() }
            answers += solution(blocks1, blocks2)
        }

        out.withWriter { writer ->
            answers.eachWithIndex { a, idx ->
                def line = "Case #${idx + 1}: $a"
                println(line)
                writer.writeLine(line)
            }
        }
    }

    static def solution(List<Double> naomi, List<Double> ken) {
        def ans = []
        naomi.sort()
        ken.sort()

        if (naomi.last() < ken.first()) {
            //if ken has all heavier, nothing to do
            ans = [0, 0]
        } else if (naomi.first() > ken.last()) {
            //if naomi has all heavier, nothing to do
            ans = [naomi.size(), naomi.size()]
        } else {
            ans << cheat(naomi, ken) << fair(naomi, ken)
        }
        return ans.join(" ")
    }

    static def cheat(List<Double> naomi, List<Double> ken) {
        naomi = new ArrayList<>(naomi)
        ken = new ArrayList<>(ken)
        int pts = 0

        while (!naomi.isEmpty()) {
            if (naomi.first() > ken.last()) {
                //naomi has all greater elements so stop
                pts += naomi.size()
                break
            } else if (naomi.first() > ken.first()) {
                //first prio: trick ken into dumping all his mins that naomi can win
                //lie: naomi says large number to force ken's min, both play min, naomi wins pt
                ken.remove(0)
                naomi.remove(0)
                pts++
            } else {
                //next prio: trick ken to pull his max
                //lie: naomi says number large enough to force ken's max, naomi plays her min
                ken.pop()
                naomi.remove(0)
            }
        }
        return pts
    }

    static def fair(List<Double> naomi, List<Double> ken) {
        naomi = new ArrayList<>(naomi)
        ken = new ArrayList<>(ken)
        int pts = 0

        while (!naomi.isEmpty()) {
            if (naomi.first() > ken.last()) {
                //when naomi's min beat's ken's max, ken is maxed out & naomi takes the rest
                pts += naomi.size()
                break
            } else {
                //ken will always plays min to beat naomi
                def nOpt = naomi.remove(0)
                def kIdx = (-Collections.binarySearch(ken, nOpt)) - 1
                ken.remove(kIdx)
            }
        }
        return pts
    }
}

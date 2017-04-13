package r014

class MagicTrick {
    public static void main(String[] args) {
        def file = new File(this.getResource("A-small-attempt0.in.txt").toURI())
        def out = new File(file.getParent(), "${file.name[0..-5]}_out.txt")
        out.delete()

        def answers = []
        def lines = file.readLines().reverse()
        def T = lines.pop().toInteger()
        T.times {
            def readGrid = {
                def grid = []
                4.times {
                    grid << lines.pop().split(" ").collect { it.toInteger() }
                }
                grid
            }

            int pick1 = lines.pop().toInteger()
            def grid1 = readGrid()
            int pick2 = lines.pop().toInteger()
            def grid2 = readGrid()

            answers += getCard(pick1, grid1, pick2, grid2)
        }

        out.withWriter { writer ->
            answers.eachWithIndex { a, idx ->
                def line = "Case #${idx + 1}: $a"
                println(line)
                writer.writeLine(line)
            }
        }
    }

    static def getCard(int pick1, def grid1, int pick2, def grid2) {
        def row1 = grid1[pick1 -1] as List
        def row2 = grid2[pick2 -1] as List

        row1.retainAll(row2)

        def ans = ""
        switch(row1.size()){
            case 0:
                ans = "Volunteer cheated!";
                break
            case 1:
                ans = "${row1.first()}";
                break
            default:
                ans = "Bad magician!"
        }
        return ans
    }
}

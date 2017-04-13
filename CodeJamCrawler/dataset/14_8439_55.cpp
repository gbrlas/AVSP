package r014

class B_Cookie {
    public static void main(String[] args) {
        def name = "B-large.in"
        def file = new File("inputs/${name}")
        def out = new File(file.getParent(), "${file.name[0..-5]}_out.txt")
        out.delete()

        def answers = []
        def lines = file.readLines().reverse()
        def T = lines.pop().toInteger()
        T.times {
            def (double c, double f, double x) = lines.pop().split(" ").collect{ it.toDouble()}
            answers += solution(c, f, x)
        }

        out.withWriter { writer ->
            answers.eachWithIndex { a, idx ->
                def line = "Case #${idx + 1}: $a"
                println(line)
                writer.writeLine(line)
            }
        }
    }

    static def solution(double c, double f, double x) {
        double cps = 2
        double secs = 0

        while (true) {
            double curTime = x / cps
            double farmPurchaseTime = (x / (cps + f)) + (c/cps)

            if (farmPurchaseTime < curTime) {
                //time it takes to buy the farm
                secs += c/cps
                //buy the farm, get faster
                cps += f
            } else {
                //don't buy
                secs += x/cps
                break
            }
        }
        return secs
    }
}

import java.io.BufferedReader

object NewLotteryGame extends App with GoogleCodeJam{
  main("NewLotteryGame/B-small-attempt1.in")

  override def solve(br: BufferedReader): String = {
    val ligne = br.readLine.split(" ").map(_.toInt)
    val a = ligne(0)
    val b = ligne(1)
    val k = ligne(2)
    var nbOfSol = 0
    for (i <- 0 to a - 1; j <- 0 to b - 1){
      if (Integer.parseInt(boolAnd( i.toBinaryString, j.toBinaryString), 2) < k){
        nbOfSol = nbOfSol + 1
      }
    }
    nbOfSol.toString
  }

  def boolAnd(s: String, t: String) = {
    var sBis = s
    var tBis = t
    sBis = "0" * (t.length - s.length) + s
    tBis = "0" * (s.length - t.length) + t
    (for (i <- 0 to (tBis.length - 1)) yield if (sBis.charAt(i) == '1' && tBis.charAt(i) == '1') "1" else "0").mkString("")
  }
}

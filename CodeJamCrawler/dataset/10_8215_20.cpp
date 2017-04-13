import scala.io.Source
import java.io.File
import java.io.PrintWriter

class RC(val cap:Int, val usage:Int) {
  def canGetMore(more:Int) : Boolean = ((usage + more) <= cap)
  def getMore(more:Int) : RC = new RC(cap, usage+more)
  def roll : Int = usage
  override def toString = "cap = " +cap +", usage = " +usage
}

def getPeopleOn(rc:RC, qLeft:List[Int], qUsed:List[Int]) : (RC, List[Int]) = {
  qLeft match {
    case Nil => (rc, qUsed)
    case _ =>
      rc.canGetMore(qLeft.head) match {
        case true => getPeopleOn(rc.getMore(qLeft.head), qLeft.tail,  qUsed ::: List(qLeft.head))
        case _ => (rc, qLeft ::: qUsed)
    }
  }
  
}

def roll(r:Int, k:Int, q:List[Int], sumMoney:Int) : Int = {
  val rc = new RC(k, 0)
  val out = getPeopleOn(rc, q, Nil)
  //println(out)
  //println(r)
  val money = out._1.roll + sumMoney
  r match {
    case 1 => money
    case _ => roll(r-1, k, out._2, money) 
  }
}

def doProb(r:Int, k:Int, q:List[Int]) : String = {
  //val ans = "r = " +r +", k = " +k +", n = " +n +", c = " +c
  roll(r, k, q, 0).toString
}

//println(doProb(100, 10, List(1)))


def doProb(line:String, line2:String) : String = {
  val a:Array[String] = line.split(" ")
  val r = a(0).toInt
  val k = a(1).toInt
  val b:List[String] = line2.split(" ").toList
  val c:List[Int] = for (
                      z <- b
                    ) yield z.toInt
  if (a(2).toInt != c.length) throw new RuntimeException("Hurrr")
  doProb(r, k, c)
}

def collectAns(n:Int, source:Source, ans:List[String]) : List[String] = {
  n match {
    case 0 => ans
    case _ => collectAns(n-1, source, List("Case #" +n +": " +doProb(source.getLine(n*2), source.getLine(n*2+1))) ::: ans)
  }
}

val in = "C-small-attempt3.in"
//val in = "mock.in"
val out = "small.out"
//val out = "mock.out"
def write(l:String, p:PrintWriter) {
  p.write(l + "\n")
}
val r = Source.fromFile(in)
val n = r.getLine(1).toInt
val ans = collectAns(n, r, Nil)
val p = new PrintWriter(new File(out))
ans.foreach( s => write(s, p))
p.close


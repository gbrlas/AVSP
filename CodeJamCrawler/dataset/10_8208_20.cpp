import scala.io.Source
import java.io.File
import java.io.PrintWriter

class Snapper(val input:Boolean, val state:Boolean) {
  def bidirectional = (!input || state) && (input || !state)
  def out = input && state
  def toggle(bOut:Boolean) = 
    bOut match {
      case true => 
        bidirectional match {
          case true => new Snapper(true, false)
          case _ => new Snapper(true, true)
        }
      case _ => 
        bidirectional match {
          case true => new Snapper(false, false)
          case _ => new Snapper(false, true)
        }
    }
  override def toString = "s(" +input +"," +state +")"
}

class SGroup(val sList:List[Snapper]) {
  private def toggle : SGroup = toggle(sList.tail, List(sList.head.toggle(true)))
  private def toggle(tempL:List[Snapper], ansL:List[Snapper]) : SGroup = 
    tempL match {
      case Nil => new SGroup(ansL)
      case _ => toggle(tempL.tail, ansL ::: List(tempL.head.toggle(ansL.last.out)))
    }
  def toggles(n:Int) : SGroup = toggles(n, new SGroup(sList))
  private def toggles(n:Int, tempGroup:SGroup) : SGroup = {
    //println(n +" " +tempGroup.toString)
    n match {
      case 0 => tempGroup
      case _ => toggles(n-1, tempGroup.toggle)
    }
  }
  def light = if (sList.last.out) "ON" else "OFF" 
  override def toString = sList.toString
}

def prepare(n:Int, accList:List[Snapper]) : List[Snapper] =
  n match {
    case 0 => accList
    case _ => prepare(n-1, accList ::: List(new Snapper(false, false)))
  }

def prepare(n:Int) : List[Snapper] = prepare(n-1, List(new Snapper(true, false)))

def doProb(n:Int, t:Int) : String = {
  val sGroup = new SGroup(prepare(n))
  sGroup.toggles(t).light
}

def doProb(line:String) : String = {
  val a:Array[String] = line.split(" ")
  val n = a(0).toInt
  val t = a(1).toInt
  doProb(n, t)
}

def collectAns(n:Int, source:Source, ans:List[String]) : List[String] = {
  //println((n-1) +" " +source.getLine(n))
  n match {
    case 1 => ans
    case _ => collectAns(n-1, source, List("Case #" +(n-1) +": " +doProb(source.getLine(n))) ::: ans)
  }
}
val in = "A-small-attempt1.in"
//val in = "mock.in"
val out = "small.out"
//val out = "mock.out"
def write(l:String, p:PrintWriter) {
  p.write(l + "\n")
}
val r = Source.fromFile(in)
val n = r.getLine(1).toInt + 1
val ans = collectAns(n, r, Nil)
val p = new PrintWriter(new File(out))
//print(ans)
ans.foreach( s => write(s, p))
p.close

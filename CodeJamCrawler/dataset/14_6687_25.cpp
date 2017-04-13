import java.io.BufferedReader

/**
 * Created by gplassard on 12/04/2014.
 */
object MagicTrick extends App with GoogleCodeJam {
  main("MagicTrick/A-small-attempt0.in")


  override def solve(br: BufferedReader): String = {
    val row1 = br.readLine.toInt - 1
    val disposition1 = (1 to 4).map{ _ =>
      br.readLine.split(" ").map(_.toInt).toList
    }.toList
    val row2 = br.readLine.toInt - 1
    val disposition2 = (1 to 4).map{ _ =>
      br.readLine.split(" ").map(_.toInt).toList
    }.toList

    val possibles = disposition1(row1).intersect(disposition2(row2))
    possibles.size match {
      case 0 => "Volunteer cheated!"
      case 1 => possibles.head.toString
      case _ => "Bad magician!"
    }
  }
}

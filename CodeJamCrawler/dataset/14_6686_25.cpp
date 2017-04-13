import java.io._

/**
 * Created by gplassard on 04/04/2014.
 */
trait GoogleCodeJam {

  def solve(br: BufferedReader): String

  def main(fileName: String){
    val br = new BufferedReader(new FileReader(new File("src/main/resources/" + fileName)))
    val bw = new BufferedWriter(new FileWriter(new File("src/main/resources/" + fileName.replace(".in",".out"))))
    val size = br.readLine.toInt
    for (i <- 1 to size){
      val solution = solve(br)
      val write = s"Case #$i: $solution"
      println(write)
      bw.write(write)
      bw.newLine()
    }
    br.close()
    bw.close()
  }
}

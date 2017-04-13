import java.io.BufferedReader

/**
 * Created by gplassard on 12/04/2014.
 */
object CookieClickerAlpha extends App with GoogleCodeJam{
  main("CookieClickerAlpha/B-small-attempt0.in")

  override def solve(br: BufferedReader): String = {
    val ligne = br.readLine.split(" ").map(BigDecimal(_))
    val C = ligne(0)
    val F = ligne(1)
    val X = ligne(2)
    var cookies = BigDecimal(0.00000000)
    var cps = BigDecimal(2.0000000000)
    var time = BigDecimal(0.0000000000)
    while (cookies < X){
      val tempsSansFerme = (X - cookies) / cps
      val tempsPourAvoirFerme = (C - cookies) / cps
      val tempsAvecFerme = tempsPourAvoirFerme +  X / (cps + F)
      if (tempsSansFerme < tempsAvecFerme){
        time = time + tempsSansFerme
        cookies = X
      } else {
        time = time + tempsPourAvoirFerme
        cps = cps + F
        cookies = 0
      }
    }
    time.toString
  }
}

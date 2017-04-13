import java.util.*;
import java.io.*;
import java.text.*;
public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			BufferedReader br = new BufferedReader(new FileReader("c.in"));
			PrintWriter pw = new PrintWriter(new FileWriter("c_output.txt"));
			int num = Integer.parseInt(br.readLine());
			for (int i=0; i<num; i++) {
				String s = br.readLine();
				StringTokenizer token = new StringTokenizer(s);
				double f = Double.parseDouble(token.nextToken());
				double R = Double.parseDouble(token.nextToken());
				double t= Double.parseDouble(token.nextToken());
				double r = Double.parseDouble(token.nextToken());
				double g = Double.parseDouble(token.nextToken());

				int gnum=0;
				double gsub=0.0;
				double sub=0.0;
				/*
				for (int j=0; j<(R-t+r)/(g+2*r)+1; j++) {
					for (int k=0; k<(R-t+r)/(g+2*r)+1; k++) {
						boolean signal = true;
						if (Math.pow(r+(g+2*r)*j+g,2)+Math.pow(r+(g+2*r)*k+g,2) > (R-t)*(R-t)) {
							signal = false;
							if (Math.pow(r+(g+2*r)*j+f,2)+Math.pow(r+(g+2*r)*k+f,2) < (R-t)*(R-t)) {

								sub = 0.0;

								for (double m=r+(g+2*r)*j+f; m<r+(g+2*r)*j+g-f; m+= g/1000.0){

									for (double n=r+(g+2*r)*k+f; n<r+(g+2*r)*k+g-f; n+= g/1000.0){
										if (m*m+n*n<=(R-t)*(R-t)) {
											sub+= 0.0000001;
										}
									}

								}
							}
						}
						gsub = gsub+sub*g*g;
						if (signal) {
							gnum++;

						}
					}
				}
				 */

				/*
				double result=0.0;
				if (g<=2*f) {
					result=1.0;
				} else {
					for (int j=0; j<(R-t+0.5*g)/(g+2*r)+1; j++) {
						for (int k=0; k<(R-t+0.5*g)/(g+2*r)+1; k++) {
							double fac = 1.0;
							if (j==0) {
								fac*= 0.5;

							}
							if (k==0) {
								fac*= 0.5;
							}

							if (Math.pow((g+2.0*r)*j+0.5*g,2.0)+Math.pow((g+2.0*r)*k+0.5*g,2.0) >= (R-t)*(R-t)) {

								sub=0.0;

								if (Math.pow((g+2.0*r)*j-0.5*g,2.0)+Math.pow((g+2.0*r)*k-0.5*g,2.0) < (R-t)*(R-t)) {
									//System.out.println("j="+j+" k="+k);
									double unit=500.0;
									for (int m=0; m<unit; m++) {
										for (int n=0; n<unit; n++) {
											if (Math.pow((g+2.0*r)*j-0.5*g+f+(g-2.0*f)/unit*m,2)+Math.pow((g+2.0*r)*k-0.5*g+f+(g-2.0*f)/unit*n,2)<=(R-t-f)*(R-t-f)) {
												sub+= 1.0/unit/unit;

											}
										}
									}
									//System.out.println(sub);
								}

							} else {
								sub = 1.0;
							}
							gsub +=sub*(g-2.0*f)*(g-2.0*f)*fac;


						}
					}
					result = 1.0-gsub/(Math.PI*R*R/4.0);
				 */
				double result=0.0;
				if (g<=2*f) {
					result=1.0;
				} else {
					int jNum = (int)((R-t-r)/(g+2*r));
					double subArray[][] = new double[jNum+1][jNum+1];
					for (int j=0; j<(R-t-r)/(g+2*r); j++) {
						for (int k=0; k<(R-t-r)/(g+2*r); k++) {
							if (k<j) {
								sub = subArray[k][j];
							}
							else {


								if (Math.pow((g+2.0*r)*j+r+g,2.0)+Math.pow((g+2.0*r)*k+r+g,2.0) >= (R-t)*(R-t)) {

									sub=0.0;

									if (Math.pow((g+2.0*r)*j+r,2.0)+Math.pow((g+2.0*r)*k+r,2.0) < (R-t)*(R-t)) {
										//System.out.println("j="+j+" k="+k);
										double unit=1000.0;
										for (int m=0; m<unit; m++) {
											for (int n=0; n<unit; n++) {
												if (Math.pow((g+2.0*r)*j+r+f+(g-2.0*f)/unit*(m+0.5),2)+Math.pow((g+2.0*r)*k+r+f+(g-2.0*f)/unit*(n+0.5),2)<=(R-t-f)*(R-t-f)) {
													sub+= 1.0/(unit+0)/(unit+0);

												}
											}
										}
										//System.out.println(sub);
									}
									
								} else {
									sub = 1.0;
								}
								subArray[j][k]=sub;
							}

							
							gsub +=sub*(g-2.0*f)*(g-2.0*f);


						}
					}
					result = 1.0-gsub/(Math.PI*R*R/4.0);
					/*
					if (result < 0.0) {
						result = 0.0;
					}
					 */

				}
				NumberFormat formatter = new DecimalFormat("0.######");
				String m= formatter.format(result);
				System.out.println("Case #"+(i+1)+": "+m);
				pw.println("Case #"+(i+1)+": "+m);
			}
			pw.close();
		} catch (IOException e) {
			System.out.println("io error");
		}
	}

}

#include <stdio.h>
#include <math.h>

int main() {
	double p = 100;
	double dx = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		double f, R, t, r, g;
		scanf("%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g);
		f /= p; R /= p; t /= p; r /= p; g /= p;
		double each = pow(g - f * 2, 2);
		int num = 0;
		double dis = r + g;
		while (sqrt(pow(dis, 2) * 2) < R - t) {
			num++;
			dis += r * 2 + g;
		}
		double totalVoid = each * pow(num * 2, 2);
		double leftLine = dis - g + f + dx;
		double rightLine = leftLine + g - 2 * (f + dx);
		double borderArea = 0;
		double eachBorderArea = 0;
		double vR = R - t - f;

		if (vR > leftLine)
		for (int j = 0; j < num + 1; j++) {
			double topLine = r + (g + r * 2) * j + f + dx;
			double bottomLine = topLine + g - 2 * (f + dx);
			
			eachBorderArea = 0;
			
			double a = (vR > rightLine) ? sqrt(vR*vR - rightLine*rightLine) : topLine;
			if (a < topLine) a = topLine;
			double b = sqrt(vR*vR - leftLine*leftLine);
			if (b > bottomLine) b = bottomLine;
			if (a > bottomLine) a = bottomLine;
			eachBorderArea += (a - topLine) * (rightLine - leftLine);
			if (a < b)
			eachBorderArea += -0.5 * atan(b * sqrt(vR*vR - b*b) / (b*b - vR*vR))*vR*vR - leftLine * b + 0.5 * b * sqrt(vR*vR - b*b)
					   -( -0.5 * atan(a * sqrt(vR*vR - a*a) / (a*a - vR*vR))*vR*vR - leftLine * a + 0.5 * a * sqrt(vR*vR - a*a));
			if (j < num && eachBorderArea > 0)
				borderArea += eachBorderArea;
		}

		totalVoid += borderArea * 8 + eachBorderArea * 4;
		
		for (int q = 0; q < 5; q++) {
			leftLine += g + 2 * r;
			rightLine = leftLine + g - 2 * (f + dx);
			borderArea = 0;
			eachBorderArea = 0;
			num++;

			if (vR > leftLine)
			for (int j = 0; j < num + 1; j++) {
				double topLine = r + (g + r * 2) * j + f + dx;
				double bottomLine = topLine + g - 2 * (f + dx);
				
				eachBorderArea = 0;
				
				double a = (vR > rightLine) ? sqrt(vR*vR - rightLine*rightLine) : topLine;
				if (a < topLine) a = topLine;
				double b = sqrt(vR*vR - leftLine*leftLine);
				if (b > bottomLine) b = bottomLine;
				if (a > bottomLine) a = bottomLine;
				eachBorderArea += (a - topLine) * (rightLine - leftLine);
				if (a < b)
				eachBorderArea += -0.5 * atan(b * sqrt(vR*vR - b*b) / (b*b - vR*vR))*vR*vR - leftLine * b + 0.5 * b * sqrt(vR*vR - b*b)
						   -( -0.5 * atan(a * sqrt(vR*vR - a*a) / (a*a - vR*vR))*vR*vR - leftLine * a + 0.5 * a * sqrt(vR*vR - a*a));
				if (eachBorderArea > 0) borderArea += eachBorderArea;
			}
			totalVoid += borderArea * 8;
		}
		
		double totalArea = R * R * M_PI;
		double totalHit = 1 - (totalVoid / totalArea);

		printf("Case #%d: %lf\n", i, totalHit);
	}
	return 0;
}

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package codejam2014;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 *
 * @author tino chagua
 */
public class Main{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String cad = br.readLine();
        int T = Integer.valueOf(cad);
        for (int i = 0; i < T; i++) {
            int[] ny = new int[4];
            cad = br.readLine();
            int y = Integer.valueOf(cad);
            for (int j = 1; j <= 4; j++) {
                cad = br.readLine();
                if (j == y) {
                    String[] cada = cad.split(" ");
                    ny[0] = Integer.valueOf(cada[0]);
                    ny[1] = Integer.valueOf(cada[1]);
                    ny[2] = Integer.valueOf(cada[2]);
                    ny[3] = Integer.valueOf(cada[3]);
                }
            }
            cad = br.readLine();
            int[] nx = new int[4];
            y = Integer.valueOf(cad);
            for (int j = 1; j <= 4; j++) {
                cad = br.readLine();
                if (j == y) {
                    String[] cada = cad.split(" ");
                    nx[0] = Integer.valueOf(cada[0]);
                    nx[1] = Integer.valueOf(cada[1]);
                    nx[2] = Integer.valueOf(cada[2]);
                    nx[3] = Integer.valueOf(cada[3]);
                }
            }
            int[] card = new int[17];

            for (int j = 0; j < 4; j++) {
                card[nx[j]]++;
            }

            for (int j = 0; j < 4; j++) {
                card[ny[j]]++;
            }
            int cont = 0;
            int index = 0;
            for (int j = 1; j < 17; j++) {
                if (card[j] == 2) {
                    cont++;
                    index = j;
                }
            }
            if (cont == 1) {
                System.out.println("Case #" + (i + 1) + ": " + index);
            } else if (cont == 0) {
                System.out.println("Case #" + (i + 1) + ": Volunteer cheated!");
            } else if (cont > 1) {
                System.out.println("Case #" + (i + 1) + ": Bad magician!");
            }

        }
    }
}

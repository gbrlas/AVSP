import com.sun.org.apache.bcel.internal.generic.IfInstruction;

import java.util.Scanner;

public class BotTrust {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int numCases = Integer.valueOf(s.nextLine());
        for (int i = 0; i < numCases; ++i) {
            String[] in = s.nextLine().split(" ");
            int btnPresses = Integer.valueOf(in[0]);
            int[][] moves = new int[btnPresses][2];
            int[] oMoves = new int[btnPresses];
            int[] bMoves = new int[btnPresses];
            int bti = 0;
            int oi = -1;
            int bi = -1;
            for (int j = 1; j < btnPresses * 2; j += 2) {
                if (in[j].equals("O")) {
                    moves[bti][0] = 0;
                    oMoves[++oi] = bti;
                } else {
                    moves[bti][0] = 1;
                    bMoves[++bi] = bti;
                }
                moves[bti][0] = in[j].equals("O") ? 0 : 1;
                moves[bti++][1] = Integer.valueOf(in[j + 1]) - 1; // zero index everything
            }
            System.out.println(String.format("Case #%d: %d",
                    i + 1,
                    doIt(moves, oi, oMoves, bi, bMoves)));
        }

    }

    public static int doIt(int[][] moves, int oi, int[] oMoves, int bi, int[] bMoves) {
        int om = 0;
        int bm = 0;
        int opos = 0;
        int bpos = 0;
        boolean bDone = (bi < 0);
        boolean oDone = (oi < 0);

        int[] oNextMove = oDone ? null : moves[oMoves[om++]];
        int[] bNextMove = bDone ? null : moves[bMoves[bm++]];
        int fin = 0;
        int cnt = 0;

        int odist = -1;
        int odir = 0;
        int absO = 0;
        int oLeft = oi + 1;

        int bdist = -1;
        int bdir = 0;
        int absB = 0;
        int bLeft = bi + 1;

        while (fin < moves.length) {
            int[] nextMove = moves[fin];

            if (oDone) {
                odist = -1;
                odir = 0;
                absO = 0;
                oLeft = 0;
            } else {
                odist = oNextMove[1] - opos;
                odir = oNextMove[1] > opos ? 1 : -1;
                absO = (odist > 0) ? odist : -odist;
                oLeft = (oi + 1) - om;
            }

            if (bDone) {
                bdist = -1;
                bdir = 0;
                absB = 0;
                bLeft = 0;
            } else {
                bdist = bNextMove[1] - bpos;
                bdir = bNextMove[1] > bpos ? 1 : -1;
                absB = (bdist > 0) ? bdist : -bdist;
                bLeft = (bi + 1) - bm;
            }
            boolean oPush = absO == 0 && (nextMove == oNextMove);
            boolean bPush = absB == 0 && (nextMove == bNextMove);

            if (oPush && bPush) {
                // if both can push, whoever needs to move the least pushes while the other moves
                if (absO > absB) {
                    // orange to move
                    opos += odir;
                    // blue to push
                    ++fin;
                    if (bm < bi) {
                        bNextMove = moves[bMoves[bm++]];
                    } else {
                        bNextMove = null;
                        bDone = true;
                    }
                } else if (absB > absO) {
                    // blue to move
                    bpos += bdir;
                    // orange to push
                    ++fin;
                    if (om < oi) {
                        oNextMove = moves[oMoves[om++]];
                    } else {
                        oNextMove = null;
                        oDone = true;
                    }
                } else {
                    // two positions are equal, pick orange
                    ++fin;
                    if (oLeft > bLeft) {
                        if (om < oi) {
                            oNextMove = moves[oMoves[om++]];
                        } else {
                            oNextMove = null;
                            oDone = true;
                        }
                    } else {
                        if (bm < bi) {
                            bNextMove = moves[bMoves[bm++]];
                        } else {
                            bNextMove = null;
                            bDone = true;
                        }

                    }
                }
            } else if (oPush && !bPush) {
                // b should be moving
                if (absB > 0) {
                    bpos += bdir;
                }
                // orange to push
                ++fin;
                if (om < moves.length) {
                    oNextMove = moves[oMoves[om++]];
                } else {
                    oNextMove = null;
                    oDone = true;
                }
            } else if (bPush && !oPush) {
                // o should move
                if (absO > 0) {
                    opos += odir;
                }
                // blue to push
                ++fin;
                if (bm < moves.length) {
                    bNextMove = moves[bMoves[bm++]];
                } else {
                    bNextMove = null;
                    bDone = true;
                }
            } else {
                // both should move if they need to
                if (absO > 0) {
                    opos += odir;
                }
                if (absB > 0) {
                    bpos += bdir;
                }
            }
            ++cnt; // "seconds"
        }
        return cnt;
    }
}

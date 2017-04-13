/* Language used is Pike: http://pike.lysator.liu.se/ */
bool fairSquare(int A) {
  if (sqrt(A)*sqrt(A) != A) return false;
  string s = sprintf("%d", A), t = sprintf("%d", sqrt(A));
  return s == reverse(s) && t == reverse(t);
}
int main() {
    for (int zz=1, T = (int)Stdio.stdin.gets(); zz <= T; zz++) {
      [int A, int B] = (array(int))(Stdio.stdin.gets() / " ");
      write(sprintf("Case #%d: %d\n", zz, 
        sizeof(filter(enumerate(B-A+1,1,A,`+), fairSquare))));
    }
    return 0;
}

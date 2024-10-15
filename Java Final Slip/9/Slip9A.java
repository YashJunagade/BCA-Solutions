class Slip9A {
  public static void main(String[] args) {
    int n = 4;
    for (int i = 1; i <= n; i++) {
      int p = (i % 2 == 0) ? 0 : 1;
      for (int j = 1; j <= i; j++) {
        System.out.print(p + " ");
        p = 1 - p;
      }
      System.out.println();
    }
  }
}

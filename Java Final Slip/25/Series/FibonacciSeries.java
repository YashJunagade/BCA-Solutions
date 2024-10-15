package Series;

public class FibonacciSeries {
  public static void printF(int n) {
    int a = 0, b = 1;

    System.out.print("Fibonacci Series : ");
    for (int i = 1; i <= n; i++) {
      System.out.print(a + " ");
      int ans = a + b;
      a = b;
      b = ans;
    }
    System.out.println();
  }
}

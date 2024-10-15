package Series;

public class CubeSeries {
  public static void printC(int n) {
    System.out.print("Cube Series : ");
    for (int i = 1; i <= n; i++) {
      System.out.print(i * i * i + " ");
    }
    System.out.println();
  }
}

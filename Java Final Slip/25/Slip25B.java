import Series.FibonacciSeries;
import Series.CubeSeries;
import Series.SquareSeries;
import java.util.*;

class Slip25B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the term n : ");
		int n = sc.nextInt();

		FibonacciSeries fibo = new FibonacciSeries();
		fibo.printF(n);

		CubeSeries cube = new CubeSeries();
		cube.printC(n);

		SquareSeries square = new SquareSeries();
		square.printS(n);

		sc.close();
	}
}
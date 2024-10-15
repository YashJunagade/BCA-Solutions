import java.util.*;

class Slip16A {
	public static int sumDigits(int num) {
		if (num == 0)
			return 0;

		return (int) (num % 10) + sumDigits(num / 10);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Number : ");
		int num = sc.nextInt();

		int result = sumDigits(num);
		System.out.println("Sum of Digits : " + result);

		sc.close();
	}
}

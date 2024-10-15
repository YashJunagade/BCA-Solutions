import java.util.*;

class Slip16B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter total number of employees : ");
		int n = sc.nextInt();
		String[] employees = new String[n];
		sc.nextLine();
		for (int i = 0; i < n; i++) {
			System.out.print("Enter " + (i + 1) + " employee name : ");
			employees[i] = sc.nextLine();
		}

		Arrays.sort(employees, (e1, e2) -> e1.compareTo(e2));

		System.out.println("Employee Name in Ascending Order");
		for (int i = 0; i < n; i++) {
			System.out.print(employees[i] + " ");
		}
		sc.close();
	}
}

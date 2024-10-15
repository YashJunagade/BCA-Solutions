import java.util.*;

class Slip15A {

	public static int search(int[] nums, int key) {
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] == key)
				return i;
		}
		return -1;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		System.out.print("Enter the element to find in array : ");
		int key = sc.nextInt();

		int result = search(nums, key);
		if (result != -1) {
			System.out.println(key + " is found at " + result + " index");
		} else {
			System.out.print(key + " is not found");
		}
	}
}
class Slip17A {

	public static boolean isArmstrong(int num) {
		int sum = 0, n = num, digits = String.valueOf(num).length();

		while (n != 0) {
			int ldigit = n % 10;
			sum += Math.pow(ldigit, digits);
			n /= 10;
		}
		return sum == num;
	}

	public static void main(String[] args) {
		int n = args.length;
		int[] nums = new int[n];

		for (int i = 0; i < n; i++) {
			nums[i] = Integer.parseInt(args[i]);
		}

		int[] armstrong = new int[n];
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (isArmstrong(nums[i])) {
				armstrong[j++] = nums[i];
			}
		}

		System.out.print("Armstrong : ");
		for (int i = 0; i < j; i++) {
			System.out.print(armstrong[i] + " ");
		}
	}
}

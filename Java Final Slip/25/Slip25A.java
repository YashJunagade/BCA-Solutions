import java.util.Scanner;

class Slip25A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input string from user
        System.out.print("Enter a string: ");
        String originalString = scanner.nextLine();
        
        // Normalize the string: Remove spaces and convert to lowercase
        String normalizedString = originalString.replaceAll("[\\W]", "").toLowerCase();
        
        // Check if the string is a palindrome
        if (isPalindrome(normalizedString)) {
            System.out.println(originalString + " is a palindrome.");
        } else {
            System.out.println(originalString + " is not a palindrome.");
        }
        
        scanner.close();
    }

    // Method to check if the string is a palindrome
    public static boolean isPalindrome(String str) {
        int left = 0;
        int right = str.length() - 1;
        
        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false; // Not a palindrome
            }
            left++;
            right--;
        }
        return true; // Is a palindrome
    }
}

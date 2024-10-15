import java.util.*;

class NumberIsZeroException extends Exception {
  NumberIsZeroException(String str) {
    super(str);
  }
}

class Slip6A {

  public static int sumOfDigit(int num) {
    String strNum = String.valueOf(num);
    return Character.getNumericValue(strNum.charAt(0)) + Character.getNumericValue(strNum.charAt(strNum.length() - 1));
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter Number : ");
    int n = sc.nextInt();

    try {
      if (n == 0) {
        throw new NumberIsZeroException("Number is Zero");
      }
      System.out.println("Sum of first and last digits is : " + sumOfDigit(n));
    } catch (NumberIsZeroException e) {
      System.out.print("Error : " + e.getMessage());
    }

    sc.close();
  }
}
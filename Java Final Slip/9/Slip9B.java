import java.util.*;

class InvalidData extends Exception {
  InvalidData(String s) {
    super(s);
  }
}

class Slip9B {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter PAN number : ");
    String pan = sc.nextLine();
    System.out.print("Enter Mobile Number : ");
    String no = sc.nextLine();

    try {
      if (!pan.matches("[A-Z]{5}[0-9]{4}[A-Z]{1}")) {
        throw new InvalidData("Invalid PAN Data");
      }
      if (!no.matches("[0-9]{10}")) {
        throw new InvalidData("Invalid Mobile Data");
      }

      System.out.println("Correct Data!!");
    } catch (InvalidData e) {
      System.out.println("Error : " + e.getMessage());
    }
  }
}

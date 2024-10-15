class Slip11A {
  public static void main(String[] args) {
    int n1 = Integer.parseInt(args[0]);
    int n2 = Integer.parseInt(args[1]);
    String operation = args[2];
    int result = 0;

    switch (operation) {
      case "1":
        result = n1 + n2;
        break;

      case "2":
        result = n1 - n2;
        break;

      case "3":
        result = n1 * n2;
        break;

      case "4":
        result = n1 / n2;
        break;

      default:
        System.out.println("Enter choice 1.Addition, 2.Subtraction, 3.Multiplication, 4.Division");
    }

    System.out.println("Result : " + result);
  }

}
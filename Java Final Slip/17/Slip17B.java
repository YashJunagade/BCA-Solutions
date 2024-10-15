import java.util.Scanner;

class Product
{
 int pid;
 String pname;
 double price;
 int qty;

 public Product(int pid, String pname, double price, int qty)
 {
  this.pid = pid;
  this.pname = pname;
  this.price = price;
  this.qty = qty;
 }

 public double calculateTotalAmount()
 {
  return price * qty;
 }

 public void displayProductDetails()
 {
  System.out.println("Product ID: " + pid);
  System.out.println("Product Name: " + pname);
  System.out.println("Price: " + price);
  System.out.println("Quantity: " + qty);
  System.out.println("Total Amount: " + calculateTotalAmount());
 }
}

public class Slip17B	
{
 public static void main(String[] args)
 {
  Scanner scanner = new Scanner(System.in);

  System.out.print("Enter the number of products: ");
  int n = scanner.nextInt();
  scanner.nextLine();

  Product[] products = new Product[n];

  for (int i = 0; i < n; i++)
  {
   System.out.println("\nEnter details for Product " + (i + 1) + ":");
   System.out.print("Enter Product ID: ");
   int pid = scanner.nextInt();
   scanner.nextLine();

   System.out.print("Enter Product Name: ");
   String pname = scanner.nextLine();

   System.out.print("Enter Price: ");
   double price = scanner.nextDouble();

   System.out.print("Enter Quantity: ");
   int qty = scanner.nextInt();

   products[i] = new Product(pid, pname, price, qty);
  }

  for (int i = 0; i < n; i++)
  {
   System.out.println("\nDetails for Product " + (i + 1) + ":");
   products[i].displayProductDetails();
  }

  scanner.close();
 }
}

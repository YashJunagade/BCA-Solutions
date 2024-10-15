import java.io.*;

class Slip1B {
  public static void main(String[] args) {
    String inpFile = "input.txt";
    String outFile = "output.txt";

    try (BufferedReader reader = new BufferedReader(new FileReader(inpFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(outFile))) {

      String line;
      while ((line = reader.readLine()) != null) {
        String nonNumeric = line.replaceAll("[0-9]", "");
        writer.write(nonNumeric);
        writer.newLine();
      }

      System.out.println("Data copied Successfully");

    } catch (IOException e) {
      System.out.println("Error : " + e.getMessage());
    }
  }

}
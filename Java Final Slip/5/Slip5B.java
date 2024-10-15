import java.io.*;

class Slip5B {
  public static void main(String[] args) {
    try {
      for (int i = 0; i < args.length; i++) {
        File file = new File(args[i]);
        if (args[i].endsWith(".txt")) {
          file.delete();
          System.out.print("File deleted : " + file.getName());
        } else {
          System.out.println("File Name : " + file.getName());
          System.out.println("Location : " + file.getAbsolutePath());
          System.out.println("Size : " + file.length());
        }
      }
    } catch (Exception e) {
      System.out.println("Error : " + e.getMessage());
    }

  }
}
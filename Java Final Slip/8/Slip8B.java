import java.io.*;

class Slip8B {

    public static void printTxtFile(File[] files, int index) {
        if (index < files.length) {
            if (files[index].getName().endsWith(".txt")) {
                System.out.println(files[index].getName());
            }
            printTxtFile(files, index + 1);
        }
    }

    public static void main(String[] args) {
        File directory = new File("../../");
        if (directory.isDirectory()) {
            File[] files = directory.listFiles();
            printTxtFile(files, 0);
        }
    }
}
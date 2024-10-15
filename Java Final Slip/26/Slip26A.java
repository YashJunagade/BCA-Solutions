import java.io.*;

class Slip26A {
	public static void main(String[] args) {
		String inpFile = "input.txt";

		try {
			BufferedReader reader = new BufferedReader(new FileReader(inpFile));

			int ch;
			while ((ch = reader.read()) != -1) {
				System.out.println("Character : " + (char) ch + ", ASCII Value : " + ch);
			}
		} catch (IOException e) {
			System.out.println("Error : " + e.getMessage());
		}
	}
}

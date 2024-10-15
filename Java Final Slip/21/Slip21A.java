import java.io.*;

class Slip21A {

	public static void reverseWord(String word) {
		for (int i = word.length() - 1; i >= 0; i--) {
			System.out.print(word.charAt(i));
		}
		System.out.print(" ");
	}

	public static void main(String[] args) {
		String inpFile = "input.txt";

		try {
			BufferedReader reader = new BufferedReader(new FileReader(inpFile));

			String line;
			while ((line = reader.readLine()) != null) {
				String[] words = line.split(" ");

				for (String word : words) {
					reverseWord(word);
				}
			}
		} catch (IOException e) {
			System.out.println("Error : " + e.getMessage());
		}
	}
}
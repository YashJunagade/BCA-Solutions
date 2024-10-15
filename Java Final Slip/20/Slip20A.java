import java.awt.*;
import java.awt.event.*;

class Slip20A {
	public static void main(String[] args) {
		Frame frame = new Frame("TYBBACA");
		frame.setBackground(Color.RED);

		frame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});

		frame.setSize(400, 400);
		frame.setVisible(true);
	}
}
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Slip2B {
	public static void main(String[] args) {
		JFrame frame = new JFrame("Mouse Event Information");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		JTextField textField = new JTextField("Mouse Click Information");
		frame.add(textField, BorderLayout.SOUTH);

		JPanel panel = new JPanel();
		frame.add(panel, BorderLayout.CENTER);

		panel.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				int x = e.getX();
				int y = e.getY();

				textField.setText("Mouse clicked At  (" + x + ", " + y + ")");
			}
		});

		frame.setSize(400, 400);
		frame.setVisible(true);
	}
}

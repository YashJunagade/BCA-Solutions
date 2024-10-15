import javax.swing.*;
import java.awt.*;
import java.util.*;

class Lamp extends JPanel {
  public void paintComponent(Graphics g) {
    super.paintComponent(g);

    Random random = new Random();
    Color newColor = new Color(random.nextInt(256), random.nextInt(256), random.nextInt(256));

    g.setColor(Color.DARK_GRAY);
    g.fillRect(140, 200, 110, 20);
    g.fillRect(180, 120, 20, 80);

    g.setColor(newColor);
    g.fillRect(140, 80, 110, 50);
  }
}

class Slip11B {
  public static void main(String[] args) {
    JFrame frame = new JFrame();
    Lamp panel = new Lamp();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.add(panel);
    frame.setSize(400, 400);
    frame.setVisible(true);
  }
}

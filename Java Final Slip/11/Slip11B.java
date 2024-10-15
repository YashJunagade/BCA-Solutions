import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.util.*;

class Lamp extends JPanel {
  @Override
  protected void paintComponent(Graphics g) {
    super.paintComponent(g);
    Random rand = new Random();
    int r = rand.nextInt(256);
    int gr = rand.nextInt(256);
    int b = rand.nextInt(256);
    Color c1 = new Color(r, gr, b);
    g.drawRect(0, 250, 290, 29);
    g.drawLine(125, 250, 125, 160);
    g.drawLine(175, 250, 175, 160);
    g.drawArc(85, 157, 130, 50, -65, 312);
    g.drawArc(85, 87, 130, 50, 62, 58);
    g.drawLine(85, 177, 119, 89);
    g.drawLine(215, 177, 181, 89);
    g.setColor(c1);
    g.fillArc(78, 120, 40, 40, 63, -174);
    g.fillOval(120, 96, 40, 40);
    g.fillArc(173, 100, 40, 40, 110, 100);
  }
}

public class Slip11B {
  public static void main(String[] args) {
    Lamp panel = new Lamp();
    JFrame app = new JFrame();
    app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    app.add(panel);
    app.setSize(300, 300);
    app.setTitle("Table Lamp");
    app.setVisible(true);
  }
}

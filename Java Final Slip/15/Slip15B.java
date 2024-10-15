import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

class SmileyFace extends JPanel {
  protected void paintComponent(Graphics g) {
    super.paintComponent(g);
    g.setColor(Color.YELLOW);
    g.fillOval(10, 10, 200, 200);

    g.setColor(Color.BLACK);
    g.fillOval(55, 65, 30, 30);
    g.fillOval(135, 65, 30, 30);

    g.fillOval(50, 110, 120, 60);

    g.setColor(Color.YELLOW);
    g.fillRect(50, 110, 120, 30);
    g.fillOval(50, 120, 120, 40);
  }
}

public class Slip15B {
  public static void main(String[] args) {
    SmileyFace panel = new SmileyFace();
    JFrame app = new JFrame();
    app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    app.add(panel);
    app.setSize(230, 250);
    app.setTitle("Smiley");
    app.setVisible(true);
  }
}

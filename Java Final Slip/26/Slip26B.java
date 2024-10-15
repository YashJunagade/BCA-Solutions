import javax.swing.*;
import java.awt.*;

public class Slip26B {
 public static void main(String[] args) {

  JFrame frame = new JFrame("Temple Drawing");
  frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

  JPanel templePanel = new JPanel() {
   @Override
   protected void paintComponent(Graphics g) {
    super.paintComponent(g);

    g.drawRect(100, 150, 90, 120);
    g.drawRect(130, 230, 20, 40);
    g.drawLine(150, 100, 100, 150);
    g.drawLine(150, 100, 190, 150);
    g.drawLine(150, 50, 150, 100);
    g.drawLine(150, 50, 190, 60);
    g.drawLine(190, 60, 150, 70);
    //x:[150,190,150]
    //y:[50,60,70]

    Color c = new Color(255, 100, 0);
    g.setColor(c);
    int[] xPoints = { 150, 190, 150 };
    int[] yPoints = { 50, 60, 70 };
    int nPoints = 3;
    g.fillPolygon(xPoints, yPoints, nPoints);

    // Fill the polygon with a color

    // g.drawRect(150,50,20,20);

    // Color c = new Color(255, 100, 0);
    // g.setColor(c);
    // g.fillRect(150, 50, 20, 20);
   }
  };

  frame.getContentPane().add(templePanel);
  frame.setSize(400, 400);
  frame.setVisible(true);
 }
}

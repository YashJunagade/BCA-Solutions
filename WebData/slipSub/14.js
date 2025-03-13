export const AdvanceJava = {
  subject: "Advance Java",
  slips: [
    {
      slipId: 1,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to scroll the text from left to right and vice versa continuously.",
          marks: 15,
          sol: `import javax.swing.*;
import java.awt.*;

public class A extends JFrame implements Runnable {
    private JLabel label;
    private int xPos = 0;
    private boolean moveRight = true;
    private final int SPEED = 5;
    private Thread thread;

    public A() {
        setTitle("Scrolling Text");
        setSize(400, 100);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        
        label = new JLabel("  TYBBA(CA)  ");
        label.setFont(new Font("Arial", Font.BOLD, 20));
        
        JPanel panel = new JPanel(null); // Set layout to null for absolute positioning
        panel.setBackground(Color.BLACK);
        label.setForeground(Color.WHITE);
        
        label.setBounds(xPos, 30, 200, 30);
        panel.add(label);
        
        add(panel);
        
        thread = new Thread(this);
        thread.start();
    }

    public void run() {
        while (true) {
            if (moveRight) {
                xPos += SPEED;
                if (xPos + label.getWidth() >= getWidth()) {
                    moveRight = false;
                }
            } else {
                xPos -= SPEED;
                if (xPos <= 0) {
                    moveRight = true;
                }
            }
            label.setBounds(xPos, 30, 200, 30);
            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new A().setVisible(true);
        });
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a socket program in Java for a chatting application. (Use Swing)",
          marks: 25,
          sol: `//Client Side
          import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.net.*;

public class BClient {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Client");
        JTextArea textArea = new JTextArea(20, 40);
        JTextField textField = new JTextField(30);
        JButton sendButton = new JButton("Send");

        textArea.setEditable(false);
        frame.setLayout(new FlowLayout());
        frame.add(new JScrollPane(textArea));
        frame.add(textField);
        frame.add(sendButton);
        frame.setSize(500, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        try (Socket socket = new Socket("localhost", 12345);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {

            sendButton.addActionListener(e -> {
                String message = textField.getText();
                textArea.append("Client: " + message + "\n");
                out.println(message);
                textField.setText("");
            });

            String line;
            while ((line = in.readLine()) != null) {
                textArea.append("Server: " + line + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


//Server Side

import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.net.*;

public class BServer {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Server");
        JTextArea textArea = new JTextArea(20, 40);
        JTextField textField = new JTextField(30);
        JButton sendButton = new JButton("Send");

        textArea.setEditable(false);
        frame.setLayout(new FlowLayout());
        frame.add(new JScrollPane(textArea));
        frame.add(textField);
        frame.add(sendButton);
        frame.setSize(500, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        try (ServerSocket serverSocket = new ServerSocket(12345);
             Socket socket = serverSocket.accept();
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {

            textArea.append("Client connected...\n");

            sendButton.addActionListener(e -> {
                String message = textField.getText();
                textArea.append("Server: " + message + "\n");
                out.println(message);
                textField.setText("");
            });

            String line;
            while ((line = in.readLine()) != null) {
                textArea.append("Client: " + line + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
`,
        },
      ],
    },
    {
      slipId: 2,
      questions: [
        {
          questionId: 1,
          text: "Write a JSP program to check whether a given number is Perfect or not. (Use Include directive).",
          marks: 15,
          sol: `//slip2A.jsp
          <%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Perfect Number Checker</title>
</head>
<body>
    <h2>Check if a Number is Perfect</h2>
    <form action="" method="post">
        Enter a number: <input type="text" name="number" required>
        <input type="submit" value="Check">
    </form>

    <% if (request.getParameter("number") != null) { %>
        <%@ include file="slip2logic.jsp" %>
    <% } %>

</body>
</html>


//slip2logic.jsp

<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%
    int num = Integer.parseInt(request.getParameter("number"));
    int sum = 0;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    if (sum == num) {
        out.println("<h3>" + num + " is a Perfect Number</h3>");
    } else {
        out.println("<h3>" + num + " is NOT a Perfect Number</h3>");
    }
%>`,
        },
        {
          questionId: 2,
          text: "Write a Java program in multithreading using an applet for drawing a flag.",
          marks: 25,
          sol: `import java.applet.*;
import java.awt.*;
/* <applet code="B.java" width="400" height="400"></applet> */
public class B extends Applet implements Runnable{
    Thread t;
    int waveOffset = 0;
    public void init(){
        t= new Thread(this);
        t.start();
    }
    public void paint(Graphics g){
        g.setColor(Color.DARK_GRAY);
        g.fillRect(50,50,10,200);

        for (int i = 0; i < 3; i++) {
            Color color = (i == 0) ? Color.ORANGE : (i == 1) ? Color.WHITE : Color.GREEN;
            g.setColor(color);
            int y = 60 + (i * 20);

            for (int x = 0; x <= 100; x += 10) {
                int wave = (int) (Math.sin((x + waveOffset) * 0.1) * 5);
                g.fillRect(60 + x, y + wave, 10, 20);
            }
        }
        g.setColor(Color.BLUE);
        g.drawOval(105,80,20, 20);
    }
    public void run() {
        try {
            while (true) {
                waveOffset += 5;
                repaint();
                Thread.sleep(100);
            }
        } catch (InterruptedException e) {
            System.out.println(e);
        }
    }
}`,
        },
      ],
    },
    {
      slipId: 3,
      questions: [
        {
          questionId: 1,
          text: "Write a socket program in Java to check whether a given number is prime or not. Display the result on the client terminal.",
          marks: 15,
          sol: `//AClient.java
          import java.io.*;
import java.net.*;
import java.util.Scanner;

public class AClient {
    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 12345);
             BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
             Scanner scanner = new Scanner(System.in)) {

            System.out.println("Connected to the server. Enter a number to check (or type 'exit' to quit):");

            while (true) {
                System.out.print("Enter number: ");
                String input = scanner.nextLine();
                if (input.equalsIgnoreCase("exit")) break;

                out.println(input);
                String response = in.readLine();
                System.out.println("Server Response: " + response);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


//AServer.java

import java.io.*;
import java.net.*;

public class AServer {
    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(12345)) {
            System.out.println("Server is waiting for a client...");
            Socket socket = serverSocket.accept();
            System.out.println("Client connected");

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            while (true) {
                String input = in.readLine();
                if (input == null || input.equalsIgnoreCase("exit")) break;

                int number = Integer.parseInt(input);
                String result = isPrime(number) ? "Prime" : "Not Prime";
                out.println(result);
                System.out.println("Checked: " + number + " -> " + result);
            }

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a Java program using an applet for a bouncing ball. For each bounce, the color of the ball should change randomly.",
          marks: 25,
          sol: `import java.applet.Applet;
import java.awt.*;
import java.util.Random;

/*
<applet code="B.class" width="400" height="300"></applet>
*/

public class B extends Applet implements Runnable {
    int x = 50, y = 50; // Ball position
    int dx = 2, dy = 2; // Ball movement direction
    int ballSize = 30;
    Color ballColor = Color.RED;
    Thread t;
    Random random = new Random();

    public void init() {
        setSize(400, 300);
        t = new Thread(this);
        t.start();
    }

    public void run() {
        while (true) {
            x += dx;
            y += dy;
            if (x <= 0 || x >= getWidth() - ballSize) {
                dx = -dx;
                changeColor();
            }
            if (y <= 0 || y >= getHeight() - ballSize) {
                dy = -dy;
                changeColor();
            }

            repaint();
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    private void changeColor() {
        ballColor = new Color(random.nextInt(256), random.nextInt(256), random.nextInt(256));
    }

    public void update(Graphics g) {
        Image offscreenImage = createImage(getWidth(), getHeight());
        Graphics offscreenGraphics = offscreenImage.getGraphics();

        offscreenGraphics.setColor(Color.WHITE);
        offscreenGraphics.fillRect(0, 0, getWidth(), getHeight());

        offscreenGraphics.setColor(ballColor);
        offscreenGraphics.fillOval(x, y, ballSize, ballSize);

        g.drawImage(offscreenImage, 0, 0, this);
    }
}`,
        },
      ],
    },
    {
      slipId: 4,
      questions: [
        {
          questionId: 1,
          text: "Write a Java Program to delete details of students whose initial character of their name is 'S'.",
          marks: 15,
          sol: `import java.sql.*;

public class A {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/slip4";
        String username = "root";
        String password = "123456";

        String deleteQuery = "DELETE FROM Student WHERE name LIKE 'S%'";

        try (Connection connection = DriverManager.getConnection(url, username, password);
             Statement statement = connection.createStatement()) {
            int rowsAffected = statement.executeUpdate(deleteQuery);
            System.out.println(rowsAffected + " student(s) deleted.");

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a SERVLET program that provides information about an HTTP request from a client, such as IP address and browser type. The servlet also provides information about the server on which the servlet is running, such as the operating system type, and the names of currently loaded servlets.",
          marks: 25,
          sol: `//slip4B.java
          
import java.io.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.annotation.*;
import javax.servlet.http.*;

@WebServlet("/slip4B")
public class slip4B extends HttpServlet {
    private static final long serialVersionUID = 1L;

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        response.getWriter().println("<html><head><title>Request & Server Info</title></head><body>");
        response.getWriter().println("<h2>Client Request Information</h2>");
        
        // Client IP Address
        String clientIP = request.getRemoteAddr();
        response.getWriter().println("<p><b>Client IP Address:</b> " + clientIP + "</p>");
        
        // Client Browser Type (User-Agent)
        String userAgent = request.getHeader("User-Agent");
        response.getWriter().println("<p><b>Browser Type:</b> " + userAgent + "</p>");
        
        // Request Method
        response.getWriter().println("<p><b>Request Method:</b> " + request.getMethod() + "</p>");

        // Server Information
        response.getWriter().println("<h2>Server Information</h2>");
        
        // OS Type
        String os = System.getProperty("os.name") + " (" + System.getProperty("os.version") + ")";
        response.getWriter().println("<p><b>Operating System:</b> " + os + "</p>");
        
        // Server Name & Port
        String serverName = request.getServerName();
        int serverPort = request.getServerPort();
        response.getWriter().println("<p><b>Server Name:</b> " + serverName + "</p>");
        response.getWriter().println("<p><b>Server Port:</b> " + serverPort + "</p>");

        // Servlet Context
        ServletContext context = getServletContext();
        response.getWriter().println("<h2>Loaded Servlets</h2>");
        response.getWriter().println("<ul>");
        
        for (String servletName : context.getServletRegistrations().keySet()) {
            response.getWriter().println("<li>" + servletName + "</li>");
        }
        response.getWriter().println("</ul>");
        
        response.getWriter().println("</body></html>");
    }
}


//web.xml

<?xml version="1.0" encoding="utf-8"?>
<web-app>
	<servlet>
		<servlet-name>slip4B</servlet-name>
		<servlet-class>slip4B</servlet-class>
	</servlet>
	<servlet-mapping>
		<servlet-name>slip4B</servlet-name>
		<url-pattern>/slip4B</url-pattern>
	</servlet-mapping>
</web-app>
`,
        },
      ],
    },
    {
      slipId: 5,
      questions: [
        {
          questionId: 1,
          text: "Write a JSP program to calculate the sum of the first and last digit of a given number. Display the sum in Red Color with font size 18.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write a Java program in multithreading using applet for Traffic signal.",
          marks: 25,
        },
      ],
    },
    {
      slipId: 6,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to blink an image on the Frame continuously.",
          marks: 15,
          sol: `import java.awt.*;
import java.awt.event.*;

public class A extends Frame implements Runnable {
    private Image image;
    private boolean isVisible = true;

    public A() {
        setTitle("Blinking Image");
        setSize(400, 400);
        setLayout(null);
        setVisible(true);
        image = Toolkit.getDefaultToolkit().getImage("C:/Users/User/Downloads/ginger.jpg"); // Replace with your image
                                                                                            // path
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        Thread t = new Thread(this);
        t.start();
    }

    public void paint(Graphics g) {
        if (isVisible && image != null) {
            g.drawImage(image, 100, 100, 200, 200, this);
        }
    }

    public void run() {
        while (true) {
            try {
                isVisible = !isVisible;
                repaint();
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }

    public static void main(String[] args) {
        new A();
    }
}`,
        },
        {
          questionId: 2,
          text: "Write a SERVLET program which counts how many times a user has visited a web page. If the user is visiting the page for the first time, display a welcome message. If the user is revisiting the page, display the number of times visited. (Use Cookie)",
          marks: 25,
          sol: `//slip6B.java
          
          import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class slip6B extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        int visitCount = 0;
        boolean isNewVisitor = true;

        // Get cookies from request
        Cookie[] cookies = request.getCookies();

        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if (cookie.getName().equals("visitCount")) {
                    visitCount = Integer.parseInt(cookie.getValue());
                    isNewVisitor = false;
                    break;
                }
            }
        }

        visitCount++;
        Cookie visitCookie = new Cookie("visitCount", String.valueOf(visitCount));
        visitCookie.setMaxAge(60); // Cookie expires after 1 minute (60 seconds)
        response.addCookie(visitCookie);

        out.println("<html><body>");
        if (isNewVisitor) {
            out.println("<h2>Welcome! This is your first visit.</h2>");
        } else {
            out.println("<h2>You have visited this page " + visitCount + " times.</h2>");
        }
        out.println("</body></html>");

        out.close();
    }
}


//web.xml


<?xml version="1.0" encoding="utf-8"?>
<web-app>
	<servlet>
		<servlet-name>slip6B</servlet-name>
		<servlet-class>slip6B</servlet-class>
	</servlet>
	<servlet-mapping>
		<servlet-name>slip6B</servlet-name>
		<url-pattern>/slip6B</url-pattern>
	</servlet-mapping>
</web-app>
`,
        },
      ],
    },
    {
      slipId: 7,
      questions: [
        {
          questionId: 1,
          text: "Write a JSP script to validate a given E-Mail ID.",
          marks: 15,
          sol: `//slip7A.jsp
          
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ page import="java.util.regex.*" %>

<html>
    <head>
        <title>Email Validation</title>
    </head>
    <body>
        <h2>Email Validation Form</h2>
        <form method="post">
            Enter Email : <input type="text" name="email" required>
            <input type="submit" value="Validate">
        </form>
        <% 
            String email = request.getParameter("email");
            if(email != null){
                String emailRegex = "^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$";
                Pattern pattern = Pattern.compile(emailRegex);
                Matcher matcher = pattern.matcher(email);
                if(matcher.matches()){
                    out.println("<p style='color:green;'>✅ Valid Email: " + email + "</p>");
                }else{
                    out.println("<p style='color:red;'>❌ Invalid Email: " + email + "</p>");
                }
            }
        %>
    </body>
</html>


//web.xml

<?xml version="1.0" encoding="utf-8"?>
<web-app>
	<servlet>
		<servlet-name>slip7A</servlet-name>
		<servlet-class>slip7A</servlet-class>
	</servlet>
	<servlet-mapping>
		<servlet-name>slip7A</servlet-name>
		<url-pattern>/slip7A</url-pattern>
	</servlet-mapping>
</web-app>

`,
        },
        {
          questionId: 2,
          text: "Write a Multithreading program in Java to display the numbers between 1 to 100 continuously in a TextField by clicking on a button. (Use Runnable Interface).",
          marks: 25,
          sol: `import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class B extends JFrame implements Runnable{
    private JTextField textfield;
    private JButton btn;
    private Thread thread;
    public B(){
        setTitle("Number Counter");
        setSize(300,150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        textfield = new JTextField(10);
        textfield.setEditable(false);
        btn = new JButton("Start Counting");
        add(textfield);
        add(btn);
        btn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if(thread == null || !thread.isAlive()){
                    thread = new Thread(B.this);
                    thread.start();
                }
            }
        });
    }
    public void run(){
        for(int i = 1; i<= 100; i++){
            try{
                textfield.setText(String.valueOf(i));
                Thread.sleep(500);
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args){
        SwingUtilities.invokeLater(()->{
            new B().setVisible(true);
        });
    }
} `,
        },
      ],
    },
    {
      slipId: 8,
      questions: [
        {
          questionId: 1,
          text: "Write a Java Program to display all the employee names whose initial character of their name is ‘A’.",
          marks: 15,
          sol: `import java.sql.*;
public class A{
    public static void main(String[] args){
        String url = "jdbc:mysql://localhost:3306/slip8";
        String user = "root";
        String password = "123456";
        String query = "SELECT ename FROM Employee WHERE ename LIKE 'A%'";
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, user, password);
            PreparedStatement stmt = con.prepareStatement(query);
            ResultSet rs = stmt.executeQuery();
            System.out.println("Employees whose name start with 'A' : ");
            while(rs.next()){
                System.out.println(rs.getString("ename"));
            }
            rs.close();
            stmt.close();
            con.close();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}`,
        },
        {
          questionId: 2,
          text: "Write a Java program in multithreading using applet for a Digital watch.",
          marks: 25,
          sol: `import java.applet.Applet;
import java.awt.*;
import java.text.SimpleDateFormat;
import java.util.*;
/* <applet code="B.class" width="300" height="150"></applet> */
public class B extends Applet implements Runnable{
    private Thread thread;
    private String time;

    public void init(){
        setSize(300, 150);
        setBackground(Color.BLACK);
        setForeground(Color.WHITE);
    }
    public void start(){
        if(thread == null){
            thread = new Thread(this);
            thread.start();
        }
    }
    public void run(){
        while(true){
            time = new SimpleDateFormat("HH:mm:ss").format(new Date());
            repaint();
            try{
                Thread.sleep(1000);
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
    }
    public void paint(Graphics g){
        g.setFont(new Font("Arial", Font.BOLD, 40));
        g.drawString(time, 70, 80);
    }
}`,
        },
      ],
    },
    {
      slipId: 9,
      questions: [
        {
          questionId: 1,
          text: "Write a Java Program to create an Emp (ENo, EName, Sal) table and insert records into it using PreparedStatement Interface.",
          marks: 15,
          sol: `import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.Statement;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/slip9"; // Change database name
        String user = "root"; // Change to your MySQL username
        String password = "123456"; // Change to your MySQL password

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, user, password);
            Statement stmt = con.createStatement();
            String createTableQuery = "CREATE TABLE IF NOT EXISTS Emp (" +
                    "ENo INT PRIMARY KEY, " +
                    "EName VARCHAR(50), " +
                    "Sal DOUBLE)";
            stmt.executeUpdate(createTableQuery);
            System.out.println("Table 'Emp' created successfully (if not exists).");

            String insertQuery = "INSERT INTO Emp (ENo, EName, Sal) VALUES (?, ?, ?)";
            PreparedStatement pstmt = con.prepareStatement(insertQuery);

            Scanner sc = new Scanner(System.in);

            System.out.print("Enter Employee Number: ");
            int eNo = sc.nextInt();
            sc.nextLine(); // Consume newline

            System.out.print("Enter Employee Name: ");
            String eName = sc.nextLine();

            System.out.print("Enter Salary: ");
            double sal = sc.nextDouble();

            // Set values in PreparedStatement
            pstmt.setInt(1, eNo);
            pstmt.setString(2, eName);
            pstmt.setDouble(3, sal);

            int rowsInserted = pstmt.executeUpdate();
            if (rowsInserted > 0) {
                System.out.println("Record inserted successfully!");
            }
            pstmt.close();
            stmt.close();
            con.close();
            sc.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a JSP program to create an online shopping mall. Users must be allowed to make purchases from two pages. Each page should have a page total. The third page should display a bill, which consists of the page total of whatever purchases have been made and print the total. (Use Session)",
          marks: 25,
          sol: `//slip9a.jsp
          
          <%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="ISO-8859-1"%>
<%@ page session="true" %>
<html>
<head>
    <title>Product Page 1</title>
</head>
<body>
    <h2>Welcome to Online Shopping Mall - Product Page 1</h2>
    
    <form method="post" action="slip9a.jsp">
        Product 1: <input type="text" name="product1" value="100" readonly> <br>
        Quantity: <input type="number" name="quantity1" min="1" value="1"> <br>
        <input type="submit" value="Add to Cart">
    </form>

    <% 
        // Fetch quantity from form
        String quantity1 = request.getParameter("quantity1");
        if (quantity1 != null) {
            int qty = Integer.parseInt(quantity1);
            int price1 = 100; // Product price

            // Calculate the total for this product and add it to session
            int page1Total = price1 * qty;
            session.setAttribute("page1Total", page1Total);
        }

        // Display current page total
        Integer page1Total = (Integer) session.getAttribute("page1Total");
        if (page1Total != null) {
            out.println("<br><b>Page Total for Product 1: " + page1Total + "</b><br>");
        }
    %>

    <br><a href="slip9b.jsp">Go to Product Page 2</a> 
</body>
</html>


//slip9b.jsp


<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="ISO-8859-1"%>
<%@ page session="true" %>
<html>
<head>
    <title>Product Page 2</title>
</head>
<body>
    <h2>Welcome to Online Shopping Mall - Product Page 2</h2>
    
    <form method="post" action="slip9b.jsp">
        Product 2: <input type="text" name="product2" value="200" readonly> <br>
        Quantity: <input type="number" name="quantity2" min="1" value="1"> <br>
        <input type="submit" value="Add to Cart">
    </form>

    <% 
        // Fetch quantity from form
        String quantity2 = request.getParameter("quantity2");
        if (quantity2 != null) {
            int qty2 = Integer.parseInt(quantity2);
            int price2 = 200; // Product price

            // Calculate the total for this product and add it to session
            int page2Total = price2 * qty2;
            session.setAttribute("page2Total", page2Total);
        }

        // Display current page total
        Integer page2Total = (Integer) session.getAttribute("page2Total");
        if (page2Total != null) {
            out.println("<br><b>Page Total for Product 2: " + page2Total + "</b><br>");
        }
    %>

    <br><a href="slip9c.jsp">View Bill</a> 
</body>
</html>


//slip9c.jsp


<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="ISO-8859-1"%>
<%@ page session="true" %>
<html>
<head>
    <title>Bill Page</title>
</head>
<body>
    <h2>Online Shopping Mall - Bill</h2>

    <% 
        // Fetch the totals for page 1 and page 2 from session
        Integer page1Total = (Integer) session.getAttribute("page1Total");
        Integer page2Total = (Integer) session.getAttribute("page2Total");

        // Calculate the final total
        int finalTotal = 0;
        if (page1Total != null) {
            finalTotal += page1Total;
        }
        if (page2Total != null) {
            finalTotal += page2Total;
        }

        // Display the bill
        out.println("<br><b>Page 1 Total: " + (page1Total != null ? page1Total : 0) + "</b><br>");
        out.println("<br><b>Page 2 Total: " + (page2Total != null ? page2Total : 0) + "</b><br>");
        out.println("<br><b>Final Bill Total: " + finalTotal + "</b><br>");
    %>

    <br><a href="slip9a.jsp">Go Back to Product 1 Page</a> 
</body>
</html>


//web.xml

<?xml version="1.0" encoding="utf-8"?>
<web-app>
	<servlet>
		<servlet-name>slip9a</servlet-name>
		<servlet-class>slip9a</servlet-class>
	</servlet>
	<servlet-mapping>
		<servlet-name>slip9a</servlet-name>
		<url-pattern>/slip9a</url-pattern>
	</servlet-mapping>
</web-app>

`,
        },
      ],
    },
    {
      slipId: 10,
      questions: [
        {
          questionId: 1,
          text: "Write a Java Program in Hibernate to display a 'Hello world' message.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write a SERVLET program to display the details of a Product (ProdCode, PName, Price) on the browser in tabular format. (Use database)",
          marks: 25,
        },
      ],
    },
    {
      slipId: 11,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to display the IP Address and name of the client machine.",
          marks: 15,
          sol: `import java.net.*;

public class A{
    public static void main(String[] args){
        try{
            InetAddress inetAddress = InetAddress.getLocalHost();
            String ipAddress = inetAddress.getHostAddress();
            String hostName = inetAddress.getHostName();
            System.out.println("Client IP Address : "+ipAddress);
            System.out.println("Client Host Name : "+hostName);
        }catch(UnknownHostException e){
            System.out.println("Error : "+e.getMessage());
        }
    }
}`,
        },
        {
          questionId: 2,
          text: "Write a Java program to display sales details of Product (PID, PName, Qty, Rate, Amount) between two selected dates. (Assume Sales table is already created).",
          marks: 25,
          sol: `import java.sql.*;
import java.util.Scanner;

public class B{
    public static void main(String[] args){
        String url = "jdbc:mysql://localhost:3306/slip11";
        String user = "root";
        String password = "123456";
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter the start date (YYYY-MM-DD) : ");
        String startDate = scanner.nextLine();
        System.out.println("Enter the end date (YYYY-MM-DD) : ");
        String endDate = scanner.nextLine();

        String query = "SELECT PID, PName, Qty, Rate, Amount FROM Sales WHERE SaleDate BETWEEN ? AND ?";

        try(
            Connection con = DriverManager.getConnection(url, user, password);
            PreparedStatement stmt = con.prepareStatement(query)
        ){
            stmt.setString(1, startDate);
            stmt.setString(2, endDate);
            ResultSet rs = stmt.executeQuery();

            System.out.println("Sales details between " + startDate + " and " + endDate + ":");
            System.out.printf("%-10s %-20s %-10s %-10s %-10s%n", "PID", "PName", "Qty", "Rate", "Amount");

            while (rs.next()) {
                int pid = rs.getInt("PID");
                String pname = rs.getString("PName");
                int qty = rs.getInt("Qty");
                double rate = rs.getDouble("Rate");
                double amount = rs.getDouble("Amount");

                System.out.printf("%-10d %-20s %-10d %-10.2f %-10.2f%n", pid, pname, qty, rate, amount);
            }

        }catch(SQLException e){
            System.out.println("Error : "+e.getMessage());
        }finally{
            scanner.close();
        }
    }
}`,
        },
      ],
    },
    {
      slipId: 12,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to count the number of records in a table.",
          marks: 15,
          sol: `import java.sql.*;

public class A {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/slip12"; // Change database name
        String user = "root"; // Change username
        String password = "123456"; // Change password
        String tableName = "book"; // Change table name

        String query = "SELECT COUNT(*) FROM " + tableName;

        try (Connection conn = DriverManager.getConnection(url, user, password);
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(query)) {

            if (rs.next()) {
                int count = rs.getInt(1);
                System.out.println("Total number of records in " + tableName + ": " + count);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a program in Java which will show the lifecycle (creation, sleep, and dead) of a thread. The program should print randomly the name of the thread and the value of the sleep time. The name of the thread should be hard-coded through the constructor. The sleep time of a thread will be a random integer in the range 0 to 4999.",
          marks: 25,
          sol: `import java.util.Random;

class MyThread extends Thread {
    public MyThread(String name) {
        super(name);
    }

    @Override
    public void run() {
        try {
            Random rand = new Random();
            int sleepTime = rand.nextInt(5000); // Generate random sleep time (0 - 4999 ms)

            System.out.println("Thread " + getName() + " is created and running...");
            System.out.println("Thread " + getName() + " will sleep for " + sleepTime + " ms.");

            Thread.sleep(sleepTime); // Sleep for the generated time

            System.out.println("Thread " + getName() + " has woken up and is terminating...");
        } catch (InterruptedException e) {
            System.out.println("Thread " + getName() + " was interrupted.");
        }
    }
}

public class B {
    public static void main(String[] args) {
        try {
            MyThread t1 = new MyThread("Thread-1");
            t1.start();
            t1.join(); // Wait for t1 to finish

            MyThread t2 = new MyThread("Thread-2");
            t2.start();
            t2.join(); // Wait for t2 to finish

            MyThread t3 = new MyThread("Thread-3");
            t3.start();
            t3.join(); // Wait for t3 to finish
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
`,
        },
      ],
    },
    {
      slipId: 13,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to display the name of the currently executing Thread in multithreading.",
          marks: 15,
          sol: `class MyThread extends Thread{
    public MyThread(String name){
        super(name);
    }
    public void run(){
        System.out.println("Currently executing thread : "+Thread.currentThread().getName());
    }
}

public class A{
    public static void main(String[] args){
        try {
            MyThread t1 = new MyThread("Thread-1");
            t1.start();
            t1.join(); // Wait for t1 to finish

            MyThread t2 = new MyThread("Thread-2");
            t2.start();
            t2.join(); // Wait for t2 to finish
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}`,
        },
        {
          questionId: 2,
          text: "Write a JSP program to display the details of College (CollegeID, Coll_Name, Address) in tabular form on the browser.",
          marks: 25,
          sol: `//slip13B.jsp
          
          
<%@ page import="java.sql.*" %>
<html>
<head>
    <title>College Details</title>
    <style>
        table { width: 60%; border-collapse: collapse; margin: 20px auto; }
        th, td { border: 1px solid black; padding: 10px; text-align: center; }
        th { background-color: #3f51b5; color: white; }
    </style>
</head>
<body>
    <h2 style="text-align: center;">College Details</h2>
    <table>
        <tr>
            <th>College ID</th>
            <th>College Name</th>
            <th>Address</th>
        </tr>
        <%
            String url = "jdbc:mysql://localhost:3306/slip13"; // Change 'your_database' to actual DB name
            String user = "root"; // Your DB username
            String password = "123456"; // Your DB password

            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                Connection con = DriverManager.getConnection(url, user, password);
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery("SELECT * FROM College");

                while (rs.next()) {
        %>
        <tr>
            <td><%= rs.getInt("CollegeID") %></td>
            <td><%= rs.getString("Coll_Name") %></td>
            <td><%= rs.getString("Address") %></td>
        </tr>
        <%
                }
                con.close();
            } catch (Exception e) {
                out.println("<tr><td colspan='3' style='color:red;'>Error: " + e.getMessage() + "</td></tr>");
            }
        %>
    </table>
</body>
</html>



//web.xml

<?xml version="1.0" encoding="utf-8"?>
<web-app>
	<servlet>
		<servlet-name>slip13B</servlet-name>
		<servlet-class>slip13B</servlet-class>
	</servlet>
	<servlet-mapping>
		<servlet-name>slip13B</servlet-name>
		<url-pattern>/slip13B</url-pattern>
	</servlet-mapping>
</web-app>

`,
        },
      ],
    },
    {
      slipId: 14,
      questions: [
        {
          questionId: 1,
          text: "Write a JSP program to accept Name and Age of Voter and check whether he is eligible for voting or not.",
          marks: 15,
          sol: `<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<html>
    <head>
        <title>Voter Eligibility Checker</title>
    </head>
    <body>
        <h2>Voter Eligibility Checker</h2>
        <form method="post">
            Name : <input type="text" name="name"><br><br>
            Age : <input type="number" name="age"><br><br>
            <input type="submit" value="Check Eligibility">
        </form>
        <% 
            String name = request.getParameter("name");
            String ageStr = request.getParameter("age");

            // Check if parameters are provided
            if (name != null && ageStr != null && !ageStr.isEmpty()) {
                try {
                    int age = Integer.parseInt(ageStr);

                    // Check voting eligibility
                    if (age >= 18) {
                        out.println("<h3>Hello, " + name + "! You are eligible to vote. ?</h3>");
                    } else {
                        out.println("<h3>Sorry, " + name + ". You are NOT eligible to vote. ?</h3>");
                    }
                } catch (NumberFormatException e) {
                    out.println("<h3>Invalid age entered. Please enter a valid number.</h3>");
                }
            }
        %> 
    </body>
</html>`,
        },
        {
          questionId: 2,
          text: "Write a Java program to display given extension files from a specific directory on the server machine.",
          marks: 25,
          sol: `BClient.java
          
          import java.io.*;
import java.net.*;

public class BClient {
    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 5000)) {
            PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
            output.println(".txt");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


// BServer.java

import java.io.*;
import java.net.*;

public class BServer {
    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(5000)) {
            System.out.println("Server is running... Waiting for client connection...");
            Socket socket = serverSocket.accept();
            System.out.println("Client Connected...");

            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            String extension = input.readLine();
            System.out.println("Client requested files with extension: " + extension);

            // Specify directory to search (Change this path as needed)
            File directory = new File("C:\\Users\\User\\OneDrive\\Desktop\\Java Slip Solution\\Slip14");

            FilenameFilter filter = (dir, name) -> name.endsWith(extension);
            String[] files = directory.list(filter);
            System.out.println("Files with " + extension + " extension:");
            for (String file : files) {
                System.out.println(file);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

`,
        },
      ],
    },
    {
      slipId: 15,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to display each alphabet after 2 seconds between ‘a’ to ‘z’.",
          marks: 15,
          sol: `public class Slip15A 
{
    public static void main(String args[])
    {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            System.out.print(ch + " ");
            try {
                Thread.sleep(2000); // Delay of 2 seconds
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted: " + e.getMessage());
            }
        }
    }
} 
`,
        },
        {
          questionId: 2,
          text: "Write a Java program to accept the details of Student (RNo, SName, Per, Gender, Class) and store them into the database. (Use appropriate Swing Components and PreparedStatement Interface).",
          marks: 25,
          sol: `import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class Slip15B extends JFrame {
    private JTextField txtRNo, txtSName, txtPer, txtClass;
    private JRadioButton rbMale, rbFemale;
    private JButton btnSave;
    private Connection con;

    public Slip15B() {
        setTitle("Student Registration");
        setSize(350, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new GridLayout(6, 2));

        JLabel lblRNo = new JLabel("Roll No:");
        txtRNo = new JTextField();

        JLabel lblSName = new JLabel("Student Name:");
        txtSName = new JTextField();

        JLabel lblPer = new JLabel("Percentage:");
        txtPer = new JTextField();

        JLabel lblClass = new JLabel("Class:");
        txtClass = new JTextField();

        JLabel lblGender = new JLabel("Gender:");
        rbMale = new JRadioButton("Male");
        rbFemale = new JRadioButton("Female");
        ButtonGroup bgGender = new ButtonGroup();
        bgGender.add(rbMale);
        bgGender.add(rbFemale);

        btnSave = new JButton("Save");
        btnSave.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                saveStudent();
            }
        });

        add(lblRNo);
        add(txtRNo);
        add(lblSName);
        add(txtSName);
        add(lblPer);
        add(txtPer);
        add(lblClass);
        add(txtClass);
        add(lblGender);
        add(rbMale);
        add(rbFemale);
        add(btnSave);

        connectToDatabase();
        setVisible(true);
    }

    private void connectToDatabase() {
        try {
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/user13", "root", "user@123");
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
    }

    private void saveStudent() {
        String query = "INSERT INTO students (RNo, SName, Per, Gender, Class) VALUES (?, ?, ?, ?, ?)";
        try (PreparedStatement pstmt = con.prepareStatement(query)) {
            pstmt.setInt(1, Integer.parseInt(txtRNo.getText()));
            pstmt.setString(2, txtSName.getText());
            pstmt.setFloat(3, Float.parseFloat(txtPer.getText()));
            pstmt.setString(5, txtClass.getText());
            pstmt.setString(4, rbMale.isSelected() ? "Male" : "Female");
            pstmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Student details saved successfully!");
        } catch (SQLException | NumberFormatException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error saving student details!", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        new Slip15B();
    }
}
`,
        },
      ],
    },
    {
      slipId: 16,
      questions: [
        {
          questionId: 1,
          text: "Write a JSP script to accept username and password from user. If they are the same, display 'Login Successfully' message in Login.html file; otherwise, display 'Login Failed' message in Error.html file.",
          marks: 15,
          sol: `//slip16A.html
          
          
          <!DOCTYPE html>
<html>
<head>
    <title>Login Page</title>
</head>
<body>
    <h2>User Login</h2>
    <form action="login.jsp" method="post">
        Username: <input type="text" name="username" required><br><br>
        Password: <input type="password" name="password" required><br><br>
        <input type="submit" value="Login">
    </form>
</body>
</html>


//login.html


<!DOCTYPE html>
<html>
<head>
    <title>Login Success</title>
</head>
<body>
    <h2>Login Successfully</h2>
    <p>Welcome! You have logged in successfully.</p>
</body>
</html>


//login.jsp

<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%
    // Retrieve form data
    String username = request.getParameter("username");
    String password = request.getParameter("password");

    // Check if username and password are the same
    if (username != null && password != null && username.equals(password)) {
        response.sendRedirect("Login.html"); // Successful login
    } else {
        response.sendRedirect("Error.html"); // Failed login
    }
%>


// Error.html

<!DOCTYPE html>
<html>
<head>
    <title>Login Failed</title>
</head>
<body>
    <h2>Login Failed </h2>
    <p>Incorrect credentials. Please try again.</p>
    <a href="slip16.html">Go Back to Login</a>
</body>
</html>

`,
        },
        {
          questionId: 2,
          text: "Write a Java program to accept the details of students (rno, sname, per) for at least 5 records, store them into the database, and display the details of the student with the highest percentage. (Use PreparedStatement Interface).",
          marks: 25,
          sol: `import java.sql.*;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/slip14";
        String user = "root"; // Change to your MySQL username
        String password = "123456"; // Change to your MySQL password
        
        Scanner scanner = new Scanner(System.in);

        String insertQuery = "INSERT INTO students (rno, sname, per) VALUES (?, ?, ?)";
        String selectQuery = "SELECT * FROM students ORDER BY per DESC LIMIT 1"; // Get highest percentage student

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, user, password);
            System.out.println("Database Connected Successfully!");

            PreparedStatement pstmt = con.prepareStatement(insertQuery);

            System.out.println("Enter details of 5 students:");
            for (int i = 0; i < 5; i++) {
                System.out.print("Enter Roll No: ");
                int rno = scanner.nextInt();
                scanner.nextLine(); // Consume newline
                System.out.print("Enter Name: ");
                String sname = scanner.nextLine();
                System.out.print("Enter Percentage: ");
                float per = scanner.nextFloat();

                pstmt.setInt(1, rno);
                pstmt.setString(2, sname);
                pstmt.setFloat(3, per);
                pstmt.executeUpdate();
            }

            System.out.println("Records inserted successfully!");

            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(selectQuery);

            if (rs.next()) {
                System.out.println("\nStudent with Highest Percentage:");
                System.out.println("Roll No: " + rs.getInt("rno"));
                System.out.println("Name: " + rs.getString("sname"));
                System.out.println("Percentage: " + rs.getFloat("per"));
            }

            pstmt.close();
            stmt.close();
            con.close();
            scanner.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
`,
        },
      ],
    },
    {
      slipId: 17,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to accept a String from the user and display each vowel from the String after 3 seconds.",
          marks: 15,
          sol: `import java.util.Scanner;

public class Slip17A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        scanner.close();
        
        displayVowels(input);
    }

    public static void displayVowels(String str) {
        for (char ch : str.toCharArray()) {
            if (isVowel(ch)) {
                System.out.println(ch);
                try {
                    Thread.sleep(3000); // 3 seconds delay
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static boolean isVowel(char ch) {
        return "AEIOUaeiou".indexOf(ch) != -1;
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a Java program to check whether a given file is present on the server or not. If it is there, display its contents on the client’s terminal; otherwise, display the message 'File Not Found'.",
          marks: 25,
          sol: `//slip17B_Client.java
          
          
          import java.io.*;
import java.net.*;

public class Slip17B_Client {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("localhost", 5000);
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter filename: ");
        String fileName = userInput.readLine();
        out.println(fileName);

        String response;
        while ((response = in.readLine()) != null) {
            System.out.println(response);
        }

        socket.close();
    }
}


//slip17B_Server.java

import java.io.*;
import java.net.*;

public class Slip17B_Server {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(5000);
        System.out.println("Server is waiting for client...");

        Socket socket = serverSocket.accept();
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

        String fileName = in.readLine();
        File file = new File(fileName);

        if (file.exists() && file.isFile()) {
            BufferedReader fileReader = new BufferedReader(new FileReader(file));
            String line;
            while ((line = fileReader.readLine()) != null) {
                out.println(line);
            }
            fileReader.close();
        } else {
            out.println("File Not Found");
        }

        socket.close();
        serverSocket.close();
    }
}


//example.txt

Hello, this is a sample file!
Welcome to Java Networking.
`,
        },
      ],
    },
    {
      slipId: 18,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to calculate the factorial of a number. (Use sleep() method).",
          marks: 15,
          sol: `
          import java.util.Scanner;

public class Slip18A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = scanner.nextInt();
        scanner.close();

        System.out.println("Calculating factorial of " + num + "...");
        long factorial = calculateFactorial(num);
        System.out.println("Factorial of " + num + " is: " + factorial);
    }

    public static long calculateFactorial(int n) {
        long fact = 1;

        for (int i = 1; i <= n; i++) {
            fact *= i;
            System.out.println("Step " + i + ": " + fact);
            
            try {
                Thread.sleep(1000); // 1-second delay between steps
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        return fact;
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a Java program for a simple standalone chatting application.",
          marks: 25,
          sol: `//Slip18B_Client.java
          
import java.io.*;
import java.net.*;

public class Slip18B_Client {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("localhost", 5000);
        System.out.println("Connected to Server...");

        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));

        String message;
        while (true) {
            System.out.print("You: ");
            message = userInput.readLine(); // Enter message
            out.println(message);
            if (message.equalsIgnoreCase("exit")) break;

            message = in.readLine(); // Receive reply from server
            System.out.println("Server: " + message);
        }

        socket.close();
    }
}


//Slip18_Server.java

import java.io.*;
import java.net.*;

public class Slip18B_Server {
    public static void main(String[] args) throws IOException {
        ServerSocket server = new ServerSocket(5000);
        System.out.println("Server started... Waiting for client...");

        Socket socket = server.accept();
        System.out.println("Client connected!");

        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));

        String message;
        while (true) {
            message = in.readLine(); // Receive message from client
            if (message.equalsIgnoreCase("exit")) break;
            System.out.println("Client: " + message);

            System.out.print("You: ");
            message = userInput.readLine(); // Enter reply
            out.println(message);
        }

        socket.close();
        server.close();
    }
}
`,
        },
      ],
    },
    {
      slipId: 19,
      questions: [
        {
          questionId: 1,
          text: "Write a JSP program which accepts UserName in a TextBox and greets the user according to the time on the server machine.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write a Java program to display the first record from the student table (rno, sname, per) onto the TextFields by clicking on a button. (Assume Student table is already created).",
          marks: 25,
        },
      ],
    },
    {
      slipId: 20,
      questions: [
        {
          questionId: 1,
          text: "Write a JDBC program to delete the details of a given employee (ENo, EName, Salary). Accept employee ID through the command line.",
          marks: 15,
          sol: `import java.sql.*;

public class Slip20A {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java DeleteEmployee <EmployeeID>");
            return;
        }

        int empId = Integer.parseInt(args[0]); // Get Employee ID from command line

        try {
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/user13", "root", "user@123");
            PreparedStatement stmt = con.prepareStatement("DELETE FROM employee WHERE ENo = ?");
            stmt.setInt(1, empId);

            int rows = stmt.executeUpdate();
            System.out.println(rows > 0 ? "Employee deleted successfully." : "Employee not found.");

            stmt.close();
            con.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a Java program in multithreading using applet for drawing a temple.",
          marks: 25,
          sol: `//Slip20B.html
          
          
          <html>
<body>
    <applet code="Slip20B.class" width="400" height="400"></applet>
</body>
</html>


//Slip20B.java


import java.applet.*;
import java.awt.*;

public class Slip20B extends Applet implements Runnable {
    private boolean lightOn = true;

    @Override
    public void init() {
        new Thread(this).start();  // Start the animation thread
    }
    
    @Override
    public void paint(Graphics g) {
        // Background
        g.setColor(Color.CYAN);
        g.fillRect(0, 0, getWidth(), getHeight());

        // Temple Base
        g.setColor(Color.GRAY);
        g.fillRect(100, 200, 200, 150); // Base structure

        // Temple Roof
        g.setColor(Color.DARK_GRAY);
        int[] x = {90, 200, 310}; 
        int[] y = {200, 100, 200}; 
        g.fillPolygon(x, y, 3); // Triangle Roof

        // Door
        g.setColor(Color.BLACK);
        g.fillRect(180, 270, 40, 80);

        // Light (Animated using Thread)
        if (lightOn) {
            g.setColor(Color.ORANGE);
            g.fillOval(185, 230, 30, 30); // Flickering Light
        }
    }

    public void run() {
        while (true) {
            lightOn = !lightOn; // Toggle light
            repaint(); // Refresh the applet

            try {
                Thread.sleep(500); // Pause for 500ms
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

`,
        },
      ],
    },
    {
      slipId: 21,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to display the name and priority of a Thread.",
          marks: 15,
          sol: `class MyThread extends Thread {
    public void run() {
        System.out.println("Thread Name: " + getName()); // Get thread name
        System.out.println("Thread Priority: " + getPriority()); // Get thread priority
    }
}

public class Slip21A {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        t1.setName("MyCustomThread"); // Set thread name
        t1.setPriority(Thread.MAX_PRIORITY); // Set priority (10)
        
        t1.start(); // Start the thread
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a SERVLET program in Java to accept details of a student (SeatNo, Stud_Name, Class, Total_Marks). Calculate percentage and grade obtained and display details on the page.",
          marks: 25,
          sol: `//Slip21B.html
          
          <!DOCTYPE html>
<html>
<head>
    <title>Student Form</title>
</head>
<body>
    <h2>Enter Student Details</h2>
    <form action="Slip21B" method="post">
        Seat No: <input type="text" name="seatNo" required><br><br>
        Name: <input type="text" name="name" required><br><br>
        Class: <input type="text" name="class" required><br><br>
        Total Marks(Under 500): <input type="number" name="totalMarks" required><br><br>
        <input type="submit" value="Submit">
    </form>
</body>
</html>


//Slip21B.java

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Slip21B extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        // Accepting Student Details
        String seatNo = request.getParameter("seatNo");
        String name = request.getParameter("name");
        String studentClass = request.getParameter("class");
        int totalMarks = Integer.parseInt(request.getParameter("totalMarks"));

        // Calculate Percentage
        double percentage = (totalMarks / 500.0) * 100; // Assuming total marks = 500

        // Determine Grade
        String grade;
        if (percentage >= 90) grade = "A+";
        else if (percentage >= 80) grade = "A";
        else if (percentage >= 70) grade = "B";
        else if (percentage >= 60) grade = "C";
        else if (percentage >= 50) grade = "D";
        else grade = "Fail";

        // Display Student Details
        out.println("<html><body>");
        out.println("<h2>Student Result</h2>");
        out.println("<p><b>Seat No:</b> " + seatNo + "</p>");
        out.println("<p><b>Name:</b> " + name + "</p>");
        out.println("<p><b>Class:</b> " + studentClass + "</p>");
        out.println("<p><b>Total Marks:</b> " + totalMarks + "</p>");
        out.println("<p><b>Percentage:</b> " + percentage + "%</p>");
        out.println("<p><b>Grade:</b> " + grade + "</p>");
        out.println("</body></html>");

        out.close();
    }
}


//web.xml



<web-app>
    <servlet>
        <servlet-name>Slip21B</servlet-name>
        <servlet-class>Slip21B</servlet-class>
    </servlet>

    <servlet-mapping>
        <servlet-name>Slip21B</servlet-name>
        <url-pattern>/Slip21B</url-pattern>
    </servlet-mapping>
</web-app>


`,
        },
      ],
    },
    {
      slipId: 22,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to display the Date and Time of the Server machine on the client machine.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write a JSP program to accept the details of an Account (ANo, Type, Bal) and store it into the database and display it in tabular form.",
          marks: 25,
        },
      ],
    },
    {
      slipId: 23,
      questions: [
        {
          questionId: 1,
          text: "Write a Java Program to display the details of a College (CID, CName, Address, Year) on a JTable.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write a SERVLET application to accept username and password, search them in the database, if found then display an appropriate message on the browser, otherwise display an error message.",
          marks: 25,
        },
      ],
    },
    {
      slipId: 24,
      questions: [
        {
          questionId: 1,
          text: "Create a JSP page to accept a number from a user and display it in words: Example: 123 – One Two Three. The output should be in red color.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write a menu-driven program in Java for the following: Assume Emp table with attributes (ENo, EName, Salary, Desg) is already created.\n1. Insert\n2. Update\n3. Delete\n4. Search\n5. Display\n6. Exit.",
          marks: 25,
        },
      ],
    },
    {
      slipId: 25,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to accept a number through the client terminal, send it to the Server, and the Server calculates its factors and sends it back to the client.",
          marks: 15,
          sol: `//Slip25A_Client.java
          
          // Client Program
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Slip25A_Client {
    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 5000)) {
            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
            
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter a number: ");
            int number = scanner.nextInt();
            
            output.println(number);
            System.out.println("Factors received from server: " + input.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


//Slip25A_Server.java

import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.List;

public class Slip25A_Server {
    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(5000)) {
            System.out.println("Server is waiting for client...");
            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("Client connected.");
                
                BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
                
                int number = Integer.parseInt(input.readLine());
                System.out.println("Received number: " + number);
                
                List<Integer> factors = getFactors(number);
                output.println(factors);
                
                socket.close();
                System.out.println("Response sent, connection closed.");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    private static List<Integer> getFactors(int number) {
        List<Integer> factors = new ArrayList<>();
        for (int i = 1; i <= number; i++) {
            if (number % i == 0) {
                factors.add(i);
            }
        }
        return factors;
    }
} 

`,
        },
        {
          questionId: 2,
          text: "Write a Java Program for the following: Assume database is already created.",
          marks: 25,
          sol: `import javax.swing.*;
import java.awt.*;
import java.sql.*;

public class Slip25B extends JFrame {
    private JTextField queryField;
    private JButton createTableBtn, alterTableBtn, dropTableBtn;

    public Slip25B() {
        setTitle("DDL Query Executor");
        setSize(500, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        JLabel label = new JLabel("Type Your DDL Query Here:");
        queryField = new JTextField(30);
        createTableBtn = new JButton("Create Table");
        alterTableBtn = new JButton("Alter Table");
        dropTableBtn = new JButton("Drop Table");

        add(label);
        add(queryField);
        add(createTableBtn);
        add(alterTableBtn);
        add(dropTableBtn);

        // Assign actions to specific buttons
        createTableBtn.addActionListener(e -> executeDDLQuery("CREATE TABLE"));
        alterTableBtn.addActionListener(e -> executeDDLQuery("ALTER TABLE"));
        dropTableBtn.addActionListener(e -> executeDDLQuery("DROP TABLE"));

        setVisible(true);
    }

    private void executeDDLQuery(String expectedCommand) {
        String query = queryField.getText().trim().toUpperCase(); // Convert to uppercase for case insensitivity

        if (query.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Please enter a DDL query!", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        // Ensure the correct query is executed for each button
        if (!query.startsWith(expectedCommand)) {
            JOptionPane.showMessageDialog(this, "Invalid query! Use a valid " + expectedCommand + " statement.",
                    "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/user13", "root", "user@123");
                Statement stmt = conn.createStatement()) {

            stmt.execute(query);
            JOptionPane.showMessageDialog(this, "Query executed successfully!", "Success",
                    JOptionPane.INFORMATION_MESSAGE);
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this, "SQL Error: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Slip25B::new);
    }
}
`,
        },
      ],
    },
    {
      slipId: 26,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program to display a list of college names from the college table. (Assume College table (CID, CName, addr) is already created.)",
          marks: 15,
          sol: `import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class Slip26A {
    public static void main(String[] args) {
        // Database connection details
        String url = "jdbc:mysql://localhost:3306/user13"; // Change 'your_database' accordingly
        String user = "root"; // Change to your MySQL username
        String password = "user@123"; // Change to your MySQL password

        try {
            // Load the MySQL JDBC Driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Establish connection
            Connection conn = DriverManager.getConnection(url, user, password);
            System.out.println("Connected to the database.");

            // Create a SQL query to fetch college names
            String query = "SELECT CName FROM college";
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(query);

            // Display college names
            System.out.println("List of Colleges:");
            while (rs.next()) {
                System.out.println(rs.getString("CName"));
            }

            // Close resources
            rs.close();
            stmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a SERVLET program to design an HTML page containing 4 option buttons (Painting, Drawing, Singing, Swimming) and 2 buttons (Reset and Submit). When the user clicks Submit, the server responds by adding a cookie containing the selected hobby and sends the HTML page to the client. Program should not allow duplicate cookies to be written.",
          marks: 25,
          sol: `//slip26B.java
          
          
          import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.*;
import javax.servlet.http.*;

public class slip26B extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String selectedHobby = request.getParameter("hobby"); 
        if (selectedHobby == null) {
            out.println("<h3>Please select a hobby!</h3>");
            return;
        }

        boolean cookieExists = false;
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if (cookie.getName().equals("selectedHobby") && cookie.getValue().equals(selectedHobby)) {
                    cookieExists = true;
                    break;
                }
            }
        }

        if (!cookieExists) {
            Cookie hobbyCookie = new Cookie("selectedHobby", selectedHobby);
            hobbyCookie.setMaxAge(860); 
            response.addCookie(hobbyCookie);
            out.println("<h3>Hobby selected: " + selectedHobby + "</h3>");
            out.println("<p>Cookie has been set successfully.</p>");
        } else {
            out.println("<h3>The hobby '" + selectedHobby + "' is already selected!</h3>");
            out.println("<p>Duplicate cookies are not allowed.</p>");
        }

        out.println("<br><a href='slip26B.html'>Go Back</a>");
    }
}



//slip26B.html

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Hobby Selection</title>
</head>
<body>
    <h2>Select Your Favorite Hobby</h2>
    <form action="slip26B" method="post">
        <!-- Fix: Match Servlet Mapping -->
        <input type="radio" name="hobby" value="Painting" required> Painting <br>
        <input type="radio" name="hobby" value="Drawing"> Drawing <br>
        <input type="radio" name="hobby" value="Singing"> Singing <br>
        <input type="radio" name="hobby" value="Swimming"> Swimming <br><br>
        <button type="submit">Submit</button>
        <button type="reset">Reset</button>
    </form>
</body>
</html>

`,
        },
      ],
    },
    {
      slipId: 27,
      questions: [
        {
          questionId: 1,
          text: "Write a JSP script to accept the details of a Teacher (TID, TName, Desg, Subject, Qualification) and display it on the browser. Use appropriate controls for accepting data.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write a Java Program for the implementation of a scrollable ResultSet. Assume Teacher table with attributes (TID, TName, Salary, Subject) is already created.",
          marks: 25,
        },
      ],
    },
    {
      slipId: 28,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program for the implementation of synchronization.",
          marks: 15,
          sol: `// Shared resource: Table Printer
class TablePrinter {
    // Synchronized block to print table safely
    public void printTable(int number) {
        synchronized (this) { // Synchronizing the critical section
            for (int i = 1; i <= 5; i++) {
                System.out.println(number + " x " + i + " = " + (number * i));
                try {
                    Thread.sleep(500); // Simulating delay
                } catch (InterruptedException e) {
                    System.out.println(e);
                }
            }
        }
    }
}

// Thread Class
class TableThread extends Thread {
    private TablePrinter printer;
    private int number;

    public TableThread(TablePrinter printer, int number) {
        this.printer = printer;
        this.number = number;
    }

    public void run() {
        printer.printTable(number);
    }
}

// Main Class
public class Slip28A {
    public static void main(String[] args) {
        TablePrinter printer = new TablePrinter(); // Shared resource

        // Creating two threads that try to access the shared printer
        TableThread t1 = new TableThread(printer, 5);
        TableThread t2 = new TableThread(printer, 10);

        // Starting the threads
        t1.start();
        t2.start();
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a Java program to design a following screen: [Details of screen design would be provided here]",
          marks: 25,
        },
      ],
    },
    {
      slipId: 29,
      questions: [
        {
          questionId: 1,
          text: "Write a Java program using multithreading for the following:\n1. Display all the odd numbers between 1 to n.\n2. Display all the prime numbers between 1 to n.",
          marks: 15,
          sol: `import java.util.Scanner;

class OddThread extends Thread {
    int n;
    public OddThread(int n) {
        this.n = n;
    }
    public void run() {
        System.out.println("Odd numbers up to " + n + ":");
        for (int i = 1; i <= n; i += 2) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}

class PrimeThread extends Thread {
    int n;
    public PrimeThread(int n) {
        this.n = n;
    }
    public void run() {
        System.out.println("Prime numbers up to " + n + ":");
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }
    
    private boolean isPrime(int num) {
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}

public class Slip29A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number (n): ");
        int n = scanner.nextInt();
        scanner.close();
        
        OddThread odd = new OddThread(n);
        PrimeThread prime = new PrimeThread(n);
        
        odd.start();
        prime.start();
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a SERVLET program to change the inactive time interval of a session.",
          marks: 25,
          sol: `import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class slip29B extends HttpServlet{
    protected void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException
    {
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        HttpSession session = req.getSession(true);
        session.setMaxInactiveInterval(1);
        out.println("<html><body>");
        out.println("<h2>Session Timeout Set to 1 Second</h2>");
        out.println("<p>Session ID: " + session.getId() + "</p>");
        out.println("<p>Inactive interval set to: " + session.getMaxInactiveInterval() + " second</p>");
        out.println("<p>Wait for a second and reload the page to see session expiration.</p>");
        out.println("</body></html>");
    }
}`,
        },
      ],
    },
    {
      slipId: 30,
      questions: [
        {
          questionId: 1,
          text: "Write a JSP script to accept a String from a user and display it in reverse order.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write a Java program in multithreading using applet for moving a car.",
          marks: 25,
        },
      ],
    },
  ],
  language: "java",
};

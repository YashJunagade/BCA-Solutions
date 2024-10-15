import javax.swing.*;
import java.awt.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Slip28B extends JFrame {

 private DefaultTableModel tableModel;
 private JTable employeeTable;
 private JTextField enoField, enameField, salaryField;
 private JButton addButton;

 public Slip28B() {
  setTitle("Employee Details");

  initializeUI();
  setVisible(true);
  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  setSize(500, 400);
  setLocationRelativeTo(null);
 }

 private void initializeUI() {
  tableModel = new DefaultTableModel();
  tableModel.addColumn("Employee Number");
  tableModel.addColumn("Employee Name");
  tableModel.addColumn("Salary");

  employeeTable = new JTable(tableModel);

  JPanel inputPanel = new JPanel(new GridLayout(2, 3, 5, 5));

  enoField = new JTextField(10);
  enameField = new JTextField(10);
  salaryField = new JTextField(10);
  addButton = new JButton("Add Employee");

  inputPanel.add(new JLabel("Employee Number:"));
  inputPanel.add(enoField);
  inputPanel.add(new JLabel("Employee Name:"));
  inputPanel.add(enameField);
  inputPanel.add(new JLabel("Salary:"));
  inputPanel.add(salaryField);
  inputPanel.add(addButton);

  addButton.addActionListener(new ActionListener() {
   @Override
   public void actionPerformed(ActionEvent e) {
    addEmployee();
   }
  });

  getContentPane().setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
  getContentPane().add(new JScrollPane(employeeTable));
  getContentPane().add(inputPanel);
 }

 private void addEmployee() {
  String eno = enoField.getText();
  String ename = enameField.getText();
  String salary = salaryField.getText();

  if (!eno.isEmpty() && !ename.isEmpty() && !salary.isEmpty()) {
   tableModel.addRow(new String[] { eno, ename, salary });
   enoField.setText("");
   enameField.setText("");
   salaryField.setText("");
  } else {
   JOptionPane.showMessageDialog(this, "Please enter all details.");
  }
 }

 public static void main(String[] args) {
  new Slip28B();
 }
}

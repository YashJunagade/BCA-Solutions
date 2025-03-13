export const DotNetFramework = {
  subject: "Dot Net Framework",
  slips: [
    {
      slipId: 1,
      questions: [
        {
          questionId: 1,
          text: "Write a VB.Net program to display the numbers continuously in a TextBox by clicking on a Button.",
          marks: 15,
          sol: `Public Class Slip1A
    Dim counter As Integer = 0
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        counter += 1
        TextBox1.Text &= counter.ToString() + " "
    End Sub
End Class
`,
        },
        {
          questionId: 2,
          text: "Write a VB.Net program to accept the details of Employee (ENO, EName, Salary) and store them into the database and display them in a GridView control.",
          marks: 25,
          sol: `Imports System
Imports System.Data.SqlClient

Public Class Slip1B
    Dim connectionString As String = "Data Source=LAPTOP-OV7L956K\SQLEXPRESS;Initial Catalog=Slip1DB;Integrated Security=True"
    Dim connection As New SqlConnection(connectionString)
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        LoadEmployees()
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Try
            Dim ename As String = txtEName.Text
            Dim salary As Decimal = Decimal.Parse(txtSalary.Text)

            Dim query As String = "INSERT INTO Employee (EName, Salary) VALUES (@EName, @Salary)"
            Dim cmd As New SqlCommand(query, connection)
            cmd.Parameters.AddWithValue("@EName", ename)
            cmd.Parameters.AddWithValue("@Salary", salary)

            connection.Open()
            cmd.ExecuteNonQuery()
            connection.Close()

            MessageBox.Show("Employee added successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information)
            LoadEmployees() ' Refresh GridView
        Catch ex As Exception
            MessageBox.Show("Error: " & ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        Finally
            connection.Close()
        End Try
    End Sub

    Private Sub LoadEmployees()
        Try
            Dim query As String = "SELECT * FROM Employee"
            Dim adapter As New SqlDataAdapter(query, connection)
            Dim dt As New DataTable()
            adapter.Fill(dt)

            dataGridView1.DataSource = dt
        Catch ex As Exception
            MessageBox.Show("Error: " & ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End Try
    End Sub
End Class
`,
        },
      ],
    },
    {
      slipId: 2,
      questions: [
        {
          questionId: 1,
          text: "Write a VB.Net program to move the text “Pune University” continuously from Left to Right and Vice Versa.",
          marks: 15,
          sol: `Public Class Slip2A
    Dim direction As Integer = 1
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Label1.Text = "Pune University"
        Label1.Left = 10
        Timer1.Interval = 50
        Timer1.Start()
    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Label1.Left += direction * 5
        If Label1.Left + Label1.Width >= Me.Width Then
            direction = -1
        ElseIf Label1.Left <= 0 Then
            direction = 1
        End If
    End Sub
End Class
`,
        },
        {
          questionId: 2,
          text: "Write a C#.Net program to create a base class Department and derived classes Sales and Human Resource. Accept the details of both departments and display them in proper format.",
          marks: 25,
          sol: `using System;

namespace Slip2B
{
    class Department
    {
        public int deptId { get; set; }
        public string deptName { get; set; }

        public void Accept()
        {
            Console.Write("Enter Department ID: "); // Changed WriteLine to Write
            deptId = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter Department Name: "); // Changed WriteLine to Write
            deptName = Console.ReadLine();
        }

        public virtual void DisplayDetails()
        {
            Console.WriteLine("\nDepartment ID: " + deptId);
            Console.WriteLine("Department Name: " + deptName);
        }
    }

    class Sales : Department
    {
        public int Target { get; set; }

        public void AcceptDetails()
        {
            Accept(); // Calling base class method
            Console.Write("Enter Monthly Sales Target: ");
            Target = Convert.ToInt32(Console.ReadLine());
        }

        public override void DisplayDetails()
        {
            base.DisplayDetails();
            Console.WriteLine("Sales Target: " + Target);
        }
    }

    class HumanResource : Department
    {
        public int NoOfEmployees { get; set; }

        public void AcceptDetails()
        {
            Accept(); // Calling base class method
            Console.Write("Enter Number of Employees: ");
            NoOfEmployees = Convert.ToInt32(Console.ReadLine());
        }

        public override void DisplayDetails()
        {
            base.DisplayDetails();
            Console.WriteLine("Number of Employees: " + NoOfEmployees);
        }
    }

    class Slip2B
    {
        static void Main(string[] args)
        {
            Console.WriteLine("\nAccept Details of Sales Department :-");
            Sales sale = new Sales();
            sale.AcceptDetails();
            Console.WriteLine("\nDetails of Sales Department :-");
            sale.DisplayDetails();

            Console.WriteLine("\nAccept Details of Human Resource Department :-"); // Fixed typo
            HumanResource hr = new HumanResource();
            hr.AcceptDetails();
            Console.WriteLine("\nDetails of Human Resource Department :-"); // Fixed incorrect label
            hr.DisplayDetails();

            Console.ReadLine();
        }
    }
}
`,
        },
      ],
    },
    {
      slipId: 3,
      questions: [
        {
          questionId: 1,
          text: "Write a program in C# .Net to create a function for the sum of two numbers.",
          marks: 15,
          sol: `using System;

namespace Slip3A
{
    class Slip3A
    {
        public static int Sum(int a, int b)
        {
            return a + b;
        }
        static void Main(string[] args)
        {
            Console.Write("Enter First Number : ");
            int a = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter Second Number : ");
            int b = Convert.ToInt32(Console.ReadLine());

            int result = Sum(a, b);
            Console.WriteLine("The Sum of {0} and {1} is {2}", a, b, result);
            Console.WriteLine("Press any key to exit....");
            Console.ReadLine();
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a VB.NET program to create a teacher table (Tid, TName, subject). Insert the records (Max: 5). Search for a teacher whose name is “Seeta” and display the result.",
          marks: 25,
          sol: `Imports System
Imports System.Data.SqlClient

Public Class Slip3B
    ' Connection String (Update with your SQL Server details)
    Dim connectionString As String = "Server=LAPTOP-OV7L956K\SQLEXPRESS;Database=Slip3DB;Trusted_Connection=True;"
    Dim connection As New SqlConnection(connectionString)

    Private Sub btnSearch_Click(ByVal sender As Object, ByVal e As EventArgs) Handles btnSearch.Click
        Try
            Dim query As String = "SELECT * FROM Teacher WHERE TName = 'Seeta'"
            Dim adapter As New SqlDataAdapter(query, connection)
            Dim dt As New DataTable()
            adapter.Fill(dt)

            If dt.Rows.Count > 0 Then
                dataGridView1.DataSource = dt
            Else
                MessageBox.Show("No records found for 'Seeta'", "Not Found", MessageBoxButtons.OK, MessageBoxIcon.Information)
                dataGridView1.DataSource = Nothing
            End If
        Catch ex As Exception
            MessageBox.Show("Error: " & ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End Try
    End Sub
End Class
`,
        },
      ],
    },
    {
      slipId: 4,
      questions: [
        {
          questionId: 1,
          text: "Design a VB.NET form to pick a date from DateTimePicker Control and display day, month, and year in separate text boxes.",
          marks: 15,
          sol: `Public Class Slip4A
    Private Sub showButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles showButton.Click
        Dim selectedDate As Date = datePicker.Value
        txtDate.Text = selectedDate.Day.ToString()
        txtMonth.Text = selectedDate.Month.ToString()
        txtYear.Text = selectedDate.Year.ToString()
    End Sub
End Class
`,
        },
        {
          questionId: 2,
          text: "Create a web application to insert 3 records into a SQL database table with the following fields: (DeptId, DeptName, EmpName, Salary). Update the salary for any one employee, increasing it by 15% of the present salary. Perform a delete operation on one row of the database table.",
          marks: 25,
          sol: `//Slip4B.aspx.cs
          
using System;
using System.Web.UI;
using System.Data;
using System.Data.SqlClient;
namespace Slip4B
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        string connectionString = "Server=LAPTOP-OV7L956K\\SQLEXPRESS;Database=SlipsDB;Trusted_Connection=True;";

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                LoadEmployees();
            }
        }
        protected void btnInsert_Click(object sender, EventArgs e)
        {
            using (SqlConnection con = new SqlConnection(connectionString))
            {
                con.Open();
                string query = @"
                    INSERT INTO Department (DeptId, DeptName, EmpName, Salary) VALUES 
                    (1, 'HR', 'John Doe', 50000),
                    (2, 'IT', 'Alice Smith', 60000),
                    (3, 'Finance', 'Robert Brown', 55000)";
                SqlCommand cmd = new SqlCommand(query, con);
                cmd.ExecuteNonQuery();
            }
            LoadEmployees();
        }

        protected void btnUpdate_Click(object sender, EventArgs e)
        {
            using (SqlConnection con = new SqlConnection(connectionString))
            {
                con.Open();
                string query = "UPDATE Department SET Salary = Salary * 1.15 WHERE EmpName = 'John Doe'";
                SqlCommand cmd = new SqlCommand(query, con);
                cmd.ExecuteNonQuery();
            }
            LoadEmployees();
        }

        protected void btnDelete_Click(object sender, EventArgs e)
        {
            using (SqlConnection con = new SqlConnection(connectionString))
            {
                con.Open();
                string query = "DELETE FROM Department WHERE EmpName = 'Alice Smith'";
                SqlCommand cmd = new SqlCommand(query, con);
                cmd.ExecuteNonQuery();
            }
            LoadEmployees();
        }

        private void LoadEmployees()
        {
            using (SqlConnection con = new SqlConnection(connectionString))
            {
                con.Open();
                SqlDataAdapter adapter = new SqlDataAdapter("SELECT * FROM Department", con);
                DataTable dt = new DataTable();
                adapter.Fill(dt);
                GridView1.DataSource = dt;
                GridView1.DataBind();
            }
        }
    }
}
    

//Slip4B.aspx

<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip4B.aspx.cs" Inherits="Slip4B.WebForm1" %>

<!DOCTYPE html>

<html>
<head runat="server">
    <title>Manage Employee Records</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h2>Employee Management</h2>

        <asp:Button ID="btnInsert" runat="server" Text="Insert 3 Records" OnClick="btnInsert_Click" />
        <asp:Button ID="btnUpdate" runat="server" Text="Update Salary by 15%" OnClick="btnUpdate_Click" />
        <asp:Button ID="btnDelete" runat="server" Text="Delete One Record" OnClick="btnDelete_Click" />

        <h3>Employee List</h3>
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="True"></asp:GridView>
    </div>
    </form>
</body>
</html>

`,
        },
      ],
    },
    {
      slipId: 5,
      questions: [
        {
          questionId: 1,
          text: "Write a VB.NET program to accept a character from the keyboard and check whether it is a vowel or consonant. Also, display the case of that character.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Design a web application form in ASP.Net with fields for loan amount, interest rate, and duration. Calculate the simple interest and perform necessary validations, ensuring data has been entered for each field and checking for non-numeric values. Use suitable web-form controls.",
          marks: 25,
        },
      ],
    },
    {
      slipId: 6,
      questions: [
        {
          questionId: 1,
          text: "Write an ASP.Net program that displays the names of some flowers in two columns. Bind a label to the RadioButtonList so that when the user selects an option from the list and clicks on a button, the label displays the flower selected by the user.",
          marks: 15,
          sol: `//Slip6A.aspx.cs
          
using System;
using System.Web.UI;

namespace Slip6A
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                lblSelectedFlower.Text = "";
            }
        }

        protected void btnSelect_Click(object sender, EventArgs e)
        {
            if (rblFlowers.SelectedItem != null)
            {
                lblSelectedFlower.Text = "You selected: " + rblFlowers.SelectedItem.Text;
            }
            else
            {
                lblSelectedFlower.Text = "Please select a flower!";
            }
        }
    }
}
    

//Slip6A.aspx


<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip6A.aspx.cs" Inherits="Slip6A.WebForm1" %>

<!DOCTYPE html>

<html>
<head runat="server">
    <title>Flower Selection</title>
    <style>
        .container {
            text-align: center;
            margin-top: 50px;
        }
        .flower-list {
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
        }
        .flower-list table {
            width: 50%;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div class="container">
            <h2>Select a Flower</h2>
            <asp:RadioButtonList ID="rblFlowers" runat="server" CssClass="flower-list" RepeatColumns="2">
                <asp:ListItem>Rose</asp:ListItem>
                <asp:ListItem>Lily</asp:ListItem>
                <asp:ListItem>Jasmine</asp:ListItem>
                <asp:ListItem>Sunflower</asp:ListItem>
                <asp:ListItem>Tulip</asp:ListItem>
                <asp:ListItem>Daisy</asp:ListItem>
            </asp:RadioButtonList>
            
            <br />
            <asp:Button ID="btnSelect" runat="server" Text="Show Selected Flower" OnClick="btnSelect_Click" />
            <br /><br />
            <asp:Label ID="lblSelectedFlower" runat="server" Font-Bold="true" ForeColor="Green"></asp:Label>
        </div>
    </form>
</body>
</html>

`,
        },
        {
          questionId: 2,
          text: "Write a VB.NET program to create a movie table (Mv_Name, Release_year, Director). Insert the records (Max: 5). Delete the records of movies whose release year is 2022 and display an appropriate message in a message box.",
          marks: 25,
          sol: `Imports System
Imports System.Collections.Generic
Imports System.Data.SqlClient

Public Class Slip6B
    Dim connectionString As String = "Server=LAPTOP-OV7L956K\SQLEXPRESS;Database=SlipsDB;Integrated Security=True"
    Private Sub btnCreateTable_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCreateTable.Click
        CreateTable()
    End Sub

    Private Sub btnInsertRecords_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnInsertRecords.Click
        InsertRecords()
    End Sub

    Private Sub btnDeleteMovies_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnDeleteMovies.Click
        DeleteMovies()
    End Sub

    Private Sub CreateTable()
        Using conn As New SqlConnection(connectionString)
            conn.Open()
            Dim query As String = "CREATE TABLE Movies(Mv_Name NVARCHAR(30), Release_Year INT, Director NVARCHAR(30))"
            Using cmd As New SqlCommand(query, conn)
                cmd.ExecuteNonQuery()
            End Using
        End Using
        MessageBox.Show("Table Created Successfully", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information)
    End Sub

    Private Sub InsertRecords()
        Dim movies As New List(Of Tuple(Of String, Integer, String)) From {
            Tuple.Create("Movie A", 2020, "Director 1"),
            Tuple.Create("Movie B", 2021, "Director 2"),
            Tuple.Create("Movie C", 2022, "Director 3"),
            Tuple.Create("Movie D", 2023, "Director 4"),
            Tuple.Create("Movie E", 2022, "Director 5")
        }

        Using conn As New SqlConnection(connectionString)
            conn.Open()
            For Each movie In movies
                Dim query As String = "INSERT INTO Movies (Mv_Name, Release_Year, Director) VALUES (@name, @year, @director)"
                Using cmd As New SqlCommand(query, conn)
                    cmd.Parameters.AddWithValue("@name", movie.Item1)
                    cmd.Parameters.AddWithValue("@year", movie.Item2)
                    cmd.Parameters.AddWithValue("@director", movie.Item3)
                    cmd.ExecuteNonQuery()
                End Using
            Next
        End Using
        MessageBox.Show("Movies Inserted Successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information)
    End Sub

    Private Sub DeleteMovies()
        Using conn As New SqlConnection(connectionString)
            conn.Open()
            Dim query As String = "DELETE FROM Movies WHERE Release_Year = 2022"
            Using cmd As New SqlCommand(query, conn)
                Dim rowsAffected As Integer = cmd.ExecuteNonQuery()
                If rowsAffected > 0 Then
                    MessageBox.Show(rowsAffected.ToString() & " movies released in 2022 were deleted.", "Deletion Successful", MessageBoxButtons.OK, MessageBoxIcon.Information)
                Else
                    MessageBox.Show("No movies from 2022 found.", "No Deletion", MessageBoxButtons.OK, MessageBoxIcon.Warning)
                End If
            End Using
        End Using
    End Sub
End Class
`,
        },
      ],
    },
    {
      slipId: 7,
      questions: [
        {
          questionId: 1,
          text: "Write an ASP.Net program to accept a number from the user in a textbox control and throw an exception if the number is not a perfect number. Assume suitable controls on the web form.",
          marks: 15,
          sol: `//Slip7A.aspx
          
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip7A.aspx.cs" Inherits="Slip7A.WebForm1" %>
<!DOCTYPE html>
<html>
<head runat="server">
    <title>Perfect Number Checker</title>
</head>
<body>
    <form id="form1" runat="server">
    <div class="container">
        <h2>Perfect Number Checker</h2>
        <asp:Label ID="lblMessage" runat="server" CssClass="error"></asp:Label>
        <br /><br />
        <asp:TextBox ID="txtNumber" runat="server" placeholder="Enter a number"></asp:TextBox>
        <br /><br />
        <asp:Button ID="btnCheck" runat="server" Text="Check" OnClick="btnCheck_Click" />
    </div>
    </form>
</body>
</html>


//Slip7A.aspx.cs

using System;

namespace Slip7A
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void btnCheck_Click(object sender, EventArgs e)
        {
            try
            {
                int number;
                if (!int.TryParse(txtNumber.Text, out number) || number <= 0)
                {
                    throw new Exception("Please enter a valid positive integer.");
                }
                if (!isPerfectNumber(number))
                {
                    throw new Exception(number.ToString() + " is not a perfect number");
                }
                lblMessage.Text = number.ToString() + " is a Perfect Number!";
            }
            catch (Exception ex)
            {
                lblMessage.Text = "Error : " + ex.Message;
            }
        }

        private bool isPerfectNumber(int num)
        {
            int sum = 0;
            for (int i = 1; i <= num / 2; i++)
            {
                if (num % i == 0)
                {
                    sum += i;
                }
            }
            return sum == num;
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a VB.NET program to create a table student (Roll No, SName, Class, City). Insert the records (Max: 5). Update the city of students to ‘Pune’ whose city is ‘Mumbai’ and display updated records in a GridView.",
          marks: 25,
          sol: `Imports System
Imports System.Data.SqlClient

Public Class Slip7B
    Dim con As New SqlConnection("Data Source=LAPTOP-OV7L956K\SQLEXPRESS;Initial Catalog=SlipsDB;Integrated Security=True")

    Private Sub UpdateCity()
        Try
            con.Open()
            Dim query As String = "update Student set City = 'Pune' where City='Mumbai'"
            Dim cmd As New SqlCommand(query, con)
            Dim rowsAffected As Integer = cmd.ExecuteNonQuery()
            con.Close()
            If rowsAffected > 0 Then
                MessageBox.Show(rowsAffected.ToString() & " records updated successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information)
                LoadGridView()
            Else
                MessageBox.Show("No records found with city 'Mumbai'.", "Info", MessageBoxButtons.OK, MessageBoxIcon.Information)
            End If
        Catch ex As Exception
            MessageBox.Show("Error: " & ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        Finally
            con.Close()
        End Try
    End Sub

    Private Sub LoadGridView()
        Try
            con.Open()
            Dim query As String = "select * from Student"
            Dim adapter As New SqlDataAdapter(query, con)
            Dim dt As New DataTable()
            adapter.Fill(dt)
            DataGridView1.DataSource = dt
            con.Close()
        Catch ex As Exception
            MessageBox.Show("Error: " & ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        Finally
            con.Close()
        End Try
    End Sub

    Private Sub btnUpdate_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnUpdate.Click
        UpdateCity()
    End Sub

    Private Sub btnLoad_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnLoad.Click
        LoadGridView()
    End Sub
End Class
`,
        },
      ],
    },
    {
      slipId: 8,
      questions: [
        {
          questionId: 1,
          text: "List of employees is available in a listbox. Write an ASP.Net application to add selected or all records from the listbox to a TextBox (assume multi-line property of TextBox is true).",
          marks: 15,
          sol: `//Slip8A.aspx
          
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip8A.aspx.cs" Inherits="Slip8A.WebForm1" %>

<!DOCTYPE html>

<html>
<head runat="server">
    <title>Employee List</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h2>Select Employees</h2>
        <asp:ListBox ID="lstEmployees" runat="server" SelectionMode="Multiple" Height="150px" Width="200px"></asp:ListBox>
        <br /><br />
        <asp:Button ID="btnAddSelected" runat="server" Text="Add Selected" OnClick="btnAddSelected_Click" />
        <asp:Button ID="btnAddAll" runat="server" Text="Add All" OnClick="btnAddAll_Click" />
        <br /><br />
        <asp:TextBox ID="txtSelectedEmployees" runat="server" TextMode=MultiLine Rows=6 Columns=30></asp:TextBox>
    </div>
    </form>
</body>
</html>

//Slip8A.aspx.cs

using System;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Slip8A
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                // Sample employee data
                lstEmployees.Items.Add("John Doe");
                lstEmployees.Items.Add("Jane Smith");
                lstEmployees.Items.Add("Robert Brown");
                lstEmployees.Items.Add("Alice Johnson");
                lstEmployees.Items.Add("David Wilson");
            }
        }

        protected void btnAddSelected_Click(object sender, EventArgs e)
        {
            txtSelectedEmployees.Text = ""; // Clear previous entries
            foreach (var item in lstEmployees.GetSelectedIndices())
            {
                txtSelectedEmployees.Text += lstEmployees.Items[item].Text + Environment.NewLine;
            }
        }

        protected void btnAddAll_Click(object sender, EventArgs e)
        {
            txtSelectedEmployees.Text = ""; // Clear previous entries
            foreach (ListItem item in lstEmployees.Items)
            {
                txtSelectedEmployees.Text += item.Text + Environment.NewLine;
            }
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a C#.Net program for multiplication of matrices.",
          marks: 25,
          sol: `using System;

namespace Slip8B
{
    class Slip8B
    {
        static void Main(string[] args)
        {
            Console.Write("Enter number of rows for Matrix A: ");
            int rowsA = int.Parse(Console.ReadLine());

            Console.Write("Enter number of columns for Matrix A (and rows for Matrix B): ");
            int colsA = int.Parse(Console.ReadLine());

            Console.Write("Enter number of columns for Matrix B: ");
            int colsB = int.Parse(Console.ReadLine());

            int[,] matrixA = new int[rowsA, colsA];
            int[,] matrixB = new int[colsA, colsB];
            int[,] resultMatrix = new int[rowsA, colsB];

            Console.WriteLine("Enter elements for Matrix A:");
            for (int i = 0; i < rowsA; i++)
            {
                for (int j = 0; j < colsA; j++)
                {
                    Console.Write("A[" + i + "," + j + "]: ");
                    matrixA[i, j] = int.Parse(Console.ReadLine());
                }
            }

            Console.WriteLine("Enter elements for Matrix B:");
            for (int i = 0; i < colsA; i++)
            {
                for (int j = 0; j < colsB; j++)
                {
                    Console.Write("B[" + i + "," + j + "]: ");
                    matrixB[i, j] = int.Parse(Console.ReadLine());
                }
            }

            for (int i = 0; i < rowsA; i++)
            {
                for (int j = 0; j < colsB; j++)
                {
                    resultMatrix[i, j] = 0;
                    for (int k = 0; k < colsA; k++)
                    {
                        resultMatrix[i, j] += matrixA[i, k] * matrixB[k, j];
                    }
                }
            }

            Console.WriteLine("\nResultant Matrix:");
            for (int i = 0; i < rowsA; i++)
            {
                for (int j = 0; j < colsB; j++)
                {
                    Console.Write(resultMatrix[i, j] + "\t");
                }
                Console.WriteLine();
            }
            Console.ReadLine();
        }
    }
}
`,
        },
      ],
    },
    {
      slipId: 9,
      questions: [
        {
          questionId: 1,
          text: "Write a Menu-driven program in C#.Net to perform the following functionalities: Addition, Multiplication, Subtraction, Division.",
          marks: 15,
          sol: `using System;

namespace Slip9A
{
    class Slip9A
    {
        static void Main()
        {
            while (true)
            {
                Console.WriteLine("\nMENU");
                Console.WriteLine("1. Addition");
                Console.WriteLine("2. Subtraction");
                Console.WriteLine("3. Multiplication");
                Console.WriteLine("4. Division");
                Console.WriteLine("5. Exit");
                Console.Write("Enter your choice: ");

                int choice;
                if (!int.TryParse(Console.ReadLine(), out choice))
                {
                    Console.WriteLine("Invalid input! Please enter a number between 1 and 5.");
                    continue;
                }

                if (choice == 5)
                {
                    Console.WriteLine("Exiting the program. Goodbye!");
                    break;  // Exit the loop when choice is 5
                }

                Console.Write("Enter first number: ");
                int num1 = Convert.ToInt32(Console.ReadLine());

                Console.Write("Enter second number: ");
                int num2 = Convert.ToInt32(Console.ReadLine());

                double result;

                switch (choice)
                {
                    case 1:
                        result = num1 + num2;
                        Console.WriteLine("Result : {0} + {1} = {2}", num1, num2, result);
                        break;
                    case 2:
                        result = num1 - num2;
                        Console.WriteLine("Result : {0} - {1} = {2}", num1, num2, result);
                        break;
                    case 3:
                        result = num1 * num2;
                        Console.WriteLine("Result : {0} * {1} = {2}", num1, num2, result);
                        break;
                    case 4:
                        if (num2 != 0)
                        {
                            result = (double)num1 / num2; // Ensure floating point division
                            Console.WriteLine("Result : {0} / {1} = {2}", num1, num2, result);
                        }
                        else
                        {
                            Console.WriteLine("Error: Division by zero is not allowed.");
                        }
                        break;
                    default:
                        Console.WriteLine("Invalid choice! Please enter a number between 1 and 5.");
                        break;
                }
            }
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Create an ASP.Net application that allows the user to enter a number in the textbox named 'getnum'. Check whether the number in the textbox 'getnum' is a palindrome or not. Print the message accordingly in the label control named 'lbldisplay' when the user clicks on the button 'check'.",
          marks: 25,
          sol: `//Slip9B.aspx
          
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip9B.aspx.cs" Inherits="Slip9B.WebForm1" %>

<!DOCTYPE html>

<html>
<head runat="server">
    <title>Palindrome Checker</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h2>Palindrome Checker</h2>
        <asp:TextBox ID="getNum" runat="server" ></asp:TextBox>
        <br />
        <asp:Button ID="check"  runat="server" Text="Check" OnClick="check_Click" />
        <br />
        <asp:Label ID="lbldisplay" runat=server Font-Bold=true></asp:Label>
    </div>
    </form>
</body>
</html>


//Slip9B.aspx.cs


using System;
using System.Web.UI;

namespace Slip9B
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void check_Click(object sender, EventArgs e)
        {
            string input = getNum.Text.Trim(); // Get input from TextBox

            int number;
            if (int.TryParse(input, out number)) // Ensure valid number input
            {
                if (IsPalindrome(number))
                {
                    lbldisplay.Text = number + " is a Palindrome.";
                }
                else
                {
                    lbldisplay.Text = number + " is not a Palindrome.";
                }
            }
            else
            {
                lbldisplay.Text = "Please enter a valid number.";
            }
        }

        private bool IsPalindrome(int num)
        {
            string strNum = num.ToString(); 
            char[] arr = strNum.ToCharArray(); 
            Array.Reverse(arr); 
            string reversed = new string(arr);

            return strNum == reversed; 
        }
    }
}
`,
        },
      ],
    },
    {
      slipId: 10,
      questions: [
        {
          questionId: 1,
          text: "Write a program that demonstrates the use of primitive data types in C#. The program should also support the type conversion of Integer to String and String to Integer.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write an ASP.Net program to connect to the master database in SQL Server in the Page_Load event. When the connection is established, the message 'Connection has been established' should be displayed in a label in the form.",
          marks: 25,
        },
      ],
    },
    {
      slipId: 11,
      questions: [
        {
          questionId: 1,
          text: "Write an ASP.Net program that gets user input such as the user name, mode of payment, and appropriate credit card. After the user enters the appropriate values, the Validation button validates the values entered.",
          marks: 15,
          sol: `//Slip11A.aspx
          
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip11A.aspx.cs" Inherits="Slip11A.WebForm1" %>

<!DOCTYPE html>
<html>
<head id="Head1" runat="server">
    <title>Payment Validation</title>
</head>
<body>
    <form id="form1" runat="server">
        <h2>Payment Validation Form</h2>

        <label>Enter Name:</label>
        <br />
        <asp:TextBox ID="txtName" runat="server"></asp:TextBox>
        <br /><br />

        <label>Mode of Payment:</label>
        <br />
        <asp:DropDownList ID="ddlPaymentMode" runat="server">
            <asp:ListItem Text="-- Select --" Value="" />
            <asp:ListItem Text="Credit Card" Value="CreditCard" />
            <asp:ListItem Text="Debit Card" Value="DebitCard" />
        </asp:DropDownList>
        <br /><br />

        <label>Enter Credit Card Number (If Applicable):</label>
        <br />
        <asp:TextBox ID="txtCreditCard" runat="server"></asp:TextBox>
        <br /><br />

        <asp:Button ID="btnValidate" runat="server" Text="Validate" OnClick="btnValidate_Click" />
        <br /><br />

        <asp:Label ID="lblMessage" runat="server" ForeColor="Red"></asp:Label>
    </form>
</body>
</html>


//Slip11A.aspx.cs


using System;
using System.Text;
using System.Web.UI;

namespace Slip11A
{
    public partial class WebForm1 : Page
    {
        protected void btnValidate_Click(object sender, EventArgs e)
        {
            StringBuilder errors = new StringBuilder();

            // Validate Name
            if (string.IsNullOrWhiteSpace(txtName.Text))
            {
                errors.AppendLine("Name is required.");
            }

            // Validate Payment Mode
            if (string.IsNullOrWhiteSpace(ddlPaymentMode.SelectedValue))
            {
                errors.AppendLine("Please select a mode of payment.");
            }

            // Validate Credit Card (Only if Credit Card is selected)
            if (ddlPaymentMode.SelectedValue == "CreditCard")
            {
                if (string.IsNullOrWhiteSpace(txtCreditCard.Text))
                {
                    errors.AppendLine("Credit Card number is required.");
                }
                else if (!System.Text.RegularExpressions.Regex.IsMatch(txtCreditCard.Text, @"^\d{16}$"))
                {
                    errors.AppendLine("Enter a valid 16-digit Credit Card Number.");
                }
            }

            // Display Errors or Success Message
            if (errors.Length > 0)
            {
                lblMessage.ForeColor = System.Drawing.Color.Red;
                lblMessage.Text = "Validation Failed:<br/>" + errors.ToString().Replace("\n", "<br/>");
            }
            else
            {
                lblMessage.ForeColor = System.Drawing.Color.Green;
                lblMessage.Text = "Validation Successful!";
            }
        }
    }
}

`,
        },
        {
          questionId: 2,
          text: "Write a C# program to make a class named Fruit with a data member to calculate the number of fruits in a basket. Create two other classes named Apples and Mangoes to calculate the number of apples and mangoes in the basket. Display the total number of fruits in the basket.",
          marks: 25,
          sol: `using System;

class Fruit
{
    protected static int totalFruits;
    public void DisplayTotalFruits()
    {
        Console.WriteLine("Total number of fruits in the basket : " + totalFruits);
    }
}

class Apples : Fruit
{
    private int appleCount;
    public Apples(int apples)
    {
        appleCount = apples;
        totalFruits += appleCount;
    }
    public void DisplayApples()
    {
        Console.WriteLine("Number of apples in the basket : " + appleCount);
    }
}

class Mangoes : Fruit
{
    private int mangoCount;
    public Mangoes(int mangoes)
    {
        mangoCount = mangoes;
        totalFruits += mangoCount;
    }
    public void DisplayMangoes()
    {
        Console.WriteLine("Number of mangoes in the basket : " + mangoCount);
    }
}

namespace Slip11B
{
    class Slip11B
    {
        static void Main(string[] args)
        {
            Apples a = new Apples(5);
            Mangoes m = new Mangoes(5);
            a.DisplayApples();
            m.DisplayMangoes();
            a.DisplayTotalFruits();
            Console.ReadLine();
        }
    }
}
`,
        },
      ],
    },
    {
      slipId: 12,
      questions: [
        {
          questionId: 1,
          text: "Write an ASP.Net program that displays a button in green color and it should change to yellow when the mouse moves over it.",
          marks: 15,
          sol: `<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip12A.aspx.cs" Inherits="Slip12A.WebForm1" %>

<!DOCTYPE html />

<html>
<head runat="server">
    <title>Button Color Change</title>
    <style>
        /* Default button color */
        .green-button {
            background-color: green;
            color: white;
            padding: 10px 20px;
            border: none;
            cursor: pointer;
        }

        /* Change color on hover */
        .green-button:hover {
            background-color: yellow;
            color: black;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
            <asp:Button ID="btnColorChange" runat="server" Text="Hover over me!" CssClass="green-button" />
        </div>
    </form>
</body>
</html>
`,
        },
        {
          questionId: 2,
          text: "Write a VB.NET program to create a player table (PID, PName, Game, no_of_matches). Insert records and update the number of matches of ‘Rohit Sharma’ and display the result in a DataGridView.",
          marks: 25,
          sol: `Imports System
Imports System.Data.SqlClient

Public Class Slip12B
    Dim con As SqlConnection
    Dim cmd As SqlCommand
    Dim da As SqlDataAdapter
    Dim dt As DataTable

    ' Establishing Database Connection
    Private Sub ConnectDatabase()
        con = New SqlConnection("Data Source=LAPTOP-OV7L956K\SQLEXPRESS;Initial Catalog=SlipsDB;Integrated Security=True")
        con.Open()
    End Sub

    ' Creating the Player Table
    Private Sub CreateTable()
        ConnectDatabase()
        Dim query As String = "CREATE TABLE Player( PID INT PRIMARY KEY IDENTITY, PName NVARCHAR(50), Game NVARCHAR(50), no_of_matches INT )"
        cmd = New SqlCommand(query, con)
        cmd.ExecuteNonQuery()
        con.Close()
    End Sub


    ' Insert Sample Records
    Private Sub InsertRecords()
        ConnectDatabase()
        Dim query As String = "INSERT INTO Player (PName, Game, no_of_matches) VALUES('Rohit Sharma', 'Cricket', 250),('Virat Kohli', 'Cricket', 270),('MS Dhoni', 'Cricket', 350)"
        cmd = New SqlCommand(query, con)
        cmd.ExecuteNonQuery()
        con.Close()
    End Sub

    ' Update Rohit Sharma's Number of Matches
    Private Sub UpdateRohitMatches()
        ConnectDatabase()
        Dim query As String = "UPDATE Player SET no_of_matches = no_of_matches + 1 WHERE PName = 'Rohit Sharma'"
        cmd = New SqlCommand(query, con)
        cmd.ExecuteNonQuery()
        con.Close()
        DisplayRecords()
    End Sub

    ' Display Data in DataGridView
    Private Sub DisplayRecords()
        ConnectDatabase()
        Dim query As String = "SELECT * FROM Player"
        da = New SqlDataAdapter(query, con)
        dt = New DataTable()
        da.Fill(dt)
        DataGridView1.DataSource = dt
        con.Close()
    End Sub

    ' On Form Load, Create Table and Insert Data
    Private Sub Form1_Load(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Load
        CreateTable()
        InsertRecords()
        DisplayRecords()
    End Sub

    ' Button Click - Update Rohit's Matches
    Private Sub btnUpdate_Click(ByVal sender As Object, ByVal e As EventArgs) Handles btnUpdate.Click
        UpdateRohitMatches()
    End Sub
End Class
`,
        },
      ],
    },
    {
      slipId: 13,
      questions: [
        {
          questionId: 1,
          text: "Write a VB.NET program for blinking an image.",
          marks: 15,
          sol: `Public Class Slip13A

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        PictureBox1.Visible = Not PictureBox1.Visible
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Timer1.Interval = 500
        Timer1.Start()
        PictureBox1.SizeMode = PictureBoxSizeMode.Zoom
    End Sub
End Class
`,
        },
        {
          questionId: 2,
          text: "Write a C# program to accept and display ‘n’ student’s details such as Roll No, Name, and marks in three subjects, using a class. Display the percentage of each student.",
          marks: 25,
          sol: `using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Slip13B
{
    class Student
    {
        public int RollNo;
        public string Name;
        public int[] Marks = new int[3];
        public float Percentage;
        public void acceptDetails()
        {
            Console.Write("Enter Roll No : ");
            RollNo = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter Name : ");
            Name = Console.ReadLine();

            int totalMarks = 0;
            for (int i = 0; i < 3; i++)
            {
                Console.Write("Enter marks for subject {0} : ", i + 1);
                Marks[i] = Convert.ToInt32(Console.ReadLine());
                totalMarks += Marks[i];
            }
            Percentage = (float)totalMarks / 3;
        }

        public void displayDetails()
        {
            Console.WriteLine("\nStudent Details:");
            Console.WriteLine("Roll No: {0}", RollNo);
            Console.WriteLine("Name: {0}", Name);
            Console.WriteLine("Marks: {0}, {1}, {2}", Marks[0], Marks[1], Marks[2]);
            Console.WriteLine("Percentage: {0:F2}%", Percentage);
        }
    }
    class Slip13B
    {
        static void Main(string[] args)
        {
            Console.Write("Enter number of students : ");
            int n = Convert.ToInt32(Console.ReadLine());
            Student[] students = new Student[n];
            for (int i = 0; i < n; i++)
            {
                Console.Write("Enter marks for subject {0}: ", i + 1);
                students[i] = new Student();
                students[i].acceptDetails();
            }
            Console.WriteLine("Student Details :- ");
            foreach (Student s in students)
            {
                s.displayDetails();
                Console.WriteLine("----------------------------");
            }
            Console.ReadLine();
        }
    }
}
`,
        },
      ],
    },
    {
      slipId: 14,
      questions: [
        {
          questionId: 1,
          text: "Write a program in C#.Net to find the sum of all elements in the array.",
          marks: 15,
          sol: `using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Slip14A
{
    class Slip14A
    {
        static void Main(string[] args)
        {
            Console.Write("Enter the size of the array : ");
            int size = Convert.ToInt32(Console.ReadLine());
            int[] array = new int[size];
            int sum = 0;
            Console.WriteLine("Enter the array elements :");
            for (int i = 0; i < size; i++)
            {
                Console.Write("Element [{0}] : ", i + 1);
                array[i] = Convert.ToInt32(Console.ReadLine());
                sum += array[i];
            }
            Console.WriteLine("Sum of array elements is {0}", sum);
            Console.ReadLine();
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a C#.Net program to define a class Person having members – name and address. Create a subclass called Employee with members – staff_id and salary. Create ‘n’ objects of the Employee class and display all the details of the Employee.",
          marks: 25,
          sol: `using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Slip14B
{
    class Person
    {
        public string Name { get; set; }
        public string Address { get; set; }

        public void AcceptPersonDetails()
        {
            Console.Write("Enter Name: ");
            Name = Console.ReadLine();
            Console.Write("Enter Address: ");
            Address = Console.ReadLine();
        }

        public virtual void DisplayDetails()
        {
            Console.WriteLine("Name: " + Name);
            Console.WriteLine("Address: " + Address);
        }
    }
    class Employee : Person
    {
        public int StaffId { get; set; }
        public double Salary { get; set; }

        public void AcceptEmployeeDetails()
        {
            AcceptPersonDetails(); // Call base class method
            Console.Write("Enter Staff ID: ");
            StaffId = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter Salary: ");
            Salary = Convert.ToDouble(Console.ReadLine());
        }

        public override void DisplayDetails()
        {
            base.DisplayDetails(); // Display person details
            Console.WriteLine("Staff ID: " + StaffId);
            Console.WriteLine("Salary: " + Salary);
        }
    }
    class Slip14B
    {
        static void Main(string[] args)
        {
            Console.Write("Enter number of employees: ");
            int n = Convert.ToInt32(Console.ReadLine());
            Employee[] employees = new Employee[n];
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("\nEnter details for Employee {0}:", i + 1);
                employees[i] = new Employee();
                employees[i].AcceptEmployeeDetails();
            }
            Console.WriteLine("\nEmployee Details:");
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("\nEmployee {0}:", i + 1);
                employees[i].DisplayDetails();
            }
            Console.ReadLine();
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
          text: "Write an ASP.Net application to create a user control that contains a list of colors. Add a button to the Web Form which, when clicked, changes the color of the form to the color selected from the list.",
          marks: 15,
          sol: `//Slip15A.aspx
          
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip15A.aspx.cs" Inherits="WebApplication1_CSharp_.Slip15A" %>
<%@ Register Src="UserControl/WebUserControl_Slip15A.ascx" TagPrefix="uc" TagName="ColorPicker" %>


<html>
<head runat="server">
     <title>ASP.NET Color Picker</title>
</head>
<body runat="server" id="bodyElement">
    <form id="form1" runat="server">
    <div>
        <uc:ColorPicker ID="ColorPicker1" runat="server" />
        <asp:Button ID="btnApplyColor" runat="server" Text="Apply Color" OnClick="btnApplyColor_Click" /> 
    </div>
    </form>
</body>
</html>


//slip15A.aspx.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1_CSharp_
{
    public partial class Slip15A : System.Web.UI.Page
    {
        protected void btnApplyColor_Click(object sender, EventArgs e)
        {
            string selectedColor = ColorPicker1.SelectedColor;
            bodyElement.Style["background-color"] = selectedColor;
        }
    }
}


//WebUserControl_Slip15A.ascx

<%@ Control Language="C#" AutoEventWireup="true" CodeBehind="WebUserControl_Slip15A.ascx.cs" Inherits="WebApplication1_CSharp_.UserControl.WebUserControl_Slip15A" %>
<asp:DropDownList ID="ddlColors" runat="server">
    <asp:ListItem Text="Red" Value="Red"></asp:ListItem>
    <asp:ListItem Text="Green" Value="Green"></asp:ListItem>
    <asp:ListItem Text="Blue" Value="Blue"></asp:ListItem>
    <asp:ListItem Text="Yellow" Value="Yellow"></asp:ListItem>
    <asp:ListItem Text="Pink" Value="Pink"></asp:ListItem>
</asp:DropDownList>



//WebUserControl_Slip.ascx.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1_CSharp_.UserControl
{
    public partial class WebUserControl_Slip15A : System.Web.UI.UserControl
    {
        public string SelectedColor
        {
            get { return ddlColors.SelectedValue; }
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a C#.Net program to accept and display ‘n’ customer’s details such as customer_no, Name, address, item_no, quantity, and price. Display the total price of all items.",
          marks: 25,
          sol: `using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
	class Customer
	{
		public int cust_no { get; set; }
		public string name { get; set; }
		public string address { get; set; }
		public int item_no { get; set; }
		public int quantity { get; set; }
		public double price { get; set; }

		public double get_total_price()
		{
			return quantity * price;
		}
	}

	class Program
	{
		static void Main()
		{
			Console.Write("Enter the number of customers: ");
			int n = int.Parse(Console.ReadLine());

			Customer[] customers = new Customer[n];
			double grand_total = 0;

			for (int i = 0; i < n; i++)
			{
				customers[i] = new Customer();

				Console.WriteLine("\nEnter details for Customer " + (i + 1) + ":");

				Console.Write("Customer No: ");
				customers[i].cust_no = int.Parse(Console.ReadLine());

				Console.Write("Name: ");
				customers[i].name = Console.ReadLine();

				Console.Write("Address: ");
				customers[i].address = Console.ReadLine();

				Console.Write("Item No: ");
				customers[i].item_no = int.Parse(Console.ReadLine());

				Console.Write("Quantity: ");
				customers[i].quantity = int.Parse(Console.ReadLine());

				Console.Write("Price per item: ");
				customers[i].price = double.Parse(Console.ReadLine());

				grand_total += customers[i].get_total_price();
			}

			Console.WriteLine("\n===== Customer Details and Total Price =====");
			Console.WriteLine("CustNo\tName\tAddress\tItemNo\tQuantity\tPrice\tTotalPrice");

			foreach (var c in customers)
			{
				Console.WriteLine(c.cust_no + "\t" + c.name + "\t" + c.address + "\t" + c.item_no + "\t" + c.quantity + "\t" + c.price + "\t" + c.get_total_price());
			}

			Console.WriteLine("\nGrand Total of All Items: " + grand_total);
			Console.ReadLine(); // Hold console screen
		}
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
          text: "Write an ASP.Net program to create a user control that receives the user name and password from the user and validates them. If the user name is 'DYP' and the password is 'Pimpri', then the user is authorized, otherwise not.",
          marks: 15,
          sol: `//Slip16A.aspx
          
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Slip16A.Slip16A" %>
<%@ Register Src="~/LoginControl.ascx" TagPrefix="uc" TagName="LoginControl" %>
<html>
<head id="Head1" runat="server">
    <title>User Login</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h2>User Login</h2>
            <uc:LoginControl runat="server" ID="LoginControl1" />
        </div>
    </form>
</body>
</html>


//LoginControl.ascx.cs


using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Slip16A
{
    public partial class LoginControl : System.Web.UI.UserControl
    {
        protected void btnLogin_Click(object sender, EventArgs e)
        {
            string username = txtUsername.Text.Trim();
            string password = txtPassword.Text.Trim();

            // Validate user credentials
            if (username == "DYP" && password == "Pimpri")
            {
                lblMessage.ForeColor = System.Drawing.Color.Green;
                lblMessage.Text = "Login Successful! You are authorized.";
            }
            else
            {
                lblMessage.ForeColor = System.Drawing.Color.Red;
                lblMessage.Text = "Invalid Username or Password. Access Denied!";
            }
        }
    }
}

//LoginControl.ascx

<%@ Control Language="C#" AutoEventWireup="true" CodeBehind="LoginControl.ascx.cs" Inherits="Slip16A.LoginControl" %>
<table>
    <tr>
        <td>Username:</td>
        <td><asp:TextBox ID="txtUsername" runat="server"></asp:TextBox></td>
    </tr>
    <tr>
        <td>Password:</td>
        <td><asp:TextBox ID="txtPassword" runat="server" TextMode="Password"></asp:TextBox></td>
    </tr>
    <tr>
        <td colspan="2">
            <asp:Button ID="btnLogin" runat="server" Text="Login" OnClick="btnLogin_Click" />
        </td>
    </tr>
    <tr>
        <td colspan="2">
            <asp:Label ID="lblMessage" runat="server" ForeColor="Red"></asp:Label>
        </td>
    </tr>
</table>
`,
        },
        {
          questionId: 2,
          text: "Define a class Supplier with fields – sid, name, address, pincode. Write a C#.Net program to accept the details of ‘n’ suppliers and display them.",
          marks: 25,
          sol: `using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Slip16B
{
    class Supplier
    {
        public int sid { get; set; }
        public string name { get; set; }
        public string address { get; set; }
        public int pincode { get; set; }
        public void Accept()
        {
            Console.Write("Enter supplier id : ");
            sid = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter name : ");
            name = Console.ReadLine();
            Console.Write("Enter address : ");
            address = Console.ReadLine();
            Console.Write("Enter pincode : ");
            pincode = Convert.ToInt32(Console.ReadLine());
        }
        public void Display()
        {
            Console.WriteLine("Supplier ID: " + sid);
            Console.WriteLine("Supplier Name: " + name);
            Console.WriteLine("Supplier Address: " + address);
            Console.WriteLine("Supplier Pincode: " + pincode);
        }
    }
    class Slip16B
    {
        static void Main(string[] args)
        {
            Console.Write("Enter the number of suppliers: ");
            int n = Convert.ToInt32(Console.ReadLine());
            Supplier[] suppliers = new Supplier[n];
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("\nEnter details for Supplier {0}:", i + 1);
                suppliers[i] = new Supplier();
                suppliers[i].Accept();
            }
            Console.WriteLine("\nSupplier Details:");
            Console.WriteLine("------------------------------");

            foreach (Supplier supplier in suppliers)
            {
                supplier.Display();
            }

            Console.ReadLine();
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
          text: "Write a C#.Net application to display the vowels from a given string.",
          marks: 15,
          sol: `using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
         static void Main()
         {
            // Get input string from the user
            Console.Write("Enter a string: ");
            string input = Console.ReadLine();

            // Call the method to extract vowels
            string vowels = GetVowels(input);

            // Display the extracted vowels
            Console.WriteLine("Vowels in the given string: " + vowels);
            Console.ReadLine();
         }

        static string GetVowels(string str)
        {
            string vowels = "";
            string vowelChars = "AEIOUaeiou"; // Define vowels (both uppercase and lowercase)

            foreach (char ch in str)
            {
                if (vowelChars.Contains(ch)) // Check if character is a vowel
                {
                    vowels += ch;
                }
            }

            return vowels;
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a VB.NET program to accept the details of a product (PID, PName, expiry_date, price). Store it in the database and display it on a DataGridView.",
          marks: 25,
          sol: `Imports System
Imports System.Data.SqlClient
Public Class Slip17B
    Dim connectionString As String = "Data Source=desktop-5qitmns\sqlexpress;Initial Catalog=MyDatabase;Integrated Security=True"

    Private Sub Buttob_Load_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Buttob_Load.Click
        Try
            Using con As New SqlConnection(connectionString)
                con.Open()
                Dim query As String = "SELECT * FROM Products"
                Dim adapter As New SqlDataAdapter(query, con)
                Dim dt As New DataTable()
                adapter.Fill(dt)
                DataGridView1.DataSource = dt
            End Using
        Catch ex As Exception
            MessageBox.Show("Error: " & ex.Message)
        End Try
    End Sub

    Private Sub Button_Save_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button_Save.Click
        Try
            Using con As New SqlConnection(connectionString)
                con.Open()
                Dim query As String = "INSERT INTO Products (Pid, Pname, Expiry_Date, Price) VALUES (@Pid, @Pname, @ExpiryDate, @Price)"
                Using cmd As New SqlCommand(query, con)
                    cmd.Parameters.AddWithValue("@Pid", txtPid.Text)
                    cmd.Parameters.AddWithValue("@Pname", txtPname.Text)
                    cmd.Parameters.AddWithValue("@ExpiryDate", DateTime.Parse(txtExpiryDate.Text))
                    cmd.Parameters.AddWithValue("@Price", Decimal.Parse(txtPrice.Text))
                    cmd.ExecuteNonQuery()
                End Using
                MessageBox.Show("Product Saved Successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information)
            End Using
        Catch ex As Exception
            MessageBox.Show("Error: " & ex.Message)
        End Try
    End Sub
End Class
`,
        },
      ],
    },
    {
      slipId: 18,
      questions: [
        {
          questionId: 1,
          text: "Write a VB.NET program to accept a number from the user through an input box and display its multiplication table in a list box.",
          marks: 15,
          sol: `Public Class Slip18A
    Private Sub btnGenerate_Click_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnGenerate_Click.Click
        ' Take input from user using InputBox
        Dim num As Integer
        Dim input As String = InputBox("Enter a number to generate its multiplication table:", "Multiplication Table")

        ' Check if input is valid
        If Integer.TryParse(input, num) Then
            lstTable.Items.Clear() ' Clear old data

            ' Generate multiplication table
            For i As Integer = 1 To 10
                lstTable.Items.Add(num & " x " & i & " = " & (num * i))
            Next
        Else
            MessageBox.Show("Please enter a valid number!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End If
    End Sub
End Class`,
        },
        {
          questionId: 2,
          text: "Write an ASP.Net program containing the following controls: ListBox, Button, Image, Label. The ListBox is used to list items available in a store. When the user clicks on an item in the ListBox, its image is displayed in the Image control. When the user clicks the Button, the cost of the selected item is displayed in the Label control.",
          marks: 25,
          sol: `//Slip18B.java
          
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip18B.aspx.cs" Inherits="WebApplication1_CSharp_.Slip18B" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
   <title>Store Item Viewer</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
            <h2>Store Items</h2>
            
            <!-- ListBox for Items -->
            <asp:ListBox ID="lstItems" runat="server" AutoPostBack="True" OnSelectedIndexChanged="lstItems_SelectedIndexChanged"></asp:ListBox>
            <br /><br />

            <!-- Image Control -->
            <asp:Image ID="imgItem" runat="server" Width="200px" Height="200px" />
            <br /><br />

            <!-- Button to Show Price -->
            <asp:Button ID="btnShowPrice" runat="server" Text="Show Price" OnClick="btnShowPrice_Click" />
            <br /><br />

            <!-- Label to Display Price -->
            <asp:Label ID="lblPrice" runat="server" Font-Bold="True" ForeColor="Red"></asp:Label>
        </div>
    </form>
</body>
</html>



//Slip18B.aspx.cs


using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1_CSharp_
{
    public partial class Slip18B : System.Web.UI.Page
    {
        Dictionary<string, Tuple<string, string>> itemData = new Dictionary<string, Tuple<string, string>>()
        {
            { "Laptop", new Tuple<string, string>("laptop.jpg", "$1200") },
            { "Phone", new Tuple<string, string>("phone.jpg", "$800") },
            { "Headphones", new Tuple<string, string>("headphones.jpg", "$150") },
            { "Watch", new Tuple<string, string>("watch.jpg", "$250") }
        };

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                // Populate ListBox
                lstItems.DataSource = itemData.Keys;
                lstItems.DataBind();
            }
        }

        protected void lstItems_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selectedItem = lstItems.SelectedItem.Text;
            if (itemData.ContainsKey(selectedItem))
            {
                imgItem.ImageUrl = "Images/" + itemData[selectedItem].Item1; // Set Image
                lblPrice.Text = ""; // Clear price label
            }
        }

        // Button Click - Show Price
        protected void btnShowPrice_Click(object sender, EventArgs e)
        {
            string selectedItem = lstItems.SelectedItem.Text;
            if (itemData.ContainsKey(selectedItem))
            {
                lblPrice.Text = "Price: " + itemData[selectedItem].Item2;
            }
        }
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
          text: "Write a VB.NET program to check whether the entered string is a palindrome or not.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Create a VB.NET application that allows users to rate the book 'ASP.NET with C#' by Wrox publication. Provide three choices: i) Good ii) Satisfactory iii) Bad. After the user votes, present the result in percentage using labels next to the choices.",
          marks: 25,
        },
      ],
    },
    {
      slipId: 20,
      questions: [
        {
          questionId: 1,
          text: "Write a VB.NET program to generate a Sample TreeView control.",
          marks: 15,
          sol: `Public Class Slip20A

    Private Sub Slip20A_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Dim rootNode As TreeNode = New TreeNode("Company")
        TreeView1.Nodes.Add(rootNode)

        ' Add Departments
        Dim dept1 As TreeNode = New TreeNode("HR Department")
        Dim dept2 As TreeNode = New TreeNode("IT Department")
        Dim dept3 As TreeNode = New TreeNode("Finance Department")

        rootNode.Nodes.Add(dept1)
        rootNode.Nodes.Add(dept2)
        rootNode.Nodes.Add(dept3)

        ' Add Employees Under IT Department
        dept2.Nodes.Add(New TreeNode("John Doe"))
        dept2.Nodes.Add(New TreeNode("Alice Smith"))
        dept2.Nodes.Add(New TreeNode("Bob Johnson"))

        ' Expand All Nodes
        TreeView1.ExpandAll()
    End Sub

    Private Sub TreeView1_AfterSelect(ByVal sender As System.Object, ByVal e As System.Windows.Forms.TreeViewEventArgs) Handles TreeView1.AfterSelect
        lbl.Text = "Selected Node: " & e.Node.Text
    End Sub
End Class`,
        },
        {
          questionId: 2,
          text: "Write a web application in ASP.Net that generates the 'IndexOutOfRange' exception when a button is clicked. Instead of displaying the exception, redirect the user to a custom error page. All of this should be done with tracing for the page being enabled.",
          marks: 25,
          sol: `//Slip20B.aspx

<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip20B.aspx.cs" Inherits="WebApplication1_CSharp_.Slip20B" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<title>IndexOutOfRangeException Example</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
            <h2>Click the button to generate an IndexOutOfRangeException</h2>
            <asp:Button ID="btnGenerateError" runat="server" Text="Generate Error" OnClick="btnGenerateError_Click" />
     </div>
    </form>
</body>
</html>


Slip20B_ErrorPage.aspx


<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip20B_ErrorPage.aspx.cs" Inherits="WebApplication1_CSharp_.Slip20_ErrorPage" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
     <title>Error Page</title>
</head>
<body>
    <h2>Oops! An Error Occurred.</h2>
    <p>Something went wrong. Please try again later.</p>
    <a href="Slip20B.aspx">Go Back</a>
</body>
</html>


//Slip20B.aspx.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1_CSharp_
{
    public partial class Slip20B : System.Web.UI.Page
    {
        protected void btnGenerateError_Click(object sender, EventArgs e)
        {
            try
            {
                // Generating IndexOutOfRangeException
                int[] numbers = { 1, 2, 3 };
                int invalidValue = numbers[5]; // Out of range index (Error)
            }
            catch (IndexOutOfRangeException)
            {
                // Redirecting to Custom Error Page
                Response.Redirect("ErrorPage.aspx");
            }
        }
    }
}

Web.config

<?xml version="1.0"?>

<!--
  For more information on how to configure your ASP.NET application, please visit
  http://go.microsoft.com/fwlink/?LinkId=169433
  -->

<configuration>
    <system.web>
        <compilation debug="true" targetFramework="4.0" />
        <customErrors mode="On" defaultRedirect="Slip20B_ErrorPage.aspx" />  <!--ye line add karni hai-->       
    </system.web>

</configuration>

`,
        },
      ],
    },
    {
      slipId: 21,
      questions: [
        {
          questionId: 1,
          text: "Write a VB.NET program to accept sentences in a text box and count the number of words. Display the count in a message box.",
          marks: 15,
          sol: `Imports System

Public Class Slip21A

    Private Sub btnCountWords_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCountWords.Click
        Dim inputText As String = txtSentence.Text.Trim()

        ' Check if the textbox is empty
        If inputText = "" Then
            MessageBox.Show("Please enter a sentence.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            Exit Sub
        End If

        ' Split the text into words using space as delimiter
        Dim words() As String = inputText.Split(New Char() {" "c}, StringSplitOptions.RemoveEmptyEntries)

        ' Count words and show the result
        Dim wordCount As Integer = words.Length
        MessageBox.Show("Total number of words: " & wordCount.ToString(), "Word Count", MessageBoxButtons.OK, MessageBoxIcon.Information)
    End Sub
End Class`,
        },
        {
          questionId: 2,
          text: "Write an ASP.Net application for the following:\n1. Create a table EMP (eno, ename, edesignation, salary, joindate)\n2. Insert a record.\n3. Update a record.",
          marks: 25,
          sol: `//Slip21B.aspx
          
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip21B.aspx.cs" Inherits="WebApplication1_CSharp_.Slip21B" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html>
<head>
    <title>Employee Management</title>
</head>
<body>
    <form id="form1" runat="server">
        <h2>Employee Management</h2>
        
        <label>Employee No:</label>
        <asp:TextBox ID="txtEno" runat="server"></asp:TextBox><br />

        <label>Employee Name:</label>
        <asp:TextBox ID="txtEname" runat="server"></asp:TextBox><br />

        <label>Designation:</label>
        <asp:TextBox ID="txtDesignation" runat="server"></asp:TextBox><br />

        <label>Salary:</label>
        <asp:TextBox ID="txtSalary" runat="server"></asp:TextBox><br />

        <label>Join Date:</label>
        <asp:TextBox ID="txtJoinDate" runat="server"></asp:TextBox><br />

        <asp:Button ID="btnInsert" runat="server" Text="Insert" OnClick="btnInsert_Click" />
        <asp:Button ID="btnUpdate" runat="server" Text="Update" OnClick="btnUpdate_Click" />
        
        <br /><asp:Label ID="lblMessage" runat="server" ForeColor="Red"></asp:Label>
    </form>
</body>
</html>



//Slip21B.aspx.cs


using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace WebApplication1_CSharp_
{
    public partial class Slip21B : System.Web.UI.Page
    {
        string connectionString = @"Server=desktop-5qitmns\SQLEXPRESS;Database=MyDatabase;Integrated Security=True";

        protected void Page_Load(object sender, EventArgs e)
        {
        }

        // ?? Insert Record
        protected void btnInsert_Click(object sender, EventArgs e)
        {
            using (SqlConnection con = new SqlConnection(connectionString))
            {
                string query = "INSERT INTO EMP (eno, ename, edesignation, salary, joindate) VALUES (@eno, @ename, @edesignation, @salary, @joindate)";
                SqlCommand cmd = new SqlCommand(query, con);

                cmd.Parameters.AddWithValue("@eno", int.Parse(txtEno.Text));
                cmd.Parameters.AddWithValue("@ename", txtEname.Text);
                cmd.Parameters.AddWithValue("@edesignation", txtDesignation.Text);
                cmd.Parameters.AddWithValue("@salary", decimal.Parse(txtSalary.Text));
                cmd.Parameters.AddWithValue("@joindate", DateTime.Parse(txtJoinDate.Text));

                con.Open();
                int rowsAffected = cmd.ExecuteNonQuery();
                con.Close();

                lblMessage.Text = rowsAffected > 0 ? "Record Inserted Successfully!" : "Error inserting record.";
            }
        }

        // ?? Update Record
        protected void btnUpdate_Click(object sender, EventArgs e)
        {
            using (SqlConnection con = new SqlConnection(connectionString))
            {
                string query = "UPDATE EMP SET ename=@ename, edesignation=@edesignation, salary=@salary, joindate=@joindate WHERE eno=@eno";
                SqlCommand cmd = new SqlCommand(query, con);

                cmd.Parameters.AddWithValue("@eno", int.Parse(txtEno.Text));
                cmd.Parameters.AddWithValue("@ename", txtEname.Text);
                cmd.Parameters.AddWithValue("@edesignation", txtDesignation.Text);
                cmd.Parameters.AddWithValue("@salary", decimal.Parse(txtSalary.Text));
                cmd.Parameters.AddWithValue("@joindate", DateTime.Parse(txtJoinDate.Text));

                con.Open();
                int rowsAffected = cmd.ExecuteNonQuery();
                con.Close();

                lblMessage.Text = rowsAffected > 0 ? "Record Updated Successfully!" : "Error updating record.";
            }
        }
    }
}
`,
        },
      ],
    },
    {
      slipId: 22,
      questions: [
        {
          questionId: 1,
          text: "Write a program in C# to create a function to swap the values of two integers.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write a VB.NET program to design the following form; it contains three menus: Color (Red, Blue, Green), Window (Maximize, Minimize, Restore), and Exit. On selection of any menu or submenu, the result should affect the form control (for example, if the user selects Red color from the Color menu, the back color of the form should change to Red, and if the user selects Maximize from the Window menu, the form should be maximized).",
          marks: 25,
        },
      ],
    },
    {
      slipId: 23,
      questions: [
        {
          questionId: 1,
          text: "Write a program in C# to create a function to display the n terms of the Fibonacci sequence.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Create an ASP.Net application that accepts name, password, age, email ID, and user ID. All the information entries are compulsory. The password should be reconfirmed. Age should be within 21 to 30. Email ID should be valid. User ID should have at least one capital letter, one digit, and its length should be between 7 and 20 characters.",
          marks: 25,
        },
      ],
    },
    {
      slipId: 24,
      questions: [
        {
          questionId: 1,
          text: "Write a program in C#.Net to create a function to check whether a number is prime or not.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write a VB.NET program to create an Author table (aid, aname, book_name). Insert up to 5 records. Delete the record of the author who has written 'VB.NET book' and display the remaining records on the DataGridView. (Use MS Access to create the database.)",
          marks: 25,
        },
      ],
    },
    {
      slipId: 25,
      questions: [
        {
          questionId: 1,
          text: "Write a program in C#.Net to create a function to calculate the sum of the individual digits of a given number.",
          marks: 15,
          sol: `using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static int SumOfDigits(int number)
        {
            int sum = 0;
            while (number != 0)
            {
                sum += number % 10; // Extract last digit and add to sum
                number /= 10; // Remove last digit
            }
            return sum;
        }

        static void Main()
        {
            Console.Write("Enter a number: ");
            int num = int.Parse(Console.ReadLine());
            int result = SumOfDigits(num);
            Console.WriteLine("Sum of digits:" + result);
            Console.ReadLine();
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Create a Web Application in ASP.Net to display all the EmpName and DeptId of the employees from the database using SQL source control and bind it to a GridView. Database fields are (DeptId, DeptName, EmpName, Salary).",
          marks: 25,
          sol: `<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip25B.aspx.cs" Inherits="WebApplication1_CSharp_.Slip25B" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="EmpName" HeaderText="Employee Name" SortExpression="EmpName" />
                <asp:BoundField DataField="DeptId" HeaderText="Department ID" SortExpression="DeptId" />
            </Columns>
        </asp:GridView>

        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="Data Source=DESKTOP-5QITMNS\SQLEXPRESS;Initial Catalog=MyDatabase;Integrated Security=True;"
            SelectCommand="SELECT EmpName, DeptId FROM employee">
        </asp:SqlDataSource>
    </form>
</body>
</html>
`,
        },
      ],
    },
    {
      slipId: 26,
      questions: [
        {
          questionId: 1,
          text: "Write a program in C#.Net to create a recursive function to find the factorial of a given number.",
          marks: 15,
          sol: `using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static long Factorial(int n)
        {
            if (n == 0 || n == 1) // Base case
                return 1;
            else
                return n * Factorial(n - 1); // Recursive case
        }

        public static void Main()
        {
            // Get user input
            Console.Write("Enter a number: ");
            int number = int.Parse(Console.ReadLine());

            // Calculate and display factorial
            long result = Factorial(number);
            Console.WriteLine("Factorial of  " + number + " is " + result);
            Console.ReadLine();
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write an ASP.Net program to create a Login Module which adds Username and Password to the database. The Username in the database should be a primary key.",
          marks: 25,
          sol: `//Slip26B.aspx
          
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Slip26B.aspx.cs" Inherits="WebApplication1_CSharp_.Slip26B" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<title>User Registration</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h2>User Registration</h2>
            <asp:Label ID="lblUsername" runat="server" Text="Username: "></asp:Label>
            <asp:TextBox ID="txtUsername" runat="server"></asp:TextBox>
            <br /><br />

            <asp:Label ID="lblPassword" runat="server" Text="Password: "></asp:Label>
            <asp:TextBox ID="txtPassword" runat="server" TextMode="Password"></asp:TextBox>
            <br /><br />

            <asp:Button ID="btnRegister" runat="server" Text="Register" OnClick="btnRegister_Click" />
            <br /><br />

            <asp:Label ID="lblMessage" runat="server" ForeColor="Red"></asp:Label>
    </div>
    </form>
</body>
</html>


//Slip26B.aspx.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;


namespace WebApplication1_CSharp_
{
    public partial class Slip26B : System.Web.UI.Page
    {
        protected void btnRegister_Click(object sender, EventArgs e)
        {
            string connectionString = "Data Source=DESKTOP-5QITMNS\\SQLEXPRESS;Initial Catalog=MyDatabase;Integrated Security=True;";
            string username = txtUsername.Text.Trim();
            string password = txtPassword.Text.Trim(); // Ideally, hash the password before storing

            if (string.IsNullOrEmpty(username) || string.IsNullOrEmpty(password))
            {
                lblMessage.Text = "Username and Password cannot be empty!";
                return;
            }

            using (SqlConnection conn = new SqlConnection(connectionString))
            {
                try
                {
                    conn.Open();

                    // Insert into Users table
                    string query = "INSERT INTO Users (Username, Password) VALUES (@Username, @Password)";
                    using (SqlCommand cmd = new SqlCommand(query, conn))
                    {
                        cmd.Parameters.AddWithValue("@Username", username);
                        cmd.Parameters.AddWithValue("@Password", password); // In production, use hashed passwords

                        cmd.ExecuteNonQuery();
                        lblMessage.ForeColor = System.Drawing.Color.Green;
                        lblMessage.Text = "User registered successfully!";
                    }
                }
                catch (SqlException ex)
                {
                    if (ex.Number == 2627) // Primary Key violation (duplicate username)
                    {
                        lblMessage.Text = "Username already exists. Please choose another.";
                    }
                    else
                    {
                        lblMessage.Text = "Database error: " + ex.Message;
                    }
                }
            }
        }
    }
}
`,
        },
      ],
    },
    {
      slipId: 27,
      questions: [
        {
          questionId: 1,
          text: "Write a program in C#.Net to find the length of a string.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Create a web application in ASP.Net which may have a textbox. The user must type some data into it, with a limit of 255 characters. After exceeding the limit, the last word should not be typed, and the color of the textbox should change to red.",
          marks: 25,
        },
      ],
    },
    {
      slipId: 28,
      questions: [
        {
          questionId: 1,
          text: "Write a program in C#.Net to read n numbers in an array and display them in reverse order.",
          marks: 15,
          sol: `using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main()
        {
            // Ask the user for the number of elements
            Console.Write("Enter the number of elements: ");
            int n = int.Parse(Console.ReadLine());

            // Declare an array
            int[] numbers = new int[n];

            // Read numbers from the user
            Console.WriteLine("Enter the array elements:");
            for (int i = 0; i < n; i++)
            {
                Console.Write("Element" + (i + 1) + ":");
                numbers[i] = int.Parse(Console.ReadLine());
            }

            // Display the array in reverse order
            Console.WriteLine("\nNumbers in reverse order:");
            for (int i = n - 1; i >= 0; i--)
            {
                Console.Write(numbers[i] + " ");
            }

            Console.ReadLine(); // For better formatting
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a VB.NET program to create a table Patient (PID, PName, Contact No, Disease). Insert five records into the table and display an appropriate message in a message box.",
          marks: 25,
          sol: `Imports System
Imports System.Data.SqlClient

Public Class Slip28B


    Private Sub btnInsert_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnInsert.Click
        Dim connectionString As String = "Data Source=DESKTOP-5QITMNS\SQLEXPRESS;Initial Catalog=MyDatabase;Integrated Security=True;"

        ' Create SQL connection
        Using conn As New SqlConnection(connectionString)
            Try
                conn.Open()

                ' Create Patient table if not exists
                Dim createTableQuery As String = "IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='Patient' AND xtype='U') " &
                                                 "CREATE TABLE Patient (PID INT PRIMARY KEY, PName VARCHAR(50), ContactNo VARCHAR(15), Disease VARCHAR(50))"
                Using cmd As New SqlCommand(createTableQuery, conn)
                    cmd.ExecuteNonQuery()
                End Using

                ' Insert records into the Patient table
                Dim insertQuery As String = "INSERT INTO Patient (PID, PName, ContactNo, Disease) VALUES " &
                                            "(1, 'John Doe', '1234567890', 'Flu'), " &
                                            "(2, 'Alice Smith', '9876543210', 'Cold'), " &
                                            "(3, 'Robert Brown', '5647382910', 'Fever'), " &
                                            "(4, 'Emma Wilson', '1029384756', 'Cough'), " &
                                            "(5, 'David Johnson', '6758493021', 'Headache')"

                Using cmd As New SqlCommand(insertQuery, conn)
                    cmd.ExecuteNonQuery()
                End Using

                ' Show success message
                MessageBox.Show("Records inserted successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information)

            Catch ex As Exception
                ' Show error message if something goes wrong
                MessageBox.Show("Error: " & ex.Message, "Database Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
            End Try
        End Using
    End Sub
End Class`,
        },
      ],
    },
    {
      slipId: 29,
      questions: [
        {
          questionId: 1,
          text: "Write a program in C#.Net to separate the individual characters from a string.",
          marks: 15,
          sol: `using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main()
        {
            // Get input from user
            Console.Write("Enter a string: ");
            string input = Console.ReadLine();

            // Display individual characters
            Console.WriteLine("\nIndividual characters in the string:");
            foreach (char c in input)
            {
                Console.WriteLine(c);
            }
            Console.ReadLine();
        }
    }
}
`,
        },
        {
          questionId: 2,
          text: "Write a VB.NET program to accept the details of a customer (CName, Contact No, Email_id). Store it in the database with proper validation and display an appropriate message using a message box.",
          marks: 25,
          sol: `Imports System.Data.SqlClient
Imports System.Text.RegularExpressions
Public Class Slip29B

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim connectionString As String = "Data Source=DESKTOP-5QITMNS\SQLEXPRESS;Initial Catalog=MyDatabase;Integrated Security=True;"

        ' Get user input
        Dim name As String = txtName.Text.Trim()
        Dim contact As String = txtContact.Text.Trim()
        Dim email As String = txtEmail.Text.Trim()

        ' Input validation
        If String.IsNullOrEmpty(name) OrElse String.IsNullOrEmpty(contact) OrElse String.IsNullOrEmpty(email) Then
            MessageBox.Show("All fields are required!", "Validation Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            Return
        End If

        ' Validate contact number (only digits, 10 characters)
        If Not Regex.IsMatch(contact, "^\d{10}$") Then
            MessageBox.Show("Invalid Contact Number! Enter 10 digits.", "Validation Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            Return
        End If

        ' Validate email format
        If Not Regex.IsMatch(email, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$") Then
            MessageBox.Show("Invalid Email Format!", "Validation Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            Return
        End If

        ' Insert into database
        Using conn As New SqlConnection(connectionString)
            Try
                conn.Open()
                Dim query As String = "INSERT INTO Customers (CName, ContactNo, Email_id) VALUES (@CName, @ContactNo, @Email)"

                Using cmd As New SqlCommand(query, conn)
                    cmd.Parameters.AddWithValue("@CName", name)
                    cmd.Parameters.AddWithValue("@ContactNo", contact)
                    cmd.Parameters.AddWithValue("@Email", email)

                    cmd.ExecuteNonQuery()
                    MessageBox.Show("Customer details saved successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information)
                End Using
            Catch ex As SqlException
                If ex.Number = 2627 Then ' Unique constraint violation for Email
                    MessageBox.Show("Email already exists! Use a different email.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
                Else
                    MessageBox.Show("Database Error: " & ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
                End If
            End Try
        End Using
    End Sub
End Class`,
        },
      ],
    },
    {
      slipId: 30,
      questions: [
        {
          questionId: 1,
          text: "Write a VB.NET program to design the following screen: accept the details from the user. Clicking on the Submit button should calculate and display the Net Salary into a textbox. Display a message box informing the Name and Net Salary of the employee.",
          marks: 15,
        },
        {
          questionId: 2,
          text: "Write a VB.NET program to accept the details of a Supplier (SupId, SupName, Phone No, Address), store it in the database, and display it.",
          marks: 25,
        },
      ],
    },
  ],
  language: "csharp",
};

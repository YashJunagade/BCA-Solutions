<!-- Write PHP program to select list of subjects from list box and displays the selected subject information on next page. 
(Use sticky Multivalued parameter). -->

<!DOCTYPE html>
<html>
  <head>
    <title>Select Subjects</title>
  </head>
  <body>
    <h2>Select Your Subjects:</h2>
    <form method="post" action="display.php">
      <input type="checkbox" name="arr[]" value="Computer Networking"
      <?php if(isset($_POST['arr']) && in_array('Computer Networking', $_POST['arr'])) echo "checked"; ?>
      /> Computer Networking<br />
      <input type="checkbox" name="arr[]" value="CPP"
      <?php if(isset($_POST['arr']) && in_array('CPP', $_POST['arr'])) echo "checked"; ?>>
      CPP <br />
      <input type="checkbox" name="arr[]" value="Operating System"
      <?php if(isset($_POST['arr']) && in_array('Operating System', $_POST['arr'])) echo "checked"; ?>>
      Operating System<br />
      <input type="checkbox" name="arr[]" value="Adv PHP"
      <?php if(isset($_POST['arr']) && in_array('Adv PHP', $_POST['arr'])) echo "checked"; ?>>
      Adv PHP <br /><br />
      <input type="submit" name="select" value="Select" />
    </form>
  </body>
</html>

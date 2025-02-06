<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student</title>
</head>
<body>
    <form action="" method="POST">
        <center>
            <br><br>
            <h1>Welcome <?php 
            session_start();
            echo $_SESSION['Name'];
            ?></h1>
            <br><br>
            <hr>
            <br>
            <br><br>
            <a href="Scorecard.php"><input type="button" name="" id="" value="Scorecard"></a>
            <br><br>
            <a href="Login.php"><input type="button" value="Logout"></a>
        </center>
    </form>
</body>
</html>
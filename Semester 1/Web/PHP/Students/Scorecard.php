<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="" method="POST">
    <center>
        <br><br>
        <h1><u>Score Card</u></h1>
        <br><br><hr><br>
            <table border="5 px">
                <tr>
                    <th style="padding : 10px;">Internal</th>
                    <th style="padding : 10px;">External</th>
                    <th style="padding : 10px;">Total</th>
                    <th style="padding : 10px;"><u>Grade</u></th>
                </tr>
                <tr>
                    <?php
                    session_start();
                    echo "<td>".$_SESSION['internal']."</td>";
                    echo "<td>".$_SESSION['external']."</td>";
                    echo "<td>".$_SESSION['internal']+$_SESSION['external']."</td>";
                    echo "<td>".$_SESSION['grade']."</td>"
                    ?>
                </tr>
            </table>
            <br><br>
            <a href="Student.php"><input type="button" value="Back"></a>
            </center>
            </form>
</body>
</html>
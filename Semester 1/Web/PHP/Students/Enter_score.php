<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Score Entering</title>
</head>
<body>
    <form action="" method="POST">
        <center>
            <br>
            <br>
            <h1>SCORE  ENTRY</h1>
            <br><br><hr>
            <br>
            <br>
            <table>
                <tr>
                    <th>Name :</th>
                    <td style="padding : 10px;">
                        <input type="text" name="name">
                    </td>
                </tr>
                <tr>
                    <th>Internal Mark :</th>
                    <td style="padding : 10px;"><input type="text" name="internal" id=""></td>
                </tr>
                <tr>
                    <th>External Mark :</th>
                    <td style="padding : 10px;">
                        <input type="text" name="external">
                    </td>
                </tr>
            </table>
            <br>
            <br>
            <input type="submit" name="submit" value="Enter Marks">
            &ensp;&ensp;
            <a href="Admin.php"><input type="button" value="Back"></a>
        </center>
    </form>
    <?php
        if(isset($_POST['submit'])){
            $name=$_POST['name'];
            $internal=$_POST['internal'];
            $external=$_POST['external'];

            $internal=(int)$internal;
            $external=(int)$external;

            $total=$internal+$external;
            if($total>=90){
                $grade="A+";
            }
            else if($total>=80){
                $grade="A";
            }
            else if($total>=70){
                $grade="B+";
            }
            else if($total>=60){
                $grade="B";
            }
            else if($total>=50){
                $grade="C+";
            }
            else if($total>=40){
                $grade="C";
            }
            else{
                $grade="Fail";
            }

            $conn=mysqli_connect('localhost','root','','scorecard');
            if(!$conn){
                echo"<br>Connection failed";
            }
            else{
                $q="UPDATE details SET internal='$internal' , external='$external' , grade='$grade' WHERE name='$name' ";
                $query=mysqli_query($conn,$q);
                if(!$query){
                    echo"Can't update score";
                }
                else{
                    echo "<br><center>Successfully Score Updated</center>";
                }
            }
        }
    ?>
    
</body>

</html>
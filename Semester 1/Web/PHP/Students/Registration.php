<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration</title>
</head>
<body>
    <form action="" method="POST" >
        <center>
        <br><h1>Register Here</h1>
        <br><br><hr>
        <br>
        <table style="padding : 10px;">
            <tr>
                <th>Name :</th>
                <td style="padding : 10px;">
                    <input type="text" name="name" id="name" required>
                </td>
            </tr>
            <tr>
                <th>Email ID :</th>
                <td style="padding : 10px;">
                    <input type="email" name="email" id="email" required>
                </td>
            </tr>
            <tr>
                <th>Password :</th>
                <td style="padding : 10px;">
                    <input type="password" name="password" id="password" required>
                </td>
            </tr>
        </table>
        <br>
        <input type="submit" name="submit" id="sub" value="Register">
        <br><br>
        <h3>Already Registered <a href="Login.php">Click Here To LOGIN</a></h3>
        </center>
    </form>
<?php
    if(isset($_POST['submit'])){
        $name=$_POST['name'];
        $password=$_POST['password'];
        $email=$_POST['email'];

        $conn=mysqli_connect('localhost','root','','scorecard');
        if(!$conn){
            echo("Connection Failed");
        }
        else{
            $q="INSERT INTO details (name,email,password) VALUES ('$name','$email','$password')";
            $query=mysqli_query($conn,$q);
            if(!$query){
                echo"<br>Registration failed";
            }
            else{
                echo"<br>Registration successful";
            }
        }
        mysqli_close($conn);   
    }
?>

</body>
</html>
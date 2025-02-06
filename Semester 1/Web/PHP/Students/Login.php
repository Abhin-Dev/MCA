<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
</head>
<body>
    <form action="" method="POST" >
        <center>
            <br>
            <h1>LOGIN</h1>
            <br><br>
            <hr>
            <table>
                <tr>
                    <th>Email :</th>
                    <td style="padding : 10px;"> 
                        <input type="email" name="email" id="email" required>
                    </td>
                </tr>
                <tr>
                    <th>Password :</th>
                    <td style="padding : 10px;">
                        <input type="password" name="password" id="pass" required>
                    </td>
                </tr>
            </table>
            <br><br>
            <input type="submit" value="Login" name="submit">&ensp;&ensp;
            <a href="Registration.php"><input type="button" name="" id="" value="Click For Registration"></a>
        </center>
    </form>
</body>
<?php
session_start();
if(isset($_POST['submit'])){
    $email=$_POST['email'];
    $password=$_POST['password'];

    $conn=mysqli_connect('localhost','root','','scorecard');

    if(!$conn){
        echo"Connection failed ";
    }
    else{
        $q="SELECT * FROM details WHERE email='$email' and password='$password' ";
        $query=mysqli_query($conn,$q);
        if(mysqli_num_rows($query)>0){
            $row=mysqli_fetch_assoc($query);
            $_SESSION['Name']=$row['name'];
            $_SESSION['internal']=$row['internal'];
            $_SESSION['external']=$row['external'];
            $_SESSION['grade']=$row['grade'];
            if($email=="admin@gmail.com" AND $password=="admin"){
                header("Location: Admin.php");
            }
            else{
                header("Location: Student.php");
            }
        }
        else{
            echo"<br>You Are Not Registered Yet";
        }

    }
}
?>
</html>
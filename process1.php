<!DOCTYPE html>
<html lang="en">

<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="">

    <title>Metrics Project</title>

    <!-- Bootstrap Core CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">

    <!-- Custom CSS -->
    <link href="css/half-slider.css" rel="stylesheet">

    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
        <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->

</head>

<body>

    <!-- Navigation -->
    <nav class="navbar navbar-inverse navbar-fixed-top" role="navigation">
        <div class="container">
            <!-- Brand and toggle get grouped for better mobile display -->
            <div class="navbar-header">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <a class="navbar-brand" href="index.html">Start</a>
            </div>
            <!-- Collect the nav links, forms, and other content for toggling -->
            <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                <ul class="nav navbar-nav">
                    <li>
                        <a href="about.html">Explanation</a>
                    </li>
                </ul>
            </div>
            <!-- /.navbar-collapse -->
        </div>
        <!-- /.container -->
    </nav>

    <!-- Half Page Image Background Carousel Header -->
    <header id="myCarousel" class="carousel slide">
        <!-- Indicators -->
        <ol class="carousel-indicators">
            <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
            <li data-target="#myCarousel" data-slide-to="1"></li>
        </ol>

        <!-- Wrapper for Slides -->
        <div class="carousel-inner">
            <div class="item active">
                <!-- Set the first background image using inline CSS below. -->
                <div class="fill" style="background-image:url('slide1.png');"></div>
                <div class="carousel-caption">
                    <!--<h2>Prof. Chandrasekar T.</h2>-->
                </div>
            </div>
            <div class="item">
                <!-- Set the third background image using inline CSS below.http://placehold.it/1900x1080&text=Tool for calculating Maintainability Index and Weighted method-->
                <div class="fill" style="background-image:url('slide2.png');"></div>
                <div class="carousel-caption">
                    <h2>Metrics Tool</h2>
                </div>
            </div>
        </div>

        <!-- Controls -->
        <a class="left carousel-control" href="#myCarousel" data-slide="prev">
            <span class="icon-prev"></span>
        </a>
        <a class="right carousel-control" href="#myCarousel" data-slide="next">
            <span class="icon-next"></span>
        </a>

    </header>

    <!-- Page Content -->
    <div class="container">

        <div class="row">
            <div class="col-lg-12">
                <h4>CALCULATED VALUES</h4>
            </div>
        </div>
<?php
$target_path = "b.cpp";
//$target_path = $target_path.basename( $_FILES['MI']['name']); 
move_uploaded_file($_FILES['MI']['tmp_name'], $target_path) or die ("There was an error uploading the file, please try again!<br>");
//if(move_uploaded_file($_FILES['MI']['tmp_name'], $target_path)) {
//   echo "The file ".  basename( $_FILES['MI']['name']). 
//    " has been uploaded<br>";
//} else{
//    echo "There was an error uploading the file, please try again!<br>";
//}
$handle = fopen($target_path, 'r') or die('Cannot open file:  '.$my_file);
//$handle=file_get_contents($target_path);
$loc=0;
$forc=0;
$wc=0;
$ifc=0;
$elsec=0;
$swc=0;
while ($userinfo = fgets($handle)) {
$loc++;
$forc+=substr_count($userinfo,"for");
$wc+=substr_count($userinfo,"while");
$ifc+=substr_count($userinfo,"if");
$elsec+=substr_count($userinfo,"else if");
$swc+=substr_count($userinfo,"switch");
}
//$hv=$_POST["halstead"];
$name="halstead.cpp";
exec("halstead.exe") or die ("couldnt run cpp");
//$handle1=fopen("hal.txt", 'r') or die('Cannot open file:  '.$my_file);
$hv1=file_get_contents("hal.txt");
$cc=$forc+$wc+$ifc-$elsec+$swc;
$mindex=171-(5.2*log($hv1))-(0.23*$cc*log($loc));
echo "LOC : ";
echo $loc;
echo "<br>";
echo "Halstead Volume : ";
echo  $hv1;
echo "<br>";?>
<a href="about.html"> <?php echo "<b><h5>MAINTAINABILITY INDEX :"; ?></a> 
<?php
echo $mindex;
//echo "<br>";
if($mindex<10)
    echo "<font color='red'> Low Maintainability </font>";
else if ($mindex>60)
    echo "<font color='green'> Better Maintainability</font>";
else 
    echo "<font color='yellow'> Moderately Maintainable</font>";
echo "<br>";
echo "<br>";?>
<a href="about.html"><?php echo "WEIGHTED METHOD PER CLASS : "; ?> </a>
<?php
echo $cc;
echo "</b>";
echo "</b></h5>";

?>

        <!-- Footer -->
        <footer>
            <div class="row">
                <div class="col-lg-12">
                    <p>Copyright &copy; Balayeswanth B 12MSE0212</p>
                </div>
            </div>
            <!-- /.row -->
        </footer>

    </div>
    <!-- /.container -->

    <!-- jQuery -->
    <script src="js/jquery.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="js/bootstrap.min.js"></script>

    <!-- Script to Activate the Carousel -->
    <script>
    $('.carousel').carousel({
        interval: 5000 //changes the speed
    })
    </script>

</body>

</html>

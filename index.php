<?php
/**
 *this script is for create part of code for arduino library for remote contorl for remote controll (tv-remote, led strip remote, magio remote, magio go remote)
 * Created by PhpStorm.
 * User: slavomir.sedlak
 * Date: 2019-07-16
 * Time: 18:21
 */
run();
/**
 *structure of file remote-signal.txt
 *first line is name of class
 *then line start,name_of_method
 *thne lines with signals for arduino
 *after this line is stop line
 *after stop line is start another method line
 *and so on....
 */
function run(){
$remoteSignalFile = fopen('remote-signal.txt', "r") or die('Unable to open file remote-signal.txt make sure if file exist!!!');
$class = fgets($remoteSignalFile);
file_put_contents('result-arduino-code-header.txt', "class $class{".PHP_EOL, FILE_APPEND | LOCK_EX)
file_put_contents('result-arduino-code-header.txt', "public:".PHP_EOL, FILE_APPEND | LOCK_EX)
while(!feof($remoteSignalFile)){
    $fileline = fgets($remoteSignalFile);
    $fileExplode  = explode(' ' , $fileline);
    $firstNumber = true;
    $startFunction = true;
    $startClass = true;
    $function = '';
    foreach ($fileExplode as $number){
        if(is_numeric($number)){
            if($firstNumber){
                file_put_contents('result-arduino-code.txt', "delayMicroseconds($number);".PHP_EOL,FILE_APPEND | LOCK_EX);
                echo "delayMicroseconds($number);<br>";
                $firstNumber = false;
                continue;
            }else{
                file_put_contents('result-arduino-code.txt', "_pulseIR($number);".PHP_EOL,FILE_APPEND | LOCK_EX);
                echo "_pulseIR($number);<br>";
                $firstNumber = true;
                continue;
            }
        }
        if(strpos($number, 'start') !== false){
            $number = explode(',',$number);
            $startFunction = "void $number[1]::$number[2](){";
            file_put_contents('result-arduino-code.txt', $startFunction.PHP_EOL, FILE_APPEND | LOCK_EX);
	    file_put_contents('result-arduino-code-header.txt', "void $number[2]".PHP_EOL, FILE_APPEND | LOCK_EX)
            echo $startFunction . "<br>";
            continue;
        }
        if(strpos($number, 'stop') !== false){
            file_put_contents('result-arduino-code.txt', '}'.PHP_EOL, FILE_APPEND | LOCK_EX);
            echo  "}<br>";
            continue;
        }

    }
}
file_put_contents('result-arduino-code-header.txt', "private:".PHP_EOL, FILE_APPEND | LOCK_EX)
file_put_contents('result-arduino-code-header.txt', "}".PHP_EOL, FILE_APPEND | LOCK_EX)
fclose($remoteSignalFile);

};

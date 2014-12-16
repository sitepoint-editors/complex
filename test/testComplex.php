<?php

//use Complex;

$c=new Complex(-3,-4);
echo "Mod of $c is: ".$c->mod()."\n";

$d=new Complex(4,3);
echo "Mod of $d is: ".$d->mod()."\n";

$e=new Complex(-4,-3);
echo ((string)$e."\n");
echo "=============================\n";

$a=new Complex(1,1);
$b=new Complex(1,2);

$res=new Complex();
echo ($res)."\n";
$res=$a->add($b)->sub($c)->add($d);
echo ($res)."\n";
echo "=============================\n";

$a=new Complex(1,2);
$b=new Complex(3,4);
$res=$a->mul($b)->add($c);

echo $res."\n";


echo "Conguate Complex of above: ".$res->conjugate()."\n";
echo "=============================\n";


//echo ((string)$res);





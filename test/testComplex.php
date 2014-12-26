<?php



$c=new tr\Complex(-3,-4);
echo "Mod of $c is: ".$c->mod()."\n";

$d=new tr\Complex(4,3);
echo "Mod of $d is: ".$d->mod()."\n";

$e=new tr\Complex(-4,-3);
echo ((string)$e."\n");
echo "=============================\n";

$a=new tr\Complex(1,1);
$b=new tr\Complex(1,2);

$res=new tr\Complex();
echo ($res)."\n";
$res=$a->add($b)->sub($c)->add($d);
echo ($res)."\n";
echo "=============================\n";

$a=new tr\Complex(1,2);
$b=new tr\Complex(3,4);
$res=$a->mul($b)->add($c);

echo $res."\n";

echo "Conguate Complex of $b is: ".($b->conjugate())."\n";
echo "=============================\n";

echo ($b->add($b->conjugate()))."\n";
echo "=============================\n";

$a=new tr\Complex(1,2);
$c=new tr\Complex(1,2);
$res=$a->div($c);

echo $res."\n";
echo "After division a becomes: $a"."\n";
echo "=============================\n";

$a=new tr\Complex(1,2);
$c=new tr\Complex();

try
{
    $res=$a->div($c);
}
catch(Exception $e)
{
    echo "Caught exception.\n";
}
echo "=============================\n";

$pi=3.1415926;

$a=new tr\Complex(1,0);
echo "$a phi is: ".$a->phi()*180/$pi."\n";

$a=new tr\Complex(0,1);
echo "$a phi is: ".$a->phi()*180/$pi."\n";

$a=new tr\Complex(-1,0);
echo "$a phi is: ".$a->phi()*180/$pi."\n";

$a=new tr\Complex(0,-1);
echo "$a phi is: ".$a->phi()*180/$pi."\n";

$a=new tr\Complex(0,0);
try
{
    echo "$a phi is: ".$a->phi()*180/$pi."\n";
}
catch (Exception $e)
{
    echo "Caught exception: $e\n";
}

$a=new tr\Complex(1,1);
echo "$a phi is: ".$a->phi()*180/$pi."\n";

$a=new tr\Complex(-1,1);
echo "$a phi is: ".$a->phi()*180/$pi."\n";

$a=new tr\Complex(-1,-1);
echo "$a phi is: ".$a->phi()*180/$pi."\n";

$a=new tr\Complex(1,-1);
echo "$a phi is: ".$a->phi()*180/$pi."\n";


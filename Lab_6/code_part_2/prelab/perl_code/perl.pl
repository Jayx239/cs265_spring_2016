
open(DATA,'input.txt');
my $counter;
$counter = 0;
$input_lines;

while( <DATA> ){
	$input_lines[$counter++] = $_;
	print "input: " . $_ . "\n";
print $_ . " =~ /o/ : " . $_=~ /o/ . "\n";
print $_ . "$_=~ /aso/ : " . $_=~ /[aso]/ . "\n";

print $_ . "=~/a/: " . $_=~/a/ . "\n";

print($_ . "=~/^\w/: ") . $_=~/^\w/ . "\n";

$segment_1;
$segment_2;
$segment_3;

($segment_1,$segment_2,$segment_3) = ($_=~ /(G)a(ll)agh(e)r/); 
print("(seg1,seg2,seg3)=" . $_ . " =~ /(G)a(ll)agh(e)r/):\n" . "\nseg1: " . $segment_1 . "\nseg2: " . $segment_2 . "\nseg3: " .  $segment_3);

$_ =~ /(\w\w\w|\w\w|\w)\1/;
print("\n-------------------------------------------------------------\n");
}

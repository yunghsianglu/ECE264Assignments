#!/usr/local/bin/perl

use strict;
use Cwd;
my $MAX_SCORE;
my $PPT;
my $NUM_TC;
my $NUM_Prob;
my $NUM_TC_per_Prob;

my @list;
my $dir;
my $totalScore;
my @score;
my @scoreEachProb;
my $fail_info;

my $line;
my $isMemTestSuccess;
my $isMaTestSuccess;
my $i;
my $j;
my $base = 0;

# Set maximum possible scores
$MAX_SCORE = $ARGV[0];
# Finds number of testcase to be run and calculates number of
# points per testcase

@list = `ls expected/expected*`;
$NUM_TC = scalar(@list);
$NUM_Prob = $#ARGV - 2;
$NUM_TC_per_Prob = $NUM_TC/$NUM_Prob;

if($ARGV[1] == 1){
    $PPT =  (0.95 * $MAX_SCORE) / $NUM_TC;
}
elsif($ARGV[1] == 2){
    $PPT =  $MAX_SCORE / $NUM_TC;
}

print "GRADING RESULTS\n";

#correct directory path
#$dir = quotemeta($_);

#Run executable and tests in testing directory	

#initalize score
for($i = 0; $i < $NUM_TC; $i++) {
    $score[$i] = 0;
}
for($i = 0; $i < $NUM_Prob; $i++) {
    $scoreEachProb[$i] = 0;
}

$totalScore = 0;

if($ARGV[1] == 1){
    for($i = $NUM_TC; $i <= $NUM_TC+1; $i++) {
	if((system("make test$i") == 512)) {
#	    print "make test$i passes\n";
	    $score[$i] = 0.025 * $MAX_SCORE;	
	} else {
	    $fail_info = `make test$i 2>&1`;
	    print "test$i fails\n";
	    print "$fail_info\n\n";
	}
    }
}

for($i = 0; $i < $NUM_TC; $i++) {
    if(system("make test$i") == 0) {
#	print "make test$i passes\n";
	$score[$i] = $PPT;
	$isMemTestSuccess = 0;
	$isMaTestSuccess = 0;
	if(-e "memoutput$i"){
	    open(MEM, "<memoutput$i");
	    while ($line = <MEM>) {
			if ($line =~ m/All heap blocks were freed -- no leaks are possible/){
#				print "memory management test passes\n";
				$isMemTestSuccess = 1;
			}
			elsif ($line =~ m/ERROR SUMMARY: 0 errors from 0 contexts/){
#				print "memory access test passes\n";
				$isMaTestSuccess = 1;
			}
	    }
		close(MEM);
		
	    if ($isMemTestSuccess == 0) {
			print "memory management test $i fails\n";
			$score[$i] = $score[$i] - ($PPT/2); 
	    }
		
		if ($isMaTestSuccess == 0) {
			print "memory access test $i fails.  Check memoutput$i to see whtat the errors are. \n";
			#$score[$i] = $score[$i] - ($PPT/2); 
	    }


	}
	
    } else {
	$fail_info = `make test$i 2>&1`;
	print "test$i fails\n";
	print "$fail_info\n";
    }
}

for ($i = 0; $i < $NUM_Prob+1; $i++) {
    for ($j = 0; $j < $ARGV[2+$i]; $j++) {
	$scoreEachProb[$i] += $score[$base+$j];
    }
	$base += $ARGV[2+$i];
}
	
for ($i = 0; $i < $NUM_TC; $i++) {
    $totalScore = $totalScore + $score[$i];
}	

#print student's score on screen
for ($i = 0; $i < $NUM_Prob+1; $i++) {
    print "\nScore for Problem $i: $scoreEachProb[$i]";
}
print "\n\nTOTAL SCORE = $totalScore/$MAX_SCORE\n";
print "\nYour Program will be manually graded for styling and implementation correctness\n";
print "This manual grading can have affect on your final grade\n";  
print "DONE\n\n";


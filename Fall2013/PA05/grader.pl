#!/usr/local/bin/perl

use strict;
use Cwd;
my $MAX_SCORE;
my $PPT;
my $NUM_TC;
my $NUM_Prob;

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
my @temp;

# PA06
my @heap;
my @unnecessaryByte;
# Set standard heap usage values in PA06 for test0 ~ test9
#@heap =(1575,1775,1931,2103,2283,2446,2629,2284,2039,1891);
@heap = (2519,2799,3035,3287,3547,3790,6861,3548,3207,2971);

# Set maximum possible scores
$MAX_SCORE = $ARGV[0];
# Finds number of testcase to be run and calculates number of
# points per testcase

@list = `ls inputs/input*`;
$NUM_TC = scalar(@list);
$NUM_Prob = $#ARGV - 2;

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

print "Running $NUM_TC tests\n";
for($i = 0; $i < $NUM_TC; $i++) {
    if(system("make test$i") == 0) {
	print "test$i passes\n";
	$score[$i] = $PPT;
	$isMemTestSuccess = 0;
	$isMaTestSuccess = 0;
	if(-e "outputs/memoutput$i"){
	    open(MEM, "<outputs/memoutput$i");
	    while ($line = <MEM>) {
		if ($line =~ m/All heap blocks were freed -- no leaks are possible/){
#		    print "memory management test passes\n";
		    $isMemTestSuccess = 1;
		}
		elsif ($line =~ m/ERROR SUMMARY: 0 errors from 0 contexts/){
#		    print "memory access test passes\n";
		    $isMaTestSuccess = 1;
		}

		# Heap usage check for PA06
		if ($line =~ m/total heap usage: /){ # Search for heap usage description and save the number of bytes to $temp[1].		  
		    $_=$line;
		    /frees,/;
		    @temp = split /\s/, "$'";
		    $temp[1]=~tr/,//d;

		    if($temp[1] <= $heap[$i]){ #If number of bytes for heap usage is less than or equal to the expected amount, memory usage test passes  		
		    } else {
			$unnecessaryByte[$i]=$temp[1]-$heap[$i];
		    }
		}
	    }
	    close(MEM);
	    
	    if ($isMemTestSuccess == 0) {
		print "memory management test $i fails\n";
		$score[$i] = $score[$i] - ($PPT/2); 
	    }
	    
	    if ($isMaTestSuccess == 0) {
		print "memory access test $i fails.  Check memoutput$i to see what the errors are\n";
		#$score[$i] = $score[$i] - ($PPT/2); 
	    }

	    # Take score for allocating unnecessary bytes
	    if ($unnecessaryByte[$i]>0){
		print "memory usage for test$i exceeds the expected amount.\n";

		# deduct 1% for every unnecessary byte
		$score[$i] = $score[$i] - ($MAX_SCORE*$unnecessaryByte[$i]/100);
		if($score[$i]<0){
		    $score[$i]=0;
		}
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
=pod
    for ($i = 0; $i < $NUM_Prob+1; $i++) {
    printf("\nScore for Problem %d: %.2f/%.2f", $i, $scoreEachProb[$i], $ARGV[0] / $NUM_TC * $ARGV[2 + $i]);
}
=cut
printf("\n\nTOTAL SCORE = %.2f/%.2f\n", $totalScore, $MAX_SCORE);
print "\nYour Program will be manually graded for styling and implementation correctness\n";
print "This manual grading can have affect on your final grade\n";
print "DONE\n\n";


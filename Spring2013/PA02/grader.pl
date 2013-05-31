#!/usr/local/bin/perl

use strict;
use Cwd;
#my $SUBMISSION_DIR = "submission_Lu";
#my $STUDENT_FILES = "*";
my $TEST_FILES = "outputs/ solutions/ testcases/";
my $TEST_DIR = "temp";
my $GRADE_DIR = cwd();
my $GRADE_FILE = "grade_report";
my $MAX_SCORE;
my $PPT;
my $NUM_TC;

my @list;
my $dir;
my $totalScore;
my @score;
my $fail_info;

my $line;
my $isMemTestSuccess;
my $i;
my $j;

# Set maximum possible scores
$MAX_SCORE = $ARGV[0];
# Finds number of testcase to be run and calculates number of
# points per testcase

@list = `ls input*`;
$NUM_TC = scalar(@list);
#print "$NUM_TC";

if($ARGV[1] == 1){
    $PPT =  (0.95 * $MAX_SCORE) / $NUM_TC;
}
elsif($ARGV[1] == 2){
    $PPT =  $MAX_SCORE / $NUM_TC;
}


#open(DETAIL, ">$GRADE_FILE");

print "GRADING RESULTS\n";

#correct directory path
#$dir = quotemeta($_);

#Run executable and tests in testing directory	


#initalize score
for($i = 0; $i < $NUM_TC; $i++) {
    $score[$i] = 0;
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
	if(-e "memoutput$i"){
	    open(MEM, "<memoutput$i");
	    while ($line = <MEM>) {
		if ($line =~ m/All heap blocks were freed -- no leaks are possible/) 				{
#		    print "memory test passes\n";
		    $isMemTestSuccess = 1;
		}
	    }
	    if ($isMemTestSuccess == 0) {
		print "memory test $i fails\n";
		$score[$i] = $score[$i] - ($PPT/2); 
	    }
	    close(MEM);
	}
	
    } else {
	$fail_info = `make test$i 2>&1`;
	print "test$i fails\n";
	print "$fail_info\n";
    }
}

	
for ($i = 0; $i < $NUM_TC; $i++) {
    $totalScore = $totalScore + $score[$i];
}	

#print student's score on screen
print "\nSCORE = $totalScore/$MAX_SCORE\n";
print "DONE\n\n";



#close(DETAIL);
#close(FILE);


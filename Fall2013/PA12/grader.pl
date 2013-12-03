#!/usr/local/bin/perl

use strict;
use Cwd;
my $MAX_SCORE;
my $PPT;
my $NUM_TC;
#my $NUM_Prob;
#my $GTYPE;

my @list;
my $dir;
my $totalScore;
my @score;
my $SPT; # score per thread
my @tcscore;
my $prefscore;
my $fail_info;

my $line;
my $isMemTestSuccess;
my $isMaTestSuccess;
my $i;
my $j;
my $base = 0;
my $time_margin = 1.5;


#@list = `ls expected/expected*`;
$NUM_TC = $ARGV[2];
#$NUM_Prob = $#ARGV - 1;

#correct directory path
#$dir = quotemeta($_);

#Run executable and tests in testing directory	
print "GRADING RESULTS\n";
print "\nChecking Correctness.\n";

my @host = `hostname`;
my @currline;
my @numthreads = (3,3,3,4,5,6,7,8,9,4, 1,2,3,4,5,6,7,8,9,10, 4,4,4,4,5,6,7);
#my @PPT_ARRAY = (.2, .2, .2, .2, .2, .2, .2, .2, .5, .3, .3, .3,.4,.3,.3);


if($ARGV[1] == 1){
    $i = $NUM_TC;
	if(system("make corrtest$i") == 0) {
	    print "\nCorrectness Test $i passes\n";
	    $isMemTestSuccess = 0;
	    $isMaTestSuccess = 0;
	    if(-e "memoutput$i"){
		open(MEM, "<memoutput$i");
		while ($line = <MEM>) {
		    if ($line =~ m/All heap blocks were freed -- no leaks are possible/){
			#print "memory management test passes\n";
			$isMemTestSuccess = 1;
		    }
		    elsif ($line =~ m/ERROR SUMMARY: 0 errors from 0 contexts/){
			#print "memory access test passes\n";
			$isMaTestSuccess = 1;
		    }
		}
		close(MEM);
		
		if ($isMemTestSuccess == 0) {
		    print "memory management test $i fails\n";
		}
		
		if ($isMaTestSuccess == 0) {
		    print "memory access test $i fails.  Check memoutput$i to see whtat the errors are\n";
		}
		
		
	    }
	    
	    if($host[0] =~ m/quatro/){
		if(system("make perftest$i") == 0) {
		    $prefscore = 0;
		    my $missedcount = 0;
		    if(-e "outputs/timeinfo$i"){
			my @stutimes;
			my @exptimes;
			open(TIMEINFO, "<outputs/timeinfo$i");
			
			while ($line = <TIMEINFO>) {
			    if ($line =~ m/run/){
				@currline = split(" ", $line);
				push(@stutimes, $currline[4]);
			    }
			}
			close(TIMEINFO);					
			
			open(EXPECTED, "<expected/exptime$i");
			
			while ($line = <EXPECTED>) {
			    if ($line =~ m/run/){
				@currline = split(" ", $line);
				push(@exptimes, $currline[4]);
			    }
			}
			close(EXPECTED);
			
			for($j = 0; $j < scalar(@stutimes); $j++){
			    if($stutimes[$j] > $time_margin * $exptimes[$j]){
				$missedcount++;
			    }
			}
		    }
		    
		
		    
		    if($missedcount > 3){
			print "missedcount is $missedcount\n";
			print "One or more threads runs longer than the allowed maximum\n";

		    }
		    else{
			print "\nPerformance test $i passes\n";
		    }
		    
		    
		    
		} else {
		    $fail_info = `make perftest$i 2>&1`;
		    print "perftest$i fails\n";
		    print "$fail_info\n";
		}
	    }
	    
	    else{
		print "Performance test needs to be run on quatro01 or quatro02\n";
	    }
	    
	    
	} else {
	    $fail_info = `make corrtest$i 2>&1`;
	    print "corrtest$i fails\n";
	    print "$fail_info\n";
	}
 
}



if($ARGV[1] == 2) {	
    print "Running $NUM_TC tests\n";
    for($i = 0; $i < $NUM_TC; $i++) {
	if(system("make corrtest$i") == 0) {
	    print "\nCorrectness Test $i passes\n";
	    $isMemTestSuccess = 0;
	    $isMaTestSuccess = 0;
	    if(-e "memoutput$i"){
		open(MEM, "<memoutput$i");
		while ($line = <MEM>) {
		    if ($line =~ m/All heap blocks were freed -- no leaks are possible/){
			$isMemTestSuccess = 1;
		    }
		    elsif ($line =~ m/ERROR SUMMARY: 0 errors from 0 contexts/){
			$isMaTestSuccess = 1;
		    }
		}
		close(MEM);
		
		if ($isMemTestSuccess == 0) {
		    print "memory management test $i fails\n";
		}
		
		if ($isMaTestSuccess == 0) {
		    print "memory access test $i fails.  Check memoutput$i to see whtat the errors are\n";
		}
		
		
	    }
	    
	    if($host[0] =~ m/quatro/){
		if(system("make perftest$i") == 0) {
		    $prefscore = 0;
		    my $missedcount = 0;
		    if(-e "outputs/timeinfo$i"){
			my @stutimes;
			my @exptimes;
			open(TIMEINFO, "<outputs/timeinfo$i");
			
			while ($line = <TIMEINFO>) {
			    if ($line =~ m/run/){
				@currline = split(" ", $line);
				push(@stutimes, $currline[4]);
			    }
			}
			close(TIMEINFO);					
			
			open(EXPECTED, "<expected/exptime$i");
			
			while ($line = <EXPECTED>) {
			    if ($line =~ m/run/){
				@currline = split(" ", $line);
				push(@exptimes, $currline[4]);
			    }
			}
			close(EXPECTED);
			
			for($j = 0; $j < scalar(@stutimes); $j++){
			    if($stutimes[$j] > $time_margin * $exptimes[$j]){
				$missedcount++;
			    }
			}
		    }
		    
				    
		    if($missedcount > 3){

			print "missedcount is $missedcount\n";
			print "One or more threads runs longer than the allowed maximum\n";

		    }
		    else{
			print "Performance test $i passes\n";
		    }
		    
		    
		    
		} else {
		    $fail_info = `make perftest$i 2>&1`;
		    print "perftest$i fails\n";
		    print "$fail_info\n";
		}
	    }
	    
	    else{
		print "Performance test needs to be run on quatro01 or quatro02\n";
	    }
	    
	    
	} else {
	    $fail_info = `make corrtest$i 2>&1`;
	    print "corrtest$i fails\n";
	    print "$fail_info\n";
	}
    }
    print "\nYour Program will be manually graded for styling and implementation correctness\n";
    print "This manual grading can have affect on your final grade\n";
    print "DONE\n\n";
}










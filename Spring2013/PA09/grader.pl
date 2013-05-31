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

# PA09
my @heap;
my @unnecessaryByte;
# Set standard heap usage values in PA09 for test0 ~ test100
@heap = (1136, 1160, 2296, 2320, 2320, 2368, 2368, 2368, 2440, 2392, 2416, 2464, 2512, 2488, 2488, 2536, 2488, 2536, 2560, 2632, 2680, 2656, 2632, 2656, 2680, 2608, 2752, 2680, 2728, 2776, 2800, 2848, 2728, 2776, 2848, 2824, 2824, 2944, 2920, 2920, 2992, 2920, 2848, 2992, 2968, 3064, 3064, 3040, 2968, 3112, 3088, 2992, 3136, 3088, 3160, 3160, 3208, 3136, 3208, 3184, 3208, 3280, 3328, 3304, 3352, 3352, 3376, 3328, 3328, 3376, 3448, 3496, 3448, 3520, 3496, 3520, 3544, 3568, 3472, 3568, 3760, 3616, 3640, 3544, 3640, 3736, 3592, 3736, 3640, 3832, 3952, 3760, 3616, 3736, 3712, 3736, 3880, 3832, 3856, 3832, 3880);

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
    for($i = $NUM_TC-1; $i <= $NUM_TC+1; $i++) {
		if((system("make test$i") == 512)) {
			print "test$i passes\n";
			if($i == 10){
				$totalScore += $PPT;
}
			else	{
				$totalScore += 0.025 * $MAX_SCORE;	
		}} 
		else {
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
#					print "memory management test passes\n";
					$isMemTestSuccess = 1;
				}
				elsif ($line =~ m/ERROR SUMMARY: 0 errors from 0 contexts/){
#					print "memory access test passes\n";
					$isMaTestSuccess = 1;
				}

				# Heap usage check for PA09
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


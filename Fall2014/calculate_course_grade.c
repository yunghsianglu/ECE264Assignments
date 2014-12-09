// Calculate course grade for ECE 264 in Fall 2014
//
// HOW TO USE:  Change the scores below to reflect your scores.  For
//        exam #4, PA12, or anything you are unsure of, enter your guess.
//        Then compile and run.  It will display a report with a course grade.
//
// Note:  This code is for convenience only and is not intended to convey
//        new information.  The course policies (posted and announced)
//        always take precedent in case of any differences.
//
// Last updated 12/8/2014 @ 6:20 PM
//
// Author:  Alexander J. Quinn (aq@purdue.edu)
// (c) Copyright 2014 Purdue University - All Rights Reserved

#include <stdio.h>
#include <stdlib.h>

const int SECTION_QUINN = 1;
const int SECTION_LU    = 2;

//////////////////////////////////////////////////////////////////////
// INPUTS

// ENTER YOUR SECTION NUMBER
const int section_num  =  1;   // section number, 1=Quinn, 2=Lu

// ENTER YOUR SCORES -- For exam #4, PA12, or anything you are unsure
//                      about, you will need to enter a guess.
const float pa01       =  3.0; // PA01
const float pa02       =  3.0; // PA02
const float pa03       =  3.0; // PA03
const float pa04       =  3.0; // PA04
const float pa05       =  5.0; // PA05
const float pa06       =  5.0; // PA06
const float pa07       =  5.0; // PA07
const float pa08       =  5.0; // PA08
const float pa09       =  5.0; // PA09
const float pa10       =  5.0; // PA10
const float pa11       =  5.0; // PA11
const float pa12       =  5.0; // PA12

const float ex1        = 20.0; // exam #1, total

const float ex2        = 20.0; // exam #2, total
const float ex2_q1     =  2.0; // exam #2, Q1, struct types
const float ex2_q2_2   =  3.0; // exam #2, Q2.2, integer parition corrections
const float ex2_q3     =  6.0; // exam #2, Q3, sort vector array
const float ex2_q4     =  6.0; // exam #2, Q4, binary files

const float ex3        = 20.0; // exam #3, total
const float ex3_q1     =  6.0; // exam #3, Q1, recursion (Lu)
const float ex3_q2     =  6.0; // exam #3, Q2, recursion (Lu)
const float ex3_q3     =  6.0; // exam #3, Q3, BST (Lu) or file I/O (Quinn)

const float ex4        = 20.0; // exam #4, total
const int   ex4_lo1    =  1;   // exam #4, pass learning objective #1, 1=yes, 0=no
const int   ex4_lo2    =  1;   // exam #4, pass learning objective #2, 1=yes, 0=no
const int   ex4_lo3    =  1;   // exam #4, pass learning objective #3, 1=yes, 0=no
const int   ex4_lo4    =  1;   // exam #4, pass learning objective #4, 1=yes, 0=no
// For ex4_lo1 (and the others), enter 1 if you are confident you would pass the
// learning objective on exam #4.  Enter 0 to see the result if you did not pass it.

const float bonus_bb   =  5.0; // bonus for Blackboard participation, total
const float bonus_ex1  =  2.0; // bonus for practice prior to exam #1
const float bonus_asgs = 10.0; // bonus for extensions to PA10, total
//////////////////////////////////////////////////////////////////////



int cmp_float(const void* l, const void* r);

int main(int argc, char *argv[]) {

	/////////////////////////////////////////////////////////////////
	// CALCULATE TOTALS

    // Sort assignment scores so that we can drop the bottom two.
    float pa_all[12] = {pa01, pa02, pa03, pa04, pa05, pa06,
                        pa07, pa08, pa09, pa10, pa11, pa12};
    qsort(pa_all, 12, sizeof(float), cmp_float);

	// Calculate assignments total
    float asg_total = 0.0;
    int i;
    for(i = 2; i < 12; i++) { // drop 2 assignments (due to i=2)
        asg_total += pa_all[i];
    }
    asg_total += bonus_asgs;  // bonus assignments (extensions to PA10)
    
    // Sort exam scores so that we can drop the bottom one and scale the others.
    float ex_all[4]  = {ex1, ex2, ex3, ex4};
    qsort(ex_all, 4, sizeof(float), cmp_float);

	// Calculate exams total
    float exam_total = 1.5 * ex_all[3]  // highest exam score
                     + 1.0 * ex_all[2]  // second highest exam score
                     + 0.5 * ex_all[1]  // third highest exam score
                     + bonus_bb         // bonus for blackboard participation
                     + bonus_ex1;       // bonus for exam #1 practice


	/////////////////////////////////////////////////////////////////
	// CHECK LEARNING OBJECTIVES

    // learning objective #1: recursion
    int passed_lo_1 = pa05      >= 2.5
                   || pa06      >= 2.5
                   || pa09      >= 2.5
                   || pa10      >= 2.5
                   || ex2_q2_2  >= 1.5
                   ||(ex3_q1    >= 3.0 && section_num == SECTION_LU)
                   ||(ex3_q2    >= 3.0 && section_num == SECTION_LU)
                   || bonus_asgs > 0.0
                   || ex4_lo1;

    // learning objective #2: structures
    int passed_lo_2 = pa10            >= 2.5
                   || ex2_q1 + ex2_q3 >= 4.0
                   ||(ex3_q3          >= 3.0 && section_num == SECTION_LU)
                   || bonus_asgs       > 0.0
                   || ex4_lo2;

    // learning objective #3: dynamic structures
    int passed_lo_3 = pa08      >= 2.5
                   || pa09      >= 2.5
                   || pa10      >= 2.5
                   ||(ex3_q3    >= 3.0 && section_num == SECTION_LU)
                   || bonus_asgs > 0.0
                   || ex4_lo3;

    // learning objective #4: files
    int passed_lo_4 = pa07      >= 2.5
                   || pa10      >= 2.5
                   ||(ex2_q4    >= 3.0 && section_num == SECTION_LU)
                   ||(ex3_q3    >= 3.0 && section_num == SECTION_QUINN)
                   || bonus_asgs > 0.0
                   || ex4_lo4;


    /////////////////////////////////////////////////////////////////
    // CALCULATE COURSE GRADE


    int eligible_to_pass = passed_lo_1 // 1. recursion
                        && passed_lo_2 // 2. structures
                        && passed_lo_3 // 3. dynamic structures
                        && passed_lo_4 // 4. file input/output
                        && asg_total >= 32;

    int eligible_for_a   = eligible_to_pass
                        && asg_total >= 37
                        && pa11 >= 0.5
                        && pa12 >= 0.5
                        && ex4 >= 5.0;

    char* grade = NULL;
    if(     exam_total >= 48 && eligible_for_a)
        grade = "A";
    else if(exam_total >= 46 && eligible_for_a)
        grade = "A-";
    else if(exam_total >= 44 && eligible_to_pass)
        grade = "B+";
    else if(exam_total >= 42 && eligible_to_pass)
        grade = "B";
    else if(exam_total >= 40 && eligible_to_pass)
        grade = "B-";
    else if(exam_total >= 38 && eligible_to_pass)
        grade = "C+";
    else if(exam_total >= 36 && eligible_to_pass)
        grade = "C";
    else if(exam_total >= 34 && eligible_to_pass)
        grade = "C-";
    else if(exam_total >= 32 && eligible_to_pass)
        grade = "D+";
    else if(exam_total >= 30 && eligible_to_pass)
        grade = "D";
    else if(exam_total >= 28 && eligible_to_pass)
        grade = "D-";
    else
        grade = "F";


    /////////////////////////////////////////////////////////////////
    // PRINT RESULT

    const char* pass_or_not[] = {"not passed", "PASSED"};
    printf("Learning objective #1 (recursion):          %s\n", pass_or_not[passed_lo_1]);
    printf("Learning objective #2 (structures):         %s\n", pass_or_not[passed_lo_2]);
    printf("Learning objective #3 (dynamic structures): %s\n", pass_or_not[passed_lo_3]);
    printf("Learning objective #4 (file input/output):  %s\n", pass_or_not[passed_lo_4]);
    printf("\n");
    printf("Assignment total:  %.2f\n", asg_total);
    printf("Exam total:        %.2f\n", exam_total);
    printf("\n");
    printf("Grade:  %s\n", grade);

    return 0;
}

int cmp_float(const void* l, const void* r) {
    return *((float*)l) - *((float*)r);
}

/* vim: set expandtab tabstop=4 shiftwidth=4 fileencoding=utf8: */

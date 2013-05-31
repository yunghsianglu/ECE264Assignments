/* ======== DO NOT MODIFY THIS FILE ======== */
#include "pa13.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

// initial size for the input set array, the array can expand if neccessary
#define INIT_SET_SIZE 50

double timeDiff(struct timeval t1, struct timeval t2)
{
  double time_diff;
  double sec_offset = 0;
  double t1_sec = t1.tv_sec;
  double t2_sec = t2.tv_sec;
  double t1_usec = t1.tv_usec;
  double t2_usec = t2.tv_usec;
  if (t2_usec < t1_usec) {
    time_diff = 1e6 + t2_usec - t1_usec;
    sec_offset = -1;
  } else {
    time_diff = t2_usec - t1_usec;
  }

  time_diff = (t2_sec - t1_sec) + sec_offset + time_diff / 1e6;
  return time_diff; //in second
}

/* This is the main funtion provided to handle the file I/O and program output
 * Please do not modify this function. All neccessary inputs are provided through
 * the interface subsetSum, please implement that funtion. */
int main(int argc, char **argv)
{
  // Check arguments
  if (argc < 4) {
    printf("Usage: %s <input_set> <input_num> <output> <number of threads>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE * fpset = fopen(argv[1], "r");
  FILE * fpnum = fopen(argv[2], "r");
  FILE * fptr = fopen(argv[3], "w");
  // check if file exist and can be read
  if (fpset == NULL) {
    fprintf(stderr, "Error opening file %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  if (fpnum == NULL) {
    fprintf(stderr, "Error opening file %s\n", argv[2]);
    return EXIT_FAILURE;
  }
  if (fptr == NULL) {
    return EXIT_FAILURE;
  } 
  int maxThread = (int) strtol(argv[4], NULL, 10);
  int numThread;

  int * intset, length, targetSumValue, tmp, cnt;
  int bfsize = INIT_SET_SIZE;
  intset = (int*) malloc(sizeof(int) * bfsize);
  cnt = 0, tmp = 0;

  // read set data from formated file input
  while ((tmp = fscanf(fpset, "%d\n", intset+cnt)) != EOF) {
    if (tmp <= 0) {
      fprintf(stderr, "Wrong input format in file %s.\n", argv[1]);
      return EXIT_FAILURE;
    }
    cnt += tmp;
    // resize array if actual number of elements is founded to be
    // larger than initial size
    if (cnt > bfsize) {
      bfsize += bfsize;
      int * nset = (int*) realloc(intset, sizeof(int) * bfsize);
      if (nset == 0) {
	fprintf(stderr, "Error allocating memory.\n");
	return EXIT_FAILURE;
      }
      intset = nset;
    }
  }
  length = cnt;

  // read N from second file
  tmp = fscanf(fpnum, "%d\n", &targetSumValue);
  if (tmp <= 0) {
    fprintf(stderr, "Wrong input format in file %s.\n", argv[2]);
    return EXIT_FAILURE;
  }
  fclose(fpset);
  fclose(fpnum);

  long result = 0;    
  for (numThread = 1; numThread <= maxThread; numThread ++) {
    struct timeval Time1;
    struct timeval Time2;
    gettimeofday(& Time1, NULL);
    result = subsetSum(intset, length, targetSumValue, numThread);
    gettimeofday(& Time2, NULL);

    printf("%d thread(s), run time: %8.4f\n", 
	   numThread, timeDiff(Time1, Time2));
  }
  free (intset);

  // Write result
  fprintf(fptr, "%ld", result);
  fclose (fptr);

  return EXIT_SUCCESS;
}


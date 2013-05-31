/* 
 * Do not modify this file.
 */

#include "pa05.h"

#define LINE_SIZE 1000

void trim(char *s)
{
  int pos = strlen(s) - 1;
  while (iscntrl(s[pos])) {
    s[pos--] = '\0';
  }
}

int main(int argc, char *argv[])
{
  if (argc != 4) {
    printf("usage: %s <command> <inputfile> <outputfile>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *f;
  if ((f = fopen(argv[2], "r")) == NULL) {
    printf("unable to open file %s!\n", argv[2]);
    return EXIT_FAILURE;
  }
  FILE *fptrout;
  if ((fptrout = fopen(argv[3], "w")) == NULL) {
    printf("unable to open file %s!\n", argv[3]);
    fclose(f);
    return EXIT_FAILURE;
  }

  int num_lines = 0;
  char buffer[LINE_SIZE];
  while (fgets(buffer, LINE_SIZE, f) != NULL) {
    num_lines++;
  }
  rewind(f);
    
  char **src = malloc(sizeof(char *) * num_lines);
  char **copy = malloc(sizeof(char *) * num_lines);
  int i;
  for (i = 0; i < num_lines; i++) {
    if (feof(f)) {
      printf("not enough num_lines in file!\n");
      fclose(f);
      fclose(fptrout);
      return EXIT_FAILURE;
    }
    copy[i] = malloc(sizeof(char) * LINE_SIZE);
    fgets(copy[i], LINE_SIZE, f);
    trim(copy[i]);
    src[i] = strdup(copy[i]);
  }
  fclose(f);

  int total_length = 0;
  for (i = 0; i < num_lines; i++) {
    total_length += my_strlen(copy[i]);
  }
  char *buf = malloc(sizeof(char) * total_length + num_lines + 1);
  buf[0] = '\0';
  //Partitioning outputs
  if (strcmp(argv[1], "my_strlen") == 0) {
    for (i = 0; i < num_lines; i++) {
      fprintf(fptrout, "length: %d\n", my_strlen(copy[i]));
    }
  } else if (strcmp(argv[1], "my_countchar") == 0) {
    for (i = 0; i < num_lines; i++) {
      fprintf(fptrout, "count(%c): %d\n", copy[i][0], my_countchar(copy[i], copy[i][0]));
    }
  } else if (strcmp(argv[1], "my_strupper") == 0) {
    for (i = 0; i < num_lines; i++) {
      my_strupper(copy[i]);
      fprintf(fptrout, "uppercase: %s\n", copy[i]);
    }
  } else if (strcmp(argv[1], "my_strlower") == 0) {
    for (i = 0; i < num_lines; i++) {
      my_strlower(copy[i]);
      fprintf(fptrout, "lowercase: %s\n", copy[i]);
    }
  } else if (strcmp(argv[1], "my_strcat") == 0) {
    for (i = 0; i < num_lines; i++) {
      my_strcat(copy[i], " ");
      my_strcat(copy[i], src[i]);
      fprintf(fptrout, "%s\n", copy[i]);
    }
  } else if (strcmp(argv[1], "my_strncat") == 0) {
    for (i = 0; i < num_lines; i++) {
      my_strncat(copy[i], "   ", 2);
      my_strncat(copy[i], "........", 1);
      fprintf(fptrout, "%s\n", copy[i]);
    }
  } else if (strcmp(argv[1], "my_strcpy") == 0) {
    for (i = 0; i < num_lines; i++) {
      my_strcpy(copy[i], "Copying this String.");
      fprintf(fptrout, "%s\n", copy[i]);
    }
  } else if (strcmp(argv[1], "my_strncpy") == 0) {
    for (i = 0; i < num_lines; i++) {
      my_strncpy(copy[i], src[i], 5);
      fprintf(fptrout, "%s\n", copy[i]);
    }
  } else if (strcmp(argv[1], "my_strstr") == 0) {
    for (i = 0; i < num_lines; i++) {
      fprintf(fptrout, "%d\n", my_strstr(copy[i], src[i]) != NULL);
    }
  } else if (strcmp(argv[1], "my_strinsert") == 0) {
    for (i = 0; i < num_lines; i++) {
      my_strinsert(buf, "\n", 0);
      my_strinsert(buf, src[i], 0);
    }
    fprintf(fptrout, "[%s]\n", buf);
  } else if (strcmp(argv[1], "my_strdelete") == 0) {
    for (i = 0; i < num_lines; i++) {
      my_strinsert(buf, "\n", 0);
      my_strinsert(buf, src[i], 0);
      my_strdelete(buf, 0, 10);
    }
    fprintf(fptrout, "[%s]\n", buf);
  }

  for (i = 0; i < num_lines; i++) {
    free(copy[i]);
    free(src[i]);
  }
  free(src);
  free(copy);
  free(buf);
  fclose(fptrout);
  return EXIT_SUCCESS;
}

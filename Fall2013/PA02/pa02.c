/* 
 * Do not modify this file.
 */

#include "pa02.h"
#include <libgen.h>

#define LINE_SIZE 1000

void trim(char * s)
{
    int pos = strlen(s) - 1;
    while (iscntrl(s[pos])) 
	{
	    s[pos--] = '\0';
	}
}

void printUsage(char * exec_path)
{
    const char * exec = basename(exec_path);
    printf("\n"
	   "   Usage: %s <command> <inputfile>\n"
	   "\n"
	   "      <command> should be one of:\n"
	   "\n"
	   "         my_strlen\n"
	   "         my_countchar\n"
	   "         my_strupper\n"
	   "         my_strlower\n"
	   "         my_strcpy\n"
	   "         my_strncpy\n"
	   "         my_strcat\n"
	   "         my_strncat\n"
	   "         my_strstr\n"
	   "         my_strinsert\n"
	   "         my_strdelete\n"
	   "\n",
	   exec);
}

int main(int argc, char *argv[])
{
    if (argc == 2 && (strcmp(argv[0], "-h") == 0 || strcmp(argv[0], "--help") == 0)) 
	{
	    printUsage(argv[0]);
	    return EXIT_SUCCESS;
	}

    if (argc != 3) {
	printUsage(argv[0]);
	return EXIT_FAILURE;
    }

    FILE * f;
    if ((f = fopen(argv[2], "r")) == NULL) {
	printf("Unable to open file '%s', aborting!\n", argv[2]);
	return EXIT_FAILURE;
    }
    FILE * fptrout = stdout;

    int line_count = 0;
    char line_buffer[LINE_SIZE];
    while (fgets(line_buffer, LINE_SIZE, f) != NULL) 
	{
	    line_count++;
	}
    int file_length = ftell(f);
    rewind(f);
    
    char * * src = malloc(sizeof(char *) * line_count);
    char * * copy = malloc(sizeof(char *) * line_count);
    int i;
    for (i = 0; i < line_count; i++) 
	{
	    if (feof(f)) 
		{
		    printf("Not enough lines in file!\n");
		    fclose(f);
		    return EXIT_FAILURE;
		}
	    copy[i] = malloc(sizeof(char) * LINE_SIZE);
	    fgets(copy[i], LINE_SIZE, f);
	    trim(copy[i]);
	    src[i] = strdup(copy[i]);
	}
    fclose(f);

    char * buffer = malloc(sizeof(char) * file_length);
    buffer[0] = '\0';
    //Partitioning outputs
    const char * command = argv[1];

    if (strcmp(command, "my_strlen") == 0) {
	for (i = 0; i < line_count; i++) {
	    fprintf(fptrout, "length: %d\n", my_strlen(copy[i]));
	}
    } else if (strcmp(command, "my_countchar") == 0) {
	for (i = 0; i < line_count; i++) {
	    fprintf(fptrout, "count(%c): %d\n", copy[i][0], my_countchar(copy[i], copy[i][0]));
	}
    } else if (strcmp(command, "my_strupper") == 0) {
	for (i = 0; i < line_count; i++) {
	    my_strupper(copy[i]);
	    fprintf(fptrout, "uppercase: %s\n", copy[i]);
	}
    } else if (strcmp(command, "my_strlower") == 0) {
	for (i = 0; i < line_count; i++) {
	    my_strlower(copy[i]);
	    fprintf(fptrout, "lowercase: %s\n", copy[i]);
	}
    } else if (strcmp(command, "my_strcat") == 0) {
	for (i = 0; i < line_count; i++) {
	    my_strcat(copy[i], " ");
	    my_strcat(copy[i], src[i]);
	    fprintf(fptrout, "%s\n", copy[i]);
	}
    } else if (strcmp(command, "my_strncat") == 0) {
	for (i = 0; i < line_count; i++) {
	    my_strncat(copy[i], "   ", 2);
	    my_strncat(copy[i], "........", 1);
	    fprintf(fptrout, "%s\n", copy[i]);
	}
    } else if (strcmp(command, "my_strcpy") == 0) {
	for (i = 0; i < line_count; i++) {
	    my_strcpy(copy[i], "Copying this String.");
	    fprintf(fptrout, "%s\n", copy[i]);
	}
    } else if (strcmp(command, "my_strncpy") == 0) {
	for (i = 0; i < line_count; i++) {
	    my_strncpy(copy[i], src[i], 5);
	    fprintf(fptrout, "%s\n", copy[i]);
	}
    } else if (strcmp(command, "my_strstr") == 0) {
	for (i = 0; i < line_count; i++) {
	    fprintf(fptrout, "%d\n", my_strstr(copy[i], src[i]) != NULL);
	}
    } else if (strcmp(command, "my_strinsert") == 0) {
	for (i = 0; i < line_count; i++) {
	    my_strinsert(buffer, "\n", 0);
	    my_strinsert(buffer, src[i], 0);
	}
	fprintf(fptrout, "[%s]\n", buffer);
    } else if (strcmp(command, "my_strdelete") == 0) {
	for (i = 0; i < line_count; i++) {
	    my_strinsert(buffer, "\n", 0);
	    my_strinsert(buffer, src[i], 0);
	    my_strdelete(buffer, 0, 10);
	}
	fprintf(fptrout, "[%s]\n", buffer);
    }

    for (i = 0; i < line_count; i++) {
	free(copy[i]);
	free(src[i]);
    }
    free(src);
    free(copy);
    free(buffer);
    fclose(fptrout);
    return EXIT_SUCCESS;
}

/* amaze: make random mazes by walking around aimlessly

Copyright (C) 2008 Henry Kroll www.thenerdshow.com

	. You might find stuff like this in the Public Domain.
	. I made this as a fun exercise, without consulting them.
	. You are free use, copy and modify this software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
POSSIBILITY OF SUCH DAMAGE.

*/

/*
>gcc -Wall -pedantic -O2 "amaze.c" -o "amaze"
>Exit code: 0

>./"amaze"
Usage: ./amaze ROWS<=39 COLS<=39 [color 1-8] [wall char]
Example: ./amaze 11 15 @
>Exit code: 1

>./amaze 6 35 3 @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@       @                     @         @     @             @         @
@ @@@ @ @ @@@@@@@ @@@@@ @@@@@ @ @@@@@@@@@ @ @@@ @ @@@ @@@@@@@ @@@@@ @@@
@   @ @ @ @     @ @   @     @   @         @     @   @ @       @   @   @
@ @@@ @ @@@ @@@ @ @ @ @@@@@ @@@@@ @@@@@@@@@@@@@@@ @ @ @ @@@@@@@@@ @@@ @
@ @   @     @   @ @ @       @             @     @ @ @ @   @     @   @ @
@@@ @@@@@@@@@ @@@@@ @@@@@@@@@ @@@@@@@@@@@@@ @@@ @ @ @@@@@ @@@ @ @ @ @ @
@ @       @ @ @     @       @   @   @       @ @ @ @           @   @ @ @
@ @@@@@@@ @ @ @@@ @@@ @@@@@ @@@ @ @ @ @@@@@@@ @ @@@@@@@ @@@@@@@@@@@@@ @
@       @ @ @   @         @     @ @   @   @     @     @ @     @   @   @
@@@@@@@ @ @ @@@ @@@@@@@@@@@@@@@@@ @@@@@ @@@ @@@@@ @@@ @@@ @@@ @ @ @ @ @
@         @                       @               @       @     @   @ @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
>Exit code: 0
*/

/* To make a maze into a .gif image:

./amaze 40 69 >maz~tmp&&asciitopgm `wc -lL maz~tmp`|convert - maze.gif&&rm maz~tmp

*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX 69 /* max rows and columns */

void usage(char **a){
	fprintf(stderr,"Usage: %s ROWS<=%d COLS<=%d [color 1-8]"
	" [wall char]\n",a[0],MAX,MAX);
	fprintf(stderr,"Example: %s 11 15 @\n",a[0]);
	exit(1);
}
void parsecmd(int argc,char **a, int *r, int *c, int *color, char *wall){
	int i;
	*color=0;*wall=0;
	switch (argc){
		case 5:
			i=atoi(a[4]); /* strips bash quotes around variables '' */
			*wall=a[4][0];
		case 4:
			*color=atoi(a[3]);
			if(*color==0&&!*wall)*wall=a[3][0];
			if(*color<1||*color>8)*color=0;
		case 3:
			*r=atoi(a[1]); /* no error checking */
			*c=atoi(a[2]);
			if(!(*r>1&&*r<=MAX&&*c>1&&*c<=MAX))usage(a);
			break;
		default: usage(a);
	}
}
void initrand(){
	struct timeval tv; /* seed srand() */
	gettimeofday(&tv,0); /* with something... */
	srand((unsigned int)tv.tv_usec);
}
char **mazeinit(int rows,int cols, char wall){
	char **a=malloc((2*rows+1)*sizeof(char*)); /* 3x3 with overlap of 1 */
	int i,j;
	for(i=0;i<2*rows+1;i++){
		if(!(a[i]=malloc(2*cols+1))){
			fprintf(stderr,"Out of memory.\n");
			exit(1);
		}
		for(j=0;j<2*cols+1;j++)
			a[i][j]=(wall)?wall:'*';
	}
	return a;
}
void mazestep(char **a,int *rows,int *cols,int r,int c){
	int i,vector[3][2];
	#define ROW vector[i][0]
	#define COL vector[i][1]
	while(1){
		i=0; /* look around */
		if(r>1			&&a[r-2][c] !=' '){ROW=r-2;COL=c;i++;}
		if(r<*rows*2-1	&&a[r+2][c] !=' '){ROW=r+2;COL=c;i++;}
		if(c>1			&&a[r][c-2] !=' '){ROW=r;COL=c-2;i++;}
		if(c<*cols*2-1	&&a[r][c+2] !=' '){ROW=r;COL=c+2;i++;}
		if(!i)break; /* check for dead end */
		i=(int)(i*(rand()/(RAND_MAX+1.0))); /* choose a path */
		a [(ROW+r)/2]	[(COL+c)/2]=' ';	/* knock out a wall */
		a [ROW] 		[COL]=' ';			/* clear to it */
		mazestep(a,rows,cols,ROW,COL);		/* repeat */
	}
}
void mazewalk(char **maze,int rows, int cols){
	/* this starts at one side but you can start anywhere */
	/* there is a way out no matter where your exits are */
	int i,r,c;
	c=cols|1;
	maze[0][c]=' ';maze[2*rows][c]=' ';
	i=(int)(2*(rand()/(RAND_MAX+1.0)));
	c=(i)?1:2*cols-1;r=rows|1;maze[r][c]=' ';

	mazestep(maze,&rows,&cols,r,c);
}
void mazeprint(char **a,int rows, int cols, int color){
	int i,j;
	for(i=0;i<2*rows+1;i++){
		for(j=0;j<2*cols+1;j++){
			if(color&&a[i][j]!=' ')
				if(j==0||a[i][j-1]==' ') /* reduce control codes */
					printf("%c[4%dm",27,color-1);
			if(color&&a[i][j]==' '&&a[i][j-1]!=' ')printf("%c[0m",27);
			printf("%c",a[i][j]);
		}		
		if(color)printf("%c[0m",27);
		printf("\n");
	}
}
void mazefree(char **a,int rows){
	int i;
	for(i=0;i<2*rows+1;i++)
		free(a[i]);
	free(a);
}

int main (int argc,char **argv){
	int rows,cols,color;char **a,wall;
	parsecmd	(argc,argv,&rows,&cols,&color,&wall);
	/* printf("rows %d cols %d color %d wall %d\n",rows,cols,color,wall); */
	initrand();
a=	mazeinit	(rows,cols,wall);
	mazewalk	(a,rows,cols);
	mazeprint	(a,rows,cols,color);
	mazefree	(a,rows);
	return 0;
}

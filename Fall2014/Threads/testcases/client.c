/*
/ file : client.c
/----------------------------------
/ This is a client socket program.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 

#define MAX_DATA_SIZE 4096
 
int main(int argc, char *argv[])
{
	int sockfd;
	int recvSize;  
	char buff[MAX_DATA_SIZE];
	char sendData[MAX_DATA_SIZE];
	struct sockaddr_in servAddr; 
	int flag;
	

	if (argc != 3) {
		fprintf(stderr,"Usage: %s <port number> <host IP address>\n", argv[0]);
		exit(1);
	}
	int PORT = atoi(argv[1]);
	
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	servAddr.sin_family = AF_INET;      
	servAddr.sin_port = htons(PORT);    
	servAddr.sin_addr.s_addr = inet_addr(argv[2]);
	bzero(&(servAddr.sin_zero), 8);     

	if (connect(sockfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) == -1) {
		perror("connect failed");
		exit(1);
	}

	buff[recvSize] = '\0';
	printf("%s", buff);

	/* repeat until "exit" input */
	flag = 0; //flag is used to handle the case where the input to the client is fail
	while(1){
		if (flag == 0) printf("Enter a series of numbers: ");
		if (fgets(sendData, MAX_DATA_SIZE, stdin) == NULL){
			flag = 1;
			continue;
		} else flag = 0;

		/* if input is "exit", terminate this program */
		//if(!strncmp(sendData, "exit", 4)) break;

		if (send(sockfd, sendData, strlen(sendData), 0) == -1) {
			perror("send failed");
			close(sockfd);
			exit(1);
		}

		if ((recvSize = recv(sockfd, buff, MAX_DATA_SIZE, 0)) == -1) {
			perror("recv failed");
			exit(1);
		}
		buff[recvSize] = '\0';
		printf("Received summation is %s\n", buff);
		fflush(stdout);
	}
	close(sockfd);

	return 0;
}


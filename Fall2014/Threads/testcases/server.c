#include <pthread.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/wait.h> 
#include <arpa/inet.h>
#include <unistd.h>


#define MAX_PENDING 10     /* maximun # of pending for connection */

int Print(char *recvBuff,char *str, int numBytes);

void* calc(void* fd){
	char *recvBuff;
	int clntSockfd;
	int senderBuffSize;
	int tot = 0;
    int number;
    char *ptr;
    char *str;
    int numBytes = 0; 
    socklen_t optlen = sizeof senderBuffSize;

    
    clntSockfd = *(int*)fd;
	while(1) {
            /* recv data from the client */
            getsockopt(clntSockfd, SOL_SOCKET,SO_SNDBUF, 
            &senderBuffSize, &optlen); /* check sender buffer size */
            recvBuff = malloc(senderBuffSize * sizeof (char));
            str = malloc(senderBuffSize * sizeof (char)); 
            tot = 0;

            if ((numBytes = 
                    recv(clntSockfd, recvBuff, senderBuffSize, 0)) == -1) {
                perror("recv failed");
                return;
            }else if (numBytes > 0){
                //recvBuff[numBytes] = '\0';
                ptr = strtok(recvBuff, " ");
                
                while(ptr != NULL){
                	//printf ("%s\n",ptr); 
                	number = atoi(ptr);
                	tot += number;
                	ptr = strtok(NULL, " ");
                }
                
                sprintf(str, "%d", tot);

                /* send data to the client */
                if (send(clntSockfd, str, strlen(str), 0) == -1) {
                    perror("send failed");
                    close(clntSockfd);
                    return;
            	}

                printf("Sent summation is: %s!\n", str);
                fflush(stdout);
            	
            }else{
                return;
            }
    	}

}

 
int main(int argc, char *argv[])
{
    if (argc < 2) {
    fprintf(stderr,"ERROR, no port provided\n");
    exit(1);
    }
    int PORT = atoi(argv[1]);

    char *ptr;
    pthread_t calculation;

    int servSockfd, clntSockfd;  
    struct sockaddr_in sevrAddr;    
    struct sockaddr_in clntAddr; 
    int clntLen;

    /* make socket */
    if ((servSockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("sock failed");
        exit(1);
    }

    /* set IP address and port */
    sevrAddr.sin_family = AF_INET;       
    sevrAddr.sin_port = htons(PORT);     
    sevrAddr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(sevrAddr.sin_zero), 8);       

    if (bind(servSockfd, (struct sockaddr *)&sevrAddr, 
                sizeof(struct sockaddr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(servSockfd, MAX_PENDING) == -1) {
        perror("listen failed");
        exit(1);
    }

    while(1) {
        clntLen = sizeof(struct sockaddr_in);
        if ((clntSockfd = accept(servSockfd, 
                    (struct sockaddr *) &clntAddr, &clntLen)) == -1) {
            perror("accept failed");
            
            exit(1);
        }
        /* repeat for one clinet service */
        
		pthread_create(&calculation, NULL, calc, &clntSockfd);
		
    }
}

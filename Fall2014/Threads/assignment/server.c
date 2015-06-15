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

void* calc(void* fd){ //fd means client socket file descriptor. you can add as many parameter as needed
	//define your variables

    //write your thread to get the received number and calculate the summation
    //while loop used here
}

int main(int argc, char *argv[])
{
    //check the valid number of arguments. if check fails, printout "Error, no port provided"
    



    //make socket




    //set IP address and port 




    //bind socket




    //listen to socket
    



    //accept socket and call pthread_create function here
    //while loop used here

}

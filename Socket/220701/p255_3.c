#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char* message);
void read_childproc(int sig);

int main(int argc, char* argv[])
{
	int sock;	//socket file descripter 
	pid_t pid;	//	pid

	pid = fork();	//create child/copy process
	sock = socket(PF_INET, SOCK_STREAM, 0);
	//create socket

	if(pid == 0)	//child proc
		printf("Child proc : %d\n", sock);
	else				// parents proc
		printf("Parent proc : %d\n", sock);
	
	return 0;
}

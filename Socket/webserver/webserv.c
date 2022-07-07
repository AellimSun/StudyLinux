#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>

#define BUF_SIZE 1024
void error_handling(char* msg);

char webpage[] = "HTTP/1.1 200 OK\r\n"
		"Server:Linux Web Server\r\n"
		"Content-Type: text/html; charset=UTF-8\r\n\r\n"
		"<!DOCTYPE html>\r\n"	
		"<html><head><title> My Web Page </title>\r\n"
		"<style>body {background-color: #FFFF00 }</style></head>\r\n"
		"<body><center><h1>Hello world!!</h1><br>\r\n" 				     
		"<img src=\"home2.jpg\" style=\"width:100%;height:auto;\"/></center></body></html>\r\n";

int main(int argc, char* argv[])
{
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_adr_sz;
	char buf[BUF_SIZE] = {0,};
	int fimg;
	char buf_img[1000000];
	
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("bind() error");
	if(listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	clnt_adr_sz = sizeof(clnt_adr);

	while(1)
	{
		printf("Waiting for client...\n");
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
		printf("Client connected!\n");
		read(clnt_sock, buf, BUF_SIZE);
//		printf("%s", buf);
		if(!strncmp(buf, "GET / HTTP/1.1",14))
		{
			write(clnt_sock, webpage,sizeof(webpage));
			printf("Send information\n");
		}
		else if(!strncmp(buf, "GET /home2.jpg",14))
		{
			fimg = open("home2.jpg", O_RDONLY);
			read(fimg, buf_img,sizeof(buf_img));
			write(clnt_sock,buf_img,sizeof(buf_img));
			printf("Send image\n");
			break;
		}
	}
	close(clnt_sock);
	close(serv_sock);

	return 0;
}

void error_handling(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

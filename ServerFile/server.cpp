#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#define portnumber 8080

void * solveData(void *socket1);


int main(int argc, char *argv[])
{
	//套接字
	int sockfd, new_fd;
	//
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	int sin_size, iDataNum;
	char buffer[] = "dsfsdfdsf";
	if (argc != 2)
	{
		fprintf(stderr, "Usage:%s portnumber\a\n", argv[0]);
		return 0;
	}
	//创建套接字失败
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "Socket error:%s\n\a", strerror(errno));
		return 0;
	}
	bzero(&server_addr, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(portnumber);
	//绑定本机
	if (bind(sockfd, (struct sockaddr *)(&server_addr), sizeof(struct sockaddr)) == -1)
	{
		fprintf(stderr, "Bind error:%s\n\a", strerror(errno));
		return 0;
	}
	//监听
	if (listen(sockfd, 5) == -1)
	{
		fprintf(stderr, "Listen error:%s\n\a", strerror(errno));
		return 0;
	}

	while (1)
	{
		//等待客户端的访问
		if ((new_fd = accept(sockfd, (struct sockaddr *)(&client_addr), (socklen_t*)&sin_size)) == -1)
		{
			fprintf(stderr, "Accept error:%s\n\a", strerror(errno));
			return 0;
		}
		else
		{
			pthread_t thread1 = pthread_create(&thread1, NULL, solveData, (void *)new_fd);
			fprintf(stderr, "Accept success");
		}
	}
	return 0;
}

void * solveData(void *socket1)
{
	int sokcet = (int)(long)socket1;
	int num = 0;
	char buffer[] = "dsfsdfdsf";
	while (1)
	{
		sleep(1);
		fprintf(stdout, "send data to client No.%d\n", num);
		send(sokcet, buffer, sizeof(buffer), 0);
		num++;
	}
}

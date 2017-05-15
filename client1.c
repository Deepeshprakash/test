/*
 * client1.c
 *
 *  Created on: Feb 6, 2016
 *      Author: deepesh
 */

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>
#define PORT 9567

struct sockaddr_in client_addr;
char msg[256];
struct sockaddr_in client_addr;
int client_fd,n;
void receive();
void reply();
int main()
{
	printf("Enter Message\n============\n");
client_addr.sin_family=AF_INET;
client_addr.sin_port=htons(PORT);
client_addr.sin_addr.s_addr=inet_addr("192.168.0.103"); //127.0.0.1



while(1)
{
receive();
sleep(2);
reply();
sleep(2);

}
}



void receive(){

	if((client_fd=socket(AF_INET,SOCK_STREAM,0))<0)
			{
			printf("Cannot create socket.");
			exit(-1);
			}
//bind(client_fd,(struct sockaddr*)&client_addr,sizeof(client_addr));
if((connect(client_fd,(struct sockaddr*)&client_addr,sizeof(client_addr)))<0)
{
printf("Cannot create connection");
exit(-1);
}
read(client_fd,msg,sizeof(msg));
printf(":>%s\n",msg);  //:> deleted
sleep(1);
}
void reply()
{
	if((client_fd=socket(AF_INET,SOCK_STREAM,0))<0)
				{
				printf("Cannot create socket.");
				exit(-1);
				}
	//bind(client_fd,(struct sockaddr*)&client_addr,sizeof(client_addr));
	if((connect(client_fd,(struct sockaddr*)&client_addr,sizeof(client_addr)))<0)
	{
	printf("Cannot create connection");
	exit(-1);
	}
	printf(":>");
	scanf("%s",msg);
	write(client_fd,msg,sizeof(msg));

	sleep(1);
	}


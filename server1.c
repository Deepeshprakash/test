/*
 * server1.c
 *
 *  Created on: Feb 6, 2016
 *      Author: deepesh
 */

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
void sent();
void reply1();
int server_sockfd,client_sockfd,len;
char msg[256]="Hello";
struct sockaddr_in server_address;
struct sockaddr_in client_address;

int main()
{

printf("Enter Message\n============\n");
server_sockfd=socket(AF_INET,SOCK_STREAM,0);



server_address.sin_port=htons(9567);
server_address.sin_family=AF_INET; //Internet not local
server_address.sin_addr.s_addr=htonl(INADDR_ANY); //Connect to any address
bzero(&server_address.sin_zero,8);

if(bind(server_sockfd,(struct sockaddr*)&server_address,sizeof(server_address))<0){

printf("Failed to bind");
exit (-1);
}
if(listen(server_sockfd,5)==-1){
	printf("Failed to listen");
	exit(-1);
	}
	while(1)
	{
	sent();
	sleep(1);
	reply1();
	sleep(1);
	}
	}

void sent(){

	printf(":>");
	scanf("%s",msg);
	len = sizeof(struct sockaddr_in);
	client_sockfd =accept(server_sockfd,(struct sockaddr*)&client_address,&len);
	write(client_sockfd,msg,sizeof(msg));
	close(client_sockfd);
	sleep(1);
}


void reply1()
{
	printf(":>");

	len = sizeof(struct sockaddr_in);
	client_sockfd =accept(server_sockfd,(struct sockaddr*)&client_address,&len);
	read(client_sockfd,msg,sizeof(msg));
	printf("%s\n",msg);
	close(client_sockfd);
	sleep(1);
}

#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
int main() {
    int sockfd, n;
    char sendline[100];
    char recvline[100];
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(22000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    
    bzero(sendline, 100);
    bzero(recvline, 100);
    printf("Type here: ");
    fgets(sendline, 100, stdin);
    send(sockfd, sendline, sizeof(sendline), 0);
    recv(sockfd, recvline, 100, 0);
    printf("%s", recvline);
} 

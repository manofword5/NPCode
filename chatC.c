#include "neth.h"
int main() {
    int sockfd;
    char sendline[100], recvline[100];
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(22000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)); 
    while(1) {
        bzero(&sendline, 100);
        bzero(&recvline, 100);
        printf("Type here: ");
        fgets(sendline, 100, stdin);
        // if(sendline == ";") break;
        send(sockfd, sendline, sizeof(sendline), 0);
        recv(sockfd, recvline, 100, 0);
        printf("Server: %s\n", recvline);
    }
    close(sockfd);
}
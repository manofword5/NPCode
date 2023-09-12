#include "neth.h"
int main() {
    int sockfd;
    char sendline[100], recvline[100];
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(22000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int slen = sizeof(servaddr);
    while(1) {
        bzero(sendline, 100);
        bzero(recvline, 100);
        printf("Type here: ");
        fgets(sendline, 100, stdin);
        sendto(sockfd, sendline, strlen(sendline), NULL, (struct sockaddr *) &servaddr, slen);
        recvfrom(sockfd, recvline, 100,  NULL, (struct sockaddr *) &servaddr, &slen);
        printf("Server: %s\n", recvline);
    }
    close(sockfd);
    return 0;
}
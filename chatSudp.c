#include "neth.h"
int main() {
    int listenfd;
    char sendline[100], recvline[100];
    struct sockaddr_in servaddr;
    struct sockaddr_in cliaddr;
    listenfd = socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    bzero(&servaddr, sizeof(cliaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(22000);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int clen = sizeof(cliaddr);
    bind(listenfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
    while(1) {
        bzero(sendline, 100);
        bzero(recvline, 100);
        recvfrom(listenfd, recvline, 100, NULL, (struct sockaddr*) &cliaddr, &clen);
        printf("Client : %s\n",recvline);
        printf("Type here: ");
        fgets(sendline, 100, stdin);
        sendto(listenfd, sendline, 100, NULL, (struct sockaddr*) &cliaddr, clen);
    }
    return 0;
}
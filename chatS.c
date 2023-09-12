#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
int main()
{
    char sendline[100], recvline[100];
    int listenfd, commfd;
    struct sockaddr_in servaddr;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(22000);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(listenfd, 10);
    commfd = accept(listenfd, NULL, NULL);
    while (1)
    {
        bzero(sendline, 100);
        bzero(recvline, 100);
        recv(commfd, recvline, 100, 0);
        printf("Client : %s\n", recvline);
        printf("Type here: ");
        fgets(sendline, 100, stdin);
        // if(sendline == ';') break;
        send(commfd, sendline, strlen(sendline), 0);
    }
    close(commfd);
}
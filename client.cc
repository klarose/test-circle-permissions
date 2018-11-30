#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

int main() {
    int sock = 0;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error:");
        return -1;

    }
    int opt = 1;
    if (setsockopt(sock, IPPROTO_IP, IP_TRANSPARENT, &opt, sizeof(opt)))
    { 
        perror("setsockopt IP_TRANSPARENT"); 
        return -1;
    } 
    printf("Successfully set IP_TRANSPARENT\n");

    opt = 123;
    if (setsockopt(sock, SOL_SOCKET, SO_MARK, &opt, sizeof(opt)))
    { 
        perror("setsockopt SO_MARK"); 
        return -1;
    } 

    printf("Successfully set SO_MARK\n");
    return 0;
}

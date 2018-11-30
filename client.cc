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
    if (setsockopt(sock, IPPROTO_IP, IP_TRANSPARENT, &opt, sizeof(opt)));
    { 
        perror("setsockopt"); 
        return -1;
    } 
    printf("Successfully set IP_TRANSPARENT");
    return 0;
}

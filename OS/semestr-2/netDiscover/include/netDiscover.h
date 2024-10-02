#include <bits/socket.h>
#ifndef NET_DISCOVER
#define NET_DISCOVER

typedef enum Result {
    ERROR,
    OK
};

enum Result createMulticastSocket(int *socket, const char *port, const char *ip);
enum Result sendMessage(int sockfd, char *msg, struct sockaddr *destAddr, socklen_t destAddrLen);

#endif
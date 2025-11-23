#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/tcp.h>
#include <stdbool.h>
#include "network_utils.h"


int create_valid_socket_tcp(const bool reuse_addr, const bool tcp_nodelay) {

    int opt_val = 1;
    int socket_fd;

    if ((socket_fd = socket(AF_UNIX, SOCK_STREAM | SOCK_NONBLOCK, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    if (reuse_addr) {
        if (setsockopt(socket_fd,SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(opt_val)) < 0) {
            perror("Setsockopt reuse failed");
            goto error_cleanup;
        }    
    }
    
    if (tcp_nodelay) {
        if (setsockopt(socket_fd, IPPROTO_TCP, TCP_NODELAY, &opt_val, sizeof(opt_val)) < 0) {
            perror("Setsockopt nodelay failed");
            goto error_cleanup;
        }
    }
    
    return socket_fd;


    error_cleanup:
        close(socket_fd);
        return -1;     
}



#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {

    int socket_fd = 0;
    struct sockaddr_in dest_addr;
    socklen_t addr_len = sizeof(dest_addr);

    //initialisation du socket pour une communcation IPv4 utilisant le protocol TCP
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create the socket\n");
        exit(EXIT_FAILURE);
    }
    printf("Successfully created socket\n");

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(11000);
    dest_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(connect(socket_fd, (struct sockaddr *)&dest_addr, addr_len) < 0) {
        perror("Failed to connect to the server\n");
        exit(EXIT_FAILURE);
    }
    printf("Connection successful\n");

    char* hello = "Hello from Client";
    int len = strlen(hello);

    int bytes_sent = send(socket_fd, hello, len, 0);
    printf("Message sent : %d bytes\n", bytes_sent);

    char buffer[BUFFER_SIZE] = {0};
    int valread = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    if (valread > 0) {
         buffer[valread] = '\0';
         printf("Message from server: %s\n", buffer);
    }

    close(socket_fd);

    return 0;
}

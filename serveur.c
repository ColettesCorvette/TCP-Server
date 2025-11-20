#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> 


int main() {

	int socket_fd = 0;

	//initialisation du socket pour une communcation IPv4 utilisant le protocol TCP
	if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Failed to create the socket\n");
		exit(EXIT_FAILURE);
	}
	
	//création de l'adresse et du port du serveur 
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET; //Format IPv4
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //Adresse IP
	serv_addr.sin_port = htons(11000); // Port TCP

	//Associe l'adresse au socket
	if (bind(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		perror("Failed to bind the address to the socket server \n");
		exit(EXIT_FAILURE);	
	}
	
	
	
	return 0;
}




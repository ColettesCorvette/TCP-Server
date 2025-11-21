#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> 

#define MAXPENDING 10
#define BUFFER_SIZE 1024

int main() {

	int socket_fd, client_socket = 0;
	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);

	//Initialisation du socket pour une communcation IPv4 utilisant le protocol TCP
	if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Failed to create the socket\n");
		exit(EXIT_FAILURE);
	}
	printf("Successfully created socket\n");
	
	//Création de l'adresse et du port du serveur 
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET; //Format IPv4
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //Adresse IP
	serv_addr.sin_port = htons(11000); // Port TCP

	//Associe l'adresse au socket
	if (bind(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		perror("Failed to bind the address to the socket server\n");
		exit(EXIT_FAILURE);
	}
	printf("Listening on port 11000...\n");
	
	//Autorisation du socket à écouter les connexions entrantes
	if (listen(socket_fd, MAXPENDING) < 0) {
		perror("Failed to listen\n");
		exit(EXIT_FAILURE);
	}
	
	//Attente de connexion
	if ((client_socket = accept(socket_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
		perror("Failed to accept connection\n");
		exit(EXIT_FAILURE);
	}
	printf("Client connected\n");

	char buffer[BUFFER_SIZE] = {0};
	int valread = 0;
	
	//Lecture jusqu'à BUFFER_SIZE en octets 
	valread = recv(client_socket, buffer, BUFFER_SIZE, 0);

	if(valread < 0) {
		perror("Failed to retrieve data");
	}
	else {
		buffer[valread] = '\0';
		printf("Data received from client: %s\n", buffer);
	}

	char* hello = "Hello from Server";
	int len = strlen(hello);
	int bytes_sent = send(client_socket, hello, len, 0);

	printf("Message sent to client : %d bytes\n", bytes_sent);
	
	close(client_socket);
	close(socket_fd);
	
	return 0;
}




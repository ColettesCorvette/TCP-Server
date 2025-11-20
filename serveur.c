#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> 


int main() {
	
	//initialisation du socket pour un communcation IPV4 utilisant le protocol TCP
	int socket = socket(AF_INET, SOCK_STREAM, 0);
	
	printf("Valeur de retour du socket%d", socket);
	
	
	
	return 0;
}



//gcc -Wall -Wextra -Werror serveur.c
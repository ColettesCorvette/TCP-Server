# TCP Client/Server Socket Implementation

![Version](https://img.shields.io/badge/version-v1.0-blue.svg)
![Language](https://img.shields.io/badge/language-C-green.svg)

A simple and robust Client/Server architecture implementation using **TCP Sockets** in C. This project demonstrates the fundamentals of network communication via the IPv4 protocol.

## Description

This **v1.0** release contains two distinct programs:
1.  **Server (`serveur.c`)**: Listens on a defined port, accepts an incoming connection, displays the received message, and sends a response.
2.  **Client (`client.c`)**: Connects to the server, sends the message "Hello from Client" and waits for the server's response.

## Libraries & Dependencies

The following standard C libraries are used in `client.c` and `serveur.c`. Below is a breakdown of the specific elements utilized from each header:

### `<sys/socket.h>`
Core socket definitions and functions.
* **Functions:** `socket()`, `bind()`, `listen()`, `accept()`, `connect()`, `send()`, `recv()`.
* **Constants:** `AF_INET` address Family, `SOCK_STREAM` TCP Stream.
* **Types:** `socklen_t` socket length type, `struct sockaddr` generic socket address structure.

### `<netinet/in.h>`
Internet address family structures and constants.
* **Structures:** `struct sockaddr_in` IPv4 specific address structure.
* **Functions:** `htons()` host to Network Short, `htonl()` host to Network Long.
* **Constants:** `INADDR_ANY` binds to all available interfaces.

### `<unistd.h>`
POSIX operating system API access.
* **Functions:** `close()` terminates the socket file descriptors.

### `<stdio.h>`
Standard Input/Output library.
* **Functions:** `printf()` output to stdout, `perror()` print error message to stderr.

### `<stdlib.h>`
Standard General Utilities library.
* **Functions:** `exit()`terminates the program, `EXIT_FAILURE` standard failure return code.

### `<string.h>`
String manipulation operations.
* **Functions:** `memset()` zeros out memory buffers/structures), `strlen()` calculates string length.

### `<sys/types.h>`
System data type definitions.
* **Usage:** Provides portability for system data types used in socket calls, required by `<sys/socket.h>`.

## Technical Specifications

* **Protocol:** TCP
* **Address Family:** AF_INET (IPv4)
* **Port:** `11000`
* **Buffer Size:** 1024 bytes
* **Architecture:** Server handles one client at a time for this version.

## Prerequisites

* A C compiler.
* A Unix/Linux environment.

## Installation and Compilation

Clone the repository, then compile the two source files using the instructions below. These commands use strict error checking and optimization flags.

### 1. Compile both server.c & client.c
```bash
gcc -O3 -march=native -Wall -Wextra -Werror serveur.c -o serveur
gcc -O3 -march=native -Wall -Wextra -Werror client.c -o client
```

### 2. Run 
```bash
./serveur
./client
```


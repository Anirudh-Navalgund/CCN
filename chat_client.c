#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 256

void func(int sockfd) {
    char buff[MAX];
    int n;

    while (1) {
        bzero(buff, sizeof(buff));
        printf("Enter the message to be sent: ");
        fgets(buff, sizeof(buff), stdin);

        // Check if client wants to exit
        if (strncmp(buff, "exit", 4) == 0) {
            printf("Client Exit...\n");
            break;
        }

        // Send to server
        n = write(sockfd, buff, strlen(buff));
        if (n < 0) {
            perror("Write to server failed");
            break;
        }

        // Receive from server
        bzero(buff, sizeof(buff));
        n = read(sockfd, buff, sizeof(buff));
        if (n <= 0) {
            printf("Server closed connection or read error\n");
            break;
        }

        printf("Message from Server: %s", buff);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <server_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sd, port = atoi(argv[1]);
    const char *server_ip = argv[2];
    struct sockaddr_in server;

    // Create socket
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server address config
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to server
    if (connect(sd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Connect failed");
        close(sd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at %s:%d\n", server_ip, port);

    // Start chat
    func(sd);

    // Close socket
    close(sd);
    return 0;
}

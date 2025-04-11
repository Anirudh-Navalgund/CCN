#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 80
#define BACKLOG 5

int flag = 0;

int func(int sockfd) {
    char buff[MAX];
    int n;

    while (1) {
        if (flag == 1) break;

        bzero(buff, MAX);

        // Read from client
        n = read(sockfd, buff, sizeof(buff));
        if (n <= 0) {
            printf("Client disconnected or error occurred.\n");
            break;
        }

        printf("Message from client: %s", buff);

        // Input server response
        bzero(buff, MAX);
        printf("Enter message to be sent to client: ");
        fgets(buff, sizeof(buff), stdin);

        // Remove newline from fgets
        buff[strcspn(buff, "\n")] = 0;

        // Exit condition
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit ...\n");
            flag = 1;
            break;
        }

        // Send message to client
        write(sockfd, buff, strlen(buff));
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int sd, new_sd, client_len, port, yes = 1;
    struct sockaddr_in server, client;

    port = atoi(argv[1]);

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Bind failed");
        exit(1);
    }

    if (listen(sd, BACKLOG) == -1) {
        perror("Listen failed");
        exit(1);
    }

    printf("Chat server listening on port %d...\n", port);
    while (1) {
        client_len = sizeof(client);
        if ((new_sd = accept(sd, (struct sockaddr *)&client, (socklen_t *)&client_len)) == -1) {
            perror("Accept failed");
            continue;
        }
        printf("Client connected: %s\n", inet_ntoa(client.sin_addr));
        func(new_sd);
        close(new_sd);
        if (flag == 1) break;
    }
    close(sd);
    return 0;
}

#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CHUNK 1024

void writefile(int sd) {
    char buf[CHUNK];
    FILE *file = fopen("temp.txt", "w");

    if (file == NULL) {
        printf("\nError in opening file\n");
        return;
    }

    while (read(sd, buf, sizeof(buf)) > 0) {
        fputs(buf, file);
        bzero(buf, sizeof(buf));
    }

    fclose(file);
}

int main(int argc, char **argv) {
    int sd, port;
    char buf[1024];
    struct sockaddr_in server;

    port = atoi(argv[1]);

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Cannot create a socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = port;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        fprintf(stderr, "Cannot connect\n");
        exit(1);
    }

    printf("\nEnter the command: ");
    scanf("%s", buf);
    write(sd, buf, sizeof(buf));

    writefile(sd);
    close(sd);
    return 0;
}

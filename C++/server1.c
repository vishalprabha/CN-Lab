#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int welcome, new_soc, fd, n;
    char buffer[1024], fname[50];
    struct sockaddr_in addr;

    welcome = socket(PF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(7891);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(welcome, (struct sockaddr *) &addr, sizeof(addr));
    printf("\nServer is Online");
    /*  listen for connections from the socket */
    listen(welcome, 5);
    /*  accept a connection, we get a file descriptor */
    new_soc = accept(welcome, NULL, NULL);

    /*  receive the filename */
    recv(new_soc, fname, 50, 0);
    printf("\nRequesting for file: %s\n", fname);

    /*  open the file and send its contents */
    fd = open(fname, O_RDONLY);

    if (fd < 0)
        send(new_soc, "\nFile not found\n", 15, 0);
    else
        while ((n = read(fd, buffer, sizeof(buffer))) > 0)
            send(new_soc, buffer, n, 0);
    printf("\nRequest sent\n");
    close(fd);

    return 0;
}



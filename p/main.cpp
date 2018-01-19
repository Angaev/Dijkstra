#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int fd;
    char ch;
    if ((fd = open(argv[1], O_RDWR)) == -1)
    {
        printf("Cannot open file.\n");
        exit(1);
    }
    while (!eof(fd))
    {
        read(fd, &ch, 1); /* чтение по символу за раз */
        printf("%с", ch);
    }
    close(fd);
    return 0;
}

#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("txtfile.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}

#include "get_next_line.h"

int main(void) 
{
    int fd;
    char *line;

    fd = open("txtfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL) 
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}

/*
int main(void)
{
    int fd;
    char *test;

    fd = open("txtfile.txt", O_RDONLY);
    if(fd == -1)
        return (-1);
    test = get_next_line(fd);
    printf("%s", test);
    free(test);
}

int main(void)
{
    int fd;
    char *line;
    int ret;

    fd = open("txtfile.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("Line: %s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}

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
*/
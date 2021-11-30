#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *res;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    res = ft_read(fd, res);
    // printf("RES:%s\n", res);
    if (res == NULL)
        return(NULL);
    line = get_line(res);
    // printf("RES:%s\n", res);
    res = res_update(res);
    return (line);
}

int main(int ac, char **av){
    int fd;

    if (!ac)
        return (0);
    fd = open(av[1], O_RDONLY);
    printf("%d\n", fd);

    char *ret;
    int i = 0;
    while ((ret = get_next_line(fd)) != NULL ){
        printf("GNL=%s", ret);
        i++;
    }
}

#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "get_next_line.h"

int main(void)
{
    char *line = NULL;

	// while ((line = get_next_line(0)) != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// 	line = NULL;
	// }

    int fd = open("./main.c", O_RDONLY);
    if (fd < 0)
        return (0);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
        line = NULL;
    }
    close(fd);
    return (0);
}

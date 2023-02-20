
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "get_next_line.h"

/* int main(void)
{
	char *line = NULL;

	while ((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	system("leaks boc > bocleak 2>&1");
	return(0);
} */
int main(void)
{
    char *line = NULL;

    // int fd = open("./gnlTester/files/41_with_nl", O_RDONLY);
    int fd = open("./main.c", O_RDONLY);
    if (fd < 0)
        return (0);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	// line = NULL;

	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	// line = NULL;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
        line = NULL;
    }
    close(fd);
    // printf("test\n");
    return (0);
}

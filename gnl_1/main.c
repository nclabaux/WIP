#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	char *line;
	int verif;

	line = NULL;
	fd = open("tester", O_RDONLY);
//	fd = open("words.txt", O_RDONLY);
    //	fd = open("5k_char_line", O_RDONLY);
//	fd = 0;
/*	while((verif = get_next_line(fd, &line)))
	{
		printf("%d\t%s\n", verif, line);
		if (verif == -1)
			break;
	}
*/	verif = get_next_line(fd, &line);
	printf("%d\t%s\n", verif, line);
	close(fd);
	free(line);
}

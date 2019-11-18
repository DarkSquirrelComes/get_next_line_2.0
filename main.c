#include "get_next_line.h"
#include <stdio.h>

int main()
{
	/*char *x = "12345";
	char *y = "12345";

	char *res;
	res = ft_strjoin(x, y);
	//printf("%s\n", res);

	




	char *overhead;
	overhead = malloc(4);
	overhead[0] = '1'; overhead[1] = '2'; overhead[2] = '3'; overhead[3] = '\0';
	char *buf;
	buf = malloc(4);
	buf[0] = '3'; buf[1] = '2';  buf[2] = '2';  buf[3] = '\0'; 
	int status = 1;

	concat(&overhead, buf, &status);
	//printf("%d\n%s\n", status, overhead);





*/

	int 		fd;
	int			res;
	char		*line;

	fd = open("./foo.txt", O_RDONLY);
	res = get_next_line(fd, &line);
	printf("FINAL BOSS1!!! RES:%d; LINE:%s;\n", res, line);
	res = get_next_line(fd, &line);
	printf("FINAL BOSS2!!! RES:%d; LINE:%s;\n", res, line);
	res = get_next_line(fd, &line);
	printf("FINAL BOSS3!!! RES:%d; LINE:%s;\n", res, line);
	res = get_next_line(fd, &line);
	printf("FINAL BOSS4!!! RES:%d; LINE:%s;\n", res, line);

	//get_next_line(fd, &line);
	//printf("FINAL BOSS2!!! LINE:%s\n", line);
	/*printf("BEFORE overhead: %s; status: %d;\n", overhead, status);
	for (int i = 0; i < 10; ++i)
	{
		extend_overhead(&overhead, fd, &status);
		printf("AFTER %d     overhead: %s; status: %d;\n", i, overhead, status);
	}




	char		*line;

	printf("BEFORE prcs_ovrh: %s; status: %d;\n", overhead, status);
	status = process_overhead(&overhead, &line);
	printf("AFTER  prcs_ovrh: %s; status: %d; line: %s;\n", overhead, status, line);*/
}

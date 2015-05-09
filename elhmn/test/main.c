#include <stdio.h>

int		main(int ac, char **av)
{
	float j;
	float ret;

	j = 0;
	(void)av;
	(void)ac;
	printf("[%f]\n", (ret = 1. / j));
	printf("[%f]\n", (ret * 5.));
	return (0);
}

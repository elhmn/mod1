#include "mod1.h"
#include "check_errors.h"
#include <stdio.h>

void	print_mesh(t_vertx *mesh)
{
	int	k;

	k = -1;
	while (!mesh[++k].end)
	{
		
		printf("\033[34m[\033[0m");
		printf("\033[33m%.0f\033[0m", mesh[k].z);
		printf("\033[34m] \033[0m");
		if (!((k + 1) % SCALE))
			printf("\n");
	}
	printf("\n");
}

void	print_mesh_line(t_vertx *mesh)
{
	int	k;

	k = -1;
	while (!mesh[++k].end)
	{
		printf("\033[34m{\033[0m");
		printf("\033[33m%2.1f, %2.1f, %2.1f\033[0m", mesh[k].x, mesh[k].y, mesh[k].z);
		printf("\033[34m} \033[0m");
		if (!((k + 1) % SCALE))
			printf("\n");
	}
	printf("\n");
}

void	print_vertx(t_vertx vertx)
{
	printf("x = [%f]\n", vertx.x);
	printf("y = [%f]\n", vertx.y);
	printf("z = [%f]\n", vertx.z);
	printf("end = [%d]\n", vertx.end);
	ft_putendl("col :: ");
	print_color(vertx.col);
}

void	print_base(t_base *base)
{
	if (!base)
		check_errors(NUL, "print_scene.c", "base");
	printf("base->o.x = [%f]\n", base->o.x);
	printf("base->o.y = [%f]\n", base->o.y);
	printf("base->o.z = [%f]\n", base->o.z);
	printf("base->o.end = [%d]\n", base->o.end);
	ft_putendl("base->o.col :: ");
	print_color(base->o.col);
	printf("base->i.x = [%f]\n", base->i.x);
	printf("base->i.y = [%f]\n", base->i.y);
	printf("base->i.z = [%f]\n", base->i.z);
	printf("base->i.end = [%d]\n", base->i.end);
	ft_putendl("base->i.col :: ");
	print_color(base->i.col);
	printf("base->j.x = [%f]\n", base->j.x);
	printf("base->j.y = [%f]\n", base->j.y);
	printf("base->j.z = [%f]\n", base->j.z);
	printf("base->j.end = [%d]\n", base->j.end);
	ft_putendl("base->j.col :: ");
	print_color(base->j.col);
	printf("base->k.x = [%f]\n", base->k.x);
	printf("base->k.y = [%f]\n", base->k.y);
	printf("base->k.z = [%f]\n", base->k.z);
	printf("base->k.end = [%d]\n", base->k.end);
	ft_putendl("base->k.col :: ");
	print_color(base->k.col);
}

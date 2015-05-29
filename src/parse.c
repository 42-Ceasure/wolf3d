/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 16:03:12 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/27 17:20:42 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"

void 		load_map(char *av, t_env *world)
{
	int 	fd;
	int 	x;
	int 	y;
	char 	*l;

	y = 0;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &l))
	{
		x = 0;
		while (l[x])
		{

			world->map[y][x] = l[x];
			x++;
		}
		y++;
		world->map[y][x + 1] = '\n';
		free(l);
	}
	close(fd);
}

int 		map_dim(char *av, t_env *world)
{
	int 	fd;
	int 	i;
	char 	*l;

	MXSIZE = 0;
	MYSIZE = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &l))
	{
		i = 0;
		while (l[i])
			i++;
		MYSIZE++;
		free(l);
	}
	MXSIZE = i;
	close(fd);
	return (0);
}

int 		parse(char *av, t_env *world)
{
	int 	i;

	i = 0;
	if (map_dim(av, world) != 0)
		return (-1);
	world->map = malloc(sizeof(int *) * (MYSIZE + 1));
	while (i <= MYSIZE)
	{
		world->map[i] = malloc(sizeof(int) * (MXSIZE + 1));
		i++;
	}
	if (world->map == NULL)
		return (-1);
	load_map(av, world);
	return (0);
}

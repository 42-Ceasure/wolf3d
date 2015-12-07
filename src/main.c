/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/06/03 21:04:09 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"
#include "../lib/colors.h"

int				impro(t_env *world)
{
	int x;
	int y;

	x = 0;
	y = 0;
	world->mapxs = 26;
	world->mapys = 26;
	world->map = (int **)malloc(sizeof(int *) * 26);
	while (y < 26)
	{
		x = 0;
		world->map[y] = (int *)malloc(sizeof(int) * 26);
		while (x < 26)
		{
			if (y == 0 || x == 0 || x == 25 || y == 25)
				world->map[y][x] = 4;
			else if ((y == 7 || y == 13) && (x > 6 && x < 16))
				world->map[y][x] = 1;
			else if ((x == 7 || x == 15) && (y > 7 && y < 13 && y != 10))
				world->map[y][x] = 1;
			else if ((y == 8 || y == 12) && (x > 7 && x < 15))
				world->map[y][x] = 3;
			// else if (x )
			// 	world->map[y][x] = 6;
			else
				world->map[y][x] = 0;
			x++;
		}
		y++;
	}
	write(1, "ok\n", 3);
	return (1);
}

int				main(int ac, char **av)
{
	t_env		*world;
	t_ray		*rayon;

	world = (t_env *)malloc(sizeof(t_env));
	rayon = (t_ray *)malloc(sizeof(t_ray));
	if (ac < 2)
	{
		if (!impro(world))
		{
			write(1, "/!\\\n", 4);
			return (0);
		}
	}
	else if (parse(av[1], world) != 0)
	{
		write(1, "There seems to be a problem with the map...\n", 44);
		return (0);
	}
	if (init_sdl(world) != 0)
	{
		write(1, "cannot intitialize SDL2\n", 24);
		return (0);
	}
	init_player(world);
	make_it_beautifull(world);
	if (world->win)
		dance(world, rayon);
	return (0);
}

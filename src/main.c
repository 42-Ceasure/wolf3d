/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/19 17:20:42 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"
#include "../lib/colors.h"

int				main(int ac, char **av)
{
	t_env		*world;
	t_ray 		*rayon;

	world = (t_env *)malloc(sizeof(t_env));
	rayon = (t_ray *)malloc(sizeof(t_ray));
	if (ac < 2)
	{
		write(1, "no file to open !!!\n", 20);
		write(1, "use ./wolf3d /maps/[map].wlf\n", 29);
		return(0);
	}
	if (parse(av[1], world) != 0)
	{
		write(1, "There seems to be a problem with the map...\n", 44);
		write(1, "Please, try an other or try to contact\n", 39);
		write(1, "cglavieu@student.42.fr\n", 23);
		return(0);
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

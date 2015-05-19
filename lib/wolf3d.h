/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 04:42:57 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/23 07:03:49 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct 					s_coord
{
	int x;
	int y;
	int type;
} 								t_coord;

typedef struct 					s_block
{
	t_coord 	*a;
	t_coord 	*b;
	t_coord 	*c;
	t_coord 	*d;
	int 		type;

}								t_block;

typedef struct					s_env
{
	t_coord 	***coord;
	t_block		***block;
}								t_env;

typedef struct 					s_all
{
	char 		**av;
	char 		**tab;
	char 		**tmp;
	int 		y;
	int 		x;
} 								t_map;

t_coord     ***ft_get_coord(t_map *map);

#endif
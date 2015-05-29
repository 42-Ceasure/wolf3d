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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "SDL2.framework/Headers/SDL.h"

# define NAME "wolf3d"
# define WIDTH 640
# define HEIGHT 400
# define MXSIZE world->mapxs
# define MYSIZE world->mapys
# define KEY w->event.key.keysym.sym

typedef struct					s_env
{
	/*   SDL   */
	SDL_Event		event;
	SDL_Renderer	*rdr;
	SDL_Texture		*txtr;
	SDL_Window		*win;
	Uint32			*pix;
	/*   MAP   */
	int 			**map;
	int 			mapxs;
	int 			mapys;
	/* PLAYER  */
	double 			posx;
	double 			posy;
	double 			dirx;
	double 			diry;
	double 			planx;
	double 			plany;
	/* SCREEN  */
	int 			wscr;
	int 			hscr;
	/*   FPS   */
	double 			ptime;
	double 			otime;
}								t_env;

int 	init_sdl(t_env *w);
int 	parse(char *av, t_env *world);
void 	dance(t_env *w);
void 	exit_game(t_env *w);
void 	init_player(t_env *w);
void 	and_there_was_light(t_env *w);

#endif
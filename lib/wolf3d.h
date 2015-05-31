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
# define WIDTH 800
# define HEIGHT 600
# define MXSIZE world->mapxs
# define MYSIZE world->mapys
# define KEY w->event.key.keysym.sym
# define MOTION w->event.motion
# define ROT M_PI/45
# define MSP 0.25
# define PROT w->rotspeed
# define PMSP w->movspeed

typedef struct 					s_ray
{
	int 	x;
	double 	camerax; 
	double 	rayposx;
	double 	rayposy;
	double 	raydirx;
	double 	raydiry;
	
	int 	mapx;
	int 	mapy;
	double 	sdstx;		// side dist x;
	double 	sdsty;		// side dist y;
	double 	ddstx;		// delta dist x;
	double 	ddsty;		// delta dist y;
	double 	pwalldst;	// perpendiculaire wall distance, to lenght of ray;
	int 	stepx;
	int 	stepy;
	int 	hit;
	int		side;

	int 	lheight;
	int 	drawstart;
	int 	drawend;

	Uint8 	c_r;
	Uint8 	c_g;
	Uint8 	c_b;
	Uint8 	c_a;
}								t_ray;

typedef struct					s_env
{
	/*   SDL   */
	SDL_Window		*win;
	SDL_Renderer	*rdr;
	SDL_Texture		*txtr;
	SDL_Event		event;
	const Uint8 	*inkeys;
	// SDL_PixelFormat *fmt;
	// void 			*pixel;
	// int 			pitch;
	Uint32			*pix;
	Uint32 			colorSDL;
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
	double movspeed;
	double rotspeed;
	/* SCREEN  */
	int 			wscr;
	int 			hscr;
	/*   FPS   */
	double 			time;
	double 			otime;
}								t_env;

int 	init_sdl(t_env *w);
int 	parse(char *av, t_env *world);
void 	dance(t_env *w, t_ray *r);
void 	exit_game(t_env *w);
void 	mv_forward(t_env *w);
void 	mv_backward(t_env *w);
void 	mv_left(t_env *w);
void 	mv_right(t_env *w);
void 	turn_left(t_env *w);
void 	turn_right(t_env *w);
void 	init_player(t_env *w);
void 	and_there_was_light(t_env *w, t_ray *r);

#endif
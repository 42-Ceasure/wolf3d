/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 04:42:57 by cglavieu          #+#    #+#             */
/*   Updated: 2015/06/03 22:21:34 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "colors.h"
# include "libft/inc/libft.h"
# include "SDL2.framework/Headers/SDL.h"

# define NAME 		"wolf3d"
# define WIDTH 		720
# define HEIGHT 	405
# define MXSIZE 	world->mapxs
# define MYSIZE 	world->mapys
# define KEY 		w->event.key.keysym.sym
# define MOTION 	w->event.motion
# define ROT 		M_PI/45
# define MSP 		0.25
# define PROT 		w->rotspeed
# define PMSP 		w->movspeed
# define FOV 		0.85
# define TEXWH 		64

typedef struct		s_ray
{
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			sdstx;
	double			sdsty;
	double			ddstx;
	double			ddsty;
	double			pwalldst;
	double			floorxwall;
	double			floorywall;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			weight;
	double			cfloorx;
	double			cfloory;
	int				ftexx;
	int				ftexy;
	int				x;
	int				y;
	int				stop;
	int				start;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lheight;
	int				drawstart;
	int				drawend;
	int				texx;
	int				texy;
	double			wallx;
	Uint32			color;
	Uint32			color2;
	Uint8			c_a1;
	Uint8			c_r1;
	Uint8			c_g1;
	Uint8			c_b1;
	Uint8			c_a2;
	Uint8			c_r2;
	Uint8			c_g2;
	Uint8			c_b2;
}					t_ray;

typedef struct		s_env
{
	SDL_Texture		*txtr;
	SDL_Window		*win;
	SDL_Renderer	*rdr;
	SDL_Event		event;
	SDL_Surface		*load;
	const Uint8		*inkeys;
	Uint32			*pix;
	Uint32			*tmp;
	Uint32			*sky;
	Uint32			*sol;
	Uint32			*mur1;
	Uint32			*mur2;
	Uint32			*mur3;
	Uint32			*mur4;
	Uint32			*mur5;
	Uint32			*wood;
	int				tmpitch;
	int				**map;
	int				mapxs;
	int				mapys;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			movspeed;
	double			rotspeed;
	int				wscr;
	int				hscr;
	double			time;
	double			otime;
}					t_env;

int					init_sdl(t_env *w);
int					parse(char *av, t_env *world);
void				dance(t_env *w, t_ray *r);
void				exit_game(t_env *w);
void				mv_forward(t_env *w);
void				mv_backward(t_env *w);
void				mv_left(t_env *w);
void				mv_right(t_env *w);
void				turn_left(t_env *w);
void				turn_right(t_env *w);
void				init_player(t_env *w);
void				and_there_was_light(t_env *w, t_ray *r);
void				trace(t_ray *r, int y1, int y2, t_env *w);
void				test_texture(t_env *w, t_ray *r);
void				make_it_beautifull(t_env *w);
Uint32				color(t_ray *r, Uint32 color1);
Uint32				color2color(t_ray *r, Uint32 color1, Uint32 color2);
Uint32				c2colorw(t_ray *r, Uint32 color1, Uint32 color2);

#endif

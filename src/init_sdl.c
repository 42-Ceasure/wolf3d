/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 16:03:12 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/27 17:20:42 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"

int init_sdl(t_env *w)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (-1);
	w->win = SDL_CreateWindow(NAME, 820, 420, WIDTH, HEIGHT, SDL_WINDOW_BORDERLESS);
	w->rdr = SDL_CreateRenderer(w->win, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderSetLogicalSize(w->rdr, WIDTH, HEIGHT);
	w->pix = (Uint32 *)malloc(sizeof(Uint32) * WIDTH * HEIGHT);
	w->txtr = SDL_CreateTexture(w->rdr, SDL_PIXELFORMAT_ARGB8888,
										SDL_TEXTUREACCESS_STREAMING,
										WIDTH,
										HEIGHT);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	SDL_ShowCursor(SDL_DISABLE);
	return (0);
}

void init_player(t_env *w)
{
	w->posx = 22;
	w->posy = 12;
	w->dirx = -1;
	w->diry = 0;
	w->planx = 0;
	w->plany = 0.66;
	w->time = 0;
	w->otime = 0;
	w->wscr = WIDTH;
	w->hscr = HEIGHT;
}

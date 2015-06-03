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

void 	make_it_beautifull(t_env *w)
{
	SDL_Surface 	*tmp;

	w->load = SDL_LoadBMP("/Users/Ceasure/Code/wolf3d/src/textures/boris.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->sky = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	w->sky = tmp->pixels;
	SDL_FreeSurface(tmp);

	w->load = SDL_LoadBMP("/Users/Ceasure/Code/wolf3d/src/textures/mur.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->sol = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	w->sol = tmp->pixels;
	SDL_FreeSurface(tmp);

	w->load = SDL_LoadBMP("/Users/Ceasure/Code/wolf3d/src/textures/grass.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->mur = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	w->mur = tmp->pixels;
	SDL_FreeSurface(tmp);
}
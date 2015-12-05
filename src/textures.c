/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/06/03 22:50:05 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"
#include "../lib/colors.h"

void	make_it_beautifull(t_env *w)
{
	SDL_Surface		*tmp;

	w->load = SDL_LoadBMP("./src/textures/5151.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->sky = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	ft_memcpy(w->sky, tmp->pixels, (sizeof(Uint32) * tmp->w * tmp->h));
	// w->sky = tmp->pixels;
	SDL_FreeSurface(tmp);

	w->load = SDL_LoadBMP("./src/textures/5107.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->sol = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	ft_memcpy(w->sol, tmp->pixels, (sizeof(Uint32) * tmp->w * tmp->h));
	// w->sol = tmp->pixels;
	SDL_FreeSurface(tmp);

	w->load = SDL_LoadBMP("./src/textures/mur.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->mur1 = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	ft_memcpy(w->mur1, tmp->pixels, (sizeof(Uint32) * tmp->w * tmp->h));
	// w->mur1 = tmp->pixels;
	SDL_FreeSurface(tmp);

	w->load = SDL_LoadBMP("./src/textures/bmur.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->mur2 = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	ft_memcpy(w->mur2, tmp->pixels, (sizeof(Uint32) * tmp->w * tmp->h));
	// w->mur2 = tmp->pixels;
	SDL_FreeSurface(tmp);

	w->load = SDL_LoadBMP("./src/textures/pika.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->mur3 = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	ft_memcpy(w->mur3, tmp->pixels, (sizeof(Uint32) * tmp->w * tmp->h));
	// w->mur3 = tmp->pixels;
	SDL_FreeSurface(tmp);

	w->load = SDL_LoadBMP("./src/textures/texture.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->mur4 = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	ft_memcpy(w->mur4, tmp->pixels, (sizeof(Uint32) * tmp->w * tmp->h));
	// w->mur4 = tmp->pixels;
	SDL_FreeSurface(tmp);

	w->load = SDL_LoadBMP("./src/textures/betty.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->mur5 = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	ft_memcpy(w->mur5, tmp->pixels, (sizeof(Uint32) * tmp->w * tmp->h));
	// w->mur5 = tmp->pixels;
	SDL_FreeSurface(tmp);

	w->load = SDL_LoadBMP("./src/textures/forest.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->wood = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	ft_memcpy(w->wood, tmp->pixels, (sizeof(Uint32) * tmp->w * tmp->h));
	// w->wood = tmp->pixels;
	SDL_FreeSurface(tmp);
}

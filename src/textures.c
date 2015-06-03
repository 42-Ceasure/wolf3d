/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/06/03 22:35:58 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"
#include "../lib/colors.h"

void	make_it_beautifull(t_env *w)
{
	SDL_Surface		*tmp;

	w->load = SDL_LoadBMP("./src/textures/wool.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->sky = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	ft_memcpy(w->sky, tmp->pixels, (sizeof(Uint32) * tmp->w * tmp->h));
	SDL_FreeSurface(tmp);
	w->load = SDL_LoadBMP("./src/textures/plank.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->sol = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	ft_memcpy(w->sol, tmp->pixels, (sizeof(Uint32) * tmp->w * tmp->h));
	SDL_FreeSurface(tmp);
	w->load = SDL_LoadBMP("./src/textures/Hellokitty1.bmp");
	tmp = SDL_ConvertSurfaceFormat(w->load, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(w->load);
	w->mur = (Uint32 *)malloc(sizeof(Uint32) * tmp->w * tmp->h);
	ft_memcpy(w->mur, tmp->pixels, (sizeof(Uint32) * tmp->w * tmp->h));
	SDL_FreeSurface(tmp);
}

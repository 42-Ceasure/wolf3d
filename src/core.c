/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/19 17:20:42 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"

void 		button_events(t_env *w)
{
	if (w)
		;
}

void 		motion_events(t_env *w)
{
	if (w)
		;
}

void		key_events(t_env *w)
{
		if (KEY == 27)
			exit_game(w);
		// if (key == 119)
		// 	mv_forward(w);
		// if (key == 115);
		// 	mv_backward(w);
		// if (key == )
		// ft_putnbr(KEY);
		// ft_putchar('\n');
}

void dance(t_env *w)
{
	t_ray 	*r;

	r = (t_ray *)malloc(sizeof(t_ray));
	while (SDL_PollEvent(&w->event) != -1)
	{
		if (w->event.type == SDL_KEYDOWN)
			key_events(w);
		if (w->event.type == SDL_MOUSEMOTION)
			motion_events(w);
		if (w->event.type == SDL_MOUSEBUTTONDOWN)
			button_events(w);
		and_there_was_light(w, r);
		SDL_RenderPresent(w->rdr);
		// SDL_SetRenderDrawColor(w->rdr, 0, 0, 0, 255);
		// SDL_RenderClear(w->rdr);
		// write(1, "ok", 2);
		// SDL_UpdateTexture(w->txtr, NULL, w->pix, WIDTH * sizeof(Uint32));
		// SDL_RenderCopy(w->rdr, w->txtr, NULL, NULL);

		SDL_Delay(16);
	}

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

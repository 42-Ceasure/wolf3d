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
	while (SDL_PollEvent(&w->event) != -1)
	{
		if (w->event.type == SDL_KEYDOWN)
			key_events(w);
		if (w->event.type == SDL_MOUSEMOTION)
			motion_events(w);
		if (w->event.type == SDL_MOUSEBUTTONDOWN)
			button_events(w);
		and_there_was_light(w); 
	}

}

void init_player(t_env *w)
{
	w->posx = 2;
	w->posy = 2;
	w->dirx = -1;
	w->diry = 0;
	w->planx = 0;
	w->plany = 0.66;
	w->ptime = 0;
	w->otime = 0;
	w->wscr = WIDTH;
	w->hscr = HEIGHT;
}

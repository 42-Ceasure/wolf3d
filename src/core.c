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
	if (MOTION.xrel < 0)
	{
		turn_left(w);
		MOTION.x = WIDTH/2;
		MOTION.y = HEIGHT/2;
	}
	if (MOTION.xrel > 0)
	{
		turn_right(w);
		MOTION.x = WIDTH/2;
		MOTION.y = HEIGHT/2;
	}
}

void		key_events(t_env *w)
{
	if (KEY == 27)
		exit_game(w);
	if (KEY == 119)
		mv_forward(w);
	if (KEY == 115)
		mv_backward(w);
	if (KEY == 97)
		mv_left(w);
	if (KEY == 100)
		mv_right(w);
	if (KEY == 113)
		turn_left(w);
	if (KEY == 101)
		turn_right(w);
		ft_putnbr(KEY);
		ft_putchar('\n');
}

void dance(t_env *w)
{
	t_ray 	*r;

	r = (t_ray *)malloc(sizeof(t_ray));
	while(1)
	{
		while (SDL_PollEvent(&w->event))
		{
			if (w->event.type == SDL_KEYDOWN)
				key_events(w);
			if (w->event.type == SDL_MOUSEMOTION)
				motion_events(w);
			if (w->event.type == SDL_MOUSEBUTTONDOWN)
				button_events(w);
			and_there_was_light(w, r);
		}
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

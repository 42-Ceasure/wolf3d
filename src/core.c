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
		MOTION.xrel = WIDTH/2;
		MOTION.yrel = HEIGHT/2;
	}
}

void		key_events(t_env *w)
{
	if (w->inkeys[SDL_SCANCODE_P])
		init_player(w);
	if (w->inkeys[SDL_SCANCODE_W])
		mv_forward(w);
	if (w->inkeys[SDL_SCANCODE_S])
		mv_backward(w);
	if (w->inkeys[SDL_SCANCODE_A])
		mv_left(w);
	if (w->inkeys[SDL_SCANCODE_D])
		mv_right(w);
	if (w->inkeys[SDL_SCANCODE_LEFT])
		turn_left(w);
	if (w->inkeys[SDL_SCANCODE_RIGHT])
		turn_right(w);
}

void hipressfps(t_env *w)
{
	double fps;

	w->otime = w->time;
	w->time = SDL_GetTicks();
	fps = (w->time - w->otime) / 1000.0;
	w->movspeed = fps * 4.0;
	w->rotspeed = fps * 1.6;
	// if (1.0 / fps > 30)
		SDL_Delay(20);
	// printf("%lf\n", (1.0 / fps));
}

void dance(t_env *w, t_ray *r)
{
	while (1)
	{
		while (SDL_PollEvent(&w->event))
		{
			if (w->event.type == SDL_KEYDOWN)
				if (KEY == 27)
					exit_game(w);
			if (w->event.type == SDL_MOUSEMOTION)
				motion_events(w);
		}
		and_there_was_light(w, r);
		hipressfps(w);
		SDL_RenderPresent(w->rdr);
		SDL_SetRenderDrawColor(w->rdr, r->c_r, r->c_g, r->c_b, 255);
		SDL_RenderClear(w->rdr);
		w->inkeys = SDL_GetKeyboardState(NULL);
		key_events(w);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/06/03 20:59:35 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"
#include "../lib/colors.h"

void		motion_events(t_env *w)
{
	if (MOTION.xrel < 0)
	{
		turn_left(w);
		MOTION.x = WIDTH / 2;
		MOTION.y = HEIGHT / 2;
	}
	if (MOTION.xrel > 0)
	{
		turn_right(w);
		MOTION.xrel = WIDTH / 2;
		MOTION.yrel = HEIGHT / 2;
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
	if (w->inkeys[SDL_SCANCODE_LSHIFT])
		mv_forward(w);
}

void		hipressfps(t_env *w)
{
	double	fps;

	w->otime = w->time;
	w->time = SDL_GetTicks();
	fps = (w->time - w->otime) / 1000.0;
	w->movspeed = fps * 4.0;
	w->rotspeed = fps * 1.6;
	SDL_Delay(16);
}

void		dance(t_env *w, t_ray *r)
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
		SDL_UpdateTexture(w->txtr, NULL, w->pix, WIDTH * sizeof(Uint32));
		SDL_RenderCopy(w->rdr, w->txtr, NULL, NULL);
		SDL_RenderPresent(w->rdr);
		w->inkeys = SDL_GetKeyboardState(NULL);
		key_events(w);
	}
}

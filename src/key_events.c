/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/06/03 21:02:43 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"
#include "../lib/colors.h"

void		mv_right(t_env *w)
{
	int		x;
	int		y;

	x = (int)(w->posx + w->planx * PMSP);
	y = (int)(w->posy + w->plany * PMSP);
	if (w->map[x][(int)w->posy] == 0)
		w->posx += w->planx * PMSP;
	if (w->map[(int)w->posx][y] == 0)
		w->posy += w->plany * PMSP;
}

void		mv_left(t_env *w)
{
	int		x;
	int		y;

	x = (int)(w->posx - w->planx * PMSP);
	y = (int)(w->posy - w->plany * PMSP);
	if (w->map[x][(int)w->posy] == 0)
		w->posx -= w->planx * PMSP;
	if (w->map[(int)w->posx][y] == 0)
		w->posy -= w->plany * PMSP;
}

void		mv_backward(t_env *w)
{
	int		x;
	int		y;

	x = (int)(w->posx - w->dirx * PMSP);
	y = (int)(w->posy - w->diry * PMSP);
	if (w->map[x][(int)w->posy] == 0)
		w->posx -= w->dirx * PMSP;
	if (w->map[(int)w->posx][y] == 0)
		w->posy -= w->diry * PMSP;
}

void		mv_forward(t_env *w)
{
	int		x;
	int		y;

	x = (int)(w->posx + w->dirx * PMSP);
	y = (int)(w->posy + w->diry * PMSP);
	if (w->map[x][(int)w->posy] == 0)
		w->posx += w->dirx * PMSP;
	if (w->map[(int)w->posx][y] == 0)
		w->posy += w->diry * PMSP;
}

void		exit_game(t_env *w)
{
	free(w);
	SDL_Quit();
	exit(1);
}

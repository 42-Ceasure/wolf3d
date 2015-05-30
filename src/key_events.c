/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/19 17:20:42 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"

void turn_right(t_env *w)
{
	double tmpx;
	double tmpp;

	tmpx = w->dirx;
	tmpp = w->planx;
	w->dirx = w->dirx * cos(-M_PI/90) - w->diry * sin(-M_PI/90);
	w->diry = tmpx * sin(-M_PI/90) + w->diry * cos(-M_PI/90);
	w->planx = w->planx * cos(-M_PI/90) - w->plany * sin(-M_PI/90);
	w->plany = tmpp * sin(-M_PI/90) + w->plany * cos(-M_PI/90);
}

void turn_left(t_env *w)
{
	double tmpx;
	double tmpp;

	tmpx = w->dirx;
	tmpp = w->planx;
	w->dirx = w->dirx * cos(M_PI/90) - w->diry * sin(M_PI/90);
	w->diry = tmpx * sin(M_PI/90) + w->diry * cos(M_PI/90);
	w->planx = w->planx * cos(M_PI/90) - w->plany * sin(M_PI/90);
	w->plany = tmpp * sin(M_PI/90) + w->plany * cos(M_PI/90);
}

void mv_right(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx + w->diry * 0.3);
	y = (int)(w->posy + w->dirx * 0.3);
	if (w->map[x][(int)w->posy] == 0)
		w->posx += w->diry * 0.3;
	if (w->map[(int)w->posx][y] == 0)
		w->posy -= w->dirx * 0.3;
}

void mv_left(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx - w->diry * 0.3);
	y = (int)(w->posy - w->dirx * 0.3);
	if (w->map[(int)w->posx][y] == 0)
		w->posx -= w->diry * 0.3;
	if (w->map[x][(int)w->posy] == 0)
		w->posy += w->dirx * 0.3;
}

void mv_backward(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx - w->dirx * 0.3);
	y = (int)(w->posy - w->diry * 0.3);
	if (w->map[x][(int)w->posy] == 0)
		w->posx -= w->dirx * 0.3;
	if (w->map[(int)w->posx][y] == 0)
		w->posy -= w->diry * 0.3;
}

void mv_forward(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx + w->dirx * 0.3);
	y = (int)(w->posy + w->diry * 0.3);
	if (w->map[x][(int)w->posy] == 0)
		w->posx += w->dirx * 0.3;
	if (w->map[(int)w->posx][y] == 0)
		w->posy += w->diry * 0.3;
}

void exit_game(t_env *w)
{
	free(w);
	SDL_Quit();
	exit(1);
}

	
// if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;

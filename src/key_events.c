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
	w->dirx = w->dirx * cos(-ROT) - w->diry * sin(-ROT);
	w->diry = tmpx * sin(-ROT) + w->diry * cos(-ROT);
	w->planx = w->planx * cos(-ROT) - w->plany * sin(-ROT);
	w->plany = tmpp * sin(-ROT) + w->plany * cos(-ROT);
}

void turn_left(t_env *w)
{
	double tmpx;
	double tmpp;

	tmpx = w->dirx;
	tmpp = w->planx;
	w->dirx = w->dirx * cos(ROT) - w->diry * sin(ROT);
	w->diry = tmpx * sin(ROT) + w->diry * cos(ROT);
	w->planx = w->planx * cos(ROT) - w->plany * sin(ROT);
	w->plany = tmpp * sin(ROT) + w->plany * cos(ROT);
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

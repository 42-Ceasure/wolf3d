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
	w->dirx = w->dirx * cos(-M_PI/24) - w->diry * sin(-M_PI/24);
	w->diry = tmpx * sin(-M_PI/24) + w->diry * cos(-M_PI/24);
	w->planx = w->planx * cos(-M_PI/24) - w->plany * sin(-M_PI/24);
	w->plany = tmpp * sin(-M_PI/24) + w->plany * cos(-M_PI/24);
}

void turn_left(t_env *w)
{
	double tmpx;
	double tmpp;

	tmpx = w->dirx;
	tmpp = w->planx;
	w->dirx = w->dirx * cos(M_PI/24) - w->diry * sin(M_PI/24);
	w->diry = tmpx * sin(M_PI/24) + w->diry * cos(M_PI/24);
	w->planx = w->planx * cos(M_PI/24) - w->plany * sin(M_PI/24);
	w->plany = tmpp * sin(M_PI/24) + w->plany * cos(M_PI/24);
}

void mv_right(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx + w->diry/* * mspeed*/);
	y = (int)(w->posy + w->dirx/* * mspeed*/);
	if (w->map[x][(int)w->posy] == 0)
		w->posx += w->diry/* * mspeed*/;
	if (w->map[(int)w->posx][y] == 0)
		w->posy -= w->dirx/* * mspeed*/;
}

void mv_left(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx - w->diry/* * mspeed*/);
	y = (int)(w->posy - w->dirx/* * mspeed*/);
	if (w->map[(int)w->posx][y] == 0)
		w->posx -= w->diry/* * mspeed*/;
	if (w->map[x][(int)w->posy] == 0)
		w->posy += w->dirx/* * mspeed*/;
}

void mv_backward(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx - w->dirx/* * mspeed*/);
	y = (int)(w->posy - w->diry/* * mspeed*/);
	if (w->map[x][(int)w->posy] == 0)
		w->posx -= w->dirx/* * mspeed*/;
	if (w->map[(int)w->posx][y] == 0)
		w->posy -= w->diry/* * mspeed*/;
}

void mv_forward(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx + w->dirx/* * mspeed*/);
	y = (int)(w->posy + w->diry/* * mspeed*/);
	if (w->map[x][(int)w->posy] == 0)
		w->posx += w->dirx/* * mspeed*/;
	if (w->map[(int)w->posx][y] == 0)
		w->posy += w->diry/* * mspeed*/;
}

void exit_game(t_env *w)
{
	free(w);
	SDL_Quit();
	exit(1);
}

	
// if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;

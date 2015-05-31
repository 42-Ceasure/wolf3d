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
	w->dirx = w->dirx * cos(-PROT) - w->diry * sin(-PROT);
	w->diry = tmpx * sin(-PROT) + w->diry * cos(-PROT);
	w->planx = w->planx * cos(-PROT) - w->plany * sin(-PROT);
	w->plany = tmpp * sin(-PROT) + w->plany * cos(-PROT);
}

void turn_left(t_env *w)
{
	double tmpx;
	double tmpp;

	tmpx = w->dirx;
	tmpp = w->planx;
	w->dirx = w->dirx * cos(PROT) - w->diry * sin(PROT);
	w->diry = tmpx * sin(PROT) + w->diry * cos(PROT);
	w->planx = w->planx * cos(PROT) - w->plany * sin(PROT);
	w->plany = tmpp * sin(PROT) + w->plany * cos(PROT);
}

void mv_right(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx + w->diry * PMSP);
	y = (int)(w->posy + w->dirx * PMSP);
	if (w->map[x][(int)w->posy] == 0)
		w->posx += w->diry * PMSP;
	if (w->map[(int)w->posx][y] == 0)
		w->posy -= w->dirx * PMSP;
}

void mv_left(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx - w->diry * PMSP);
	y = (int)(w->posy - w->dirx * PMSP);
	if (w->map[(int)w->posx][y] == 0)
		w->posx -= w->diry * PMSP;
	if (w->map[x][(int)w->posy] == 0)
		w->posy += w->dirx * PMSP;
}

void mv_backward(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx - w->dirx * PMSP);
	y = (int)(w->posy - w->diry * PMSP);
	if (w->map[x][(int)w->posy] == 0)
		w->posx -= w->dirx * PMSP;
	if (w->map[(int)w->posx][y] == 0)
		w->posy -= w->diry * PMSP;
}

void mv_forward(t_env *w)
{
	int x;
	int y;

	x = (int)(w->posx + w->dirx * PMSP);
	y = (int)(w->posy + w->diry * PMSP);
	if (w->map[x][(int)w->posy] == 0)
		w->posx += w->dirx * PMSP;
	if (w->map[(int)w->posx][y] == 0)
		w->posy += w->diry * PMSP;
}

void exit_game(t_env *w)
{
	free(w);
	SDL_Quit();
	exit(1);
}

	
// if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;

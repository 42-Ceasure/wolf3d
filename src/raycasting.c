/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/19 17:20:42 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"

void 		and_there_was_light(t_env *w)
{
	int 	x;
	double 	camerax; 
	double 	rayposx;
	double 	rayposy;
	double 	raydirx;
	double 	raydiry;
	
	int 	mapx;
	int 	mapy;
	double 	sdstx;		// side dist x;
	double 	sdsty;		// side dist y;
	double 	ddstx;		// delta dist x;
	double 	ddsty;		// delta dist y;
	double 	pwalldst;	// perpendiculaire wall distance, to lenght of ray;
	int 	stepx;
	int 	stepy;
	int 	hit;
	int		side;

	int 	lheight;
	int 	drawstart;
	int 	drawend;

	x = 0;
	while (x < w->wscr)
	{
		camerax = 2 * x / (double)w->wscr - 1;
		rayposx = w->posx;
		rayposy = w->posy;
		raydirx = w->dirx + w->planx * camerax;
		raydiry = w->diry + w->plany * camerax;
		mapx = (int)rayposx;
		mapy = (int)rayposy;
		ddstx = sqrt(1 + (raydiry * raydiry) / (raydirx * raydirx));
		ddsty = sqrt(1 + (raydirx * raydirx) / (raydiry * raydiry));
		hit = 0;
		if (raydirx < 0)
		{
			stepx = -1;
			sdstx = (rayposx - mapx) * ddstx;
		}
		else
		{
			stepx = 1;
			sdstx = (mapx + 1.0 - rayposx) * ddstx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sdsty = (rayposy - mapy) * ddsty;
		}
		else
		{
			stepy = 1;
			sdsty = (mapy + 1.0 - rayposy) * ddsty;
		}
		while (hit == 0)
		{
			if (sdstx < sdsty)
			{
				sdstx += ddstx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sdsty += ddsty;
				mapy += stepy;
				side = 1;
			}
			if (w->map[mapx][mapy] > 0)
				hit = 1;
		}
		if (side == 0)
			pwalldst = fabs((mapx - rayposx + (1 - stepx) / 2) / raydirx);
		else
			pwalldst = fabs((mapy - rayposy + (1 - stepy) / 2) / raydiry);
		lheight = abs((int)(w->hscr / pwalldst));
		drawstart = -lheight / 2 + w->hscr / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = lheight / 2 + w->hscr / 2;
		if (drawend >= w->hscr)
			drawend = w->hscr - 1;
		// ColorRGB color;
		// switch(w->map[mapx][mapy])
		// {
		// case 1:  color = RGB_Red;  break; //red
		// case 2:  color = RGB_Green;  break; //green
		// case 3:  color = RGB_Blue;   break; //blue
		// case 4:  color = RGB_White;  break; //white
		// default: color = RGB_Yellow; break; //yellow
		// }
		// if (side == 1) {color = color / 2;}
		// verLine(x, drawStart, drawEnd, color);
	}
}
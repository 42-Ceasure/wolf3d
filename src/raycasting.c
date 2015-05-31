/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/06/01 01:46:19 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"

Uint32 color(int r, int g, int b)
{ 
	return (((((r << 8) + g) << 8)+ b));
}

void trace(t_ray *r, int y1, int y2, t_env *w)
{
	int y;

	y = 0;
	while (y < y1 && y < 150)
	{
		w->pix[r->x + (y * WIDTH)] = color((169 - y * 169/150), (208 - y * 81/150), 255);
		y++; 							//   0  127  254
	}
	while (y < y1)
	{
		w->pix[r->x + (y * WIDTH)] = color(0, 127, 255);
		y++; 							//   0  127  254
	}
	while (y <= y2)
	{
		w->pix[r->x + (y * WIDTH)] = color(r->c_r, r->c_g, r->c_b);
		y++;
	}
	while (y > y2 && y < 350)
	{
		w->pix[r->x + (y * WIDTH)] = color(159 - y * 101/350, 232 - y * 75/350, 85 - y * 50/350);// 103-159-90-vertmousse 159-232-85-vertannis
		y++; 							// 58, 157, 35
	}
	while (y > y2 && y < WIDTH)
	{
		w->pix[r->x + (y * WIDTH)] = color(58, 157, 35);// 103-159-90-vertmousse 159-232-85-vertannis
		y++; 							// 58, 157, 35
	}
}

void 		and_there_was_light(t_env *w, t_ray *r)
{
	r->x = 0;
	while (r->x < w->wscr)
	{
		r->camerax = 2 * r->x / (double)w->wscr - 1;
		r->rayposx = w->posx;
		r->rayposy = w->posy;
		r->raydirx = (w->dirx) + (w->planx) * (r->camerax);
		r->raydiry = (w->diry) + (w->plany) * (r->camerax);
		r->mapx = (int)(r->rayposx);
		r->mapy = (int)(r->rayposy);
		r->ddstx = sqrt(1 + (r->raydiry * r->raydiry) / (r->raydirx * r->raydirx));
		r->ddsty = sqrt(1 + (r->raydirx * r->raydirx) / (r->raydiry * r->raydiry));
		r->hit = 0;
		if (r->raydirx < 0)
		{
			r->stepx = -1;
			r->sdstx = (r->rayposx - r->mapx) * r->ddstx;
		}
		else
		{
			r->stepx = 1;
			r->sdstx = (r->mapx + 1.0 - r->rayposx) * r->ddstx;
		}
		if (r->raydiry < 0)
		{
			r->stepy = -1;
			r->sdsty = (r->rayposy - r->mapy) * r->ddsty;
		}
		else
		{
			r->stepy = 1;
			r->sdsty = (r->mapy + 1.0 - r->rayposy) * r->ddsty;
		}
		while (r->hit == 0)
		{
			if (r->sdstx < r->sdsty)
			{
				r->sdstx += r->ddstx;
				r->mapx += r->stepx;
				r->side = 0;
			}
			else
			{
				r->sdsty += r->ddsty;
				r->mapy += r->stepy;
				r->side = 1;
			}
			if (w->map[r->mapx][r->mapy] > 0)
				r->hit = 1;
		}
		if (r->side == 0)
			r->pwalldst = fabs((r->mapx - r->rayposx + (1 - r->stepx) / 2) / r->raydirx);
		else
			r->pwalldst = fabs((r->mapy - r->rayposy + (1 - r->stepy) / 2) / r->raydiry);
		r->lheight = abs((int)(w->hscr / r->pwalldst));
		r->drawstart = -(r->lheight) / 2 + w->hscr / 2;
		if (r->drawstart < 0)
			r->drawstart = 0;
		r->drawend = r->lheight / 2 + w->hscr / 2;
		if (r->drawend >= w->hscr)
			r->drawend = w->hscr - 1;
		switch(w->map[r->mapx][r->mapy])
		{
			case 1:
				r->c_r = 0xBB;
				r->c_g = 0xAE;
				r->c_b = 0x98;
				break;
			case 2:
				r->c_r = 0x5B;
				r->c_g = 0x3C;
				r->c_b = 0x11;
				break;
			case 3:
				r->c_r = 0x09;
				r->c_g = 0x52;
				r->c_b = 0x28;
				break;
			case 4:
				
				r->c_r = 0x84;
				r->c_g = 0x2E;
				r->c_b = 0x1B;
				break;
			default:
				r->c_r = 0xC6;
				r->c_g = 0x08;
				r->c_b = 0x00;
				break;
			}
			if (r->side == 1)
		{
			r->c_r /= 2;
			r->c_g /= 2;
			r->c_b /= 2;
		}
		trace(r, r->drawstart, r->drawend, w);
		r->x++;
	}
}
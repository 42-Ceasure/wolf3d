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

void trace(t_ray *r, int y1, int y2, t_env *w)
{
	SDL_SetRenderDrawColor(w->rdr, r->c_r, r->c_g, r->c_b, 100);
	SDL_RenderDrawLine(w->rdr, r->x, y1, r->x, y2); 
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
				r->c_r = 0xFF;
				r->c_g = 0x00;
				r->c_b = 0x00;
				break;
			case 2:
				r->c_r = 0x00;
				r->c_g = 0xFF;
				r->c_b = 0x00;
				break;
			case 3:
				r->c_r = 0x00;
				r->c_g = 0x00;
				r->c_b = 0xFF;
				break;
			case 4:
				r->c_r = 0xFF;
				r->c_g = 0xFF;
				r->c_b = 0xFF;
				break;
			default:
				r->c_r = 0xFF;
				r->c_g = 0xFF;
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
	// w->otime = w->time;
	// time = 
	// SDL_UpdateTexture(w->txtr, NULL, w->pix, WIDTH * sizeof(Uint32));
	// SDL_RenderCopy(w->rdr, w->txtr, NULL, NULL);
	SDL_RenderPresent(w->rdr);
	SDL_Delay(8);
	ft_bzero(w->pix, sizeof(Uint32) * WIDTH * HEIGHT);
	SDL_SetRenderDrawColor(w->rdr, 0, 0, 0, 255);
	SDL_RenderClear(w->rdr);
}
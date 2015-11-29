/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/06/03 22:26:23 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"
#include "../lib/colors.h"

static void		cross(t_env *w, t_ray *r)
{
	r->y = 0;
	w->pix[WIDTH / 2 - 5 + (HEIGHT / 2 - 1) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 - 5 + HEIGHT / 2 * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 - 4 + (HEIGHT / 2 - 1) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 - 4 + HEIGHT / 2 * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 - 3 + (HEIGHT / 2 - 1) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 - 3 + HEIGHT / 2 * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 - 1 + (HEIGHT / 2 - 5) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 - 1 + (HEIGHT / 2 - 4) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 - 1 + (HEIGHT / 2 - 3) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + (HEIGHT / 2 - 5) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + (HEIGHT / 2 - 4) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + (HEIGHT / 2 - 3) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 - 1 + (HEIGHT / 2 + 2) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 - 1 + (HEIGHT / 2 + 3) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 - 1 + (HEIGHT / 2 + 4) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + (HEIGHT / 2 + 2) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + (HEIGHT / 2 + 3) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + (HEIGHT / 2 + 4) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + 2 + (HEIGHT / 2 - 1) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + 2 + HEIGHT / 2 * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + 3 + (HEIGHT / 2 - 1) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + 3 + HEIGHT / 2 * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + 4 + (HEIGHT / 2 - 1) * WIDTH] = color(r, BLANC);
	w->pix[WIDTH / 2 + 4 + HEIGHT / 2 * WIDTH] = color(r, BLANC);
}

static void		wall(t_ray *r, int y1, int y2, t_env *w)
{
	int			d;

	r->y = y1;
	while (r->y < y2)
	{
		d = r->y * 256 - HEIGHT * 128 + r->lheight * 128;
		r->texy = ((d * 64) / r->lheight) / 256;
		r->color = color(r, w->tmp[64 * r->texy + r->texx]);
		w->pix[r->x + (r->y * WIDTH)] = r->color;
		r->y++;
	}
}

void			fond(t_ray *r)
{
	if (r->side == 0 && r->raydirx > 0)
	{
		r->floorxwall = r->mapx;
		r->floorywall = r->mapy + r->wallx;
	}
	else if (r->side == 0 && r->raydirx < 0)
	{
		r->floorxwall = r->mapx + 1.0;
		r->floorywall = r->mapy + r->wallx;
	}
	else if (r->side == 1 && r->raydiry > 0)
	{
		r->floorxwall = r->mapx + r->wallx;
		r->floorywall = r->mapy;
	}
	else
	{
		r->floorxwall = r->mapx + r->wallx;
		r->floorywall = r->mapy + 1.0;
	}
	r->distwall = r->pwalldst;
	r->distplayer = 0.0;
	if (r->drawend < 0)
		r->drawend = HEIGHT;
	r->y = r->drawend + 1;
}

void			fond2(t_ray *r, t_env *w)
{
	while (r->y < HEIGHT)
	{
		r->currentdist = HEIGHT / (2.0 * r->y - HEIGHT);
		r->weight = (r->currentdist - r->distplayer)
					/ (r->distwall - r->distplayer);
		r->cfloorx = r->weight * r->floorxwall + (1.0 - r->weight) * w->posx;
		r->cfloory = r->weight * r->floorywall + (1.0 - r->weight) * w->posy;
		r->ftexx = (int)(r->cfloorx * TEXWH) % TEXWH;
		r->ftexy = (int)(r->cfloory * TEXWH) % TEXWH;
		w->pix[r->x + (r->y * WIDTH)] =
						(w->sol[TEXWH * r->ftexy + r->ftexx] >> 1) & 8355711;
		w->pix[r->x + ((HEIGHT - r->y) * WIDTH)] =
						w->sky[TEXWH * r->ftexy + r->ftexx];
		r->y++;
	}
	
}

void			trace(t_ray *r, int y1, int y2, t_env *w)
{
	wall(r, y1, y2, w);
	fond(r);
	fond2(r, w);
	cross(w, r);
}

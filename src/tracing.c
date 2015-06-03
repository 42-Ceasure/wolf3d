/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/06/01 04:03:43 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"
#include "../lib/colors.h"

static void cross(t_env *w, t_ray *r)
{
	r->y = 0;
	w->pix[355 + 201 * WIDTH] = color(r, BLANC);
	w->pix[355 + 202 * WIDTH] = color(r, BLANC);
	w->pix[356 + 201 * WIDTH] = color(r, BLANC);
	w->pix[356 + 202 * WIDTH] = color(r, BLANC);
	w->pix[357 + 201 * WIDTH] = color(r, BLANC);
	w->pix[357 + 202 * WIDTH] = color(r, BLANC);
	w->pix[359 + 197 * WIDTH] = color(r, BLANC);
	w->pix[359 + 198 * WIDTH] = color(r, BLANC);
	w->pix[359 + 199 * WIDTH] = color(r, BLANC);
	w->pix[360 + 197 * WIDTH] = color(r, BLANC);
	w->pix[360 + 198 * WIDTH] = color(r, BLANC);
	w->pix[360 + 199 * WIDTH] = color(r, BLANC);
	w->pix[359 + 204 * WIDTH] = color(r, BLANC);
	w->pix[359 + 205 * WIDTH] = color(r, BLANC);
	w->pix[359 + 206 * WIDTH] = color(r, BLANC);
	w->pix[360 + 204 * WIDTH] = color(r, BLANC);
	w->pix[360 + 205 * WIDTH] = color(r, BLANC);
	w->pix[360 + 206 * WIDTH] = color(r, BLANC);
	w->pix[362 + 201 * WIDTH] = color(r, BLANC);
	w->pix[362 + 202 * WIDTH] = color(r, BLANC);
	w->pix[363 + 201 * WIDTH] = color(r, BLANC);
	w->pix[363 + 202 * WIDTH] = color(r, BLANC);
	w->pix[364 + 201 * WIDTH] = color(r, BLANC);
	w->pix[364 + 202 * WIDTH] = color(r, BLANC);
}

static void wall(t_ray *r, int y1, int y2, t_env *w)
{
	// r->y = y1;
	// if (y2 > HEIGHT)
	// 	y2 = HEIGHT;
	// if (r->y < 0)
	// 	r->y = 0;
	// r->start = r->y;
	// r->stop = y2;
	// while (r->y <= y2)
	// {
	// 	w->pix[r->x + (r->y * WIDTH)] = c2colorw(r, r->color2, r->color, w);

	// 	r->y++;
	// }
	int d;

	r->y = y1;
	while (r->y < y2)
	{
		d = r->y * 256 - HEIGHT * 128 + r->lheight * 128;
		r->texy = ((d * 64) / r->lheight) / 256;
		r->color = w->mur[64 * r->texy + r->texx];
		if(r->side == 1) 
			r->color = (r->color >> 1) & 8355711;
		w->pix[r->x + (r->y * WIDTH)] = r->color;
		r->y++;
	}
}

void fond(t_ray *r, t_env *w)
{
	// r->y = 0;
	// r->start = 0;
	// r->stop = 150;
	// while (r->y < r->stop)
	// {
	// 	w->pix[r->x + (r->y * WIDTH)] = color2color(r, AZUR, AZURIN);
	// 	r->y++;
	// }
	// r->start = 150;
	// r->stop = 202;
	// while (r->y < r->stop)
	// {
	// 	w->pix[r->x + (r->y * WIDTH)] = color(r, AZURIN);
	// 	r->y++;
	// }
	// r->start = 202;
	// r->stop = HEIGHT;
	// while (r->y < r->stop)
	// {
	// 	w->pix[r->x + (r->y * WIDTH)] = color2color(r, VERTGAZON, VERTDEHOOKER);
	// 	r->y++;
	// }
	int y;

	y = 0;
	r->y = 0;
	while (r->y < 200)
	{
		w->pix[r->x + (r->y * WIDTH)] = w->sky[r->x + (r->y * WIDTH)];
		r->y++;
	}
	while (r->y < 405)
	{
		w->pix[r->x + (r->y * WIDTH)] = w->sol[r->x + (y * 768)];
		y++;
		r->y++;
	}
}

void 		trace(t_ray *r, int y1, int y2, t_env *w)
{
	fond(r, w);
	wall(r, y1, y2, w);
	cross(w, r);
}

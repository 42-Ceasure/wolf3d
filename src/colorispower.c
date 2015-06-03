/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorispower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/06/03 21:20:31 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"
#include "../lib/colors.h"

Uint32		color(t_ray *r, Uint32 color1)
{
	Uint8	a;
	Uint8	ro;
	Uint8	g;
	Uint8	b;

	a = (color1 & 0xFF000000) >> 24;
	ro = (color1 & 0x00FF0000) >> 16;
	g = (color1 & 0x0000FF00) >> 8;
	b = (color1 & 0x000000FF);
	if (r->side == 1 && r->y > r->drawstart)
	{
		a = 0x00;
		ro /= 1.2;
		g /= 1.2;
		b /= 1.2;
	}
	return ((((((a << 8) + ro) << 8) + g) << 8) + b);
}

Uint32		color2color(t_ray *r, Uint32 color1, Uint32 color2)
{
	Uint8	a;
	Uint8	ro;
	Uint8	g;
	Uint8	b;

	r->c_a1 = (color1 & 0xFF000000) >> 24;
	r->c_r1 = (color1 & 0x00FF0000) >> 16;
	r->c_g1 = (color1 & 0x0000FF00) >> 8;
	r->c_b1 = (color1 & 0x000000FF);
	r->c_a2 = (color2 & 0xFF000000) >> 24;
	r->c_r2 = (color2 & 0x00FF0000) >> 16;
	r->c_g2 = (color2 & 0x0000FF00) >> 8;
	r->c_b2 = (color2 & 0x000000FF);
	a = 0;
	ro = r->c_r1 + (r->y - r->start) *
		(r->c_r2 - r->c_r1) / (r->stop - r->start);
	g = r->c_g1 + (r->y - r->start) *
		(r->c_g2 - r->c_g1) / (r->stop - r->start);
	b = r->c_b1 + (r->y - r->start) *
		(r->c_b2 - r->c_b1) / (r->stop - r->start);
	return ((((((a << 8) + ro) << 8) + g) << 8) + b);
}

Uint32		c2colorw(t_ray *r, Uint32 color1, Uint32 color2)
{
	Uint8	a;
	Uint8	ro;
	Uint8	g;
	Uint8	b;
	double	cren;

	cren = (r->y - (double)(int)r->y);
	cren *= 100;
	r->c_a1 = (color1 & 0xFF000000) >> 24;
	r->c_r1 = (color1 & 0x00FF0000) >> 16;
	r->c_g1 = (color1 & 0x0000FF00) >> 8;
	r->c_b1 = (color1 & 0x000000FF);
	r->c_a2 = (color2 & 0xFF000000) >> 24;
	r->c_r2 = (color2 & 0x00FF0000) >> 16;
	r->c_g2 = (color2 & 0x0000FF00) >> 8;
	r->c_b2 = (color2 & 0x000000FF);
	a = 0;
	ro = (r->c_r2 * cren / 100) + ((r->c_r1 * (100 - cren)) / 100);
	g = (r->c_g2 * cren / 100) + ((r->c_g1 * (100 - cren)) / 100);
	b = (r->c_b2 * cren / 100) + ((r->c_b1 * (100 - cren)) / 100);
	return ((((((a << 8) + ro) << 8) + g) << 8) + b);
}

void		test_texture(t_env *w, t_ray *r)
{
	if (w->map[r->mapx][r->mapy] == 1)
		w->tmp = w->mur1;
	else if (w->map[r->mapx][r->mapy] == 2)
		w->tmp = w->mur2;
	else if (w->map[r->mapx][r->mapy] == 3)
		w->tmp = w->mur3;
	else if (w->map[r->mapx][r->mapy] == 4)
		w->tmp = w->mur4;
	else if (w->map[r->mapx][r->mapy] == 5)
		w->tmp = w->mur5;
	else if (w->map[r->mapx][r->mapy] == 6)
		w->tmp = w->wood;
}

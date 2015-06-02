/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:12:35 by cglavieu          #+#    #+#             */
/*   Updated: 2015/06/01 04:03:43 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"
#include "../lib/colors.h"

static void tres(t_env *w, t_ray *r)
{
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
	r->drawend = r->lheight / 2 + w->hscr / 2;
}

static void dos(t_ray *r)
{
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
}

static void uno(t_env *w, t_ray *r)
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
}

void 		and_there_was_light(t_env *w, t_ray *r)
{
	r->x = 0;
	while (r->x < w->wscr)
	{
		// ft_putendl("1");
		uno(w, r);
		// ft_putendl("2");
		dos(r);
		// ft_putendl("3");
		tres(w, r);
		// ft_putendl("4");
		test_couleur(w, r);
		// ft_putendl("5");
		trace(r, r->drawstart, r->drawend, w);
		// ft_putendl("6");
		r->x++;
		// ft_putendl("7");
	}
}
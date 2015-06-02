/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 04:42:57 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/23 07:03:49 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/wolf3d.h"
#include "../lib/colors.h"

void 		turn_right(t_env *w)
{
	double 	tmpx;
	double 	tmpp;

	tmpx = w->dirx;
	tmpp = w->planx;
	w->dirx = w->dirx * cos(-PROT) - w->diry * sin(-PROT);
	w->diry = tmpx * sin(-PROT) + w->diry * cos(-PROT);
	w->planx = w->planx * cos(-PROT) - w->plany * sin(-PROT);
	w->plany = tmpp * sin(-PROT) + w->plany * cos(-PROT);
}

void 		turn_left(t_env *w)
{
	double 	tmpx;
	double 	tmpp;

	tmpx = w->dirx;
	tmpp = w->planx;
	w->dirx = w->dirx * cos(PROT) - w->diry * sin(PROT);
	w->diry = tmpx * sin(PROT) + w->diry * cos(PROT);
	w->planx = w->planx * cos(PROT) - w->plany * sin(PROT);
	w->plany = tmpp * sin(PROT) + w->plany * cos(PROT);
}

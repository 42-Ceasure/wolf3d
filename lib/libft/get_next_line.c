/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 16:34:01 by cglavieu          #+#    #+#             */
/*   Updated: 2015/05/18 19:02:45 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

static	char	*ft_line(char *s)
{
	int			i;
	char		*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	str = ft_strnew(i);
	ft_strncpy(str, s, i);
	str[i] = '\0';
	return (str);
}

static	char	*ft_stock(char *s)
{
	int			i;
	char		*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	str = ft_strdup(s + i + 1);
	ft_strdel(&s);
	return (str);
}

void			ft_del(char **buff, char **line, char **svg, int ret)
{
	ft_strdel(buff);
	*line = ft_line(*svg);
	if (ret == 0)
		ft_strdel(svg);
}

int				get_next_line(int const fd, char **line)
{
	int			ret;
	char		*tmp;
	static char	*svg;
	char		*buff;

	buff = ft_strnew(BUFF_SIZE + 1);
	svg = (svg == NULL) ? ft_strnew(1) : svg;
	if (buff == NULL || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	ret = 42;
	while ((ft_strchr(svg, '\n') == NULL) && ret > 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		tmp = svg;
		svg = ft_strjoin(svg, buff);
		ft_strdel(&tmp);
		buff[ret] = '\0';
	}
	ft_del(&buff, line, &svg, ret);
	if (ret == 0)
		return (0);
	svg = ft_stock(svg);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:26:19 by loamar            #+#    #+#             */
/*   Updated: 2020/06/16 02:58:37 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char		*get_cub_string(char **argv, int index)
{
	int		fd;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	char	*str;
	int		ret;

	str = ft_strdup("\0");
	fd = open(argv[index], O_RDONLY);
	if (fd < 0 || !argv[1] || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
	{
		free(str);
		return (NULL);
	}
	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (str);
}

int				fill_map(t_map *map, char *str_cub, int index)
{
	int		check;

	check = index;
	index += ft_nowhitespace(str_cub, index, map, 1);
	if (check_map_param(str_cub, index) == 1)
	{
		check = index;
		index += ft_get_my_ticket(map, str_cub, index);
		if (check == index)
			return (0);
		index += ft_nowhitespace(str_cub, index, map, 2);
		if (map->error == 1)
			return (0);
		else
		{
			size_and_param(map, str_cub, index);
			index += (map->size + map->size_space + map->size2 - 1);
			index += ft_nowhitespace(str_cub, index, map, 1);
			return (index);
		}
	}
	else
		return (check);
	return (index);
}

static int		ft_nbrlen(long long value, int base)
{
	int		len;
	int		neg;

	neg = 0;
	len = 1;
	if (value < 0)
	{
		value = -value;
		neg = 1;
	}
	if (base == 0)
		return (0);
	while (value >= (long long)base)
	{
		len++;
		value /= base;
	}
	return (len);
}

int				color(char *col, int *dest)
{
	int		i;
	int		pos;
	int		dec_nb;

	i = -1;
	pos = 1;
	*dest = 0x000000;
	while (col[++i])
	{
		if (ft_isdigit(col[i]))
		{
			dec_nb = ft_atoi(col + i);
			if (dec_nb < 0 || dec_nb > 255)
				return (0);
			i += ft_nbrlen(dec_nb, 10) - 1;
			if (pos == 1)
				*dest += dec_nb * 65536;
			else if (pos == 2)
				*dest += dec_nb * 256;
			else if (pos == 3)
				*dest += dec_nb * 1;
			pos++;
		}
	}
	return (pos == 4 ? 1 : 0);
}

int				parsing_cub3d(int argc, char **argv, t_cub3d *cub)
{
	char	*str_cub;
	int		index;
	char	*tmp;

	index = check_arg(argc, argv);
	if (index == 2)
		cub->game->save = 1;
	if (index == 0)
		ft_error(cub, "Bad argument(s).\n", 3);
	str_cub = get_cub_string(argv, index);
	if (str_cub == NULL)
		return (0);
	tmp = str_cub;
	index = loop_index(cub, index, str_cub);
	str_cub += index;
	if (index == 0 || parsing_map2(cub, str_cub) == 0)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	if (parsing_map(cub) == 0)
		return (0);
	return (1);
}

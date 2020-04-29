/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:26:19 by loamar            #+#    #+#             */
/*   Updated: 2020/03/11 22:41:31 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char 	*get_cub_string(char **argv, int index)
{
	int				fd;
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;
	char			*str;
	int				ret;

	str = ft_strdup("\0");
	if (!argv[1])
		return (NULL);
	if (!(fd = open(argv[index], O_RDONLY)))
 		return (NULL);
	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
	}
	return (str);
}

static int		fill_map(t_map *map, char *str_cub, int index)
{
	int		check;

	check = 0;
	index += ft_nowhitespace(str_cub, index, map);

	while (str_cub[index] != ' ')
	{
		// printf("poet\n");
		// printf("str_cub[index] = [%c]\n", str_cub[index]);
		if (check_map_param(str_cub, index) == 1)
		{
			// printf("poet1\n");
			// printf("str_cub[index] = [%c]\n", str_cub[index]);
			check = index;
			index += ft_get_my_ticket(map, str_cub, index);
			// printf("poet2\n");
			// printf("ticket = %d\n", map->ticket);
			if (check == index)
				return (0);
			// printf("poet3\n");
			// ft_get_ticket que faire si il n y a pas de bon flag ?? genre jefopvbpvnvoibeove.
			index += ft_nowhitespace(str_cub, index, map);
			// printf("str_cub[index] = [%c]\n", str_cub[index]);
			// printf("poet4\n");
			if (map->error == 1)
			{
				return (0);
			}
			else
			{
				// printf("poet6\n");
				// printf("str_cub[index] = [%c]\n", str_cub[index]);
				ft_find_size(map, str_cub, index);
				// printf("str_cub[index] = [%c]\n", str_cub[index]);
				get_map_param(map, str_cub, index);
				// printf("str_cub[index] = [%c]\n", str_cub[index]);
				if (map->ticket != R)
					map->size2 = 0;
				// printf("str_cub[index] = [%c]\n", str_cub[index]);
				index += (map->size + map->size_space + map->size2 - 1);
				// printf("str_cub[index] = [%c]\n", str_cub[index]);
				index += ft_nowhitespace(str_cub, index, map);
				// printf("str_cub[index] = [%c]\n", str_cub[index]);
				return (index);
			}
		}
		// printf("str_cub[index] = [%c]\n", str_cub[index]);
		index++;
	}
	return (index);
}

///////////////////////////////////////
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

static int		color(char *col, int *dest)
{
	int i;
	int	pos;
	int dec_nb;

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

////////////////////////////////////

// static int	 	color(char *str)
// {
// 	int 			check;
// 	int 			index;
// 	// int 		 	color;
// 	int 	color;
//
// 	check = 0;
// 	index = 0;
// 	while (str[index])
// 	{
// 		if (check > 2)
// 			return (0);
// 		if (str[index] == ',')
// 			check++;
// 		if (check == 0)
// 			color[1] = (unsigned char)ft_atoi(str + index);
// 		else if (check == 1)
// 			color[2] = (unsigned char)ft_atoi(str + index);
// 		else if (check == 2)
// 			color[3] = (unsigned char)ft_atoi(str + index);
// 		if (check == 2)
// 		{
// 			while (str[index])
// 				index++;
// 		}
// 		else
// 		{
// 			while (str[index] != ',')
// 				index++;
// 		}
// 	}
// 	return (color);
//
// }

int 	parsing_cub3d(int argc, char **argv, t_cub3d *cub)
{
	char 	*str_cub;
	int		index;
	int 	check;

	index = 0;
	index = check_arg(argc, argv);
	if (index == 2)
		cub->game->save = 1;
	if (index == 0)
		return (0);
	str_cub = get_cub_string(argv, index);
	if (str_cub == NULL)
		return (0);
	index = 0;
    while (data_check(cub->map) != 1)
    {
		check = index;
		index = fill_map(cub->map, str_cub, index);
		if (index == check)
			return (0);
	}
	// printf("\n*********************************************************\n");
	// printf("\nout of fill_map\n");
	// printf("\nmap->beta_res_x = %s\nmap->beta_res_y = %s\n", cub->map->beta_res_x, cub->map->beta_res_y);
	// printf("\nmap->res_x = %d\nmap->res_y = %d\n", cub->map->res_x, cub->map->res_y);
	// printf("\nmap->north_texture = %s\n", cub->map->north_texture);
	// printf("\nmap->south_texture = %s\n", cub->map->south_texture);
	// printf("\nmap->west_texture = %s\n", cub->map->west_texture);
	// printf("\nmap->east_texture = %s\n", cub->map->east_texture);
	// printf("\nmap->sprite_texture = %s\n", cub->map->sprite_texture);
	// printf("\nmap->floor_color = %s\n", cub->map->floor_color);
	// printf("\nmap->ceiling_color = %s\n", cub->map->ceiling_color);
	// printf("\n*********************************************************\n");
	cub->map->res_x = ft_atoi(cub->map->beta_res_x);
	cub->map->res_y = ft_atoi(cub->map->beta_res_y);
	if (color(cub->map->ceiling_color, &(cub->map->ceiling_addr)) == 0)
		return (0);
	if (color(cub->map->floor_color, &(cub->map->floor_addr)) == 0)
		return (0);
	// cub->map->ceiling_addr = color(cub->map->ceiling_color);
	// cub->map->floor_addr = color(cub->map->floor_color);
	// printf("\nmap->res_x = %d\nmap->res_y = %d\n", cub->map->res_x, cub->map->res_y);
	// printf("\n*********************************************************\n");
	if (cub->map->res_x > 2560)
		cub->map->res_x = 2560;
	if (cub->map->res_y > 1440)
		cub->map->res_y = 1440;
	check = index;
	if (str_cub[index] == '\n')
		index++;
	while (str_cub[index] == ' ')
	{
		index++;
		while (str_cub[index] == '\n')
		{
			check = index;
			index++;
		}
	}
	index = check;
	str_cub += index;
	if (parsing_map(cub, str_cub) == 0)
		return (0);
	return (1);
}

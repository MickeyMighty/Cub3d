/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:51:34 by loamar            #+#    #+#             */
/*   Updated: 2020/07/02 15:36:48 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		check_arg(int argc, char **argv)
{
	if (argc == 0 || argc > 3 || argc == 1)
		return (0);
	else if ((str_end_check(argv[1], ".cub") != NULL)
	&& (ft_strncmp("--save", argv[2], 7) == 0) && argc == 3)
		return (2);
	else if (str_end_check(argv[1], ".cub") && argc == 2)
		return (1);
	else
		return (0);
}

int		on_exit(t_cub3d *cub)
{
	ft_error(cub, "", 0);
	return (1);
}

void	error_msg(int error, char *msg)
{
	if (error == 1 || error == 3 || error == 4)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(msg, 2);
	}
}

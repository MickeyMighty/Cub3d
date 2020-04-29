/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:20:09 by loamar            #+#    #+#             */
/*   Updated: 2020/01/14 17:39:43 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;
//
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == c)
// 		{
// 			return ((char *)(s + i));
// 		}
// 		i++;
// 	}
// 	if (s[i] == c)
// 		return ((char *)(s + i));
// 	return (0);
// }

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i])
		if (s[i] == c)
			return ((char*)s + i);
	if (c == '\0')
		return ((char*)s + i);
	return (NULL);
}

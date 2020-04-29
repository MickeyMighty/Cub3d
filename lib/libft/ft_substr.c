/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:23:16 by loamar            #+#    #+#             */
/*   Updated: 2020/01/14 17:34:29 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*dest;
// 	size_t	i;
//
// 	if (!s)
// 		return (0);
// 	i = 0;
// 	if (ft_strlen(s) < start)
// 		len = 0;
// 	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
// 		return (0);
// 	while (i < len && s[start] != '\0')
// 	{
// 		dest[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (!len || (unsigned int)ft_strlen(s) < start)
	{
		if (!(str = (char*)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

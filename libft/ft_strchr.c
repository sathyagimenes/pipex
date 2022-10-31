/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:35:28 by sde-cama          #+#    #+#             */
/*   Updated: 2022/04/16 19:27:55 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;
	unsigned char	*string;

	character = c;
	string = (unsigned char *)s;
	while (*string)
	{
		if (*string == character)
			return ((char *)string);
		string++;
	}
	if (character == '\0')
		return ((char *)string);
	return (NULL);
}

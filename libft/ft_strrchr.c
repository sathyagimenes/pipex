/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:29:34 by sde-cama          #+#    #+#             */
/*   Updated: 2022/04/16 20:26:50 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	character;
	const char		*s_end;

	character = c;
	s_end = s;
	while (*s_end)
		s_end++;
	while (s_end != s)
	{
		if (*s_end == character)
			return ((char *)s_end);
		s_end--;
	}
	if (*s_end == character)
		return ((char *)s_end);
	return (NULL);
}

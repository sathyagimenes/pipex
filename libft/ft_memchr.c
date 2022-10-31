/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:35:12 by sde-cama          #+#    #+#             */
/*   Updated: 2022/05/11 02:50:53 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	character;
	unsigned char	*string;

	character = c;
	string = (unsigned char *)s;
	while (n > 0)
	{
		if (*string == character)
			return ((void *)string);
		string++;
		n--;
	}
	return (NULL);
}

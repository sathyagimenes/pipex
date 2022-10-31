/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:01:54 by sde-cama          #+#    #+#             */
/*   Updated: 2022/04/16 22:55:20 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*fst_s;
	unsigned char	*snd_s;

	fst_s = (unsigned char *)s1;
	snd_s = (unsigned char *)s2;
	while (n > 0)
	{
		if (*fst_s > *snd_s)
			return (1);
		if (*fst_s < *snd_s)
			return (-1);
		fst_s++;
		snd_s++;
		n--;
	}
	return (0);
}

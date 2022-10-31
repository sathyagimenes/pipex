/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:35:27 by sde-cama          #+#    #+#             */
/*   Updated: 2022/05/06 01:01:43 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*memory_dest;
	unsigned char	*memory_src;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	memory_dest = (unsigned char *)dest;
	memory_src = (unsigned char *)src;
	while (i < n)
	{
		memory_dest[i] = memory_src[i];
		i++;
	}
	return (dest);
}

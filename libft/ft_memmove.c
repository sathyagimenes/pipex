/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:15:33 by sde-cama          #+#    #+#             */
/*   Updated: 2022/05/15 17:12:59 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{	
	unsigned char	*memory_dest;
	unsigned char	*memory_src;

	if (src == NULL && dest == NULL)
		return (dest);
	memory_dest = (unsigned char *)dest;
	memory_src = (unsigned char *)src;
	if (memory_src <= memory_dest)
	{
		while (n--)
		{
			memory_dest[n] = memory_src[n];
		}
		return (dest);
	}
	ft_memcpy(memory_dest, memory_src, n);
	return (dest);
}

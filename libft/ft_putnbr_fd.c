/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:35:41 by sde-cama          #+#    #+#             */
/*   Updated: 2022/05/14 22:41:44 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*converter(int n, char *s, size_t size_n);
static int	size_number(int n);

void	ft_putnbr_fd(int n, int fd)
{
	char	ptr[32];
	size_t	len;

	len = size_number(n);
	converter(n, ptr, len);
	write(fd, ptr, len);
}

static char	*converter(int n, char *s, size_t size_n)
{
	unsigned int	number;

	number = n;
	if (n < 0)
		number *= -1;
	s[size_n] = '\0';
	while (size_n--)
	{
		s[size_n] = number % 10 + 48;
		number /= 10;
	}
	if (n < 0)
		*s = '-';
	return (s);
}

static int	size_number(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

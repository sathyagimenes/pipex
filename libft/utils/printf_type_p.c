/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:42:22 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/02 01:03:52 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	type_p(unsigned long number)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp2 = ft_convert_to_base(number, 16);
	if (*tmp2 == '0')
	{
		i = write(1, "(nil)", 5);
		free(tmp2);
		return (i);
	}
	tmp = ft_strjoin("0x", tmp2);
	i = write(1, tmp, ft_strlen(tmp));
	if (tmp)
		free(tmp);
	if (tmp2)
		free(tmp2);
	return (i);
}

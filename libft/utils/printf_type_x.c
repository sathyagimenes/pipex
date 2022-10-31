/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:24:41 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/02 01:04:07 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	type_x(unsigned long number)
{
	char	*tmp;
	int		i;

	tmp = ft_convert_to_base(number, 16);
	i = write(1, tmp, ft_strlen(tmp));
	if (tmp)
		free(tmp);
	return (i);
}

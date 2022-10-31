/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:35:28 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/02 01:03:58 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	type_u(unsigned long number)
{
	char	*tmp;
	int		i;

	tmp = ft_convert_to_base(number, 10);
	i = write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (i);
}

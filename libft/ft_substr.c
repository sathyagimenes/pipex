/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:43:48 by sde-cama          #+#    #+#             */
/*   Updated: 2022/05/13 01:52:24 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	char	*copy;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s == NULL || s_len < start)
		return (ft_strdup(""));
	if ((start + len) < s_len)
		substring = malloc((len + 1 * sizeof(char)));
	else
		substring = malloc(((s_len - start + 1) * sizeof(char)));
	if (substring == NULL)
		return (NULL);
	i = start;
	copy = substring;
	while (i < (start + len) && *(s + i) != '\0')
		*copy++ = *(s + i++);
	*copy = '\0';
	return (substring);
}

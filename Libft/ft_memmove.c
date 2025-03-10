/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:43:04 by figarcia          #+#    #+#             */
/*   Updated: 2024/10/16 20:25:27 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num_bytes)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dest == NULL && src == NULL && num_bytes > 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s && d < s + num_bytes)
	{
		i = num_bytes;
		while (i--)
			d[i] = s[i];
	}
	else
	{
		i = 0;
		while (i < num_bytes)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:36:28 by muguveli          #+#    #+#             */
/*   Updated: 2023/12/22 17:34:27 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	char	*byte;
	int		i;

	byte = (char *)dest;
	i = 0;
	while (len > 0)
	{
		byte[i] = (char)c;
		len--;
		i++;
	}
	return (dest);
}

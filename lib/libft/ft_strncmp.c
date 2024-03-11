/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:37:54 by muguveli          #+#    #+#             */
/*   Updated: 2023/12/19 16:39:22 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (dest[i] && src[i] && dest[i] == src[i] && i < n - 1)
		i++;
	return ((unsigned char)dest[i] - (unsigned char)src[i]);
}

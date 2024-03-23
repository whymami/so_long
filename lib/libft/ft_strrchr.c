/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:55:28 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/23 14:23:17 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	j = i - 4;
	while (i >= j)
	{
		if (str[i] == (char)c)
			return (1);
		i--;
	}
	return (0);
}

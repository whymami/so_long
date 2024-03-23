/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:25:13 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/16 15:11:21 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_map_check(argv[1]);
	else
		ft_exit(_INV_ARG, "INVALID ARGUMENT\nUSAGE: ./so_long <map/map.ber>",
			NULL);
}

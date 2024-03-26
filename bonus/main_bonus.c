/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:01:26 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/26 13:01:28 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_bns_map_check(argv[1]);
	else
		ft_bns_exit(_INV_ARG,
			YELLOW "INVALID ARGUMENT\n" COLOR_RESET GREEN "USAGE:"
			COLOR_RESET YELLOW "./so_long <map/map.ber>" COLOR_RESET, NULL);
}

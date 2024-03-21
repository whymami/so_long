/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:40:52 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/20 15:47:34 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_bns_map_check(argv[1]);
	else
		ft_bns_exit(_INV_ARG, "INVALID ARGUMENT\nUSAGE: ./so_long <map/map.ber>",
			NULL);
}

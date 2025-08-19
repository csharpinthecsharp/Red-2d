/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:24:49 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/19 02:09:55 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *msg, t_data *d)
{
	ft_printf("Error\n%s\n", msg);
	close_game(d, EXIT_FAILURE);
}

void	exit_success(char *msg, t_data *d)
{
	ft_printf("Error\n%s\n", msg);
	close_game(d, EXIT_SUCCESS);
}

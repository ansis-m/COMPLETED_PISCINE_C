/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <adespond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 14:57:00 by adespond          #+#    #+#             */
/*   Updated: 2015/09/16 04:45:39 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_op.h"

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

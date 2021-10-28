/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   islower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:32:06 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:32:06 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_islower(int c)
{
	return ((c >= 'a') && (c <= 'z'));
}

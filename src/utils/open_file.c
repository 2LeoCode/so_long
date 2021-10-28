/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:23:03 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:27:46 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, __O_DIRECTORY);
	close(fd);
	if (fd != -1)
		return (-1);
	return (open(filename, O_RDONLY));
}

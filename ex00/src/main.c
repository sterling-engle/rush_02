/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:26:53 by sengle            #+#    #+#             */
/*   Updated: 2019/07/28 22:47:37 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define MAX_BUF	32767

#include <stdio.h>

int	main(int argc, char **argv)
{
	int		buf_size;
	int		bytes_read;
	char	*buf;

	bytes_read = 0;
	if (argc < 1)
		return (1);
	if (argv[0][0] == 0)
		return (1);
	buf = (char*)malloc(sizeof(char) * MAX_BUF);
	while ((buf_size = read(0, &buf[bytes_read], MAX_BUF)) > 0)
		bytes_read += buf_size;
	buf[bytes_read] = '\0';
	parse_rush(buf);
	free(buf);
	return (0);
}

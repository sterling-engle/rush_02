/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:26:53 by sengle            #+#    #+#             */
/*   Updated: 2019/07/28 21:29:02 by sjiseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define MAX_BUF	32768

#include <stdio.h>

int	main(int argc, char **argv)
{
	int		buf_size;
	char	*buf;

	if (argc < 1)
		return (1);
	if (argv[0][0] == 0)
		return (1);
	buf = (char*)malloc(sizeof(char) * (MAX_BUF + 10000));
	buf_size = read(0, buf, MAX_BUF);
	buf[buf_size] = 0;
	parse_rush(buf);
	free(buf);
	return (0);
}

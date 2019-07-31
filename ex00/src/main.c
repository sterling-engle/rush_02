/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:26:53 by sengle            #+#    #+#             */
/*   Updated: 2019/07/31 14:05:43 by sengle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define MAX_BUF	100000

#include <stdio.h>

/*
**	int main(int argc, char **argv)
**
**	Local variables:
**
**	int	 buf_size;	 // size of buffer returned by read(), 0 means end of file
**	int	 bytes_read; // total bytes read in multiple calls to read(), buf offset
**	char *buf;		 // MAX_BUF byte buffer allocated by malloc(3)
**
**	Algorithm:
**
**	1. Calls malloc(3) to allocate MAX_BUF bytes to hold the rush 00 square
**
**	2. Reads in the rush 00 square from a pipe (standard input 0):
**
**		a. Store the data in the buffer outset by bytes_read (already).
**		b. While data is returned from the pipe
**			i. add the number of bytes read to bytes read.
**		c. Terminate the buffer with a null character.
**
**	3.	Call parse_rush(buf)
**	4.	Free the memory occupied by buf with a call to free(buf);
**
**	Returns 0
*/

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

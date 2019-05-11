/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:01:11 by bcharity          #+#    #+#             */
/*   Updated: 2019/05/11 13:27:13 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_GET_NEXT_LINE_H
# define GNL_GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# define MAX_FD 4096
# define BUFF_SIZE 3

int         get_next_line(const int fd, char **line);
int         to_line(char **line, t_list *box, int ret, int fd);
t_list      *find_fd(t_list **file, int fd);
#endif

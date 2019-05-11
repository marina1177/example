/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:00:49 by bcharity          #+#    #+#             */
/*   Updated: 2019/05/11 16:28:38 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
int to_line(char **line, t_list *box, int ret, int fd)
{
    char *tmp;
    int i;

	i = 0;
	box = find_fd(&box, fd);
   // printf("box->content_size_FD: %zu\n",box->content_size);
//	printf("box->content_BEFORE: %s\n",box->content);

    while (((char*)box->content)[i] != '\n' && ((char*)box->content)[i] != '\0')
		i++;
//	printf("len: %d\n", i);
    if (((char*)box->content)[i] == '\n')
    {
	 	*line = ft_strsub(box->content, 0, i);
//		printf("line_n: %s\n", *line);
        tmp = ft_strdup((box->content) + i + 1);
		free(box->content);
		box->content = tmp;

    }
	else if (((char*)box->content)[i] == '\0')
    {
  //      printf("box->contentEND0: %s\n",box->content);
		if (ret == BUFF_SIZE)
			return (get_next_line(fd,line));
        *line = ft_strdup(box->content);
//		printf("line_0: %s\n", *line);
        ft_strclr(box->content);
    //    printf("box->contentCLR: %s\n",box->content);
        free(box->content);
    }
        return (1);
}

int get_next_line(const int fd, char **line)
{
	int				ret;
    static t_list	*box;
	char            *tmp;
	char			buf[BUFF_SIZE + 1];

	box = NULL;
    box = find_fd(&box, fd);

	if (fd < 0 || !line || fd > MAX_FD || BUFF_SIZE == 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
        buf[ret] = '\0';
//		printf("buf_: %s\n",buf);

        tmp = box->content;
        box->content = ft_strjoin(box->content, buf);
        free(tmp);
        /*box = find_fd(&box, fd);
        printf("box->content_loop: %s\n",box->content);
        tmp = ft_strjoin(box->content, buf);
        printf("tmp_: %s\n",tmp);
        free(box->content);
        box->content = tmp;*/
//		printf("box->content_loop: %s\n",box->content);
		if (ft_strrchr(buf, '\n'))
		   	break;
	}
//	printf("box->content_endl: %s\n",box->content);
    if (ret < 0)
        return (-1);
    if (ret < BUFF_SIZE && !ft_strlen(box->content))
        return(0);
    return (to_line(line, box, ret, fd));
}


t_list *find_fd(t_list **file, int fd)
{
    t_list				*tmp;
    t_list				*current;

    tmp = *file;
    while (tmp)
    {
        if ((int)tmp->content_size == fd)
		{
	//		printf("tmp->content_size_loop: %zu\n",tmp->content_size);
       printf("tmp->content_loop: %s\n",tmp->content);
			return (tmp);
		}
        tmp = tmp->next;
    }

    tmp = ft_lstnew("\0", fd);
    ft_lstadd(file, tmp);
//    tmp = *file;
//	printf("tmp->content_size_final: %zu\n",(tmp->content_size));
    printf("tmp->content_final: %s\n",tmp->content);
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:24:56 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/13 02:58:12 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
int				ft_buffer_rd(char *buffer, char **line, int *index);
void			ft_buffer_cut(char *buffer);
int				ft_init(char **line);

int				ft_realloc(char **line);
void			ft_strncpy(char *dst, char *src, int size);
size_t			ft_strlen(const char *s);

#endif

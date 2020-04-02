/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:32:31 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/06 21:45:00 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flag
{
	int		pad;
	int		prec;
	int		position;
	int		modif;
	char	filler;
}				t_flag;

int				ft_printf(const char *str, ...);
int				ft_flag_rd(va_list *aap, const char *str, int i, int *result);
int				ft_arg_rd(va_list *aap, char *str_i, t_flag *afl, int *result);
void			ft_flag_init(t_flag *afl);
int				ft_prec_rd(va_list *aap, t_flag *afl, int i, const char *str);

void			ft_character(va_list *aap, t_flag *afl, int *result);
void			ft_padding_char(int *result, t_flag *afl);

void			ft_string(va_list *aap, t_flag *afl, int *result);
void			ft_padding_str(int *result, t_flag *afl, int len);
void			ft_putstr_nb_cpt(char *s, int len, int *result);

void			ft_pointeur(va_list *aap, t_flag *afl, int *result);
void			ft_padding_pnt(int *result, t_flag *afl, long long x);
void			ft_precision_pnt(int *result, t_flag *afl, long long x);

void			ft_integer(va_list *aap, t_flag *afl, int *result);
void			ft_padding_int(int *result, t_flag *afl, int x, int n);
void			ft_precision_int(int *result, t_flag *afl, int x);
void			ft_int_wr(t_flag *afl, int *result, long x);

void			ft_unsigned_int(va_list *aap, t_flag *afl, int *result);
void			ft_padding_ui(int *result, t_flag *afl, int len);
void			ft_precision_ui(int *result, t_flag *afl, int len);

void			ft_hex(va_list *aap, t_flag *afl, int *result, char *base);
void			ft_padding_hex(int *result, t_flag *afl, long long x);
void			ft_precision_hex(int *result, t_flag *afl, long long x);

void			ft_percent(t_flag *afl, int *result);
void			ft_padding_pct(int *result, t_flag *afl);

int				ft_digit_nbr(int x);
int				ft_dgt_nbr_hex(long long x);
int				ft_min(int x, int y);
int				ft_max(int x, int y);
void			ft_putchar_cpt(char c, int *result);

int				ft_begin_rd(int i, t_flag *afl, const char *str);

#endif

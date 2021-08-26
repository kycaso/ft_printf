/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelda-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:50:05 by fbelda-h          #+#    #+#             */
/*   Updated: 2021/07/07 13:29:05 by fbelda-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		value;
	va_list	argptr;
	char	*aux;

	va_start(argptr, s);
	aux = ft_strdup(s);
	i = -1;
	value = 0;
	while (aux[++i] != '\0')
	{
		if (aux[i] == '%')
		{
			i = next_char(aux, i + 1);
			value += piecer(&argptr, aux, i) - 1;
		}
		else
			ft_putchar_fd(aux[i], 1);
		value++;
	}
	va_end(argptr);
	free (aux);
	return (value);
}

int	next_char(char *s, int i)
{
	while (s[i] != '%' && s[i] != 'c' && s[i] != 's' && s[i] != 'p'
		&& s[i] != 'd' && s[i] != 'i' && s[i] != 'u' && s[i] != 'x'
		&& s[i] != 'X')
		i++;
	return (i);
}

int	piecer(va_list *argptr, char *s, int i)
{
	char	*p;
	int		j;
	t_word	*text;

	j = i - 1;
	while (s[j] != '%')
		j--;
	p = ft_substr(s, j + 1, i - j);
	text = ft_calloc(1, sizeof(t_word));
	text->type = p[ft_strlen(p) - 1];
	smaker(&text, p, argptr);
	j = pather(&text, argptr);
	free (p);
	free (text);
	return (j);
}

void	smaker(t_word **text, char *s, va_list *argptr)
{
	int	j;
	int	n;

	j = 0;
	while (s[j] != '\0')
	{
		n = 0;
		if (s[j] == '-' || (s[j] == '0' && s[j - 1] != '.'
				&& (*text)->flag != '-'))
			(*text)->flag = s[j];
		if (s[j] == '.')
			(*text)->pre = 1;
		if (s[j] > '0' && s[j] <= '9')
			n = ft_atoi(ft_substr(s, j, 10));
		if ((*text)->pre == 1 && (*text)->preval == 0)
			(*text)->preval = n;
		else if (n != 0)
			(*text)->width = n;
		if (s[j] == '*')
			asterisk(argptr, text);
		j = j + 1 + ent_logar(10, n);
	}
}

int	pather(t_word **text, va_list *argptr)
{
	if ((*text)->type == 'c')
		return (chars(text, va_arg(*argptr, int)));
	else if ((*text)->type == '%')
		return (numbers(text, ft_strdup("%\0")));
	else if ((*text)->type == 's')
		return (strings(text, argptr));
	else if ((*text)->type == 'i' || (*text)->type == 'd')
		return (numbers(text, i_b(text, va_arg(*argptr, int), 10, 0)));
	else if ((*text)->type == 'u')
		return (numbers(text, i_b(text, va_arg(*argptr, unsigned int), 10, 0)));
	else if ((*text)->type == 'x')
		return (numbers(text, i_b(text, va_arg(*argptr, unsigned int), 16, 0)));
	else if ((*text)->type == 'X')
		return (numbers(text, i_b(text, va_arg(*argptr, unsigned int), 16, 1)));
	else if ((*text)->type == 'p')
		return (pointers(text, va_arg(*argptr, unsigned long int)));
	return (0);
}

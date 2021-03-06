/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/08 18:19:40 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**
**  - Воспроизвести поведение функции strstr (man strstr).
**
**
**  - Вот как это должно быть обьявлено:
**
**       char	*ft_strstr(char *str, char *to_find);
**
**
** ************************************************************************** **
**
**
**  Аргументы:
**
**  str – указатель на строку, в которой ведется поиск.
**  to_find – указатель на искомую строку.
**
**  Возвращаемое значение:
**
**  Функция возвращает указатель на массив, в который добавлена строка (dest).
**
**  Положительное число – если в первых n символах сравниваемых строк есть отличия
**  и код первого отличающегося символа в строке s1 больше кода символа на той же
**  позиции в строке 's2'.
** 
**  Отрицательное число – в первых n символах сравниваемых строк есть отличия и
**  код первого отличающегося символа в строке 's1' меньше кода символа на той же 
**  позиции в строке 's2'.
** 
**  Описание:
**
**  Функция 'strstr' ищет первое вхождение строки (за исключением признак конца строки), 
**  на которую указывает аргумент 'to_find', в строку , на которую указывает аргумент 'str'. 
**  Если строка 'to_find' имеет нулевую длину, то функция вернет указатель на начало 
**  строки 'str'
**
**
**  К примеру: в строке «0123456789», с помощью функции 'ft_strstr', ищется первое вхождение
**  строки: «345». Эта функця ищет нужную строку. и возвращает адрес эдемента с 
**  которого начинаеться искомая строка если символы идентичны. 
**
** 
** 
** ************************************************************************** **
**
**
** Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
**
** ************************************************************************** */
/* ************************************************************************** */



char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return ((void *)0);
}

/* ************************************************************************** */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*a;
	char	*b;

	b = to_find;
	if (*b == '\0')
		return (str);
	while (*str)
	{
		if (*str == *b)
		{
			a = str;
			while (*a == *b || *b == '\0')
			{
				if (*b == '\0')
					return (str);
				a++;
				b++;
			}
			b = to_find;
		}
		str++;
	}
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		y;
	char	*occurrence;

	occurrence = 0;
	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			occurrence = str + i;
			y = 0;
			while (str[i + y] == to_find[y])
			{
				if (to_find[y + 1] == '\0')
					return (occurrence);
				y++;
			}
			occurrence = 0;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


/* 
 * ===-----------------------------------------------------------------------===
 *
 *	  • Написать функцию "ft_decrypt". Эта функция примет строку символов в 
 *	качестве параметра и разделит ее на массив структуры "t_perso". Массив будет 
 *  разделен 0.
 * 
 *	  • Эта функция будет прототипирована следующим образом:
 *											t_perso		**ft_decrypt(char *str)
 *
 *	  • Строка, переданная в качестве параметра, будет отформатирована следующим 
 *	образом:
 * 											Age|Name;Age2|Name2;Age3|Name3
 *	
 *	• Структура "t_perso" должна сказать вам что-то! Неуказанные поля не будут 
 *	инициализированы. Подумайте о том, чтобы включить "ft_perso.н "в свой".с"!
 *
 * ===-----------------------------------------------------------------------===
 */


#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>						/* Подключаем библиотеку содержащую функцию "malloc" */
#include "ft_perso.h"					/* Подключаем библиотеку содержащую структуру "t_perso" */


/* ************************************************************************** */
void		ft_putchar(char c)			/* Функция печати символа */
{
	write(1, &c, 1);
}
/* ************************************************************************** */
void		ft_putstr(char *str)		/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}
/* ************************************************************************** */
void		ft_putnbr(int nb)			/* Функция печати числа */
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)((temp / size)) + 48);
		temp %= size;
		size /= 10;
	}
}
/* ************************************************************************** */
void		ft_put_struct(t_perso *perso)/* Функция печати содержимого струкуры */
{
	ft_putnbr(perso->age);
	ft_putchar('\t');
	ft_putstr(perso->name);
}
/* ************************************************************************** */
void		ft_put_tab_struct(t_perso **tab)/* Функция печати содержимого массива со струкурами */
{
	while (*tab)
	{
		ft_put_struct(*tab++);
		write(1, "\n", 1);
	}
	
}
/* ************************************************************************** */

int			ft_isspace(char c)			/* Функция узнает является ли наш символ разделителем между словами */
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '|' || c == ';');/* Если наш символ это пробел или табуляция, 
										 * или концом строки то завершаем функцию и возвращаем '1'.
										 * Если это какой то др символ то завершаем функцию и возвращаем '0' */
}

int			ft_wordlen(char *str)		/* Функция узнает длинну ближайшего слова */
{
	int	i;

	i = 0;
	while (*str && !(ft_isspace(*str++)))
	{
		i++;
	}
	return (i);
}

char		*ft_get_name(char *str)		/* Функция находит первое имя из строки, выделяет память для дубликата 
										 * и возвращает его адрес  */
{	int	j;
	char	*name;

	j = 0;
	while(*str && (ft_isspace(*str) || (*str >= '0' && *str <= '9')))
		str++;
	name = (char *)malloc(sizeof(char) * ft_wordlen(str) + 1);
	while (*str && !(ft_isspace(*str)) && ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
		name[j++] = *str++;
	name[j] = '\0';
	return (name);
}

int			ft_get_age(char *str)		/* Функция находит в строке первые попавшееся цифровые символы указывающее
										 * на возраст, переводит их в целое число и его возвращает */
{
	int age;

	age = 0;
	while (*str >= '0' && *str <= '9')
		age = (age * 10) + (*str++ - '0');
	return (age);
}


t_perso		**ft_decrypt(char *str)		/* функция анализирует строку и вычисляет сколько нужно будет создать экземпляров структуры
										 * "t_perso" чтобы сохранить в каждом из них данные о возрасте и имени из строки каждого */
{
	t_perso	**tab;						/* Обьявим указатель на указатель типа структуры "t_perso" чтобы позже сохранить туда адрес
										 * выделеной нами памяти под массив указателей типа "t_perso", которые уже будут хранить
										 * адреса самих структур (память для них мы тоже выделим. Для каждой структуры отдельно) */
	int		numstructs;					/* Обьявим целочисленную переменную для хранения информации о количестве нужных структур */
	int		j;							/* Обьявим целочисленную переменную для счетчика */
	
	numstructs = 0;						/* Инициализируем переменную, для хранения информации о количестве нужных структур, нулем */
	j = 0;								/* Инициализируем счетчик нулем */
	while (str[j])						/* Анализируем строку чтобы посчитать количестов нужных экземпляров */
	{
		if (str[j] && str[j++] == '|')
			numstructs++;
	}
	if (numstructs > 0)					/* Если внутри строки данные найдены то запускем код внутри скобок */
	{
		j = 0;							/* Обнуляем счетчик "j" чтобы использовать его в другой части кода */
		if ((tab = (t_perso **)malloc(sizeof(t_perso *) * (numstructs + 1))) == ((void *)0))/* Выделяем память под массив указателей на указатели */
			return	((void *)0);		/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
		while (j < numstructs)			/* Запускаем цикл который запишет в каждую ячейку массива указателей адреса экземпляров структур типа "t_perso" */
		{
			if ((*(tab + j) = (t_perso *)malloc(sizeof(t_perso))) == ((void *)0)) /* Выделяем память под экземпляры структуры типа "t_perso" */
				return	((void *)0);	/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
			while(*str && (ft_isspace(*str) || !(*str >= '0' && *str <= '9')))	  /* Пропускаем все символы которые не являются возрастом */
				str++;
			(*(tab + j))->age = ft_get_age(str);								  /* Получаем число с возрастом из строки и сохраняем его */
			while(*str && (ft_isspace(*str) || (*str >= '0' && *str <= '9')))	  /* Пропускаем все символы которые не являются именем */
				str++;
			(*(tab + j))->name = ft_get_name(str);								  /* Получаем дубликат имени из строки и сохраняем его адресс */
			j++;						/* Переходим к след ячейке массива указателей */
		}
		return (tab);					/* Завершаем функцию и возвращаем адрес массива с адресами экземпляров структуры "t_perso" */
	}
	return	((void *)0);				/* Если внутри строки данные не найдены то завершаем функцию и возвращаем нулевой указатель */
}


int 		main(void)
{
	char *arr = "28 JohnRembo; 21|ChakNoris; 27|YourMom"; /* Создадим строку с возрастами и Именами чтобы разобрать это на состовляющие и разложить */
	ft_put_tab_struct(ft_decrypt(arr));	/* Отправляем адресс строки в функцию "ft_decrypt" для разложения строки, Эта функция должна вернуть адресс
										 * массива с адресами экземпляров структуры "t_perso" в которые функция "ft_decrypt" разложила строку. Этот 
										 * адрес мы отправим в функцию "ft_put_tab_struct" которая напечатает содержимое каждой структуры */
    return (0);		
}
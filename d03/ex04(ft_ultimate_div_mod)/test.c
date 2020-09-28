/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 18:56:43 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)           /* функция вывода символа */
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)            /* Функция вывода числа */
{
	int		temp;
	int		size;

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
		ft_putchar((char)(temp / size) + '0');
		temp %= size;
		size /= 10;
	}
}
/* #######################################################################*/
/* Эта функция производит деление с помощью содержимого параметров 'а', 'b' и сохраняет результат в переменной типа 'int',
на которую указывает адресс указателя 'a'. А потом функция получает остаток от деления 'а', 'b' и сохраняет результат в переменной типа 'int',
на которую указывает адресс указателя 'b'. */

void	ft_ultimate_div_mod(int *a, int *b) /* Указателями 'a' и 'b'(они обьявлены в скобках) принимаются и записываются, отправленные 
                                            ** в функцию, АДРЕСА ПЕРЕМЕННЫХ */
{
	int	temp;                       /* Создадим переменную для временного хранения данных */

	temp = *a;                      /* С помощью операции разыменовывания(*a) достаем из адреса(который хранится в указателе 'a') данные и сохраняем их в 'temp' */
	*a = *a / *b;                   /* Делим число из ячейки, на которую указывает указатель 'a', на число из ячейки, на которую указывает указатель 'b' и сохраняем
                                    ** результат в ячейку адресс которой хранит указатель 'b' с помощью операции разыменовывания(*b) */
	*b = temp % *b;                 /* Делим по модулю число из перменнной 'temp' на число из ячейки на которую указывает указатель 'b'
                                    ** и сохраняем их в ячейку адресс которой хранит указатель 'b' с помощью операции разыменовывания(*b) */
}

int		main(void)
{
	int		i;                     /* Обьявляем переменную, в которой будет хранится делимое */
	int		t;                     /* Обьявляем переменную, в которой будет хранится делитель */


	i = 452;                        /* Запишем туда  452 */
	t = 88;                         /* Запишем туда  88  */
	ft_ultimate_div_mod(&i, &t);    /* Вызываем функцию и отправляем туда адреса переменных, из которых возьмем делимое с делителем, 
                                    ** и в которые запишем результат их деления и остаток от их деления */

                                    /* Сейчас консоль должна вывести результат деления и остаток от деления "5 12" и перейти на сл. строку */
                                    /* Если сомневаетесь проверьте на калькуляторе */
	ft_putnbr(i);                   /* печатаем результат деления i */
	ft_putchar(' ');                /* Печатаем символ ' ' */
	ft_putnbr(t);                   /* печатаем делимое t */
	ft_putchar('\n');               /* печатаем символ переноса строки '\n' */

	return (0);
}
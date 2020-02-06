/*
git add .
git commit -m "Ecole42"
git push -u ssh master
*/
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */

#include <unistd.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_putchar(char c)
{
	write(1, &c, 1);

	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putnbr(int nb)
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
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
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_put_Arr_int(int *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(str[i]);
		if(i < n - 1)
		{
			ft_putchar(' ');
		}
		if(i == n - 1)
			ft_putchar('\n');
		i++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int 	main(void)
{
	int i[] = {5,4,3,2,1};

	ft_sort_integer_table(i, 5);

	ft_put_Arr_int(i,5);
	return 0;
}

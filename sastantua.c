/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:40:21 by galemair          #+#    #+#             */
/*   Updated: 2018/02/11 14:11:52 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		calc_bottom(int size)
{
	int transition;
	int top_line;
	int bottom_line;
	int line;
	int i;

	i = 1;
	line = 3;
	transition = 3;
	top_line = 1;
	while (i <= size)
	{
		bottom_line = top_line + 2 * (line - 1);
		if (i > 1 && i % 2 == 1)
			transition++;
		top_line = bottom_line + (transition * 2);
		i++;
		line++;
	}
	return (bottom_line + 2);
}

int		print_whitespaces(int whitespaces, int length)
{
	int i;

	i = 0;
	while (i < (whitespaces / 2 - ((length + 2) / 2)))
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

void	print(int length, int line, int whitespaces, int door_size)
{
	int i;
	int spaces;

	while (line > 0)
	{
		i = 0;
		spaces = print_whitespaces(whitespaces, length);
		ft_putchar('/');
		while (i++ < length)
		{
			if (length > 49 && line == door_size / 2 + 1 && i ==
				(whitespaces / 2) - spaces + door_size / 2 - 1)
				ft_putchar('$');
			else if (line <= door_size && i >= ((whitespaces / 2) - spaces -
					door_size / 2) && i <= ((whitespaces / 2) -
					spaces + door_size / 2))
				ft_putchar('|');
			else
				ft_putchar('*');
		}
		length += 2;
		ft_putchar('\\');
		ft_putchar('\n');
		line--;
	}
}

int		print_stage(int length, int line, int whitespaces)
{
	int i;

	while (line > 0)
	{
		i = 0;
		print_whitespaces(whitespaces, length);
		ft_putchar('/');
		while (i++ < length)
			ft_putchar('*');
		length += 2;
		ft_putchar('\\');
		ft_putchar('\n');
		line--;
	}
	return (length - 2);
}

void	sastantua(int size)
{
	int length;
	int line;
	int stage;
	int transition;
	int door_size;

	door_size = (size % 2 == 0) ? size - 1 : size;
	transition = 3;
	stage = 1;
	length = 1;
	while (stage <= size)
	{
		line = stage + 2;
		if (stage == size)
			print(length, line, calc_bottom(size), door_size);
		else
		{
			length = print_stage(length, line, calc_bottom(size));
			if (stage > 1 && stage % 2 == 1)
				transition++;
			length += (transition * 2);
		}
		stage++;
	}
}
int	main(int argc, char **argv)
{
	sastantua(atoi(argv[1]));
	return (0);
}

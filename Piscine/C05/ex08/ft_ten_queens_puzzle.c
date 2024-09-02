/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:44:22 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/30 18:40:55 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 10

#include <unistd.h>

int	is_safe(int board[N][N], int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < col)
	{
		if (board[row][i++])
			return (0);
	}
	i = row;
	j = col;
	while (i >= 0 && j >= 0)
	{
		if (board[i--][j--])
			return (0);
	}
	i = row;
	j = col;
	while (i < N && j >= 0)
	{
		if (board[i++][j--])
			return (0);
	}
	return (1);
}

void	print_board(int board[N][N])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < N)
	{
		while (j < N)
		{
			if (board[i][j])
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	write(1, "\n", 1);
}

int	solve(int board[N][N], int col, int *counter)
{
	int	row;

	row = 0;
	if (col >= N)
	{
		(*counter)++;
		print_board(board);
		return (1);
	}
	while (row < N)
	{
		if (is_safe(board, row, col))
		{
			board[row][col] = 1;
			solve(board, col + 1, counter);
			board[row][col] = 0;
		}
		row++;
	}
	return (0);
}

void	build_board(int board[N][N])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < N)
	{
		while (j < N)
		{
			board[i][j++] = 0;
		}
		j = 0;
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[N][N];
	int	solution_counter;

	solution_counter = 0;
	build_board(board);
	solve(board, 0, &solution_counter);
	return (solution_counter);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("solution count: %d", ft_ten_queens_puzzle());
// }
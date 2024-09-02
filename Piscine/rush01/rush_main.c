/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:42:02 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/21 23:41:54 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cell.h"
#include "checker.c"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

#define row 4
#define col 4

const int	base_positibilities[4] = {1, 2, 3, 4};

void	display_grid(struct Cell *grid)
{
	int	x;
	int	y;
	int	index;

	x = 0;
	y = 0;
	index = 0;
	while (y < col)
	{
		while (x < row)
		{
			printf(" %d", grid[index].value);
			x++;
			index++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

void	print_line(struct Cell *line)
{
	printf("Line: ");
	for (int i = 0; i < col; i++)
	{
		printf("%d ", line[i].value);
	}
}

short	is_used(int value, int used_values[col])
{
	for (int i = 0; i < col; i++)
	{
		if (used_values[i] == value)
		{
			return (1);
		}
	}
	return (0);
}

int	count_potential_values(int potential_values[col])
{
	int	count;

	count = 0;
	for (int i = 0; i < col; i++)
	{
		if (potential_values[i] != 0)
		{
			count++;
		}
	}
	return (count);
}

void	print_potential_values(struct Cell *line)
{
	int	i;

	i = 0;
	// printf("Cell X: %d, Cell Y: %d \n", (*line).x, (*line).y);
	printf("Potential Values for Cell:");
	while (i < col)
	{
		printf(" %d", (*line).potential_values[i]);
		i++;
	}
	printf("\n");
}

void	check_line(int *premuted_line, int left, int right,
		struct Cell *original_line)
{
	int	z;

	z = 0;
	if (!is_valid_line(left, right, premuted_line, col))
	{
		printf("\n");
		while (z < col)
		{
			if ((*original_line).potential_values[z] == premuted_line[z])
			{
				printf("Nullify\n");
				(*original_line).potential_values[z] = 0;
			}
			z++;
		}
	}
	// printf("\n");
	// print_potential_values(original_line);
	// printf("\n");
	// printf("\n");
	// printf("\n");
	if (count_potential_values((*original_line).potential_values) == 1)
	{
		printf("*****************************it happened ***********************************");
		for (int i = 0; i < col; i++)
		{
			if ((*original_line).potential_values[i] != 0)
				(*original_line).value = (*original_line).potential_values[i];
		}
	}
}

void	generate_permutations(struct Cell line[col], int index,
		int used_values[col], int left, int right, struct Cell *original_line)
{
	int	potential_value;
	int	line_to_check[col] = {0};
	int	l;

	if (index == col)
	{
		print_line(line);
		l = 0;
		while (l < col)
		{
			line_to_check[l] = line[l].value;
			l++;
		}
		check_line(line_to_check, left, right, original_line);
		return ;
	}
	if (line[index].value != 0)
	{
		used_values[index] = line[index].value;
		generate_permutations(line, index + 1, used_values, left, right,
			original_line);
	}
	else
	{
		for (int i = 0; i < col; i++)
		{
			potential_value = line[index].potential_values[i];
			if (potential_value != 0 && !is_used(potential_value, used_values))
			{
				used_values[index] = potential_value;
				line[index].value = potential_value;
				generate_permutations(line, index + 1, used_values, left, right,
					original_line);
				if (line[index].value == potential_value)
				{
					line[index].value = 0;
				}
				used_values[index] = 0;
			}
		}
	}
}

void	process_line(int left, int right, struct Cell **line, int size,
		short is_vertical)
{
	int	i;
	int	used_values[col] = {0};

	// printf("\nRECEIVED --------> ");
	// print_line(*line);
	// Input 4 **** 1
	i = 0;
	if (left == row && right == 1)
	{
		while (i < size)
		{
			(*line[i]).value = i + 1;
			i++;
		}
	}
	printf("\n---Original %d ", is_vertical);
	print_line(*line);
	printf("\nPermutations --- Start --- \n");
	generate_permutations(*line, 0, used_values, left, right, *line);
	printf("Permutations --- End --- \n");
}

void	prepare_grid(struct Cell *grid)
{
	int	x;
	int	y;
	int	index;

	x = row;
	y = col;
	index = 0;
	while (x > 0)
	{
		while (y > 0)
		{
			grid[index].x = x;
			grid[index].y = y;
			grid[index].value = 0;
			for (int i = 0; i < 4; i++)
			{
				grid[index].potential_values[i] = base_positibilities[i];
			}
			y--;
			index++;
		}
		y = col;
		x--;
	}
}

// void	process_vertically(struct Cell *grid, struct Input *v_input)
// {
// 	int			h;
// 	int			v;
// 	int			v_index;
// 	struct Cell	*v_array[row];

// 	h = 0;
// 	v = 0;
// 	v_index = 0;
// 	while (v < col)
// 	{
// 		while (h < row)
// 		{
// 			v_index = (h * col) + v;
// 			printf("v_index: %d\n", v_index);
// 			v_array[h] = &grid[v_index];
// 			printf("Expected V_ARRAY[%d] =  %d\n", h,  v_array[h]->value);
// 			h++;
// 		}

// 		printf("results v_array:");
// 		print_line(*v_array);
// 		process_line(v_input[v].left, v_input[v].right, v_array, row, 1);
// 		v++;
// 		h = 0;
// 	}
// }

void process_vertically(struct Cell *grid, struct Input *v_input) {
    int h, v, v_index;
    struct Cell **v_array; // Declare v_array as a pointer to a pointer to Cell

    h = 0;
    v = 0;
    v_index = 0;

    // Allocate memory for v_array
    v_array = malloc(row * sizeof(struct Cell *));
    if (!v_array) {
        printf("Failed to allocate memory for v_array.\n");
        return;
    }

    while (v < col) {
        while (h < row) {
            v_index = (h * col) + v;
            printf("v_index: %d\n", v_index);
            v_array[h] = &grid[v_index]; // Correctly assign the address of the current cell
            printf("Expected V_ARRAY[%d] =  %d\n", h, v_array[h]->value);
            h++;
        }

        printf("results v_array:");
        print_line(*v_array); // Ensure this function handles a pointer to the first element of v_array
        process_line(v_input[v].left, v_input[v].right, v_array, row, 1);
        v++;
        h = 0;
    }

    // Free allocated memory
    free(v_array);
}

void	process_horizontally(struct Cell *grid, struct Input *h_input)
{
	int			h;
	int			v;
	int			h_index;
	struct Cell	*h_array[col];

	h = 0;
	v = 0;
	h_index = 0;
	while (v < col)
	{
		while (h < row)
		{
			h_array[h] = &grid[h_index];
			h++;
			h_index++;
		}
		process_line(h_input[v].left, h_input[v].right, h_array, col, 0);
		v++;
		h = 0;
	}
}

void	remove_spaces(char *str)
{
	int	count;

	count = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] != ' ')
			str[count++] = str[i]; // here count is
									// incremented
	str[count] = '\0';
}

int	is_input_valid(int l, int r)
{
	if ((l == 4 && r != 1) || (r == 4 && l != 1))
		return (0);
	if ((l == 3 && (r != 2 && r != 3)) || (r == 3 && (l != 2 && l != 3)))
		return (0);
	if ((l == 2 && r == 4) || (r == 2 && l == 4))
		return (0);
	if (l == 1 && r == 1)
		return (0);
	return (1);
}

void	process_v_input(struct Input *v_input, int argc, char **argv)
{
	char	*str;
	int		i;

	str = argv[1];
	remove_spaces(str);
	i = 0;
	if (argc != 2)
	{
		printf("INVALID INPUT");
	}
	while (str[i])
	{
		if (i < col)
		{
			v_input[i].left = str[i] - '0';
			v_input[i].right = str[i + col] - '0';
			if (!is_input_valid(v_input[i].left, v_input[i].right))
			{
				printf("WRONG INPUT ZONG!\n");
				return ;
			}
			printf("vertical left: %d, right: %d\n", v_input[i % col].left,
				v_input[i % col].right);
		}
		i++;
	}
}

void	process_h_input(struct Input *h_input, int argc, char **argv)
{
	char	*str;
	int		i;
	int		k;

	str = argv[1];
	remove_spaces(str);
	i = col * 2;
	if (argc != 2)
	{
		printf("INVALID INPUT");
	}
	while (str[i] && i < col * 2 + row)
	{
		k = i - col * 2;
		h_input[k].left = str[i] - '0';
		h_input[k].right = str[i + col] - '0';
		if (!is_input_valid(h_input[i].left, h_input[i].right))
		{
			printf("WRONG INPUT ZONG!\n");
			return ;
		}
		printf("horizontal left: %d, right: %d\n", h_input[k % col].left,
			h_input[k % col].right);
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct Input	v_input[col] = {};
	struct Input	h_input[row] = {};
	struct Cell		grid[row * col] = {};

	printf("Processed Input:\n");
	process_v_input(v_input, argc, argv);
	process_h_input(h_input, argc, argv);
	printf("-------------------------------------------------------------");
	prepare_grid(grid);
	process_horizontally(grid, h_input);
	process_vertically(grid, v_input);
	printf("\n");
	display_grid(grid);
	printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	process_horizontally(grid, h_input);
	process_vertically(grid, v_input);
	printf("\n");
	display_grid(grid);
}

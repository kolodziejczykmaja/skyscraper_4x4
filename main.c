#include <unistd.h>

void	board_initial_0(int grid[4][4], int row, int col);
void	board_print(int grid[4][4]);
int		check_views(int map[4][4], int *numb);

int	convert(char *input, int *numb, int i, int j)
{
	while (input[i] != '\0')
	{
		if (input[i] < '1' || input[i] > '4')
			return (0);
		numb[j] = input[i] - '0';
		i++;
		j++;
		if (input[i] == ' ')
			i++;
	}
	if (j != 16)
		return (0);
	return (1);
}

int	check_conflict(int map[4][4], int row, int col, int num)
{
	int	count;

	count = 0;
	while (count < 4)
	{
		if (map[row][count] == num || map[count][col] == num)
			return (1);
		count++;
	}
	return (0);
}

int	solver(int map[4][4], int *numb, int poz)
{
	int	row;
	int	col;
	int	num;

	row = poz / 4;
	col = poz % 4;
	num = 0;
	if (poz == 4 * 4)
		return (check_views(map, numb));
	if (map[row][col] != 0)
		return (solver(map, numb, poz + 1));
	while (num <= 4)
	{
		if (check_conflict(map, row, col, num) == 0)
		{
			map[row][col] = num;
			if (solver(map, numb, poz + 1) == 1)
				return (1);
			map[row][col] = 0;
		}
		num++;
	}
	return (0);
}

void	find_input_equal_to_one(int map[4][4], int *numb, int count)
{
	count = 0;
	while (count < 4)
	{
		if (numb[count] == 1)
			map[0][count] = 4;
		if (numb[count + 4] == 1)
			map[4 - 1][count] = 4;
		if (numb[count + 2 * 4] == 1)
			map[count][0] = 4;
		if (numb[count + 3 * 4] == 1)
			map[count][4 - 1] = 4;
		count++;
	}
}

int	main(int ac, char **av)
{
	int	numb[16];
	int	map[4][4];

	if (ac != 2 || convert(av[1], numb, 0, 0) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	board_initial_0(map, 0, 0);
	find_input_equal_to_one(map, numb, 0);
	if (solver(map, numb, 0))
		board_print(map);
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

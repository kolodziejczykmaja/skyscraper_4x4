int	col_up(int map[4][4], int *numb, int row, int col)
{
	int	max;
	int	count;

	col = 0;
	while (col < 4)
	{
		max = 0;
		count = 0;
		row = 0;
		while (row < 4)
		{
			if (map[row][col] > max)
			{
				max = map[row][col];
				count++;
			}
			row++;
		}
		if (numb[col] != count)
			return (0);
		col++;
	}
	return (1);
}

int	col_down(int map[4][4], int *numb, int row, int col)
{
	int	max;
	int	count;

	col = 0;
	while (col < 4)
	{
		max = 0;
		count = 0;
		row = 4 - 1;
		while (row >= 0)
		{
			if (map[row][col] > max)
			{
				max = map[row][col];
				count++;
			}
			row--;
		}
		if (numb[4 + col] != count)
			return (0);
		col++;
	}
	return (1);
}

int	row_left(int map[4][4], int *numb, int row, int col)
{
	int	max;
	int	count;

	row = 0;
	while (row < 4)
	{
		max = 0;
		count = 0;
		col = 0;
		while (col < 4)
		{
			if (map[row][col] > max)
			{
				max = map[row][col];
				count++;
			}
			col++;
		}
		if (numb[2 * 4 + row] != count)
			return (0);
		row++;
	}
	return (1);
}

int	row_right(int map[4][4], int *numb, int row, int col)
{
	int	max;
	int	count;

	row = 0;
	while (row < 4)
	{
		max = 0;
		count = 0;
		col = 4 - 1;
		while (col >= 0)
		{
			if (map[row][col] > max)
			{
				max = map[row][col];
				count++;
			}
			col--;
		}
		if (numb[3 * 4 + row] != count)
			return (0);
		row++;
	}
	return (1);
}

int	check_views(int map[4][4], int *numb)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	return (col_up(map, numb, row, col)
		&& col_down(map, numb, row, col)
		&& row_left(map, numb, row, col)
		&& row_right(map, numb, row, col));
}

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);	
}

void get_door(int j, int size, int p, int maxi)
{
	if(j == 2 && p == (maxi / 2) + 1 && size >= 5)
		ft_putchar('$');
	else
		ft_putchar('|');
}

int max(int size)
{
	int i;
	int mem;
	int c;

	i = 1;
	mem = 7;
	c = 6;
	while(i < size)
	{
		if(i == 1)
			c = c;
                else if((i + 1) % 2 == 0)
                        c = c + 2;
		else 
			c = c + 1;
		mem = mem + c * 2;
		i++;
	}
	return(mem);
}
void display(int i, int mem, int size, int j)
{
	int p;
	int maxi;

	maxi = max(size);
	p = 1;
	while(p <= (maxi/2) - mem/2  + i)
	{	
		ft_putchar(' ');
		p++;
	}
	
	ft_putchar('/');
	while(p < (maxi/2) + (mem/2) - i + (mem % 2) - 1)
	{
		if((i + 1) + 1 - (size%2) - size <= 0 && p < (maxi/2) + (size/2) + (size%2) && p > (maxi/2) - size/2 - (size%2)  && j == size)
			get_door(i, size, p, maxi);
		else
			ft_putchar('*');
		p++;
	}	
	ft_putchar('\\');
	ft_putchar('\n');
}
void sastantua(int size)
{
	int i;
	int j;
	int c;
	int mem;

	i = 1;
	mem = 7;
	c = 6;
	while(i <= size)
	{
		if((i + 1) % 2 == 0 && i != 1)
                	c = c + 2;
		if((i + 1) % 2 != 0 && i != 1)
			c = c + 1;
		j = i + 1;
		while(j >= 0)
		{
			display(j, mem, size, i);
			j--;
		}
		mem = mem + c * 2;
		i++;
	}
}

int main(int argc, char **argv)
{
	int n;

	if(argc == 2)
	{
		n = *argv[1] - 48;
		sastantua(n);
	}
		
}

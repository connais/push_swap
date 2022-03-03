#include "push_swap.h"
int	sort_tab_3(s_data *a, s_data *b)
{
	int	tmp;

	if (a->tab[0] > a->tab[1])
		swap_sa(a, b);
	if (a->tab[1] > a->tab[2])
		reverse_rra(a, b);
	if (a->tab[0] > a->tab[1])
		swap_sa(a, b);
	return (0);
}
int main(int argc, char **argv)
{
	s_data *a;
	s_data *b;
	int	i;
	char **arg_long;
	if (argc == 2)
	{
		arg_long = ft_split(argv[1], ' ');
		if (!arg_long)
			return (ft_printf("error of arguments\n"), 0);
		a->len = count_words(argv[1], ' ');
		ft_printf("taille arg : %d\n", a->len);
		a->tab = get_tab_long(arg_long, a->len);
		if (!a->tab)
			return (ft_printf("error of arguments2\n"), 0);
		i = 0;
		printf("premier elemtab ->%d\n", a->tab[0]);
		while (i < 3)
			printf("%d\n", a->tab[i++]);
		sort_tab_3(a, b);
		i = 0;
		while (i < 3)
			printf("%d\n", a->tab[i++]);
	}
	printf("enter !! \n");
	if (argc > 2)
	{
		i = 0;
		a->tab = get_tab(argv, argc - 1);
		if (!a->tab || a->tab == NULL)
			return (ft_printf("error of arguments3\n"), 0);
		printf("premier elemtab ->%d\n", a->tab[0]);
		while (i < 3)
			printf("%d\n", a->tab[i++]);
		sort_tab_3(a, b);
		i = 0;
		while (i < 3)
			printf("%d\n", a->tab[i++]);
	}
	return (0);
}

#include "../includes/cube3d.h"

int main()
{
	char op[15] = "myname is Zed";
	char **sp = ft_split(op, ' ');
	int i = -1;
	while (sp[++i])
		printf("\n%s\n", sp[i]);
	return (0);
}

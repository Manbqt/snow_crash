#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_des(char *str)
{
	char *ret = strdup(str);
	char current_char;
	int index = 0;
	int n = 0;

	do
	{
		int max = __INT_MAX__;
		char *str_tmp = ret;
		do
		{
			if (max == 0)
				break;
			max--;
			current_char = *str_tmp;
			str_tmp = str_tmp + 1;
		} while (current_char);

		if (~max - 1 <= index)
			return ret;

		if (index == 6)
			index = 0;

		if ((n & 1) == 0)
		{
			for (int i = 0; i < "0123456"[index]; index++)
			{
				ret[index] = ret[index] - 1;
				if (ret[index] == 31)
					ret[index] = '~';
			}
		}
		else
		{
			for (int i = 0; i < "0123456"[index]; index++)
			{
				ret[index] = ret[index] + 1;
				if (ret[index] == 127)
					ret[index] = ' ';
			}
		}
	} while (1);
}

int main()
{
	uid_t uid = getuid();

	if (uid == 4242)
	{
		printf("your token is %s\n", ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I"));
	}
	else
	{
		printf("UID %d started us but we we expect %d\n", uid, 4242);
		exit(1);
	}
	return 0;
}

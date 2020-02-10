#include "libmp.h"

static long		chk_ovf(long result, short sign)
{
	if (sign == 1)
	{
		if (result > INT_MAX)
			return (0);
	}
	else if (sign == -1)
	{
		if ((result * (-1)) < INT_MIN)
			return (-1);
	}
	return (1);
}

static short	get_sign(const char **str)
{
	short sign;

	if (**str == '+')
	{
		sign = 1;
		(*str)++;
	}
	else if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else
		sign = 1;
	return (sign);
}

int				mp_atoi(const char *str)
{
	long	result;
	int		digit;
	int		ret;
	short	sign;

	result = 0;
	str = ft_skip_space(str);
	sign = get_sign(&str);
	if (str)
	{
		while (*str && ft_isdigit(*str))
		{
			digit = *str - '0';
			result = result * 10 + digit;
			ret = chk_ovf(result, sign);
			if (ret == -1 || ret == 0)
				return (ret);
			++str;
		}
	}
	return ((int)(result * sign));
}

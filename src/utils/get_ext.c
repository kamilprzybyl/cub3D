#include <cub3D.h>

const char	*get_ext(const char *file)
{
	const char	*dot;

	dot = ft_strrchr(file, '.');
	if(!dot || dot == file)
		return "";
	return (dot + 1);
}

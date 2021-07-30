# include <stdlib.h>
# include <stdio.h>

size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
size_t		ft_read(int fildes, void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);
void		file_wrt(int b, char *m, int c);

int	main(void)
{
	char *buff;
	char *write_buffer;
	char *dest;
	char read_buffer[5];

	buff = malloc(6);
	write_buffer = "abcdefg";
	printf("ft_strlen: %zu\n", ft_strlen("42seoul"));
	printf("ft_strcpy: %s\n", ft_strcpy(buff, "born to code"));
	printf("ft_strcmp: %d\n", ft_strcmp("qwer", "qwer"));
	printf("ft_strcmp: %d\n", ft_strcmp("qwer", "asdf"));
	printf("ft_strcmp: %d\n", ft_strcmp("qwer", "qwerty"));
	printf("%zd >> \n", ft_write(1, write_buffer, 5));
	printf("\n");
	printf("%zu\n", ft_read(0, read_buffer, 2));
	printf("read_buffer: %s\n", read_buffer);
	dest = ft_strdup("42");
	printf("ft_strdup: %s\n", dest);
	return (0);
}
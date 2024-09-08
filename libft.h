/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:58:17 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/08 18:38:37 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <sys/types.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(char *str);
int					ft_isalpha(int c);
void				ft_bzero(void *s, int n);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *s, int c, int n);
unsigned int		ft_strlcat(char *dest, char *src, unsigned int size);
int					ft_strlen(char *str);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
int					ft_strlcpy(char *dest, char *src, int size);
void				*ft_memcpy(void *dest, const void *src, size_t num);
void				*ft_memchr(void *s, int c, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
#endif

/*
1. int ft_isalpha(int c);
   - Simple check if a character is an alphabetic letter.

2. int ft_isdigit(int c);
   - Simple check if a character is a digit.

3. int ft_isalnum(int c);
   - Simple check if a character is alphanumeric.

4. int ft_isascii(int c);
   - Simple check if a character is an ASCII character.

5. int ft_isprint(int c);
   - Simple check if a character is printable.

6. int ft_toupper(int c);
   - Simple conversion from lowercase to uppercase.

7. int ft_tolower(int c);
   - Simple conversion from uppercase to lowercase.

8. int ft_strlen(char *str);
   - Counts the length of a string.

9. int ft_strncmp(char *s1, char *s2, unsigned int n);
   - Compares two strings up to n characters.

10. void ft_bzero(void *s, int n);
	- Sets n bytes of memory to zero.

11. void *ft_memset(void *s, int c, int n);
	- Fills the first n bytes of memory with a constant byte.

12. void *ft_memcpy(void *dest, const void *src, size_t num);
	- Copies num bytes from src to dest.

13. void *ft_memchr(void *s, int c, size_t num);
	- Scans memory for a character within num bytes.

14. void *ft_memmove(void *dest, const void *src, size_t n);
	- Copies n bytes from src to dest with overlap safety.

15. int ft_memcmp(const void *s1, const void *s2, size_t n);
	- Compares n bytes of two memory areas.

16. int ft_atoi(char *str);
	- Converts a string to an integer.

17. unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
	- Concatenates src to dest with size limitation.

18. int ft_strlcpy(char *dest, char *src, int size);
	- Copies a string with size limitation.

19. char *ft_strchr(const char *s, int c);
	- Locates the first occurrence of a character in a string.

20. char *ft_strrchr(const char *s, int c);
	- Locates the last occurrence of a character in a string.

21. char *ft_strnstr(const char *big, const char *little, size_t len);
	- Locates a substring in a string within len characters.

22. void *ft_calloc(size_t nmemb, size_t size);
	- Allocates memory for an array, initializes to zero.

23. char *ft_strdup(const char *s);
	- Duplicates a string using dynamic memory.

24. char *ft_strjoin(char const *s1, char const *s2);
	- Concatenates two strings into a new string.

25. char *ft_substr(char const *s, unsigned int start, size_t len);
	- Creates a substring from a given string.

26. char *ft_strtrim(char const *s1, char const *set);
	- Trims characters from the beginning and end of a string.

27. char **ft_split(char const *s, char c);
	- Splits a string into an array of strings based on a delimiter.
*/

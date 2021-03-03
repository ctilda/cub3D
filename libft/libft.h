/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:07:47 by ctilda            #+#    #+#             */
/*   Updated: 2021/02/25 12:29:07 by ctilda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_isalnum(int ch);
int					ft_isalpha(int ch);
int					ft_isascii(int ch);
int					ft_isprint(int ch);
int					ft_tolower(int word);
int					ft_toupper(int word);
int					ft_isdigit(int ch);
int					ft_atoi(const char *str);
int					ft_strlen(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memccpy(void *dest, const void *src,
					int end_sym, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr(char const *s);
void				ft_putendl_fd(char *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t destsize);
char				*ft_strchr(const char *str, int ch);
char				*ft_strdup(const char *str);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *str, int ch);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);

#endif

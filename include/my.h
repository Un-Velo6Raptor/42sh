/*
** my.h for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 10 13:57:28 2017 Martin Januario
** Last update Tue May 16 13:41:40 2017 Martin Januario
*/

#ifndef		MY_H_
# define	MY_H_

# include	<term.h>

typedef struct	s_key
{
  char		c[2];
  char		*key_l;
  char		*key_r;
  char		*key_sup;
  int		check;
  int		width;
  char		*cvvis;
  char		*civis;
  char		*bold;
  char		*key_t;	// Sahel  top
  char		*key_b; // Sahel  bottom
}		t_key;

/*
**		Prototypes of basics files.
*/
char		*my_realloc(char *, char *);
char		*my_realloc_sup(char *, int, int);
char		*my_realloc_idx(char *, char *, int);
int		my_strlen(char *);
void		my_free(char *);
int		my_puterror(char *);
int		my_putstr(char *);

/*
**		Prototypes of sources files.
*/
int		found_term(char **);
int		ini_keys(t_key *, char *);
int		check_is_key(t_key *, char *, int);
int		same_key(t_key *, char *, int *);
char		*my_reset(char *, t_key *);
char		*start_edit_line(char *, struct termios *,
				struct termios *, t_key *);
int		end_edit_line(struct termios *, t_key *);
int		is_a_key(t_key *, char **, int *, char **);
int		reset_line(int, char *, int, t_key *);
int		is_not_a_key(char **, char **, int *, t_key *);
char		*loop_read(t_key *keys, char *tmp, char *str);

#endif		/* !MY_H_ */

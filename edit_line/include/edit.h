/*
** edit.h for  in /home/januar_m/delivery/PSU/edit_line
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 17 15:38:26 2017 Martin Januario
** Last update Wed May 17 17:35:27 2017 Martin Januario
*/

#ifndef		EDIT_H_
# define	EDIT_H_

typedef struct	s_key
{
  int		idx;
  char		*key[6];
  /*
  **  char          *key_l;
  **  char          *key_r;
  **  char          *key_t;
  **  char          *key_b;
  **  char          *key_sup;
  */
}		t_key;

/*
**		Protoypes of files sources.
*/
int		found_term(char **);
int		ini_keys(t_key *, char *);
int		check_is_key(t_key *, char *, char *);
void		key_left_(t_key *, char *, char *);
void		key_right_(t_key *, char *, char *);
void		key_top_(t_key *, char *, char *);
void		key_bottom_(t_key *, char *, char *);
void		key_sup_(t_key *, char *, char *);
void		key_del_(t_key *, char *, char *);

/*
**		Protoypes of files basics.
*/
int		my_strlen(char *);
int		my_putstr(char *);
int		my_puterror(char *);

#endif		/* !EDIT_H_ */

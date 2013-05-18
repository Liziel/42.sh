/*
** env.c for  in
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat May 18 11:54:27 2013 vincent colliot
** Last update Sat May 18 20:28:06 2013 vincent colliot
*/

BOOL	print_help(void)
{
  my_putstr("Uasge: env [options]\n", 1);
  my_putstr("env built-in loads a temporary environment, wich is setted by:\n",
	    1);
  my_putstr("    -i      : unset all\n", 1);
  my_putstr("    -u {p}  : unset {p}\n", 1);
  my_putstr("    -s {v,p}: set {v} with {p}\n", 1);
  return (TRUE);
}

int print_str(char *str)
{
  int i;
  
  i = 0;
  while (str)
  {
    write(1, &str[i], 1);
    str += i;
    i++;
  }
  return (i);
}

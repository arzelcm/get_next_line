# get_next_line
Welcome to `free()` hell.

Enjoy!

Version: 12

## Desc
The aim of this function is to get the next line for a given `int fd` (file descriptor). It means everything until `\n` or `EOF`(end of file).

### Prototype
```C
char	*get_next_line(int fd);
```

### Return values
If valid: `char *` pointing to the first `char` of the `\0` terminated line string.

If not valid: `NULL` meaning wether there are no more lines or some error occurred.

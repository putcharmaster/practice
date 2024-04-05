char	*read_line(int fd, char *line);
char *buf and int b_read(bytes read)
if line is empty ft_calloc(1,1) for null character
buf = calloc(buffersize plus 1 for the null at the end. buffer size of char)
define b_read as 1 to make it into the while loop
while b_read is bigger than 0
then redefine b_read return value (-1, 0 or 1)read(fd, buf, buffer_size)
	if -1,  free the buf and return null
last char of buf[] = 0;
line will be freed 


char	*get_next_line(int fd);
buffer and line

if fd < 0 or BUFFER_SIZE is <= 0, return null
buffer will be "read_line(fd, buffer), if buffer == 0, return null
line will be "ft_line(buffer)"
(new)buffer will be ft_next(buffer)
	buffer value will be updated ergo static
return line.

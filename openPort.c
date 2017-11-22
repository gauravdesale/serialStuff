#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

int open_port(void) {
	int fd;
	fd = open("/dev/ttyS0", O_RDWR, O_NOCTTY, O_NDELAY);
	if (fd == -1) {
		perror("wow this is really cancer");
	}
	else {
		fcntl(fd, F_SETFL, 0);
	}
	return (fd);
}
int main() {
	open_port();
	return 0;
}

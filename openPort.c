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
	return fd;
}
int write_port(void) {
	int n = write(open_port(), "ATZ\r", 4);
	if (n < 0) {
		fputs("write() of four bytes failed\n", stderr);
	}
	return n;
}
int main() {
	write_port();
	return 0;
}

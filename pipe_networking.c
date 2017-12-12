#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Perofrms the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  int fd;
  char *pipename = "WKP";
  mkfifo("WKP", 0600);
  fd = open("WKP", O_RDONLY, 0);
  char buffer[256];
  read(fd , buffer, sizeof(buffer));
  close(fd);
  sscanf(buffer, &d, *to_client);
  write(*to_client, *pipename, sizeof(*pipename) );
  return fd;
}


/*=========================
  client_handshake
  args: int * to_server

  Perofrms the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  int fd;
  char *pipename = "PP";
  mkfifo(pipename, 0600);
  *to_server = open("WKP", O_WRONLY, 0);
  write(*to_server , &pipename, sizeof(pipename));
  fd = open(*pipename);//stufff
	    
  return fd;//PP's fd
}

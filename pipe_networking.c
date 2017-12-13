#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
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
  
  *to_client = open(buffer, O_WRONLY, 0);
  printf("buffer: %s\n", buffer);
  write(*to_client, pipename, sizeof(pipename) );
  printf("to_client: %d\n", *to_client);
  return fd;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  int fd;
  char *pipename = "PP";
  mkfifo(pipename, 0600);
  *to_server = open("WKP", O_WRONLY, 0);
  write(*to_server , pipename, sizeof(pipename));
  printf("to_server: %d\n", *to_server);

  char buffer[256];
  fd = open(pipename,O_RDONLY,0);//stuff
  read(fd , buffer, sizeof(buffer));
  close(fd);
  printf("fd2: %d\n",fd);
  return fd;//PP's fd
}

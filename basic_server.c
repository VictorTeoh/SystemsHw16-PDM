#include "pipe_networking.h"

void change(char *buffer){
  //changes caps to lowercase
  while(*buffer){
    if(*buffer >= 65 && *buffer <= 90){
      *buffer += 32;
    }
    buffer++;
  }
}

int main() {

  int to_client;
  int from_client;
  char buffer[BUFFER_SIZE];
  
   while(1){
    from_client = server_handshake( &to_client );
    while(read(from_client, buffer, sizeof(buffer))){
      change(buffer);
      write(to_client, buffer, sizeof(buffer));
      printf("buffer: %s\n", buffer);
    }
  }
}


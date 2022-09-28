#include "connect.h"


int init_channel (char *ip, int port, char *name) {
	char msg[CMD_LENGTH];
	struct sockaddr_in server;

	server.sin_addr.s_addr = inet_addr('127.0.0.1');//convert the ip to network byte order
	server.sin_family = AF_INET;//set the server's communications domain
  server.sin_port = htons(port);//convert port to network byte order
  
  int channel = socket(AF_INET, SOCK_STREAM, 0);//define a SOCK_STREAM socket
  
  if(channel < 0) {
    perror ("socket:");
    exit(1);
  }
  
  int connection_status = connect(channel, server, ) //use the defined channel to connect the slave to the master server
  
  if (connection_status < 0) {
    perror ("connect:");
    exit(1);
  }

  //send a greeting message back to master by loading a string into msg (hint: snprintf will come in handy)
  respond (channel, msg);
  return channel;
}

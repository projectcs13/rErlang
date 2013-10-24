#include <unistd.h>

#include "erl_interface.h"
#include "ei.h"


typedef unsigned char byte; 

int read_exact(byte *buf, int len);
int write_exact(byte *buf, int len);


int read_cmd(byte *buf){
  int len;
  
  if(read_exact(buf, 2) != 2)
    return(-1);
  len = (buf[0] << 8) | buf[1];
  return read_exact(buf, len);
}

int write_cmd(ei_x_buff *buff){
  byte li;

  li = (buff->index >> 8) & 0xff; 
  write_exact(&li, 1);
  li = buff->index & 0xff;
  write_exact(&li, 1);

  return write_exact(buff->buff, buff->index);
}

int read_exact(byte *buf, int len){
  int i, got=0;
  
  do{
    if ((i=read(0, buf+got, len-got)) <= 0)
      return (i);
    got += i;
  }while (got<len);
  
  return(len);
}

int write_exact(byte *buf, int len){
  int i, wrote = 0;

  do{
    if ((i=write(1, buf+wrote, len-wrote)) <=0)
      return (i);
    wrote += i;
  }while(wrote<len);
  
  return (len);
}  

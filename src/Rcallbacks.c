#include <stdio.h>

#include "Rcallbacks.h"

int Re_ReadConsole(RCCONST char *prompt, unsigned char *buf, int len, int addtohistory){
  fputs(prompt,stdout);
  fflush(stdout);
  if(fgets(buf,len,stdin)) return 1; else return 0;
}

void Re_ShowMessage(RCCONST char *buf){
  fprintf(stderr,"%s",buf); 
}

void Re_WriteConsoleEx(RCCONST char *buf, int len, int oType){
  fprintf(stderr,"%s",buf);
}


/* Indicate that input is coming from the console */
void Re_ResetConsole(){
  printf("Re_ResetConsole\n");
}

/* Stdio support to ensure the console file buffer is flushed */
void Re_FlushConsole(){
  printf("Re_FlushConsole\n");
}

/* Reset stdin if the user types EOF on the console. */
void Re_ClearerrConsole(){  
  fprintf(stderr,"Re_ClearerrConsole\n");
}
void Re_Busy(int which){
  printf("rBusy(%d)\n",which);
}

int Re_ShowFiles(int nfile, 		/* number of files */
                 RCCONST char **file,	/* array of filenames */
                 RCCONST char **headers,/* the `headers' args of file.show. Printed before each file. */
                 RCCONST char *wtitle,  /* title for window = `title' arg of file.show */
                 Rboolean del,	        /* should files be deleted after use? */
                 RCCONST char *pager)	/* pager to be used */{
  printf("Re_ShowFiles\n");
  return 1;
}

int Re_ChooseFile(int new, char *buf, int len){
  printf("Re_ChooseFile\n");
}

void Re_loadhistory(SEXP call, SEXP op, SEXP args, SEXP env){
  printf("Re_loadhistory\n");
}

void Re_savehistory(SEXP call, SEXP op, SEXP args, SEXP env){
  printf("Re_savehistory\n");
}

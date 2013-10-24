#include "rErlang.h"

SEXP add(SEXP a, SEXP b){
  int i, n;
  n = length(a);
  for(i=0; i < n; i++){
    REAL(a)[i] += REAL(b)[i];
  }
  return (a);
}

int  rE_init(){  
  erl_init(NULL,0);  
  return 1;
}

SEXP rE_connect(SEXP a){  
  int init;
  init =  rE_init();

  int identification_number = 99;
  int creation=1;  
  erl_connect_init(identification_number, COOKIE, creation);
  
  if ((fd = erl_connect(NODE_NAME)) >= 0){    
    return a;    
  }else {
    /* (failure) */
    switch (fd) {
    case ERL_NO_DAEMON:
      erl_err_quit("<ERROR> No epmd running!");
      break;
    case ERL_CONNECT_FAIL:
      erl_err_quit("<ERROR> Connect failed!");
      break;
    case ERL_NO_PORT:
      erl_err_quit("<ERROR> Node is not running!");
      break;
    case ERL_TIMEOUT:
      erl_err_quit("<ERROR> Connect timed out!");
      break;
    default:
      erl_err_quit("<ERROR> Error during connect! (%d)",fd);
      break;
    }
    return a;
  }  
}

SEXP rE_test(int num){

  ETERM *reply,*ep;
  SEXP result;

  ep = erl_format("[~i]", num);
  reply = erl_rpc(fd, "rErlang", "test", ep);

  result = ETERM2SEXP(reply);
    
  erl_free_term(ep);
  erl_free_term(reply);  

  return result;
}

SEXP rE_eval(SEXP str){

  
  SEXP result;
  int type;  
  
  type = TYPEOF(str);
  
  if(type == STRSXP){    
    char *buf;
    ETERM *reply,*ep;
    buf = CHAR(STRING_ELT(str,0));       
    ep = erl_format("[~s]", buf);
    reply = erl_rpc(fd, "rErlang", "eval", ep);
    
    result = ETERM2SEXP(reply);
    erl_free_term(ep);
    erl_free_term(reply);    
  }else{    
    result = NULL;
  }
  return result;  
}

SEXP bind_eterm(ETERM *eterm){
  
  SEXP result;

  if(ERL_IS_TUPLE(eterm)){
    int size = ERL_TUPLE_SIZE(eterm);    
  }

  erl_print_term(stderr,eterm);

  
  PROTECT(result = allocVector(STRSXP, 1));
  SET_STRING_ELT(result, 0, mkChar("ok"));
  UNPROTECT(1);

  return result;  
}

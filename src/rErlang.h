/* important changes between versions:

   0.1- first public release
 */
#include <Rinternals.h>
#include "erl_interface.h"
#include "ei.h"

#define COOKIE "rerlang"
#define NODE_NAME "node01@localhost"

#define ETERM2SEXP(a) bind_eterm(a);

int fd;
SEXP rE_connect();
SEXP rE_test(int num);
SEXP rE_eval(SEXP str);
SEXP bind_eterm(ETERM *eterm);

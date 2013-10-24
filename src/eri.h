#include <R.h>
#include <Rinternals.h>
#include <Rversion.h>

#include "erl_interface.h"
#include "ei.h"

#define SEXP2L(s) ((unsigned long)(s))
#define L2SEXP(s) ((SEXP)(unsigned long)(s))


/* the viewpoint is from R, i.e. "get" means "Erlang->R" whereas "put" means "R->Erlang" */

int setup();
long parse(const char *s);
long erl_eval(long exp);
int convert(long exp, ei_x_buff *result);
int terminate();

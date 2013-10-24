-module(rErlang).

% API
-export([test/1, eval/1]).

test(X)->
   X*2.

eval(Expr)->
    {ok, Tokens, _}=erl_scan:string(Expr),
    {ok,[Expression]} = erl_parse:parse_exprs(Tokens),
    {value, Ret, _} = erl_eval:expr(Expression ,erl_eval:bindings(erl_eval:new_bindings())),
    Ret.

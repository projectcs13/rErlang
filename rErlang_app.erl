-module(rErlang_app).
-export([start_deps/0]).

start_deps() ->
    start_deps(erlastic_search, permanent).

start_deps(App, Type) ->
    case application:start(App, Type) of
        ok ->
            ok;
        {error, {not_started, Dep}} ->
            start_deps(Dep, Type),
            start_deps(App, Type)
    end.

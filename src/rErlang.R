dyn.load("./rErlang-0.1.so")

add <- function(a, b){
    if(length(a) != length(b))
      stop("a and b must have same length!")
      .Call("add", as.double(a), as.double(b))
}

connect <- function(){
     result <- 0
     .Call("rE_connect",as.double(result))
     return (result)
}

eval <- function(expr){
     .Call("rE_eval",expr)
}

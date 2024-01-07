binaryConFunction(n){
  if(n>1){
    binaryConFunction(as.integer(n/2))
  }
  cat(n%%2)
}

binaryConFunction(11)
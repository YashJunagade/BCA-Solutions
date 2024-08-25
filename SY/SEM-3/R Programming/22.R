# Loop from 1 to 100
for (i in 1:100) {
  output <- ""
  
  # Check if the number is a multiple of 3
  if (i %% 3 == 0) {
    output <- "SY"
  }
  
  # Check if the number is a multiple of 5
  if (i %% 5 == 0) {
    output <- paste(output, "BBA", sep = "")
  }
  
  # Print the number or the combined output
  if (output == "") {
    cat(i, "\n")
  } else {
    cat(output, "\n")
  }
}

# Sample Weather dataset
Weather <- data.frame(
  Temperature = c(68, 72, 65, 75),
  WindSpeed = c(5, 8, 6, 10)
)

# Selecting using the column number
selected_columns_num <- Weather[, c(1, 2)]  # Corrected column numbers

# Selecting using the column name
selected_columns_name <- Weather[, c("Temperature", "WindSpeed")]

# Creating a scatter plot to compare Wind Speed and Temperature
library(ggplot2)

ggplot(Weather, aes(x = WindSpeed, y = Temperature)) +
  geom_point() +
  labs(x = "Wind Speed (mph)", y = "Temperature (°F)") +
  ggtitle("Scatter Plot of Wind Speed vs. Temperature")


weather = data.frame(
  Temperature = c(39, 24, 20, 40),
  WindSpeed = c(68, 56, 78, 29)
)

# Accessing columns by position
c1 = weather[, c(1, 2)]
print(c1)

# Accessing columns by name
c2 = weather[, c("Temperature", "WindSpeed")]
print(c2)

library(ggplot2)

# Corrected ggplot code
ggplot(weather, aes(x = WindSpeed, y = Temperature)) + 
  geom_point() +
  labs(x = "Speed (mph)", y = "Temperature (°C)")


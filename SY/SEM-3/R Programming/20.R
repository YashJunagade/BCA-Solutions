# Load necessary library
library(ggplot2)

# Load the dataset
df <- read.csv('wheater.csv')


# i) Selecting using the column number
# Let's select the first column (column index 1)
first_column <- df[, 1]

# ii) Selecting using the column name
# Let's select the 'Temperature' column
temperature <- df$Temperature

# iii) Make a scatter plot to compare Wind speed and temperature
ggplot(df, aes(x = WindSpeed, y = Temperature)) +
  geom_point() +
  labs(title = "Wind Speed vs Temperature", x = "Wind Speed", y = "Temperature")


# Load the built-in PlantGrowth dataset
data(PlantGrowth)

# i) Create a variable y and attach to it the output attribute of the PlantGrowth dataset
y <- PlantGrowth$group

# ii) Create a barplot to break down your output attribute
barplot(table(y), 
        main = "Barplot of Plant Groups", 
        col = "lightblue", 
        ylab = "Count", 
        xlab = "Group")

# iii) Create a density plot matrix for each attribute by class value
# Load required package for lattice plotting
library(lattice)

# Create density plot matrix for each attribute by class value
densityplot(~weight | group, 
            data = PlantGrowth, 
            main = "Density Plot Matrix", 
            layout = c(3, 1), 
            col = "lightgreen")

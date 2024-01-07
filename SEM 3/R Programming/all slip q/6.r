# Create a vector of marks for five subjects
marks <- c(85, 92, 78, 89, 95)

# Create a bar plot with reduced margins
par(mar = c(1, 1, 1, 1))  # Adjust the margins as needed (bottom, left, top, right)

barplot(marks, names.arg = c("Subject 1", "Subject 2", "Subject 3", "Subject 4", "Subject 5"),
        main = "Subject Marks",
        xlab = "Subjects",
        ylab = "Marks",
        col = "red",
        border = "black",
        ylim = c(0, 100))

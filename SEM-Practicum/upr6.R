data("airquality")
temp <- airquality$Temp
median(temp)
mean(temp)
sd(temp)

summary(temp)

mean(temp) - 3*sd(temp)
mean(temp) + 3*sd(temp)

boxplot(temp, horizontal=T)

ozone <- airquality$ozone
median(ozone, na.rm=T)
mean(ozone, na.rm=T)
sd(ozone, na.rm=T)

summary(ozone)

boxplot(ozone, horizontal=T)

#z43
library(MASS)
data(survey)
attach(survey)

median(Pulse, na.rm=T)
mean(Pulse, na.rm=T)
sd(Pulse, na.rm=T)

median(Pulse[Sex=="Fem"], na.rm=T)
mean(Pulse[Sex=="Fem"], na.rm=T)
sd(Pulse[Sex=="Fem"], na.rm=T)

median(Pulse[Age <= 25], na.rm=T)
mean(Pulse[Age <= 25], na.rm=T)
sd(Pulse[Age <= 25], na.rm=T)

median(Pulse[Exer=="Freq"], na.rm=T)
mean(Pulse[Exer=="Freq"], na.rm=T)
sd(Pulse[Exer=="Freq"], na.rm=T)

median(Pulse[Smoke == "Never" & Exer=="Freq"], na.rm=T)
mean(Pulse[Smoke == "Never" & Exer=="Freq"], na.rm=T)
sd(Pulse[Smoke == "Never" & Exer=="Freq"], na.rm=T)

##

#z44


#purvi nachin
boxplot( Pulse ~ Exer )

#vtori nachin
boxplot( Pulse[Exer=="Freq"],
         Pulse[Exer=="None"],
         Pulse[Exer=="Some"])

##
x <- rnorm(100,5,1)
y <- 2*x
plot(x, y)
cor(x,y)  ##smqta korelaciq

x <- rnorm(100,5,1)
y <- (-2)*x
plot(x, y)
cor(x,y)  ##smqta korelaciq

x <- rnorm(100,5,1)
y <- 2*x + rnorm(100,0,1)
plot(x, y)
cor(x,y)  ##smqta korelaciq

##
getwd() ##dava ni rabotnata direktoriq

grades <- read.table( "exam_grades.txt", header=T )
attach(grades)

## grades <- read.table( "celiq put", header=T )

#z45

#a)
plot(test1, course.grade)
plot(test2, course.grade)
plot(test3, course.grade)

cor(test1, course.grade, use="complete.obs")
cor(test2, course.grade, use="complete.obs")
cor(test3, course.grade, use="complete.obs")

#b)

boxplot( course.grade ~ sex )

median(course.grade[sex=="Man"])
median(course.grade[sex=="Woman"])

mean(course.grade[sex=="Man"])
mean(course.grade[sex=="Woman"])

# c)

boxplot( course.grade ~ semester )

#z46

x <- runif(500, 3, 7) # a)
x <- rexp(500, 1/5) # b)
x <- rnorm(500, 5, 1) # c)
#boxplot(x, horizontal = T)

i1 <- min( mean(x) - 3*sd(x), min(x) )
i2 <- max( mean(x) + 3*sd(x), max(x) )

boxplot(x, ylim=c(i1,i2) , horizontal = T)
points( mean(x), 1, pch=18, col="darkorange1", cex=1.7)
points( mean(x) - 3*sd(x), 1, pch="[", col="darkorange1", cex=1.5)
points( mean(x) + 3*sd(x), 1, pch="]", col="darkorange1", cex=1.5)





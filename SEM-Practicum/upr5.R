library(MASS)
data(survey)

sum(survey$Exer=="Freq")
levels(survey$Exer)

#z36
table(survey$Exer)

attach(survey)
table(Exer)
sort(table(Exer), decreasing = T)
100 *table(Exer) / length(Exer)

barplot( table(Exer) )
barplot(sort(table(Exer), decreasing = T))

pie(table(Exer), col=c("red", "yellow", "blue"))

#z37
table(Smoke)
table(Smoke, useNA = "ifany")

sort(table(Smoke), decreasing = T)
100 *table(Smoke) / length(Smoke)

barplot( table(Smoke))
barplot( sort(table(Smoke), decreasing = T) )
barplot( 100 *table(Smoke) / length(Smoke) )

#z38

#a
tb <- 100 *table(Smoke) / length(Smoke)
tb[2]
tb["Never"]

#b
table(Smoke, Exer)
table(Smoke, Exer)[2,1]
table(Smoke, Exer)["Never","Freq"]

#v
100*table(Smoke, Exer) / sum(table(Smoke, Exer))
tab.smoke.exer <- table(Smoke, Exer)
100 * prop.table(tab.smoke.exer) #sumata na vsichki chisla v tablicata shte e 100
100 * prop.table(tab.smoke.exer)[2,1]
100 * prop.table(tab.smoke.exer)["Never", "Freq"]

#g
100 * prop.table(tab.smoke.exer, margin=1) # sumata na vseki red shte e 100
100 * prop.table(tab.smoke.exer, margin=1)[2,1]
100 * prop.table(tab.smoke.exer, margin=1)["Never", "Freq"]

#d
100 * prop.table(tab.smoke.exer, margin=2) # sumata na vsqka kolona shte e 100
100 * prop.table(tab.smoke.exer, margin=2)[2,1]
100 * prop.table(tab.smoke.exer, margin=2)["Never", "Freq"]

#z39
barplot(table(Smoke,Exer), legend=T)
barplot(table(Smoke,Exer), legend=T,
        args.legend = list(x="top"))

barplot(100*prop.table(tab.smoke.exer, 2),
        legend=T, xlim=c(0,5),
        args.legend=list(x="right"))

#z40
barplot(table(Exer,Smoke), legend=T,
        args.legend = list(x="topright"))
barplot(table(Exer,Smoke), legend=T,
        beside=T,
        args.legend = list(x="topright"))


#z41

table(Pulse, useNA="ifany")
pulse.grp <- cut(Pulse, breaks=seq(30,110,10)) #interval: ot 30 do 110 prez 10
pulse.grp
table(pulse.grp)
barplot(table(pulse.grp))
hist(Pulse)
hist(Pulse, breaks=seq(30,110,5))
stripchart(Pulse, method = "stack", pch=20)

#z42
table(Age, useNA = "ifany")
age.grp <- cut(Age, breaks=seq(15,75,10))
table(age.grp)

hist(Age)
stripchart(Age, method = "stack", pch=20)














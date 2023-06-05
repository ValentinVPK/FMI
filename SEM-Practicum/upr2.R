
##Zad3


anyDuplicated(x) > 0

sim.bday <- function(k) {
  x <- sample( c(1:365), k, replace=TRUE)
  anyDuplicated(x) > 0
}

sim.bday(25)

rs <- replicate( 100000, sim.bday(25))
sum(rs)/length(rs)

prob.bday <- function(Nrep, k) {
  rs <- replicate( Nrep, sim.bday(k))
  sum(rs)/length(rs)
}

prob.bday(100000,25)
prob.bday(100000,23)

##

##Zad4

q <- c(rep(1,3), rep(2,17)) ## vektor s 3 edinici i 17 dvoiki
q
x <- sample(q, 2, replace=FALSE) ## generirame permutaciq
x
sum(x)==3

sim.exam <- function() {
  q <- c(rep(1,3), rep(2,17)) ## vektor s 3 edinici i 17 dvoiki
  x <- sample(q, 2, replace=FALSE)
  sum(x)==3
}

sim.exam()

prob.exam <- function(Nrep) {
  rs <- replicate( Nrep, sim.exam() )
  sum(rs)/length(rs)
}

prob.exam(100000)

## zad 5 1-vi nachin
sim.keys <- function() {
  x <- sample( c(1,0,0,0,0), 5, replace=F)
  x[5] == 1 ## dali na 5-to mqsto ima edinica
}

sim.keys()

prob.keys <- function(Nrep) {
  rs <- replicate( Nrep, sim.keys() )
  sum(rs)/length(rs)
}

prob.keys(100000)

## zad 5 - vtori nachin

sim.keys1 <- function() {
  x <- sample( c(1:5), 5, replace=F)
  x[5] == 1 ## dali na 5-to mqsto ima edinica
}

sim.keys1()

prob.keys1 <- function(Nrep) {
  rs <- replicate( Nrep, sim.keys() )
  sum(rs)/length(rs)
}

prob.keys1(100000)

## zad 6
sim.ants <- function() {
  a <- vector("numeric", length=3)
  a[1] <- sample( c(2,3), 1 )
  a[2] <- sample( c(1,3), 1 )
  a[3] <- sample( c(1,2), 1 )
  ##c(1,2,3) %in% a - za vseki ot elementite na vektora (1,2,3) dali go ima v a
  all(c(1,2,3) %in% a) ## all vrushta true ako navsqkude imame true v podadeniq vektor
}

prob.ants <- function(Nrep) {
  rs <- replicate( Nrep, sim.ants() )
  sum(rs)/length(rs)
}

prob.ants(100000)

## zad 7 - uslovna veroqtnost


card <- sample( c("bb", "ww", "bw"), 1)
card
side <- sample( c(1,2), 1)
side
up <- substr(card, start=side, stop=side)
c(up, card)

sim.bw <- function() {
  card <- sample( c("bb", "ww", "bw"), 1)
  side <- sample( c(1,2), 1)
  up <- substr(card, start=side, stop=side)
  c(up, card)
}

sim.bw()

rs <- replicate( 1000, sim.bw() )

sum( rs[2,]=="ww" ) / sum( rs[1,]=="w") ##[2,] - vtoriq red na matricata

## zad 8

x <- sample( c(1:5), 2, replace=T )
x
x[1]==x[2]


sim.balls <- function() {
  x <- sample( c(1:5), 2, replace=T )
  x[1]==x[2]
}

sim.balls()

prob.balls <- function(Nrep) {
  rs <- replicate( Nrep, sim.balls() )
  sum(rs)/length(rs)
}

prob.balls(100000)

## zad 9

x <- sample( c(1,1,2,2,3,3), 2, replace=F )
x
x[1] == x[2]

sim.socks <- function() {
  x <- sample( c(1,1,2,2,3,3), 2, replace=F )
  x[1]==x[2]
}

sim.socks()

prob.socks <- function(Nrep) {
  rs <- replicate( Nrep, sim.socks() )
  sum(rs)/length(rs)
}

prob.socks(100000)



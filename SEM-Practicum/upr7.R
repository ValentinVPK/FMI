myplot1 <- function(rs.mean, rs.sd, true.val) {
  i1 <- min(rs.mean) - max(rs.sd) # zdavat granicite na grafikata
  i2 <- max(rs.mean) + max(rs.sd)
  
  plot( 1, xlim=c(0,11), ylim=c(i1,i2), pch="", 
        xlab="", ylab="",  xaxt="n" ) # pravi prazna grafika, v koqto sme zadali granica na x i y
  abline( h=true.val, col="red", lwd=1.4 ) # dobavqme horizontalna liniq na visochina 
  arrows( c(1:10), rs.mean-rs.sd, c(1:10), rs.mean+rs.sd, 
          code=3, angle=90, 
          length=0.05, lwd=1.4, col=c("gray55", "blue3") ) #dobavqme sinite chertichki 
  points( c(1:10), rs.mean, pch=20, type="p", 
          col=c("gray55", "blue3") ) # dobavq tochkite
  axis( side=1, at=seq(1.5, 9.5, 2), 
        labels=c(20, 50, 100, 500, 1000), tick=FALSE ) # dobavq leibalite na osta x, i q pravi bez chertichki
}


#z50

sim.unif.med <- function (n,b) {
  x <- runif(n, 0, b) ## generirame n sluchaini chisla ravnomerno v intervala ot 0 do b
  est1 <- max(x) / 2
  est2 <- median(x)
  
  c(est1, est2)
}

rs1 <- replicate(30000, sim.unif.med(n = 20, b=8))
rs2 <- replicate(30000, sim.unif.med(n = 50, b=8))
rs3 <- replicate(30000, sim.unif.med(n = 100, b=8))
rs4 <- replicate(30000, sim.unif.med(n = 500, b=8))
rs5 <- replicate(30000, sim.unif.med(n = 1000, b=8))

rs <- rbind(rs1, rs2, rs3, rs4, rs5)

rs.mean <- apply( rs, 1, mean) ## s apply vurhu vseki red na matricata rs prilagame funckiqta mean, toest za vseki red na matricata shte smetne srednoto na reda
rs.sd <- apply(rs, 1, sd) ## analogichno za vseki red sus sd smqtame standartnoto otklonenie, ako e 2 vmesto 1 shte go priloji na vsqka kolona, a ne na vseki red
rs.mean
rs.sd

true.val <- 4

myplot1(rs.mean, rs.sd, true.val)

#z51

sim.exp.med <- function(n, lambda) {
  x <- rexp(n, lambda)
  est1 <- mean(x)*log(2)
  est2 <- median(x)
  c(est1, est2)
  
}

rs1 <- replicate(30000, sim.exp.med(n = 20, lambda = 1/5) )
rs2 <- replicate(30000, sim.exp.med(n = 50, lambda = 1/5) )
rs3 <- replicate(30000, sim.exp.med(n = 100, lambda = 1/5) )
rs4 <- replicate(30000, sim.exp.med(n = 500, lambda = 1/5) )
rs5 <- replicate(30000, sim.exp.med(n = 1000, lambda = 1/5) )

rs <- rbind(rs1, rs2, rs3, rs4, rs5)

rs.mean <- apply( rs, 1, mean) ## s apply vurhu vseki red na matricata rs prilagame funckiqta mean, toest za vseki red na matricata shte smetne srednoto na reda
rs.sd <- apply(rs, 1, sd) ## analogichno za vseki red sus sd smqtame standartnoto otklonenie, ako e 2 vmesto 1 shte go priloji na vsqka kolona, a ne na vseki red
rs.mean
rs.sd

true.val <- 5*log(2)
myplot1(rs.mean, rs.sd, true.val)

## z49

sim.norm.prob <- function(n, mu, sigma, a) {
  x <- rnorm(n, mu, sigma) ## generirame chisla sus sluchaino razpredelnie
  est1 <- pnorm(a, mean(x), sd(x))
  est2 <- sum( x <= a)/n
  c(est1, est2)
}

rs1 <- replicate(30000, sim.norm.prob(n = 20, mu = 5, sigma = 1, a=4.5) )
rs2 <- replicate(30000, sim.norm.prob(n = 50, mu = 5, sigma = 1, a=4.5) )
rs3 <- replicate(30000, sim.norm.prob(n = 100, mu = 5, sigma = 1, a=4.5) )
rs4 <- replicate(30000, sim.norm.prob(n = 500, mu = 5, sigma = 1, a=4.5) )
rs5 <- replicate(30000, sim.norm.prob(n = 1000, mu = 5, sigma = 1, a=4.5) )


rs <- rbind(rs1, rs2, rs3, rs4, rs5)

rs.mean <- apply( rs, 1, mean) ## s apply vurhu vseki red na matricata rs prilagame funckiqta mean, toest za vseki red na matricata shte smetne srednoto na reda
rs.sd <- apply(rs, 1, sd) ## analogichno za vseki red sus sd smqtame standartnoto otklonenie, ako e 2 vmesto 1 shte go priloji na vsqka kolona, a ne na vseki red
rs.mean
rs.sd

true.val <- pnorm(4.5, 5, 1)

myplot1(rs.mean, rs.sd, true.val)

#z52

# a)
sim.norm.sd <- function(n, mu, sigma) {
  x <- rnorm(n, mu, sigma) ## generirame chisla sus sluchaino razpredelnie
  x.bar <- mean(x)
  est1 <- sqrt( sum((x - x.bar)^2)/n)
  est2 <- sqrt( sum((x - x.bar)^2)/(n - 1))
  c(est1, est2)
}

rs1 <- replicate(30000, sim.norm.sd(n = 20, mu = 5, sigma = 2) )
rs2 <- replicate(30000, sim.norm.sd(n = 50, mu = 5, sigma = 2) )
rs3 <- replicate(30000, sim.norm.sd(n = 100, mu = 5, sigma = 2) )
rs4 <- replicate(30000, sim.norm.sd(n = 500, mu = 5, sigma = 2) )
rs5 <- replicate(30000, sim.norm.sd(n = 1000, mu = 5, sigma = 2) )

rs <- rbind(rs1, rs2, rs3, rs4, rs5)

rs.mean <- apply( rs, 1, mean) ## s apply vurhu vseki red na matricata rs prilagame funckiqta mean, toest za vseki red na matricata shte smetne srednoto na reda
rs.sd <- apply(rs, 1, sd) ## analogichno za vseki red sus sd smqtame standartnoto otklonenie, ako e 2 vmesto 1 shte go priloji na vsqka kolona, a ne na vseki red
rs.mean
rs.sd
true.val <- 2

myplot1(rs.mean, rs.sd, true.val)

# b)

rs.mean <- apply( rs^2, 1, mean) ## s apply vurhu vseki red na matricata rs prilagame funckiqta mean, toest za vseki red na matricata shte smetne srednoto na reda
rs.sd <- apply(rs^2, 1, sd) ## analogichno za vseki red sus sd smqtame standartnoto otklonenie, ako e 2 vmesto 1 shte go priloji na vsqka kolona, a ne na vseki red
rs.mean
rs.sd
true.val <- 4

myplot1(rs.mean, rs.sd, true.val)




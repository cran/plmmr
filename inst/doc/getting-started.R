## ----include = FALSE----------------------------------------------------------
knitr::opts_chunk$set(
  collapse = TRUE,
  comment = "#>"
)

## ----setup--------------------------------------------------------------------
library(plmmr)

## -----------------------------------------------------------------------------
# library(plmmr)
fit <- plmm(admix$X, admix$y) # admix data ships with package
plot(fit)

cvfit <- cv_plmm(admix$X, admix$y)
plot(cvfit)
summary(cvfit)


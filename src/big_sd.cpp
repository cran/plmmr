#include "utilities.h"

RcppExport SEXP big_sd(SEXP X_, SEXP ncore_){

  // declarations
  //Rprintf("\nDeclarations in big_sd()");
  XPtr<BigMatrix> X(X_); // points to the filebacked matrix of rotated data
  //MatrixAccessor<double> X_acc(*X);
  int n = X->nrow();
  int p = X->ncol();


  // set up omp
  //Rprintf("\n set up OpenMP");
  int useCores = INTEGER(ncore_)[0];
#ifdef PLMMR_OMP_H_
  int haveCores = omp_get_num_procs();
  if(useCores < 1) {
    useCores = haveCores;
  }
  omp_set_dynamic(0);
  omp_set_num_threads(useCores);
#endif

  // calculate sd
  //Rprintf("\nCalling sd()");
  NumericVector sd_vals;
  sd_vals = sd(X, n, p);

  //Rprintf("\nreturn result");
  Rcpp::List result;
  result["sd_vals"] = sd_vals;
  return result;

}

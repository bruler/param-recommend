// example.c
// version 1.03
//#################################
//#				  #
//# Calling the driver routine	  #
//#				  #
//#################################


// Compiling
//---------

// gcc -Wall example.c -c -I../include/

// Linking
//--------

// Linking requires the library libnnmf.a (or libnnmf.so)
// This library can be created using the provided Makefile and target 'lib' (or target 'shared' for libnnmf.so)

// Using generic blas/lapack routines:		-lnnmf -larpack -llapack -lblas(depending on system maybe -lgfortran)
// Using atlas blas/lapack routines:		-lnnmf -larpack -llapack -lf77blas -lcblas -latlas (depending on system maybe -lgfortran)
// Using goto blas and generic lapack		-lnnmf -larpack -llapack -lgoto(depending on system maybe -lgfortran)

#include <stdio.h>
#include "nmfdriver.h"
#include "loadmatrix.h"


/** main function
 *
 */
int main(int argc, char** argv) {
  
// @ 1. call - default options
//############################
  
  // calling parameters:		exemplary values		comment
  //##########################################################################################################################################
  
  // filename matrix a			"a.matrix"			Matrix to be factorized			
  // factor k				25				approximation rank, has to be smaller than original matrix dimensions
  // max. iterations			100				
  // filename initial matrix w0		NULL				set to NULL to generate a matrix in the first repetition as well
  // filename initial matrix h0		NULL				set to NULL to generate a matrix in the first repetition as well
  // algorithm				"als" 	 			set to one of the implemented algorithms
  // options to be used			NULL				set to NULL to use default options
  
  
  // load and factorize matrix "a.dat" using random initialization and store resulting factor matrices
  printf("ALSPG Algorithm, Default-Random Initialization:\n");
  nmfDriver("emaildata.matrix", 25, 100, NULL, NULL, alspg, NULL);
  
// @ 2. call - explicitly set options: nndsvd initialization
//####################################
  
  
  // options is of type options_t* with following elements
  //######################################################
  
  // int rep;				1				Number of repetitions with new starting matrices
  // init_t init;			nndsvd				Method to use for initialising the starting matrices
  // int min_init;			0				minimal value for random initialisation
  // int max_init;			1				maximal value for random initialisaton
  // char* w_out;			"final_w.matrix"		Filename to write final matrix w to
  // char* h_out;			"final_h.matrix"		Filename to write final matrix h to
  // double TolX;			2.0E-02				tolerance value for convergence check of maxChange
  // double TolFun;			2.0E-02				tolerance value for convergence check of dnorm
  // int nndsvd_maxiter			-1				maxiter in nndsvd initialization (-1 requests setting of default value)
  // int nndsvd_blocksize		1				blocksize in nndsvd initialization; !! only works for 1 so far
  // double nndsvd_tol			2E-08				tolerance value for nndsvd initialization
  // int nndsvd_ncv			-1				length of arnoldi iteration (-1 requests setting of default value)
  
  // Creating option structure
  options_t opts;
  opts.rep = 1;
  opts.init = init_nndsvd;
  opts.min_init = 0;
  opts.max_init = 1;
  opts.w_out = "final_w.matrix";
  opts.h_out = "final_h.matrix";
  opts.TolX = 2.0E-02;
  opts.TolFun = 2.0E-02;
  opts.nndsvd_maxiter = -1;			//if set to -1 - default value will be set in generateMatrix
  opts.nndsvd_blocksize = 1;
  opts.nndsvd_tol = 2E-08;
  opts.nndsvd_ncv = -1;		

  // load and factorize matrix "a.dat" using nndsvd initialization and store resulting factor matrices
  printf("MU Algorithm, NNDSVD Initialization:\n");  
  nmfDriver("emaildata.matrix", 25, 100, NULL, NULL, mu, &opts);
  
  
  // @ 3. call - explicitly set options: gainratio initialization
//####################################
  
  
  // options is of type options_t* with following elements
  //######################################################
  
  // int rep;				1				Number of repetitions with new starting matrices
  // init_t init;			nndsvd				Method to use for initialising the starting matrices
  // int min_init;			0				minimal value for random initialisation
  // int max_init;			1				maximal value for random initialisaton
  // char* w_out;			"final_w.matrix"		Filename to write final matrix w to
  // char* h_out;			"final_h.matrix"		Filename to write final matrix h to
  // double TolX;			2.0E-02				tolerance value for convergence check of maxChange
  // double TolFun;			2.0E-02				tolerance value for convergence check of dnorm
  // int nndsvd_maxiter			-1				maxiter in nndsvd initialization (-1 requests setting of default value)
  // int nndsvd_blocksize		1				blocksize in nndsvd initialization; !! only works for 1 so far
  // double nndsvd_tol			2E-08				tolerance value for nndsvd initialization
  // int nndsvd_ncv			-1				length of arnoldi iteration (-1 requests setting of default value)
  
  // Creating option structure
  opts.rep = 1;
  opts.init = init_gainratio;
  opts.min_init = 0;
  opts.max_init = 1;
  opts.w_out = "final_w.matrix";
  opts.h_out = "final_h.matrix";
  opts.TolX = 2.0E-02;
  opts.TolFun = 2.0E-02;
  
  //load necessary class Column vector
  int m, n;
  loadMatrix("emailclasscolumn.matrix", &m, &n, &(opts.classColumn) );	// loads matrix "emailclasscolumn.matrix" into "opts.classColumn"
  opts.num_dist_classes = 3;						//3 mail classes -- alternative: count distinct classes in class column vector
  opts.parallelization = par_openmp;					//OpenMP parallelization || Default is pthreads


  // load and factorize matrix "a.dat" using nndsvd initialization and store resulting factor matrices
  printf("NEALS Algorithm, GainRatio Initialization using OpenMP parallelization:\n");  
  nmfDriver("emaildata.matrix", 25, 100, NULL, NULL, neals, &opts);
  
  
  //free class Column vector.




  return 0;
}

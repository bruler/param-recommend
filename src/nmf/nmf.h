#pragma once

#ifndef NMF_H_
#define NMF_H_

#include <pthread.h>
#include <time.h>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include "sparse.h"
#include "lfm.h"

#define T_REGRESS  1
#define T_CLASSIFY 2
#define LIMITED_EPOCHS  100
#define LIMITED_VALIDATE 10

namespace skunk {
  class LFM;

  class NMFParams {
  public:
    int type;
    int num_factor;
    double sigma;
    double lambda;
    int max_epoch;
    double alpha;
    int validate;

  public:
    NMFParams();
    NMFParams(int _type, int _num_factor, double _sigma, \
      double _lambda, int _max_epoch, double _alpha, int _validate);
    virtual ~NMFParams();
  };


  class NMF {
  public:
    static pthread_rwlock_t rwlock;

  private:
    typedef struct{
      int row;
      int col;
      double val;
    }Triplet;

    Triplet* data;

    double loss_train[LIMITED_EPOCHS];
    double loss_validate[LIMITED_EPOCHS];

    double clf_err_train[LIMITED_EPOCHS];
    double clf_err_validate[LIMITED_EPOCHS];

    int num_train;
    int num_validate;

    NMFParams* _params;
    SparseMatrix* _matrix;
    LFM* _model;

  public:
    NMF();

    LFM* train(NMFParams* params, SparseMatrix* matrix, std::string path);
    void validate(int start, int end, int epoch);
    double predict(Triplet* p);
    void test(std::string in, std::string out);

    NMFParams* getNMFParams(){ return _params; }
    void setNMFParams(NMFParams* params){
      _params = params;
    }

    SparseMatrix* getSparseMatrix(){return _matrix;}
    void setSparseMatrix(SparseMatrix* matrix){
      _matrix = matrix;
    }

    LFM* getLFM(){return _model;}
    void setLFM(LFM* model){
      _model = model;
    }

    virtual ~NMF();
    static void* run_helper(void *params);
  };
}

#endif  // NMF_H_

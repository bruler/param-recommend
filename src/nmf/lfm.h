#pragma once

#ifndef LFM_H_
#define LFM_H_

#include <strstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <stdexcept>
#include "sparse.h"
#include "nmf.h"

#define PI 3.141592654

namespace skunk {
  class LFM {
  private:
    SparseMatrix *matrix;
    int type;
    int num_factor;
    double sigma;
    bool init_params(double *v, int size);

  public:
    LFM();
    LFM(SparseMatrix* matrix, int type, int num_factor, double sigma);

    bool dump(std::string path);
    bool load(std::string path);
    bool swap();

    SparseMatrix* getSparseMatrix(){ return matrix; }
    void setSparseMatrix(SparseMatrix* _matrix){ matrix = _matrix; }

    int getType(){ return type; }
    void setType(int _type){ type = _type; }

    int getNumFactor(){ return num_factor; }
    void setNumFactor(int _num_factor){ num_factor = _num_factor; }

    double getSigma(){ return sigma; }
    void setSigma(double _sigma){ sigma = _sigma; }

    virtual ~LFM();

  public:
    double *P, *P0, *P1;
    double *Q, *Q0, *Q1;
    double *bu, *bu0, *bu1;
    double *bi, *bi0, *bi1;
    double mu;
  };
}

#endif  // LFM_H_

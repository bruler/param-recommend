#pragma once

#ifndef SPARSE_H_
#define SPARSE_H_

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256

namespace skunk {
  class SparseMatrix {
  private:
    std::map<std::string, int>* _rows;
    std::map<std::string, int>* _cols;
    std::map<std::pair<int, int>, std::vector<double>*>* _kv_dict;
    double _sum;
    int _size;

  public:
    SparseMatrix();
    SparseMatrix(std::map<std::string, int>* rows, std::map<std::string, int>* cols);

    bool get_rating(const std::string& row, const std::string& col, std::vector<double>* rating_list);
    bool set_rating(const std::string& row, const std::string& col, double rating);

    int kv_size(){ return _kv_dict->size(); }
    int size(){ return _size; }
    double sum(){ return _sum; }

    std::map<std::string, int>* rows(){return _rows;}
    std::map<std::string, int>* cols(){return _cols;}
    std::map<std::pair<int, int>, std::vector<double>*>* kv_dict(){return _kv_dict;}

    static SparseMatrix* load(std::string path);
    static SparseMatrix* load(std::string path, std::map<std::string, int>* rows, std::map<std::string, int>* cols);

    void print_info();

    virtual ~SparseMatrix ();
  };
}

#endif  // SPARSE_H_

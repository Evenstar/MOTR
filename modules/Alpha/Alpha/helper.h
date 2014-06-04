//
//  Header.h
//  Alpha
//
//  Created by ChengTai on 5/22/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef HELPER_H
#define HELPER_H

using namespace std;
void LoadFilter(vector<FilterType>& filter, string fname);

MatType Conv2_Valid(const MatType& a, const MatType& b);

/**
 * @param a The first parameter.
 * @param b The second parameter.
 */
MatType Conv2(const MatType& a, const MatType& b, string boundarytype);

///convert an opencv format image to a Eigen format matrix.
///
///The input is requierd to have one channel.
MatType Img2Mat(ImgType& img);

ImgType Mat2Img(MatType& mat);

vector<FilterType> GenerateRandomFilter(int _ninmaps, int _noutmaps,
                                        int _kernelsize);

MatType GenerateRandomWeights(int _fanin, int _fanout);

MatType MaxPooling( const MatType &, int stride, int side);

MatType ApplyReLU( const MatType &);

void printVector(VecMatPtr ptr);

void displayVector(VecMatPtr ptr);















#endif

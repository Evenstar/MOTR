//
//  Header.h
//  Alpha
//
//  Created by ChengTai on 5/22/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef HELPER_H
#define HELPER_H


void LoadFilter(vector<FilterType>& filter, string fname);

MatType Conv2_Valid(const MatType& a, const MatType& b);

MatType Conv2(const MatType& a, const MatType& b, BoundaryType boundarytype);

///convert an opencv format image to a Eigen format matrix.
MatType Img2Mat(ImgType& img);

#endif
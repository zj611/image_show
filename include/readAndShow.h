//
// Created by zj on 19-3-18.
//

#ifndef SMALL_PROJECT_READANDSHOW_H
#define SMALL_PROJECT_READANDSHOW_H

#include <readImg.h>
#include <opencv/cv.h>
#include<opencv2/core/core.hpp>

namespace small_P
{
    class readAsMat
    {
    public:
        readAsMat(read_img* read);

        void LoadAImag(cv::Mat &a,cv::Mat &b,double &t,int i);

        read_img* READ;
    };
}

#endif //SMALL_PROJECT_READANDSHOW_H

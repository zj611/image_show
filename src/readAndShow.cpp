//
// Created by zj on 19-3-18.
//
#include <iostream>
#include <readAndShow.h>
#include <assert.h>
#include <opencv2/imgcodecs.hpp>

using namespace cv;
namespace small_P
{
    readAsMat::readAsMat(read_img* read):READ(read){}

    void readAsMat::LoadAImag(cv::Mat &a_left,cv::Mat &a_right,double &t_stamp,int i)
    {
        assert(i>=0&&i<READ->getNum());
        if(READ->vstrImageLeft.empty()||READ->vstrImageRight.empty())
            std::cout<<"msg is not loaded"<<endl;
        a_left = cv::imread(READ->vstrImageLeft[i]);
        a_right = cv::imread(READ->vstrImageRight[i]);
        t_stamp = READ->vTimestamps[i];

    }
}
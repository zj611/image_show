#include <iostream>
#include <readImg.h>
#include <readAndShow.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core/core.hpp>
#include <cv.hpp>


using namespace small_P;

void DrawTextInfo(cv::Mat &im, const double& time, cv::Mat &imText,int& i)
{
    stringstream s;

        s << " No."<<i<<"  Timestamps:" << time <<" s";


    int baseline=0;
    cv::Size textSize = cv::getTextSize(s.str(),cv::FONT_HERSHEY_PLAIN,1,1,&baseline);

    imText = cv::Mat(im.rows+textSize.height+40,im.cols,im.type());
    im.copyTo(imText.rowRange(0,im.rows).colRange(0,im.cols));
    imText.rowRange(im.rows,imText.rows) = cv::Mat::zeros(textSize.height+40,im.cols,im.type());
    cv::putText(imText,s.str(),cv::Point(5,imText.rows-5),cv::FONT_HERSHEY_PLAIN,3,cv::Scalar(255,0,255),3,8);
    /*第一个参数是：需要写字的原图像，
      第二个：需要写的内容，string类型的；
      第三个：需要写的内容的左下角的坐标
      第四个：字体风格
      第五个：字体大小
      第六个：颜色
      第七个：字体的厚度
      第八个：默认8
      */
}
int main()
{
    string s = "your path";
    cv::Mat left,right;
    double t;

    read_img* read;
    read = new read_img(s);
    read->ss = s;
    readAsMat visual1(read);


    visual1.READ->LoadImages();//往 left right中添加Mat格式的图片

    cout<<visual1.READ->vstrImageLeft[2]<<endl;

    cvNamedWindow("left image",CV_WINDOW_NORMAL);
    cvNamedWindow("right image",CV_WINDOW_NORMAL);
    for(int i=0;i<visual1.READ->getNum();i++)
    {
        visual1.LoadAImag(left,right,t,i);

        cv::Mat Info_left,Info_right;

        DrawTextInfo(left,t,Info_left,i);
        DrawTextInfo(right,t,Info_right,i);
        cv::imshow("left image",Info_left);
        cv::imshow("right image",Info_right);
        cv::waitKey(10);//ms

    }
    cout<<"total: "<<read->getNum()<<endl;
    return 0;
}

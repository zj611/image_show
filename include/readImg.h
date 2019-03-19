//
// Created by zj on 19-3-18.
//

#ifndef SMALL_PROJECT_READIMG_H
#define SMALL_PROJECT_READIMG_H

#include <vector>
#include <string>
using namespace std;
namespace small_P
{
    class read_img
    {
    public:
        read_img(const string& s);
        void LoadImages();
        int getNum();


        int img_col,img_row;
        int num;
    public:
        vector<string> vstrImageLeft;
        vector<string> vstrImageRight;
        vector<double> vTimestamps;
        string ss;



    };
}










#endif //SMALL_PROJECT_READIMG_H

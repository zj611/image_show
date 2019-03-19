//
// Created by zj on 19-3-18.
//
#include <readImg.h>
#include <sstream>
#include<fstream>
#include <iomanip>

namespace small_P
{
    read_img::read_img(const string& s):ss(s){}

    void read_img::LoadImages()
    {
        const string &strPathToSequence = ss;
        ifstream fTimes;
        string strPathTimeFile = strPathToSequence + "/times.txt";
        fTimes.open(strPathTimeFile.c_str());
        while(!fTimes.eof())
        {
            string s;
            getline(fTimes,s);
            if(!s.empty())
            {
                stringstream ss;
                ss << s;
                double t;
                ss >> t;
                vTimestamps.push_back(t);
            }
        }

        string strPrefixLeft = strPathToSequence + "/image_0/";
        string strPrefixRight = strPathToSequence + "/image_1/";

        const int nTimes = vTimestamps.size();
        vstrImageLeft.resize(nTimes);
        vstrImageRight.resize(nTimes);

        for(int i=0; i<nTimes; i++)
        {
            stringstream ss;
            ss << setfill('0') << setw(6) << i;
            vstrImageLeft[i] = strPrefixLeft + ss.str() + ".png";
            vstrImageRight[i] = strPrefixRight + ss.str() + ".png";
        }
        num  = vstrImageLeft.size();
    }

    int read_img::getNum()
    {
        return num;
    }
}





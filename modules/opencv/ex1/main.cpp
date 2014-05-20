#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
  Mat img=imread("../hepburn.jpg",CV_LOAD_IMAGE_UNCHANGED);
  if (img.empty()) 
    {
      cout<<"Error: image not loaded"<<endl;
      return -1;
    }
  
  namedWindow("Audrey Hepburn", CV_WINDOW_NORMAL);
  imshow("Audrey Hepburn",img);

  waitKey(0);

  destroyWindow("Audrey Hepburn");

  Mat img2(500,5000,CV_8UC3,Scalar(100,0,0));

  namedWindow("Blue", CV_WINDOW_AUTOSIZE);
  imshow("Blue", img2);
  waitKey(0);

  return 0;
}

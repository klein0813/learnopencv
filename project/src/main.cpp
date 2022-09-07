#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <typeinfo>

using namespace std;

int main()
{
  // cv::namedWindow("image", cv::WINDOW_NORMAL);
  // cv::Mat a = cv::imread("C:\\Users\\klein.zhou\\Desktop\\practice\\opencv\\project\\assert\\webgl24glb.jpg", cv::IMREAD_UNCHANGED);
  // cv::imshow("Origin", a);
  // cv::Mat a2 = cv::imread("C:\\Users\\klein.zhou\\Desktop\\practice\\opencv\\project\\assert\\webgl24glb.jpg", cv::IMREAD_GRAYSCALE);
  // cv::imshow("OpenCV Demo", a2);
  // cv::Mat a3 = cv::imread("C:\\Users\\klein.zhou\\Desktop\\practice\\opencv\\project\\assert\\webgl24glb.jpg", cv::IMREAD_COLOR);
  // cv::imshow("OpenCV Demo a3", a3);
  // cv::Mat img = cv::imread("C:\\Users\\klein.zhou\\Desktop\\practice\\opencv\\project\\assert\\webgl24glb.jpg", cv::IMREAD_UNCHANGED);
  // cv::imshow("image", img);
  // int key = cv::waitKey(0);
  // if (key == 27) {
  //   cv::destroyAllWindows();
  // } else if (key == 's') {
  //   cv::imwrite("save.png", img);
  // }

  cv::VideoCapture cap = cv::VideoCapture("C:\\Users\\klein.zhou\\Desktop\\practice\\opencv\\project\\assert\\last.mp4");
  if (!cap.isOpened()) {
    cout<<"cannot open camera"<<endl;
    return 0;
  }
  cv::Mat frame;
  cv::namedWindow("Video Demo");

  int frameCount = cap.get(cv::CAP_PROP_FRAME_COUNT);
  cout<<"total frame count is: "<<frameCount<<endl;
  while(true) {
    cap.read(frame);
    if (!frame.empty()) {
      cv::imshow("Video Demo", frame);
    }

    if (cv::waitKey(40) == 'q') {
      break;
    }
  }

  cap.release();
  cv::destroyWindow("Video Demo");

  return 0;
}

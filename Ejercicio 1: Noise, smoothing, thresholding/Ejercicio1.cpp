#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const int max_value_H = 360 / 2;
const int max_value = 255;

//{} <> []

int main()
{
    string image_p1 = "/home/computacion/Desktop/OpenCV/Ejercicio 1: Noise, smoothing, thresholding/BabyFood-Test6.JPG";
    string image_p2 = "/home/computacion/Desktop/OpenCV/Ejercicio 1: Noise, smoothing, thresholding/redHats.jpg";
    string image_p3 = "/home/computacion/Desktop/OpenCV/Ejercicio 1: Noise, smoothing, thresholding/redHatSImple.JPG";

    Mat image1 = imread(image_p2, IMREAD_COLOR);
    resize(image1, image1, {500,500});

    if (image1.empty()){
        cout << "Cold not read the image: ";
        return 1;
    }


    vector<int> lower_bound = {170,80,50};

    int low_h = lower_bound[0], low_s = lower_bound[1], low_v = lower_bound[2];
    int high_h = max_value_H, high_s = max_value, high_v = max_value;


    Mat hsvImg, imgThreshold;

    //convert from BGR to HSV colorspace
    cvtColor(image1, hsvImg, COLOR_BGR2HSV);

    //detect the object based on HSV range values
    inRange(hsvImg, Scalar(low_h, low_s, low_v), Scalar(high_h, high_s, high_v), imgThreshold);

    Mat medianBlurImg, gaussianBlurImg;
    //9:size of the kernel
    medianBlur(image1, medianBlurImg, 9);
    //
    GaussianBlur(image1, gaussianBlurImg, Size(1,1), 9, 9);

    imshow("Original image: ", image1);
    imshow("median blur image: ", medianBlurImg);
    imshow("gaussian image: ", gaussianBlurImg);


    int k = waitKey(0);

    destroyAllWindows();








}



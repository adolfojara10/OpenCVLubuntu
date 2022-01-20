#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using std::cout;

int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_binary_value = 255;
Mat src, src_gray, dst;
const char* window_name = "Threshold Demo";
const char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char* trackbar_value = "Value";

static void Threshold_Demo( int, void* )
{
    /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
    */
    threshold( src_gray, dst, threshold_value, max_binary_value, threshold_type );
    imshow( window_name, dst );
}

int main( int argc, char** argv )
{

    /**
     * @brief image threshold
     * 
     */

    String imageName("/home/computacion/Desktop/OpenCV/A practical introduction to CV/Church.jpg"); // by default
    if (argc > 1)
    {
        imageName = argv[1];
    }
    src = imread( samples::findFile( imageName ), IMREAD_COLOR ); // Load an image
    if (src.empty())
    {
        cout << "Cannot read the image: " << imageName << std::endl;
        return -1;
    }
    cvtColor( src, src_gray, COLOR_BGR2GRAY ); // Convert the image to Gray
    namedWindow( window_name, WINDOW_AUTOSIZE ); // Create a window to display results
    createTrackbar( trackbar_type,
                    window_name, &threshold_type,
                    max_type, Threshold_Demo ); // Create a Trackbar to choose type of Threshold
    createTrackbar( trackbar_value,
                    window_name, &threshold_value,
                    max_value, Threshold_Demo ); // Create a Trackbar to choose Threshold value
    Threshold_Demo( 0, 0 ); // Call the function to initialize
    waitKey();
    return 0;


    /**
     * @brief OTSU thresholding
     * 
     */


    String pat1 = "/home/computacion/Desktop/OpenCV/A practical introduction to CV/Church.jpg";
    Mat gray_stationery_image = imread(pat1), otsu_binary_image;
    int current_threshold = 128;
	int max_threshold = 255;
    cvtColor(gray_stationery_image, gray_stationery_image, COLOR_RGB2GRAY);
	threshold(gray_stationery_image,otsu_binary_image,current_threshold,max_threshold,
		THRESH_BINARY | THRESH_OTSU);
	Mat otsu_binary_image_display;
	cvtColor(otsu_binary_image, otsu_binary_image_display, COLOR_GRAY2BGR);
/*
    imshow("iamge", otsu_binary_image);

    waitKey();
*/
    /**
     * SEmi thresholding
     * 
     */


    String pat22 ="/home/computacion/Desktop/OpenCV/A practical introduction to CV/Stationery.jpg";

    Mat image22 = imread(pat22, IMREAD_COLOR);
    cvtColor(image22, image22, COLOR_BGR2GRAY);

    Mat semi_thresholded_image;
	threshold(image22,otsu_binary_image,current_threshold,max_threshold,
		THRESH_BINARY_INV | THRESH_OTSU);
	bitwise_and( image22, otsu_binary_image, semi_thresholded_image );

 /*   imshow("image grey", image22);
    imshow("otsu", otsu_binary_image);
    imshow("semi", semi_thresholded_image);

    waitKey();*/


    /**
     * @brief Mathematical morphology
     *          Dilation
     */

    String pat33 ="/home/computacion/Desktop/OpenCV/A practical introduction to CV/PCBImage.jpg";

    Mat image33 = imread(pat33, IMREAD_COLOR);

    cvtColor(image33, image33, COLOR_BGR2GRAY);

    Mat binary_image;

    threshold(image33,binary_image, current_threshold, max_threshold, THRESH_BINARY | THRESH_OTSU);
	Mat otsu_binary_image_display2;
	cvtColor(binary_image, otsu_binary_image_display2, COLOR_GRAY2BGR);

    Mat dilate_image;
    //mat(): so the kernel is 3x3
    dilate(otsu_binary_image_display2, dilate_image, Mat());

  /*  imshow("image grey", image33);
    imshow("otsu", otsu_binary_image_display2);
    imshow("dilated", dilate_image);

    waitKey();*/


    /**
     * erode
     * 
     */

    Mat erode_iamge;
    //mat(): so the kernel is 3x3
    erode(otsu_binary_image_display2, erode_iamge, Mat());

/*    imshow("image grey", image33);
    imshow("otsu", otsu_binary_image_display2);
    imshow("dilated", dilate_image);
    imshow("erode", erode_iamge);

    waitKey();*/

    /**
     * Opening and closing
     * 
     */

    String pat55 = "/home/computacion/Desktop/OpenCV/A practical introduction to CV/PETS2000Frame0124.jpg";

    Mat image55 = imread(pat55, IMREAD_COLOR);
    cvtColor(image55, image55, COLOR_BGR2GRAY);

    current_threshold = 128;
	max_threshold = 255;
    Mat otsu_binary_image3;

	threshold(image55,otsu_binary_image3,current_threshold,max_threshold,
		THRESH_BINARY | THRESH_OTSU);
	Mat otsu_binary_image_display3;
	cvtColor(otsu_binary_image3, otsu_binary_image_display3, COLOR_GRAY2BGR);


    Mat fivexfive(5,5, CV_8U, Scalar(1));
    Mat open_image, close_image;
    morphologyEx(otsu_binary_image_display3, open_image, MORPH_OPEN, fivexfive);
    morphologyEx(otsu_binary_image_display3, close_image, MORPH_CLOSE, fivexfive);

    imshow("original", image55);
    imshow("otsu", otsu_binary_image_display3);
    imshow("open", open_image);
    imshow("close", close_image);

    waitKey();


    
}
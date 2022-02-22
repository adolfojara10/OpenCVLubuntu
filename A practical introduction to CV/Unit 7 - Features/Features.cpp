#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/video/tracking.hpp"
#include "opencv2/features2d/features2d.hpp"

#include <opencv2/xfeatures2d/nonfree.hpp>

#include <opencv2/features2d/features2d.hpp>

using namespace cv;
using std::cout;

//{} <> []
int main(){

    /**
     * @brief First derivative detection
     * FAST
     */

    String pat = "/home/computacion/Desktop/OpenCV/A practical introduction to CV/Church.jpg";

    Mat image = imread(pat, IMREAD_COLOR);
    Mat gray_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY);
/*
    //es un puntero
    Ptr<FeatureDetector> fd = FeatureDetector::create("FAST");

    vector<KeyPoint> kp;

    fd->detect(gray_image,kp);
    imshow("FAST", gray_image);
    waitKey();


    FASTX(gray_image, kp, 50, true, FastFeatureDetector::TYPE_9_16);
	
	
	imshow("FASTX", gray_image);

	waitKey();*/


    //SIFT

    Ptr<SIFT> fd = SIFT::create();

    /*

    vector<KeyPoint> kp;

    fd->detect(gray_image,kp);
    imshow("SIFT", gray_image);
    waitKey();


    SiftFeatureDetector sift_detector;
    vector<KeyPoint> keypoints1, keypoints2;
    sift_detector.detect( gray_image1, keypoints1 );
    sift_detector.detect( gray_image2, keypoints2 );
    
    // Extract feature descriptors
    SiftDescriptorExtractor sift_extractor;
    Mat descriptors1, descriptors2;
    sift_extractor.compute( gray_image1, keypoints1, descriptors1 );
    sift_extractor.compute( gray_image2, keypoints2, descriptors2 );
    
    // Match descriptors.
    
    BFMatcher sift_matcher(NORM_L2 );
    vector< DMatch> matches;
    sift_matcher.match( descriptors1, descriptors2, matches );
    
    // Display SIFT matches
    
    Mat display_image;
    drawMatches( gray_image1, keypoints1, gray_image2,keypoints2, matches, display_image );
    */

   return 0;

}
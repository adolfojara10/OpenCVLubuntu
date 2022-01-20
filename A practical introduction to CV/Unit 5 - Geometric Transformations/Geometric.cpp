#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using std::cout;
//{} <> []
int interpolation_type = 2;
int const max_type = 4;
Mat src, dst, perspective_matrix( 3, 3, CV_32FC1 ), perspective_warped_image;
const char* window_name = "INterpolation Demo";
const char* trackbar_type = "Type: \n 0: Nearest neighbour \n 1: bilinear \n 2: bi-cubic \n 3:Area relaton  \n 4: 8*8 neighbourdhood";

static void Interpolation( int, void*)
{
    /* 0 INTER_NEAREST 
    1. INTER_LINEAR 
	2. INTER_CUBIC 
    3:Area relaton
    4: 8*8 neighbourdhood
    */
    Point2f source_points[4], destination_points[4];
    source_points[0] = Point2f(29.0, 66.0);
    source_points[1] = Point2f(25.0, 135.0);
    source_points[2] = Point2f(256.0, 9.0);
    source_points[3] = Point2f( 252.0, 71.0 );

    destination_points[0] = Point2f(0.0, 0.0); 
    destination_points[1] = Point2f(0.0, 99.0);
    destination_points[2] = Point2f(399.0, 0.0);
	destination_points[3] = Point2f( 399.0, 99.0 );

    int expansion_factor=2;
	for (int point=0; point<4; point++)
	{
		destination_points[point].x *= expansion_factor;
		destination_points[point].y *= expansion_factor;
	}

    perspective_matrix = getPerspectiveTransform( source_points, destination_points );
	Size result_size(perspective_warped_image.cols*expansion_factor, perspective_warped_image.rows*expansion_factor);
	warpPerspective( src, dst, perspective_matrix, Size(800,300), interpolation_type );
    imshow( window_name, dst );
}

int main(){

    /**
     * @brief affine transformation
     * skewing
     */


    Mat affineMatrix = Mat::eye(2,3, CV_32FC1);
    String pat1 = "/home/computacion/Desktop/OpenCV/A practical introduction to CV/LicensePlate1.jpg";

    Mat image1 = imread(pat1, IMREAD_COLOR), result;

    //affineMatrix[0][1] Skewing:
    *(((float*) (affineMatrix.data))+1) = 0.37;

    //affineMatrix[0][2] translate to the left:
    *(((float*) (affineMatrix.data))+2) = -30.0;


    //apply transformation
    warpAffine(image1, result, affineMatrix, image1.size());
/**
    imshow("original", image1);
    imshow("affine", result);

    waitKey();
*/

    /**
     * panoramic transformation
     * 
     */

    Mat panoMatrix = Mat::eye(2,3, CV_32FC1);
// [0][0] Panoramic distortion
    *((float*)(panoMatrix.data)) = 1.25;
// [0][2] Translate to the left
    *(((float*)(panoMatrix.data))+2) = 0.0;


    Mat panoImage;

    warpAffine(result, panoImage, panoMatrix, result.size());

  /*  imshow("original", image1);
    imshow("Skew", result);
    imshow("pano", panoImage);

    waitKey();*/


    /**
     * affine transformation
     * 
     */

    Mat affineMatrix2(2,3,CV_32FC1), affineImage;
    affineImage = Mat::zeros(100,400,image1.type());

//points of the corners
    Point2f sourcePoint[4], destinationPoints[4];
    sourcePoint[0] = Point2f(29.0, 66.0);
    sourcePoint[1] = Point2f(25.0, 135.0);
    sourcePoint[2] = Point2f(256.0, 9.0);

    destinationPoints[0] = Point2f(0.0, 0.0); 
    destinationPoints[1] = Point2f(0.0, 99.0);
    destinationPoints[2] = Point2f(399.0, 0.0);

    affineMatrix2 = getAffineTransform(sourcePoint, destinationPoints);

    warpAffine(image1, affineImage, affineMatrix2, affineImage.size());
/*
    imshow("original", image1);
    imshow("Affine", affineImage);
    
    waitKey();
*/

    /**
     * @brief perspective transformations
     * 
     */

  /*  Mat perspective_matrix( 3, 3, CV_32FC1 ), perspective_warped_image;
	perspective_warped_image = Mat::zeros( 100, 400, image1.type() );

    Point2f source_points[4], destination_points[4];
    source_points[0] = Point2f(29.0, 66.0);
    source_points[1] = Point2f(25.0, 135.0);
    source_points[2] = Point2f(256.0, 9.0);
    source_points[3] = Point2f( 252.0, 71.0 );

    destination_points[0] = Point2f(0.0, 0.0); 
    destination_points[1] = Point2f(0.0, 99.0);
    destination_points[2] = Point2f(399.0, 0.0);
	destination_points[3] = Point2f( 399.0, 99.0 );

	perspective_matrix = getPerspectiveTransform( source_points, destination_points );
	warpPerspective( image1, perspective_warped_image, perspective_matrix, perspective_warped_image.size() );
	Mat output1 = JoinImagesVertically( image1, "Original Image", result, "Skewed Image", 4, Scalar( 255, 0, 0 ) );
	Mat col1_output = JoinImagesVertically( output1, "", affineImage, "Affine transformation", 4, Scalar( 255, 0, 0 ) );
	output1 = JoinImagesVertically( result, "Rotated Image (-15 degrees)", panoImage, "Panoramic Distortion", 4, Scalar( 255, 0, 0 ) );
	Mat col2_output = JoinImagesVertically( output1, "", perspective_warped_image, "Perspective transformation", 4, Scalar( 255, 0, 0 ) );
	Mat geometric_output = JoinImagesHorizontally( col1_output, "", col2_output, "", 4, Scalar( 255, 0, 0 ) );
	imshow("Geometric transformations", geometric_output );*/

    /**
     * @brief Interpolation
     * 
     */

  /*  String imageName("/home/computacion/Desktop/OpenCV/A practical introduction to CV/LicensePlate1.jpg"); // by default
    
    src = imread( samples::findFile( imageName ), IMREAD_COLOR ); // Load an image
    if (src.empty())
    {
        cout << "Cannot read the image: " << imageName << std::endl;
        return -1;
    }
    
    namedWindow( window_name, WINDOW_AUTOSIZE ); // Create a window to display results
    createTrackbar( trackbar_type,
                    window_name, &interpolation_type,
                    max_type,Interpolation ); // Create a Trackbar to choose type of Threshold
    Interpolation(0,0); // Call the function to initialize
    waitKey();
    return 0;*/


}


#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
//#include <Utilities.h>

using namespace cv;
using std::cout;

//{} <> []
int main(){

    /**
     * @brief First derivative detection
     * 
     */

    String pat = "/home/computacion/Desktop/OpenCV/A practical introduction to CV/Church.jpg";

    Mat image = imread(pat, IMREAD_COLOR);
    cvtColor(image, image, COLOR_BGR2GRAY);

    /**
	 * First derivative (Roberts) Edge detection
	 * 
	 * 
	 * */
	/*
	int kernel_size = 2;
	Mat kernel = Mat::eye( 2, 2, CV_32FC1 );
	Point anchor = Point( 0,0 );
	*(((float*) (kernel.data))) = 0.0;  // [0][1] 
	*(((float*) (kernel.data))+1) = 1.0;  // [0][1] 
	*(((float*) (kernel.data))+2) = -1.0;  // [1][0] 
	*(((float*) (kernel.data))+3) = 0.0;  // [1][0] 
	Mat roberts1;
	filter2D(image, roberts1, CV_32F, kernel, anchor);
	Mat roberts1_gray = convert_32bit_image_for_display( roberts1, 128.0, 0.4 );
	*(((float*) (kernel.data))) = 1.0;  // [0][1] 
	*(((float*) (kernel.data))+1) = 0.0;  // [0][1] 
	*(((float*) (kernel.data))+2) = 0.0;  // [1][0] 
	*(((float*) (kernel.data))+3) = -1.0;  // [1][0] 
	Mat roberts2;
	filter2D(image, roberts2, CV_32F, kernel, anchor);
	Mat roberts2_gray = convert_32bit_image_for_display( roberts2, 128.0, 0.4 );
	//cartToPolar(roberts1,roberts2,l2norm_gradient,orientation);
	Mat abs_gradient = abs(roberts1) + abs(roberts2);
	Mat roberts_gradient = convert_32bit_image_for_display(abs_gradient);
	Mat image1_gray_display, roberts1_gray_display, roberts2_gray_display, roberts_gradient_display;
	cvtColor(image, image1_gray_display, COLOR_BGR2GRAY);
	cvtColor(roberts1_gray, roberts1_gray_display, COLOR_BGR2GRAY);
	cvtColor(roberts2_gray, roberts2_gray_display, COLOR_BGR2GRAY);
	cvtColor(roberts_gradient, roberts_gradient_display, COLOR_BGR2GRAY);

	imshow("GRAY", image);
    imshow("Horizontal", image1_gray_display);
    imshow("vertical", roberts1_gray);
	imshow("Horizontal", roberts2_gray);
    imshow("vertical", roberts_gradient);

    waitKey();
*/

    /**
     * @SObel detection 
     * 
     */
	
	
 /*  
    Mat horizontalDerivative, verticalDerivative;
    Sobel(image, horizontalDerivative, CV_32F,1,0);
    Sobel(image, verticalDerivative, CV_32F,0,1);

	
	Mat horizontal_partial_derivative, vertical_partial_derivative;
	Mat l2norm_gradient, orientation;
	Sobel(image,horizontal_partial_derivative,CV_32F,1,0);
	Sobel(image,vertical_partial_derivative,CV_32F,0,1);
	Mat abs_gradient = abs(horizontal_partial_derivative) + abs(vertical_partial_derivative);
	cartToPolar(horizontal_partial_derivative,vertical_partial_derivative,l2norm_gradient,orientation);
	Mat horizontal_partial_derivative_gray = convert_32bit_image_for_display( horizontal_partial_derivative );
	Mat vertical_partial_derivative_gray = convert_32bit_image_for_display( vertical_partial_derivative );
	Mat abs_gradient_gray = convert_32bit_image_for_display( abs_gradient );
	Mat l2norm_gradient_gray = convert_32bit_image_for_display( l2norm_gradient );
	Mat l2norm_gradient_mask,display_orientation,the_gradient;
	l2norm_gradient.convertTo(l2norm_gradient_mask,CV_8U);
	threshold(l2norm_gradient_mask,l2norm_gradient_mask,50,255,THRESH_BINARY);
	orientation.copyTo(display_orientation, l2norm_gradient_mask);
	Mat orientation_gray = convert_32bit_image_for_display( orientation, 0.0, 255.0/(2.0*PI) );
	Mat display_orientation_gray = convert_32bit_image_for_display( display_orientation, 0.0, 255.0/(2.0*PI) );
	Mat nms_result;
	NonMaximaEdgeGradientSuppression( l2norm_gradient, orientation, nms_result );
	Mat nms_result_gray = convert_32bit_image_for_display( nms_result );
	Mat horizontal_partial_derivative_gray_display, vertical_partial_derivative_gray_display, abs_gradient_gray_display, l2norm_gradient_gray_display, orientation_gray_display, display_orientation_gray_display, nms_result_gray_display;
	cvtColor(horizontal_partial_derivative_gray, horizontal_partial_derivative_gray_display, COLOR_GRAY2BGR);
	cvtColor(vertical_partial_derivative_gray, vertical_partial_derivative_gray_display, COLOR_GRAY2BGR);
	cvtColor(abs_gradient_gray, abs_gradient_gray_display, COLOR_GRAY2BGR);
	cvtColor(l2norm_gradient_gray, l2norm_gradient_gray_display, COLOR_GRAY2BGR);
	cvtColor(orientation_gray, orientation_gray_display, COLOR_GRAY2BGR);
	cvtColor(display_orientation_gray, display_orientation_gray_display, COLOR_GRAY2BGR);
	cvtColor(nms_result_gray, nms_result_gray_display, COLOR_GRAY2BGR);
 
	imshow("GRAY", image);
    imshow("Horizontal", horizontal_partial_derivative_gray);
    imshow("vertical", vertical_partial_derivative_gray);
	imshow("GRAY", abs_gradient_gray);
    imshow("Horizontal", l2norm_gradient_gray);
    imshow("vertical", orientation_gray);
	imshow("Horizontal", display_orientation_gray);
    imshow("vertical", nms_result_gray);

    imshow("GRAY", image);
    imshow("Horizontal", horizontalDerivative);
    imshow("vertical", verticalDerivative);

    waitKey();

*/
	/**
	 * @brief Second derivative edge detector
	 * 
	 */
	
	/*
		Laplacian: first the image has to be gray, then smooth it with gaussianblur, and the apply laplacian method

	*/

	/*Mat laplacian, blurred_image1_gray;
	
	
	GaussianBlur(image, blurred_image1_gray, Size(5,5), 1.5);
	Laplacian(blurred_image1_gray, laplacian, CV_32F, 3);

	imshow("Gray", blurred_image1_gray);
    imshow("Laplacian", laplacian);

	waitKey();*/

	/*
		Canny: first the image has to be gray, then smooth it with gaussianblur, and the apply laplacian method

	*/

	Mat canny1, canny2, canny3, canny4, gray;

	GaussianBlur(image, gray, Size(5,5), 1.5);
	Canny(gray, canny1, 100, 200);
	Canny(gray, canny2, 7, 236);
	Canny(gray, canny3, 7, 100);
	Canny(gray, canny4, 1, 1);

	imshow("Gray", gray);
    imshow("Canny1", canny1);
	imshow("Canny2", canny2);
	imshow("Canny3", canny3);
	imshow("Canny4", canny4);

	waitKey();



}
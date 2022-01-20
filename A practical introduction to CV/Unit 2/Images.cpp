#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//{} <> []

int main(){

    string image1 = "/home/computacion/Desktop/OpenCV/A practical introduction to CV/Unit 2/TrinityRegentHouse.jpg";

    Mat img1 = imread(image1);
   // resize(img1,img1,{img1.rows/2,img1.cols/2});
/*
    imshow("IMage", img1);

    waitKey();*/

    int num_bits = 1;
    
    //CV_Assert((img1.type() == CV_8UC1) && (num_bits >= 1) && (num_bits <= 8));

    /**
     * an example of how to change the channels of an image. at function uses too many resources, therefore, cvtColor is the best option
     * 
     */
    uchar mask = 0xFF << (8-num_bits);

    for (int row=0; row < img1.rows; row++){
        for (int col=0; col < img1.cols; col++){
            img1.at<uchar>(row,col) = img1.at<uchar>(row,col) & mask;
        }
    }
    
 /*   imshow("IMage", img1);

    waitKey();*/



  

    /**
     * to convert between colour representations and grey scale, and split colour images into their component channels
     * 
     */
//{} <> []

    string image2 = "/home/computacion/Desktop/OpenCV/A practical introduction to CV/Unit 2/CoatHanger.jpg";

    Mat img2 = imread(image2);   

    Mat grey_image;
    cvtColor(img2, grey_image, 4);
    vector<Mat> bgr_images(3);
    split(img2, bgr_images);
/*
    imshow("Original", img2);
    imshow("Gray", grey_image);
    imshow("Blue", bgr_images[0]);
    imshow("Green", bgr_images[1]);
    imshow("Reed", bgr_images[2]);

    waitKey();
*/

    /**
     * skin detection
     * 
     */
//{} <> []

    string image3= "/home/computacion/Desktop/OpenCV/A practical introduction to CV/Unit 2/Astronaut1.jpg";

    Mat img3 = imread(image3);
  /*  Mat skin_image;

    Mat hls_image = imread(image3);

    for (int row=0; row < hls_image.rows; row++){
        for (int col=0; col < hls_image.cols; col++)
        {
            uchar hue = hls_image.at<Vec3b>(row,col)[0];
            uchar luminance = hls_image.at<Vec3b>(row,col)[1];
            uchar saturation = hls_image.at<Vec3b>(row,col)[2];
            double luminance_saturation_ratio = ((double) luminance) / ((double) saturation);
            bool skin_pixel = (saturation >= 50) && (luminance_saturation_ratio > 0.5) &&
                            (luminance_saturation_ratio < 3.0) && ((hue <= 14) || (hue >= 165));
            for (int channel=0; channel < hls_image.channels(); channel++){
                skin_image.at<Vec3b>(row,col)[channel] = skin_pixel ? hls_image.at<Vec3b>(row,col)[channel] : 0;
            }
        }

    }*/

    /*
    imshow("IMagen", img3);
    imshow("IMagen", skin_image);
    waitKey();
*/



    /**
     * noise image
     * 
     */
    //{} <> []

    
    Mat image = imread("/home/computacion/Desktop/OpenCV/A practical introduction to CV/Unit 2/TrinityRegentHouse.jpg");
    Mat copyImage = image.clone();


    //salt and pepper noise
  /*  double noise_percentage = 8;

    int image_rows = image.rows;
	int image_columns = image.cols;
	int image_channels = image.channels();
	int number_of_noise_points = (int) ((((double) image_rows*image_columns*image_channels)*noise_percentage)/100.0);
	for (int count = 0; count < number_of_noise_points; count++)
	{
		int row = rand() % image_rows;
		int column = rand() % image_columns;
		int channel = rand() % image_channels;
		uchar* pixel = image.ptr<uchar>(row) + (column*image_channels) + channel;
		*pixel = (rand()%2 == 1) ? 255 : 0;
	}
    
    GaussianBlur(copyImage, copyImage, Size(3,3), 9, 9);
    imshow("II", copyImage);
    
    imshow("Image noise", image);

    waitKey();
*/

    /**
     * Smoothing images
     * 
     */


    Mat image4 = imread("/home/computacion/Desktop/OpenCV/A practical introduction to CV/Unit 2/Church.jpg");
    Mat sapImage = image4.clone();
    Mat smoothIMage, gausianIMage,blurImage, medianFIlterIMage;
    //salt and pepper noise
    double noise_percentage = 8;

    int image_rows = sapImage.rows;
	int image_columns = sapImage.cols;
	int image_channels = sapImage.channels();
	int number_of_noise_points = (int) ((((double) image_rows*image_columns*image_channels)*noise_percentage)/100.0);
	for (int count = 0; count < number_of_noise_points; count++)
	{
		int row = rand() % image_rows;
		int column = rand() % image_columns;
		int channel = rand() % image_channels;
		uchar* pixel = sapImage.ptr<uchar>(row) + (column*image_channels) + channel;
		*pixel = (rand()%2 == 1) ? 255 : 0;
	}

    //fastNlMeansDenoising(img3,smoothIMage,(double)8,7,21);

    addWeighted(image4,0.6,sapImage,0.3,0.0,smoothIMage);
    blur(sapImage,blurImage,Size(3,3));
    GaussianBlur(sapImage,blurImage, Size(5,5),1.5);

    medianBlur(sapImage,medianFIlterIMage,3);


    //imshow("Normal", image4);
    imshow("Salt and pepper", sapImage);
    imshow("Smooth", smoothIMage);
    //imshow("Blur", blurImage);
    //imshow("Gausian", gausianIMage);
    imshow("Median filter", medianFIlterIMage);

    waitKey();


    /**
     * @brief 
     * 
     */
}
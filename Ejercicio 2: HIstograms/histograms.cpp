#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;

//{} <> []

int main(){

    string image_p1 = "/home/computacion/Desktop/OpenCV/Ejercicio 2: HIstograms/ball.png";
    string image_p2 = "/home/computacion/Desktop/OpenCV/Ejercicio 2: HIstograms/redball.png";
    string image_p3 = "/home/computacion/Desktop/OpenCV/Ejercicio 2: HIstograms/house.jpeg";
    string image_p4 = "/home/computacion/Desktop/OpenCV/Ejercicio 2: HIstograms/house2.jpeg";
    string image_p5 = "/home/computacion/Desktop/OpenCV/Ejercicio 2: HIstograms/dark.jpeg";


    Mat image1 = imread(image_p1, IMREAD_COLOR);
    resize(image1, image1, {500, 500}, 0, 0, cv::INTER_NEAREST);

    Mat image2 = imread(image_p2, IMREAD_COLOR);
    resize(image2, image2, {500, 500}, 0, 0, cv::INTER_NEAREST);

    Mat image3 = imread(image_p3, IMREAD_GRAYSCALE);
    resize(image3, image3, {500, 500}, 0, 0, cv::INTER_NEAREST);

    Mat image4 = imread(image_p4, IMREAD_GRAYSCALE);
    resize(image4, image4, {500, 500}, 0, 0, cv::INTER_NEAREST);

    Mat image5 = imread(image_p5, IMREAD_GRAYSCALE);
    resize(image5, image5, {500, 500}, 0, 0, cv::INTER_NEAREST);

    //histogram for picture 3
    MatND histogram;
    int histsize = 256;
    const int* channelNumbers = {0};
    float channelRange[] = {0.0, 256.0};
    const float* channelRanges = channelRange;
    int numberBins = histsize;

    calcHist(&image3, 1, 0, Mat(), histogram, 1, &numberBins, &channelRanges);

    int histW= 512, histH = 400;
    int binW = cvRound((double)histW/histsize);
    Mat histImage(histH, histW, CV_8UC3, Scalar(0,0,0));
    normalize(histogram, histogram,0, histImage.rows, NORM_MINMAX, -1, Mat());

    for (int i=1; i< histsize; i++){

        line(histImage, Point(binW*(i-1), histH - cvRound(histogram.at<float>(i-1))), 
            Point(binW*(i), histH - cvRound(histogram.at<float>(i))),
            Scalar(255,0,0),2, 8, 0      
        
        );
    }

//histogram for picture 5
    MatND histogram2;
    calcHist(&image5, 1, 0, Mat(), histogram2, 1, &numberBins, &channelRanges);

    Mat histImage2(histH, histW, CV_8UC3, Scalar(0,0,0));
    normalize(histogram2, histogram2,0, histImage2.rows, NORM_MINMAX, -1, Mat());

    for (int i=1; i< histsize; i++){

        line(histImage2, Point(binW*(i-1), histH - cvRound(histogram2.at<float>(i-1))), 
            Point(binW*(i), histH - cvRound(histogram2.at<float>(i))),
            Scalar(255,0,0),2, 8, 0      
        
        );
    }


    double histMatchingCorrelation = compareHist(histogram, histogram2, HISTCMP_CORREL);
    double histMatchingChiSquare = compareHist(histogram, histogram2, HISTCMP_CHISQR);
    double histMatchingIntersect = compareHist(histogram, histogram2, HISTCMP_INTERSECT);
    double histMatchingBhattacharyya = compareHist(histogram, histogram2, HISTCMP_BHATTACHARYYA);

    cout << "Correlation: " << histMatchingCorrelation << endl;
    cout << "ChiSquare: " << histMatchingChiSquare << endl;
    cout << "Intersect: " << histMatchingIntersect << endl;
    cout << "Bhattacharyya: " << histMatchingBhattacharyya << endl;

    imshow("Image 1", image3);
    imshow("calcHIst1", histImage);
    imshow("IMage 2", image4);
    imshow("histImage2", histImage2);

    waitKey();

    //equalize the histogram
    Mat histEqualized;
    equalizeHist(image5, histEqualized);

    imshow("Image", image5);
    imshow("Calc histogram ", histEqualized);

    waitKey();




//{} <> []


    vector<Mat> bgrPlanes;
    split(image3, bgrPlanes);

    int histSize = 256;
    float range[] = {0, 256};
    const float* histRange = {range};
    bool uniform = true, accumulate = false;

    Mat bHIst, gHist, rHist;

    calcHist(&bgrPlanes[0], 1, 0, Mat(), bHIst, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgrPlanes[1], 1, 0, Mat(), gHist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgrPlanes[2], 1, 0, Mat(), rHist, 1, &histSize, &histRange, uniform, accumulate);


    int histW2 = 512, histH2 = 400;
    int binW2 = cvRound((double) histW2/histSize);

    Mat histImage3(histH, histW, CV_8UC3, Scalar(0,0,0));

    normalize(bHIst, bHIst, 0, histImage3.rows, NORM_MINMAX, -1, Mat());
    normalize(gHist, gHist, 0, histImage3.rows, NORM_MINMAX, -1, Mat());
    normalize(rHist, rHist, 0, histImage3.rows, NORM_MINMAX, -1, Mat());

    for (int i=1; i<histSize;i++){
        line(histImage3, Point(binW*(i-1), histH2 - cvRound(bHIst.at<float>(i-1))),
            Point(binW2*(i), histH2 - cvRound(bHIst.at<float>(i))),
            Scalar(255,0,0), 2, 8, 0);

        line(histImage3, Point(binW2*(i-1), histH2 - cvRound(gHist.at<float>(i-1))),
            Point(binW2*(i), histH2 - cvRound(gHist.at<float>(i))),
            Scalar(255,0,0), 2, 8, 0);

        line(histImage3, Point(binW2*(i-1), histH2 - cvRound(rHist.at<float>(i-1))),
            Point(binW2*(i), histH2 - cvRound(rHist.at<float>(i))),
            Scalar(255,0,0), 2, 8, 0);
    }

    imshow("IMage", image3);
    imshow("HistImage", histImage3);

    waitKey();

}
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace cv;
using namespace std;

int main()
{
	Mat img0, img1, map;
	img0 = imread("D:\\opencv\\sources\\doc\\tsukuba\\left.png");
	img1 = imread("D:\\opencv\\sources\\doc\\tsukuba\\right.png");
	cvtColor(img0, img0, COLOR_BGR2GRAY);
	cvtColor(img1, img1, COLOR_BGR2GRAY);

	map = Mat::zeros(img0.rows, img0.cols, img0.type());

	float sum = 0, min = -1;
	int d;

	for (int i = 0; i < img0.rows - 5; i++) {
		for (int j = 0; j < img0.cols - 5; j++) {

			for (int pass = 0; pass < img0.cols - 5 - j; pass++) { // 오른쪽으로 한줄 쭉 훑어보기
				if (pass > 25)
					break;

				for (int s = 0; s < 5; s++) { // window size = 5
					for (int t = 0; t < 5; t++) {
						sum += abs(img1.at<uchar>(i + s, j + t) - img0.at<uchar>(i + s, j + t + pass));
					}
				}
				sum /= 25;
				if (min == -1) { // 처음일때 최소값 설정
					min = sum;
					d = pass;
				}
				if (min > sum) {
					min = sum;
					d = pass;
				}

			}
			sum = 0;
			min = -1;
			map.at<uchar>(i, j) = saturate_cast<uchar>(d * 15);
		}
	}

	imshow("Left", img0);
	imshow("Right", img1);
	imshow("Result", map);

	waitKey(0);
	return 0;
}
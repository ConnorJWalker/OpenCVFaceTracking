#pragma once
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

class Camera
{
//Properties
private:
	cv::VideoCapture camera;

public:
	cv::Mat image;
	cv::Mat greyscaleImage;

// Methods
public:
	Camera();
	bool captureNextFrame();
};


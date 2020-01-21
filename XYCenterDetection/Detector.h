#pragma once
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>

struct DetectorResult {
	cv::Rect rectangleLocation;
	cv::Point2i lineEndPoint;
	int distance;
};

class Detector
{
// Properties
public:
	int closestDistance = -10;

private:
	std::string trainedDataLocation = "YOUR FILEPATH HERE opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt2.xml";
	cv::CascadeClassifier classifier;

// Methods
public:
	Detector();
	std::vector<DetectorResult> detect(cv::Mat& greyscaleImage);

private:
	cv::Point2i getLineEndLocation(cv::Rect faceLocation, cv::Point2i center, cv::Point2i centerOfRectangle);
	int getFaceDistance(cv::Rect faceLocation, cv::Point2i center, cv::Point2i centerOfRectangle);
};


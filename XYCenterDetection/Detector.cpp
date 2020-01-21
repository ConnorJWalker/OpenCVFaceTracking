#include "Detector.h"

Detector::Detector() : classifier(trainedDataLocation) {}

std::vector<DetectorResult> Detector::detect(cv::Mat& greyscaleImage) {
	std::vector<DetectorResult> returnData;
	std::vector<cv::Rect> detectedFaces;
	closestDistance = -10;

	classifier.detectMultiScale(greyscaleImage, detectedFaces);
	cv::Point2i center(greyscaleImage.cols / 2, greyscaleImage.rows / 2);

	for (auto face : detectedFaces) {
		cv::Point2i centerOfRectangle(
			face.tl().x + (face.width / 2),
			face.br().y - (face.height / 2)
		);

		returnData.push_back({
			face,
			getLineEndLocation(face, center, centerOfRectangle),
			getFaceDistance(face, center, centerOfRectangle)
		});
	}

	return returnData;
}

cv::Point2i Detector::getLineEndLocation(cv::Rect faceLocation, cv::Point2i center, cv::Point2i centerOfRectangle) {
	// To the left of the center
	if (centerOfRectangle.x < center.x) {
		// Top
		if (centerOfRectangle.y < center.y) {
			return faceLocation.br();
		}
		// Bottom 
		else {
			return cv::Point2i(faceLocation.br().x, faceLocation.tl().y);
		}
	}
	// To the right of the center
	else {
		// Top
		if (centerOfRectangle.y < center.y) {
			return cv::Point2i(faceLocation.tl().x, faceLocation.br().y);
		}
		// Bottom
		else {
			return faceLocation.tl();
		}
	}
}

int Detector::getFaceDistance(cv::Rect faceLocation, cv::Point2i center, cv::Point2i centerOfRectangle) {
	int a = abs(center.x - centerOfRectangle.x);
	int b = abs(center.y - centerOfRectangle.y);
	
	int distance = sqrt((a * a) + (b * b));

	if (closestDistance == -10 || distance < closestDistance) {
		closestDistance = distance;
	}

	return distance;
}


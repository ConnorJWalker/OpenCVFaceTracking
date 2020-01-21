#include "Camera.h"

Camera::Camera() : camera(0) {}

bool Camera::captureNextFrame() {
	camera >> image;

	if (image.empty()) {
		std::cout << "Could not capture image" << std::endl;
		return false;
	}

	cv::cvtColor(image, greyscaleImage, cv::COLOR_BGR2GRAY);
	return true;
}



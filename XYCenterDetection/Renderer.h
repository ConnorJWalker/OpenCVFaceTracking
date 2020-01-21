#pragma once
#include "Detector.h"
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class Renderer
{
// Properties
private:
	const std::string windowName = "distanceWindow";

// Methods
public:
	Renderer();
	~Renderer();
	void render(cv::Mat& image, std::vector<DetectorResult> itemsToRender, int closestDistance);
};


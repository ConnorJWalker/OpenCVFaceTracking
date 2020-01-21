#include "Renderer.h"

Renderer::Renderer() {
	cv::namedWindow(windowName, cv::WindowFlags::WINDOW_AUTOSIZE);
}

Renderer::~Renderer() {
	cv::destroyWindow(windowName);
}

void Renderer::render(cv::Mat& image, std::vector<DetectorResult> itemsToRender, int closestDistance) {
	cv::Point2i center(image.cols / 2, image.rows / 2);

	if (itemsToRender.size() == 0) {
		cv::putText(image, "NO FACES FOUND", cv::Point2i(image.rows / 2, 20), cv::FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(0, 0, 255), 2);
	}

	for (auto item : itemsToRender) {
		cv::Point2i textLocation(
			item.rectangleLocation.x - 10,
			item.rectangleLocation.y
		);

		int red = item.distance == closestDistance ? 255 : 0;
		int green = item.distance == closestDistance ? 0 : 255;
		cv::Scalar colour(0, green, red);

		cv::rectangle(image, item.rectangleLocation, colour, 2);
		cv::line(image, center, item.lineEndPoint, colour, 2);
		cv::putText(image, std::to_string(item.distance), textLocation, cv::FONT_HERSHEY_PLAIN, 1.0, colour, 2);
	}

	cv::imshow(windowName, image);
}

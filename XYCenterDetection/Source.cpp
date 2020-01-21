#include "Camera.h"
#include "Detector.h"
#include "Renderer.h"
#include <opencv2/highgui.hpp>

int main() {
	Camera camera;
	Detector detector;
	Renderer renderer;

	while (true) {
		camera.captureNextFrame();
		renderer.render(camera.image, detector.detect(camera.greyscaleImage), detector.closestDistance);

		if (cv::waitKey(30) >= 0) break;
	}
}
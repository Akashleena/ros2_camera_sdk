#include "camera_a.cpp"
#include "camera_b.cpp"
#include "camera_c.cpp"
#include "rclcpp/rclcpp.hpp"

class CameraDriver : public rclcpp::Node {
public:
    CameraDriver() : Node("camera_driver") {
        std::string camera_type;
        int resolution_width, resolution_height, frame_rate;

        this->declare_parameter("camera_type", "camera_a");
        this->declare_parameter("resolution_width", 1920);
        this->declare_parameter("resolution_height", 1080);
        this->declare_parameter("frame_rate", 30);

        this->get_parameter("camera_type", camera_type);
        this->get_parameter("resolution_width", resolution_width);
        this->get_parameter("resolution_height", resolution_height);
        this->get_parameter("frame_rate", frame_rate);

        Camera* camera;
        if (camera_type == "camera_a") {
            camera = new CameraA();
        } else if (camera_type == "camera_b") {
            camera = new CameraB();
        } else if (camera_type == "camera_c") {
            camera = new CameraC();
        }

        camera->initialize();

        // Configure the camera directly with the parameters
        camera->configure(resolution_width, resolution_height, frame_rate);

        camera->start();

        // Remember to properly stop and clean up
    }
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CameraDriver>());
    rclcpp::shutdown();
    return 0;
}

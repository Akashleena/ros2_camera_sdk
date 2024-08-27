#include "camera_a.cpp"
/* Uncomment for multiple cameras*/
//#include "camera_b.cpp"
//#include "camera_c.cpp"
#include "rclcpp/rclcpp.hpp"

class CameraDriver : public rclcpp::Node{
public:
    CameraDriver() : Node("camera_driver") {
        // Get parameters and initialize the appropriate camera
        std::string camera_type;
        this->declare_parameter("camera_type", "camera_a");
        this->get_parameter("camera_type", camera_type);

        Camera* camera;
        if (camera_type == "camera_a") {
            camera = new CameraA();
        // } else if (camera_type == "camera_b") {
        //     camera = new CameraB();
        // } else if (camera_type == "camera_c") {
        //     camera = new CameraC();
        // }

        CameraConfig config;
        // Get other parameters and populate config

        camera->initialize();
        camera->configure(config);
        camera->start();

        // Remember to properly stop and clean up
    }
    }
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CameraDriver>());
    rclcpp::shutdown();
    return 0;
}

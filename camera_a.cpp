#include "camera.h"
#include "camera_config.h"

class CameraA : public Camera {
public:
    bool initialize() override {
        // Initialize Camera A using SDK
    }
    
    bool configure(const CameraConfig& config) override {
        // Configure Camera A using SDK with provided config
    }
    
    bool start() override {
        // Start Camera A
    }
    
    bool stop() override {
        // Stop Camera A
    }
};
#ifndef CAMERA_H
#define CAMERA_H

// Include SDK headers
#include "sdk_camera.h"

// Common interface for cameras
class Camera {
public:
    virtual bool initialize() = 0;
    virtual bool configure(const CameraConfig& config) = 0;
    virtual bool start() = 0;
    virtual bool stop() = 0;
    virtual ~Camera() = default;
};

#endif // CAMERA_H



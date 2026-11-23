#include "CarModel.h"
#include <cmath>   // std::fmod (optional)

// --------------------
// Motor implementation
// --------------------

Motor::Motor()
    : name("unnamed"), speedPercent(0), enabled(false)
{
    // Nothing else to do.
}

Motor::Motor(const std::string& motorName)
    : name(motorName), speedPercent(0), enabled(false)
{
    // Optional: you may add debug prints while testing, but not required.
}

void Motor::setSpeed(int newSpeedPercent)
{
    if (newSpeedPercent > 100) {
        speedPercent = 100;
    } else if (newSpeedPercent < -100) {
        speedPercent = -100;
    } else {
        speedPercent = newSpeedPercent;
    }  
}

int Motor::getSpeed() const
{
    return speedPercent;
}

void Motor::enable()
{
    enabled = true;
}

void Motor::disable()
{
    enabled = false;
    speedPercent = 0;
}

bool Motor::isEnabled() const
{
    return enabled;
}

std::string Motor::getName() const
{
    return name;
}


// -----------------------
// PiCamera implementation
// -----------------------

PiCamera::PiCamera()
    : streaming(false)
{
    // Nothing else to do.
}

void PiCamera::startStream()
{
    streaming = true;
}

void PiCamera::stopStream()
{
    streaming = false;
}

bool PiCamera::isStreaming() const
{
    return streaming;
}


// ------------------------
// MecanumCar implementation
// ------------------------

MecanumCar::MecanumCar()
   
    : frontLeft("front-left"),
      frontRight("front-right"),
      rearLeft("rear-left"),
      rearRight("rear-right"),
      camera(),
      x(0.0),
      y(0.0),
      headingDeg(0.0)
{
    // Constructor body can be empty once the member-initialization list is complete.
}

void MecanumCar::updatePose(double dx, double dy, double dThetaDeg)
{

    x += dx;
    y += dy;
    headingDeg += dThetaDeg;

    headingDeg = std::fmod(headingDeg, 360.0);
    if (headingDeg < 0.0) {
        headingDeg += 360.0;
    }
}

void MecanumCar::moveForward(double distance)
{
    // Forward increases y
    updatePose(0.0, distance, 0.0);

    // Simple symmetric speeds (illustrative)
    frontLeft.setSpeed(50);
    frontRight.setSpeed(50);
    rearLeft.setSpeed(50);
    rearRight.setSpeed(50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::moveBackward(double distance)
{
    updatePose(0.0, -distance, 0.0);

    frontLeft.setSpeed(-50);
    frontRight.setSpeed(-50);
    rearLeft.setSpeed(-50);
    rearRight.setSpeed(-50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::strafeLeft(double distance)
{
    updatePose(-distance, 0.0, 0.0);

    frontLeft.setSpeed(-50);
    rearLeft.setSpeed(50);
    frontRight.setSpeed(50);
    rearRight.setSpeed(-50);
    
    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::strafeRight(double distance)
{
    updatePose(distance, 0.0, 0.0);

    frontLeft.setSpeed(50);
    rearLeft.setSpeed(-50);
    frontRight.setSpeed(-50);
    rearRight.setSpeed(50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::rotateLeft(double angleDeg)
{
   updatePose(0.0, 0.0, angleDeg);

    frontLeft.setSpeed(-40);
    rearLeft.setSpeed(-40);
    frontRight.setSpeed(40);
    rearRight.setSpeed(40);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::rotateRight(double angleDeg)
{
    updatePose(0.0, 0.0, -angleDeg);

    frontLeft.setSpeed(40);
    rearLeft.setSpeed(40);
    frontRight.setSpeed(-40);
    rearRight.setSpeed(-40);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::stopAllMotors()
{
    frontLeft.setSpeed(0);
    frontRight.setSpeed(0);
    rearLeft.setSpeed(0);
    rearRight.setSpeed(0);

    frontLeft.disable();
    frontRight.disable();
    rearLeft.disable();
    rearRight.disable();
}

void MecanumCar::cameraOn()
{
    camera.startStream();
}

void MecanumCar::cameraOff()
{
    camera.stopStream();
    
}

double MecanumCar::getX() const
{

    return x; 
}

double MecanumCar::getY() const
{
    return y; 
}

double MecanumCar::getHeadingDeg() const
{
    return headingDeg; 
}

Motor MecanumCar::getFrontLeftMotor() const
{
    return frontLeft; 
}

Motor MecanumCar::getFrontRightMotor() const
{
    return frontRight;
}

Motor MecanumCar::getRearLeftMotor() const
{
    return rearLeft;
}

Motor MecanumCar::getRearRightMotor() const
{
    return rearRight;
}
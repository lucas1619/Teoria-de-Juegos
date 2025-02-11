#include "Camera2D.h"

Camera2D::Camera2D() : scale(1.0f),
screenWidth(500),
screenHeight(500),
cameraMatrix(1.0f),
needsUpdateMatrix(true)
{
}

void Camera2D::init(int screenWidth, int screenHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->orthoMatrix = glm::ortho(0.0f,
		(float)screenWidth, 0.0f, (float)screenHeight);
}

void Camera2D::update()
{
	if (needsUpdateMatrix) {
		glm::vec3 translate(-position.x + screenWidth / 2,
			-position.y + screenHeight / 2, 0.0f);
		cameraMatrix = glm::translate(orthoMatrix, translate);
		glm::vec3 scaleCamera(this->scale,this->scale,0.0f);
		cameraMatrix = glm::scale(glm::mat4(1.0f), scaleCamera)
						* cameraMatrix;
	}
}

Camera2D::~Camera2D()
{
}

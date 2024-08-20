#include "player.hpp"

// Constructor implementation
Player::Player(float startX, float startY, float velocity, char model)
    : x(startX), y(startY), velocity(velocity), model(model) {}

// Move the player up (decrease y-coordinate)
void Player::moveUp() { y -= velocity; }

// Move the player down (increase y-coordinate)
void Player::moveDown() { y += velocity; }

// Move the player right (increase x-coordinate)
void Player::moveRight() { x += velocity; }

// Move the player left (decrease x-coordinate)
void Player::moveLeft() { x -= velocity; }

// Get the current x position
float Player::getX() const { return x; }

// Get the current y position
float Player::getY() const { return y; }

// Get the current velocity
float Player::getVel() const { return velocity; }

// Set the position of the player
void Player::setPosition(float x, float y) {
  this->x = x;
  this->y = y;
}

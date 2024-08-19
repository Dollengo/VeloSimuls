#ifndef PLAYER_HPP
#define PLAYER_HPP

// Class representing the player in the game
class Player {
public:
    // Constructor to initialize the player with starting position, velocity, and model
    Player(float startX, float startY, float velocity, char model);

    // Movement functions
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    // Getter functions
    float getX() const;
    float getY() const;
    float getVel() const;

    // Setter function for position
    void setPosition(float x, float y);

private:
    float x;         // Current x position of the player
    float y;         // Current y position of the player
    float velocity;  // Movement speed of the player
    char model;      // Character model representing the player
};

#endif // PLAYER_HPP

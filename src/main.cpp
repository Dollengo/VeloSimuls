#include "player.hpp"
#include <iomanip> // For std::setw to format grid output
#include <iostream>

const int GRID_WIDTH = 10;          // Width of the grid
const int GRID_HEIGHT = 10;         // Height of the grid
char grid[GRID_WIDTH][GRID_HEIGHT]; // The grid representation

// Clear the console screen
void clearScreen() {
  std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the screen
}

// Initialize the grid with empty spaces ('.')
void initializeGrid() {
  for (int i = 0; i < GRID_WIDTH; ++i) {
    for (int j = 0; j < GRID_HEIGHT; ++j) {
      grid[i][j] = '.'; // Empty space
    }
  }
}

// Display the grid with the player position
void displayGrid(const Player &player) {
  clearScreen();
  int x = static_cast<int>(player.getX());
  int y = static_cast<int>(player.getY());

  // Ensure the player is within grid boundaries
  if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT) {
    grid[x][y] = 'P'; // Mark the player's position
  }

  // Print the grid
  for (int j = 0; j < GRID_HEIGHT; ++j) { // Y-axis
    for (int i = 0; i < GRID_WIDTH; ++i) { // X-axis
      std::cout << std::setw(2) << grid[i][j] << ' '; // Format spacing
    }
    std::cout << '\n';
  }

  // Clear the player's previous position
  if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT) {
    grid[x][y] = '.'; // Clear the position
  }
}

// Handle the game menu and player movements
void menu(Player &player) {
  int choice;

  while (true) {
    displayGrid(player);
    std::cout << "Player Position: X=" << player.getX()
              << ", Y=" << player.getY() << "\n";
    std::cout << "Help:\n1 - Up\n2 - Down\n3 - Right\n4 - Left\n5 - Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      player.moveUp();
      break; // Move player up
    case 2:
      player.moveDown();
      break; // Move player down
    case 3:
      player.moveRight();
      break; // Move player right
    case 4:
      player.moveLeft();
      break; // Move player left
    case 5:
      return; // Exit the game loop
    default:
      std::cout << "Invalid choice, please try again.\n";
    }

    // Ensure the player stays within grid boundaries
    float x = player.getX();
    float y = player.getY();
    if (x < 0)
      player.setPosition(0, y);
    if (x >= GRID_WIDTH)
      player.setPosition(GRID_WIDTH - 1, y);
    if (y < 0)
      player.setPosition(x, 0);
    if (y >= GRID_HEIGHT)
      player.setPosition(x, GRID_HEIGHT - 1);

    clearScreen();
  }
}

int main() {
  initializeGrid();

  float startX, startY, velocity;
  std::cout
      << "Welcome to VeloSimul! A minigame to simulate physics (I think...)\n";
  std::cout << "Please enter the Player velocity: ";
  std::cin >> velocity;

  std::cout << "Please enter the start player X position (0 to "
            << GRID_WIDTH - 1 << "): ";
  std::cin >> startX;

  std::cout << "Please enter the start player Y position (0 to "
            << GRID_HEIGHT - 1 << "): ";
  std::cin >> startY;

  // Ensure starting positions are within grid boundaries
  if (startX < 0)
    startX = 0;
  if (startX >= GRID_WIDTH)
    startX = GRID_WIDTH - 1;
  if (startY < 0)
    startY = 0;
  if (startY >= GRID_HEIGHT)
    startY = GRID_HEIGHT - 1;

  Player player(startX, startY, velocity, 'P');

  menu(player);

  return 0;
}

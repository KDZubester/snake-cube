/*
 * Main function for snake game
 * if starting game: init snake and apple
 * update Apple
 * Check User Input
 * Update Snake
 */
void snake_main() 
{
  if (initSnake) 
    {
      initSnake = false;
      // Get rid of tail
      s_length = 0;
      // Set snake speed
      maxSnakeCounter = INIT_SNAKE_COUNTER;
      // Clear the cube
      clearCube();
      //Initial direction is RIGHT
      snake.dir = RIGHT;
      // Set random starting LED for snake
      snake.x = randomCounter % random(0,7);
      if (snake.x > 7) {snake.x = random(0,7);}
      randomCounter++;
      snake.y = randomCounter % random(0,7);
      if (snake.y > 7) {snake.y = random(0,7);}
      randomCounter++;
      snake.z = randomCounter % random(0,7);
      if (snake.z > 7) {snake.z = random(0,7);}
      // Set random LED for apple
      genNewApple();
    }
  updateApple();
  checkButtons();
  updateSnake();
}

/*
 * Make snake move
 * Draw tail 
 * Check for collisions
 */
void updateSnake() 
{
  // Update snake at a specific speed
  if (snakeMovementCounter > maxSnakeCounter) 
  {
    snakeMovementCounter = 0;
    
    // Erase where the head used to be
    clearLED(snake.x, snake.y, snake.z);
    // Erase where the tail used to be
    for (int i = 0; i < s_length; i++) 
    {
      clearLED(tail[i].x, tail[i].y, tail[i].z);
    }

    // Update the tail
    for (int i = s_length - 1; i > 0; i--) 
    {
      tail[i].x = tail[i-1].x;
      tail[i].y = tail[i-1].y;
      tail[i].z = tail[i-1].z;
      tail[i].dir = tail[i-1].dir;
    }
    tail[0].x = snake.x;
    tail[0].y = snake.y;
    tail[0].z = snake.z;
    tail[0].dir = snake.dir;

    // Update snakes direction
    if (snake.dir == FORWARD) {snake.x += s_speed;}
    else if (snake.dir == BACKWARD) {snake.x -= s_speed;}
    else if (snake.dir == LEFT) {snake.z -= s_speed;}
    else if (snake.dir == RIGHT) {snake.z += s_speed;}
    else if (snake.dir == UP) {snake.y += s_speed;}
    else if (snake.dir == DOWN) {snake.y -= s_speed;}

    // Wrap snake around cube if approaching an edge
    if (snake.x > 7) {snake.x = 0;}
    if (snake.x < 0) {snake.x = 7;}
    if (snake.y > 7) {snake.y = 0;}
    if (snake.y < 0) {snake.y = 7;}
    if (snake.z > 7) {snake.z = 0;}
    if (snake.z < 0) {snake.z = 7;}

    // Check for collisions with self and apple
    checkCollisions();

    // Draw tail
    for (int i = 0; i < s_length; i++) 
    {
      setLED(tail[i].x, tail[i].y, tail[i].z);
    }

    // Draw snake head
    setLED(snake.x, snake.y, snake.z);
  }
  snakeMovementCounter++;
}

/*
 * Make apple blink
 */
void updateApple() 
{
  appleBlinkCounter++;
  // Reset blink counter
  if (appleBlinkCounter > 1000) { appleBlinkCounter = 0; }
  // Erase apple half the time
  if (appleBlinkCounter > 500) { clearLED(apple.x2, apple.y2, apple.z2); }
  // Draw apple half the time
  else { setLED(apple.x2, apple.y2, apple.z2); }
}

/*
 * Check if snake eats an apple
 * Check if snake collides with itself
 */
void checkCollisions() 
{
  // If snake eats an apple
  if ((snake.x == apple.x2) && (snake.y == apple.y2) && (snake.z == apple.z2)) 
  {
    // Increase tail until maximum tail length (length limited by RAM)
    if (s_length < MAX_SNAKE_LENGTH) 
    {
      tail[s_length] = {snake.x, snake.y, snake.z, snake.dir};
      s_length++;
    }

    // Increase snake speed
    maxSnakeCounter -= SPEED_INCREASE;
    // Min speed is 25% of original speed
    if (maxSnakeCounter < MIN_SNAKE_COUNTER) { maxSnakeCounter = MIN_SNAKE_COUNTER; }

    // Erase apple
    clearLED(apple.x2, apple.y2, apple.z2);
    // Generate a new location for apple
    genNewApple();
  }
  // Check if snake hits itself
  else 
  {
    // Check each tail LED for collision
    for (int i = 0; i < s_length; i++) 
    {
      // If collision, stop game and set up game to reset upon replaying
      if ((snake.x == tail[i].x) && (snake.y == tail[i].y) && (snake.z == tail[i].z)) 
      {
        playingSnake = false;
        initSnake = true;
        startXYZPlane = true;
        randomSeed(randomCounter);
      }
    }
  }
}

/*
 * Find a new location that is not occupied by snake
 */
void genNewApple() 
{
  // Make sure apple doesn't overlap with snake head
  while(snakeAppleOverlap(snake.x, snake.y, snake.z, apple.x2, apple.y2, apple.z2)) 
  {
      genAppleCoordinates();
  }

  // Make sure apple doesn't overlap with snake tail
  for (int i = 0; i < s_length; i++) 
  {
    while(snakeAppleOverlap(tail[i].x, tail[i].y, tail[i].z, apple.x2, apple.y2, apple.z2)) 
    {
      genAppleCoordinates();
    }
  }
}

/*
 * Check if snake head/tail overlaps with apple.
 * Overlap: Return True
 * No Overlap: Return False
 */
bool snakeAppleOverlap(int x, int y, int z, int x2, int y2, int z2) 
{
  return ((x == x2) && (y == y2) && (z == z2));
}

/*
 * Use pseudo-random numbers to pick new apple location
 */
void genAppleCoordinates() 
{
  randomCounter++;
  apple.x2 = randomCounter % random(0,8);
  // Make sure apple coordinate is within cube
  if (apple.x2 > 7) {apple.x2 = random(0,7);}
  randomCounter++;
  apple.y2 = randomCounter % random(0,8);
  // Make sure apple coordinate is within cube
  if (apple.y2 > 7) {apple.y2 = random(0,7);}
  randomCounter++;
  apple.z2 = randomCounter % random(0,8);
  // Make sure apple coordinate is within cube
  if (apple.z2 > 7) {apple.z2 = random(0,7);}
}

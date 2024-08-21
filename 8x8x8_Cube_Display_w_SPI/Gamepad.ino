/*
 * Check which button has been pressed
 * Only one signal is sent for each button press
 * No logic implemented if multiple buttons pressed at once
 */
void checkButtons() 
{
  if ((digitalRead(FORWARD) == HIGH) && !buttonPressed) {
    buttonPressed = true;
    forwardPress();
  } else if (digitalRead(BACKWARD) == HIGH && !buttonPressed) {
    buttonPressed = true;
    backwardPress();
  } else if (digitalRead(LEFT) == HIGH && !buttonPressed) {
    buttonPressed = true;
    leftPress();
  } else if (digitalRead(RIGHT) && !buttonPressed) {
    buttonPressed = true;
    rightPress();
  } else if (digitalRead(UP) == HIGH && !buttonPressed) {
    buttonPressed = true;
    upPress();
  } else if (digitalRead(DOWN) == HIGH && !buttonPressed) {
    buttonPressed = true;
    downPress();
  }

  if ((digitalRead(FORWARD) == LOW) && (digitalRead(BACKWARD) == LOW) && (digitalRead(LEFT) == LOW) 
          && (digitalRead(RIGHT) == LOW) && (digitalRead(UP) == LOW) && (digitalRead(DOWN) == LOW)) 
  {
    buttonPressed = false;
  }
}

/*
 * Logic for when FORWARD BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake FORWARD
 *  Testing Cube movement: move cube FORWARD
 *  Animations are playing: begin playing Snake
 */
void forwardPress() 
{
  // If testing cube movement
  if (!playingSnake && testingCube) {
    eraseFullCubeShape(PLAYER_W, PLAYER_L, PLAYER_H, cubeX, cubeY, cubeZ);
    if (cubeX == (8 - PLAYER_W)) { cubeX = (8 - PLAYER_W); }
    else { cubeX++; }
  }
  // If Animations are playing
  else if (!(playingSnake || testingCube)) { playingSnake = true; }
  // If playing Snake
  else 
  {
    if (snake.dir != BACKWARD) 
    {
      snake.dir = FORWARD;
    }
  }
}

/*
 * Logic for when BACKWARD BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake BACKWARD
 *  Testing Cube movement: move cube BACKWARD
 *  Animations are playing: begin playing Snake
 */
void backwardPress() 
{
  // If testing cube movement
  if (!playingSnake && testingCube) {
    eraseFullCubeShape(PLAYER_W, PLAYER_L, PLAYER_H, cubeX, cubeY, cubeZ);
    if (cubeX == 0) { cubeX = 0; }
    else { cubeX--; }
  }
  // If Animations are playing
  else if (!(playingSnake || testingCube)) { playingSnake = true;}
  // If playing Snake
  else 
  {
    if (snake.dir != FORWARD) 
    {
      snake.dir = BACKWARD;
    }
  }
}

/*
 * Logic for when LEFT BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake LEFT
 *  Testing Cube movement: move cube LEFT
 *  Animations are playing: begin playing Snake
 */
void leftPress() 
{
  // If testing cube movement
  if (!playingSnake && testingCube) {
    eraseFullCubeShape(PLAYER_W, PLAYER_L, PLAYER_H, cubeX, cubeY, cubeZ);
    if (cubeZ == 0) { cubeZ = 0; }
    else { cubeZ--; }
  }
  // If Animations are playing
  else if (!(playingSnake || testingCube)) { playingSnake = true;}
  // If playing Snake
  else 
  {
    if (snake.dir != RIGHT) 
    {
      snake.dir = LEFT;
    }
  }
}

/*
 * Logic for when RIGHT BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake RIGHT
 *  Testing Cube movement: move cube RIGHT
 *  Animations are playing: begin playing Snake
 */
void rightPress() 
{
  // If testing cube movement
  if (!playingSnake && testingCube) {
    eraseFullCubeShape(PLAYER_W, PLAYER_L, PLAYER_H, cubeX, cubeY, cubeZ);
    if (cubeZ == (8 - PLAYER_L)) { cubeZ = (8 - PLAYER_L); }
    else { cubeZ++; }
  }
  // If Animations are playing
  else if (!(playingSnake || testingCube)) { playingSnake = true;}
  // If playing Snake
  else 
  {
    if (snake.dir != LEFT) 
    {
      snake.dir = RIGHT;
    }
  }
}

/*
 * Logic for when UP BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake UP
 *  Testing Cube movement: move cube UP
 *  Animations are playing: begin testing cube
 */
void upPress() 
{
  // If testing cube movement
  if (!playingSnake && testingCube) {
    eraseFullCubeShape(PLAYER_W, PLAYER_L, PLAYER_H, cubeX, cubeY, cubeZ);
    if (cubeY == (8 - PLAYER_H)) 
    { 
      testingCube = false;
      initTestingCube = true;
      startXYZPlane = true;
      randomSeed(randomCounter); 
    }
    else { cubeY++; }
  }
  // If Animations are playing
  else if (!(playingSnake || testingCube)) 
  {
    clearCube(); 
    testingCube = true;
  }
  // If playing Snake
  else 
  {
    if (snake.dir != DOWN) 
    {
      snake.dir = UP;
    }
  }
}

/*
 * Logic for when DOWN BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake DOWN
 *  Testing Cube movement: move cube DOWN
 *  Animations are playing: begin playing Snake
 */
void downPress() 
{
  // If testing cube movement
  if (!playingSnake && testingCube) {
    eraseFullCubeShape(PLAYER_W, PLAYER_L, PLAYER_H, cubeX, cubeY, cubeZ);
    if (cubeY == 0) { cubeY = 0; }
    else { cubeY--; }
  }
  // If Animations are playing
  else if (!(playingSnake || testingCube)) { playingSnake = true;}
  // If playing Snake
  else 
  {
    if (snake.dir != UP) 
    {
      snake.dir = DOWN;
    }
  }
}

#include <Arduino.h>
#include <SPI.h>

#define FORWARD 3
#define BACKWARD 5
#define LEFT 7
#define RIGHT 6
#define UP 4
#define DOWN 9

#define PLAYER_W 2
#define PLAYER_L 2
#define PLAYER_H 2

#define INIT_SNAKE_COUNTER 1000
#define MIN_SNAKE_COUNTER 250
#define SPEED_INCREASE 25
#define MAX_SNAKE_LENGTH 75

#define XYZ_PLANE_SPEED 200

volatile uint8_t cube[8][8];
volatile uint16_t timer = 0;

volatile bool xyzPlane[6] = {false, false, false, false, false, false};
volatile int xyzNum = 0;
volatile bool startXYZPlane = true;

volatile uint8_t cubeX = 0;
volatile uint8_t cubeY = 0;
volatile uint8_t cubeZ = 0;
volatile bool buttonPressed = false;
volatile bool testingCube = false;
volatile bool initTestingCube = true;

struct snakeObject {
  int x;
  int y;
  int z;
  int dir;
};

struct appleObject {
  int x2;
  int y2;
  int z2;
};

snakeObject snake = {0, 0, 0, RIGHT};
snakeObject tail[MAX_SNAKE_LENGTH];
int s_length = 0;
int s_speed = 1;
appleObject apple = {0, 0, 0};
volatile bool initSnake = true;
volatile bool playingSnake = false;
volatile int maxSnakeCounter = INIT_SNAKE_COUNTER;
volatile int snakeMovementCounter = 0;
volatile int randomCounter = 0;
volatile int appleBlinkCounter = 0;

void setup() {
  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, LSBFIRST, SPI_MODE0));

  clearCube();

  pinMode(FORWARD, INPUT);
  pinMode(BACKWARD, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(UP, INPUT);

  randomSeed(analogRead(0));
//  drawXPlane(0);
}

void loop() {
//  testMoveCube();
  randomCounter++;
  timer++;
  if (randomCounter > 100) { randomCounter = 0; }
  if (playingSnake) 
  {
    snake_main();
  }
  else if (testingCube) 
  {
    testMoveCube();
  }
  else 
  {
//    clearCube();
    XYZ_Plane_Animation();
  }
  checkButtons(); 
  renderCube();
}

void testMoveCube()
{
  if (initTestingCube) 
  {
    initTestingCube = false;
    cubeX = 0;
    cubeY = 0;
    cubeZ = 0;
  }
  drawFullCubeShape(PLAYER_W, PLAYER_L, PLAYER_H, cubeX, cubeY, cubeZ);
  checkButtons();
}

/*
 * Draw a line along the x axis from START to STP
 * Y chooses how far up y axis line is drawn
 * Z chosses how far along z axis line is drawn
 *        x, y, and z axes go from 0 to 7
 */
void xAxisLine(uint8_t start, uint8_t stp, uint8_t y, uint8_t z) 
{
  for (uint8_t i = start; i <= stp; i++) 
  {
    setLED(i, y, z);
  }
}

/*
 * Draw a line along the y axis from START to STP
 * X chooses how far along x axis line is drawn
 * Z chosses how far along z axis line is drawn
 *        x, y, and z axes go from 0 to 7
 */
void yAxisLine(uint8_t start, uint8_t stp, uint8_t x, uint8_t z) 
{
  for (uint8_t i = start; i <= stp; i++) 
  {
    setLED(x, i, z);
  }
}

/*
 * Draw a line along the z axis from START to STP
 * X chooses how far along x axis line is drawn
 * Y chooses how far up y axis line is drawn
 *        x, y, and z axes go from 0 to 7
 */
void zAxisLine(uint8_t start, uint8_t stp, uint8_t x, uint8_t y) 
{
  for (uint8_t i = start; i <= stp; i++) 
  {
    setLED(x, y, i);
  }
}

/*
 * Light up an entire plane by picking how far up the y axis it will be drawn
 *        x, y, and z axes go from 0 to 7
 */
void drawXPlane(uint8_t y) 
{
  for (uint8_t x = 0; x <= 7; x++) 
  {
    for (uint8_t z = 0; z <= 7; z++) 
    {
      setLED(x, y, z);
    }
  }
}

/*
 * Erase up an entire plane by picking how far up the y axis it will be drawn
 *        x, y, and z axes go from 0 to 7
 */
void eraseXPlane(uint8_t y) 
{
  for (uint8_t x = 0; x <= 7; x++) 
  {
    for (uint8_t z = 0; z <= 7; z++) 
    {
      clearLED(x, y, z);
    }
  }
}

/*
 * Light up an entire plane by picking how far along the x axis it will be drawn
 *        x, y, and z axes go from 0 to 7
 */
void drawYPlane(uint8_t x) 
{
  for (uint8_t y = 0; y <= 7; y++) 
  {
    for (uint8_t z = 0; z <= 7; z++) 
    {
      setLED(x, y, z);
    }
  }
}

/*
 * Erase up an entire plane by picking how far along the x axis it will be drawn
 *        x, y, and z axes go from 0 to 7
 */
void eraseYPlane(uint8_t x) 
{
  for (uint8_t y = 0; y <= 7; y++) 
  {
    for (uint8_t z = 0; z <= 7; z++) 
    {
      clearLED(x, y, z);
    }
  }
}

/*
 * Light up an entire plane by picking how far along the z axis it will be drawn
 *        x, y, and z axes go from 0 to 7
 */
void drawZPlane(uint8_t z) 
{
  for (uint8_t x = 0; x <= 7; x++) 
  {
    for (uint8_t y = 0; y <= 7; y++) 
    {
      setLED(x, y, z);
    }
  }
}

/*
 * Erase up an entire plane by picking how far along the z axis it will be drawn
 *        x, y, and z axes go from 0 to 7
 */
void eraseZPlane(uint8_t z) 
{
  for (uint8_t x = 0; x <= 7; x++) 
  {
    for (uint8_t y = 0; y <= 7; y++) 
    {
      clearLED(x, y, z);
    }
  }
}

/*
 * Draw a cube outline
 * Provide the width, length and height
 * Provide the x,y,z coordinate of corner
 */
void drawEmptyCubeShape(uint8_t width, uint8_t leng, uint8_t height, uint8_t x, uint8_t y, uint8_t z) 
{
  width = width - 1;
  leng = leng - 1;
  height = height - 1;
  xAxisLine(x, x+width, y, z);
  xAxisLine(x, x+width, y+height, z);
  xAxisLine(x, x+width, y, z+leng);
  xAxisLine(x, x+width, y+height, z+leng);
  zAxisLine(z, z+leng, x, y);
  zAxisLine(z, z+leng, x+width, y);
  zAxisLine(z, z+leng, x, y+height);
  zAxisLine(z, z+leng, x+width, y+height);
  yAxisLine(y, y+height, x, z);
  yAxisLine(y, y+height, x+width, z);
  yAxisLine(y, y+height, x, z+leng);
  yAxisLine(y, y+height, x+width, z+leng);
}

/*
 * Draw a cube
 * Provide the width, length and height
 * Provide the x,y,z coordinate of corner
 */
void drawFullCubeShape(uint8_t width, uint8_t leng, uint8_t height, uint8_t x, uint8_t y, uint8_t z)
{
  for (uint8_t i = x; i < x + width; i++) 
  {
    for (uint8_t j = z; j < z + leng; j++) 
    {
      for (uint8_t k = y; k < y + height; k++) 
      {
        setLED(i, k, j);
      }
    }
  }
}

/*
 * Erase a cube
 * Provide the width, length and height
 * Provide the x,y,z coordinate of corner
 */
void eraseFullCubeShape(uint8_t width, uint8_t leng, uint8_t height, uint8_t x, uint8_t y, uint8_t z)
{
  for (uint8_t i = x; i < x + width; i++) 
  {
    for (uint8_t j = z; j < z + leng; j++) 
    {
      for (uint8_t k = y; k < y + height; k++) 
      {
        clearLED(i, k, j);
      }
    }
  }
}

void clearLED(uint8_t x, uint8_t y, uint8_t z) {
  cube[7 - y][7 - z] |= (0x01 << x);
}

void setLED(uint8_t x, uint8_t y, uint8_t z) {
  cube[7 - y][7 - z] ^= (0x01 << x);
}

bool getLED(uint8_t x, uint8_t y, uint8_t z) {
  return (cube[7 - y][7 - z] & (0x01 << x)) == (0x01 << x);
}

void lightCube() {
  for (uint8_t i = 0; i < 8; i++) {
    for (uint8_t j = 0; j < 8; j++) {
      cube[i][j] = 0;
    }
  }
}

void clearCube() {
  for (uint8_t i = 0; i < 8; i++) {
    for (uint8_t j = 0; j < 8; j++) {
      cube[i][j] = 0xFF;
    }
  }
} 

void renderCube() {
  for (uint8_t i = 0; i < 8; i++) {
    digitalWrite(SS, LOW);
    SPI.transfer(0x01 << i);
    for (uint8_t j = 0; j < 8; j++) {
      SPI.transfer(cube[i][j]);
    }
    digitalWrite(SS, HIGH);
  }
}

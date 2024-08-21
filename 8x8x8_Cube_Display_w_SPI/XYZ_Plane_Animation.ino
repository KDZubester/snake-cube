void XYZ_Plane_Animation() 
{
  if (startXYZPlane) 
  {
    drawXPlane[0];
    startXYZPlane = false;
    xyzPlane[0] = true;
    xyzNum = 1;;
  }
  if (timer > XYZ_PLANE_SPEED) 
  {
    timer = 0;
    if (xyzPlane[0]) 
    {
      if (xyzNum == 7) 
      {
        eraseXPlane(xyzNum - 1);
        drawXPlane(xyzNum);
        xyzPlane[0] = false;
        xyzPlane[1] = true;
      }
      else 
      {
        eraseXPlane(xyzNum - 1);
        drawXPlane(xyzNum);
        xyzNum++;
      }
    }
    else if (xyzPlane[1]) 
    {
      if (xyzNum == 1) 
      {
        eraseXPlane(xyzNum);
        drawYPlane(0);
        xyzPlane[1] = false;
        xyzPlane[2] = true;
      }
      else 
      {
        eraseXPlane(xyzNum);
        xyzNum--;
        drawXPlane(xyzNum);
      }
    }
    else if (xyzPlane[2]) 
    {
      if (xyzNum == 7) 
      {
        eraseYPlane(xyzNum - 1);
        drawYPlane(xyzNum);
        xyzPlane[2] = false;
        xyzPlane[3] = true;
      }
      else 
      {
        eraseYPlane(xyzNum - 1);
        drawYPlane(xyzNum);
        xyzNum++;
      }
    }
    else if (xyzPlane[3]) 
    {
      if (xyzNum == 1) 
      {
        eraseYPlane(xyzNum);
        drawZPlane(0);
        xyzPlane[3] = false;
        xyzPlane[4] = true;
      }
      else 
      {
        eraseYPlane(xyzNum);
        xyzNum--;
        drawYPlane(xyzNum);
      }
    }
    else if (xyzPlane[4]) 
    {
      if (xyzNum == 7) 
      {
        eraseZPlane(xyzNum - 1);
        drawZPlane(xyzNum);
        xyzPlane[4] = false;
        xyzPlane[5] = true;
      }
      else 
      {
        eraseZPlane(xyzNum - 1);
        drawZPlane(xyzNum);
        xyzNum++;
      }
    }
    else if (xyzPlane[5])
    {
      if (xyzNum == 1) 
      {
        eraseZPlane(xyzNum);
        drawXPlane(0);
        xyzPlane[5] = false;
        xyzPlane[0] = true;
      }
      else 
      {
        eraseZPlane(xyzNum);
        xyzNum--;
        drawZPlane(xyzNum);
      }
    }
  }
}

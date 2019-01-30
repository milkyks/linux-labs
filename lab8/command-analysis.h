#pragma once
#include "device.h"

int analysCommand(const char* buffer)
{
  char deleteFile[BUF_LEN] = "file_delete";
  char reverse[BUF_LEN] = "direction_back";
  int i;
  int k = 0;

  for (i = 0; i < 11; i++) 
  {
    if (deleteFile[i] == buffer[i])
    {
      k++;
    }
  }

  if (k == 11)
  {
    return k;
  }

  k = 0;

  for (i = 0; i < 14; i++)
  {
    if (reverse[i] == buffer[i])
    {
      k++;
    }
  }

  if (k == 14)
  {
    return k;
  }

  return 0;
}

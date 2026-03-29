#pragma once
#include <iostream>
#include "src/RailEngine.h"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    cout << "No input files provided." << endl;
    return -1;
  }

  RailEngine engine;
  engine.run(argv[1]);
  return 0;
}
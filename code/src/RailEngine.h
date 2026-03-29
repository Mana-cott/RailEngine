#ifndef RAIL_ENGINE_H
#define RAIL_ENGINE_H

#pragma once
#include <string>

class RailEngine
{
public:
  RailEngine() = default;
  ~RailEngine() = default;
  void run(const char *filename);
  void run(std::string filename);
};

#endif
// Copyright (c) 2013-2014 Flowgrammable.org
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
// 
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an "AS IS"
// BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied. See the License for the specific language governing
// permissions and limitations under the License.

#ifndef FREEFLOW_PIPE_HPP
#define FREEFLOW_PIPEL_HPP

#include <unistd.h>
#include <fcntl.h>
#include <string>
#include "error.hpp"


namespace freeflow {

struct Pipe
{
  Pipe(std::string n = std::string());
  Pipe(Pipe&& p);
  ~Pipe();

  std::string name;
  int fd;
};

} // namespace freeflow 

#include "pipe.ipp"

#endif

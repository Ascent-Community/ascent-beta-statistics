// Copyright (c) 2015 - 2016 Anyar, Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//      http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

// Base class for distribution classes

#include "ascent/Link.h"

#include <random>

namespace stats
{
   class Distribution : public asc::Module
   {
   public:
      double* variable = nullptr; // External variable that can be manipulated by a statistical distribution (DO NOT DELETE)

      double discrete = false; // whether or not this distribution should be handled as a discrete signal

      Distribution(size_t sim, const unsigned seed = 0);
      
      void seed(const unsigned seed);

      virtual double compute() = 0; // Allows more generic use of manipulators

   protected:
      std::mt19937 generator;

      void update();

   private:
      void assign();
   };
}
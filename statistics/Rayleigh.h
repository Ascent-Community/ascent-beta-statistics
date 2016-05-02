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

// Generating a Rayleigh distribution with peak value of pdf = 'mode'
// The mean of the distribution is: mean = mode * (pi/2)
// The variance is: variance = mode^2 * (2 - pi/2)

#include "statistics/Distribution.h"

namespace stats
{
   class Rayleigh : public Distribution
   {
   private:
      std::uniform_real_distribution<double> distribution;
      const double mode;

   public:
      Rayleigh(size_t sim, const double mode) : Distribution(sim), mode(mode), distribution(0.0, 1.0) {}
      
      double compute()
      {
         return sqrt(2.0*(-log(distribution(generator))))*mode;
      }
   };
}
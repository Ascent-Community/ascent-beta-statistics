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

// Also known as a Gaussian Distribution

#include "statistics/Distribution.h"

namespace stats
{
   class Normal : public Distribution
   {
   private:
      std::normal_distribution<double> distribution;

   public:
      Normal(size_t sim, const double mean, const double sigma) : Distribution(sim), distribution(mean, sigma) {}

      double compute()
      {
         return distribution(generator);
      }
   };
}
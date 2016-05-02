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

#include "Distribution.h"

using namespace stats;

Distribution::Distribution(size_t sim, const unsigned seed) : asc::Module(sim), generator(seed) {}

void Distribution::seed(const unsigned seed)
{
   generator = std::mt19937(seed);
}

void Distribution::update()
{
   if (variable)
   {
      if (discrete)
      {
         if (sample())
            assign();
      }
      else
         assign();
   }
}

void Distribution::assign()
{
   if (time_advanced || first_update)
      *variable = compute();
}
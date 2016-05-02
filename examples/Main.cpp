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

#include "statistics\Normal.h"
#include "statistics\Rayleigh.h"
#include "statistics\StudentT.h"
#include "statistics\Uniform.h"

#include "Tester.h"

using namespace stats;
using namespace std;

int main()
{
   const size_t sim = 0;

   // This example is showcasing the addManipulator method inherited from asc::Module
   // Adding manipulators allows us to destruct the asc::Link<Normal> instance and the distribution will still be applied to the variable x, until the Tester is finally destroyed
   // The Tester owns a std::shared_ptr to the Normal distribution class

   // The Tester class doesn't know anything about the Normal distribution manipulator that has been applied to its x parameter.
   Tester tester(sim);
   asc::Link<Normal> normal = tester.addManipulator<Normal>(sim, 5.0, 2.0);
   normal->variable = &tester.x;

   // Other distributions:
   //tester.addManipulator<Rayleigh>(sim, 2.0)->variable = &tester.x;
   //tester.addManipulator<StudentT>(sim, 10.0)->variable = &tester.x;
   //tester.addManipulator<Uniform>(sim, 0.0, 10.0)->variable = &tester.x;

   tester.track("x");

   tester.run(0.01, 100.0);

   deque<double> x_hist = tester.history<double>("x");

   const size_t n = x_hist.size();

   size_t p[10] = {};

   for (double d : x_hist)
   {
      if ((d >= 0.0) && (d < 10.0))
         ++p[size_t(d)];
   }
   
   cout << "Distribution:\n";

   const size_t nstars = 100; // maximum number of stars to distribute
   
   for (size_t i = 0; i < 10; ++i)
   {
      cout << i << "-" << (i + 1) << ": ";
      cout << std::string(p[i] * nstars / n, '*') << '\n';
   }

   cout << '\n' << "Simulation finished. Press ENTER to close.";
   cin.get();
   return 0;
}
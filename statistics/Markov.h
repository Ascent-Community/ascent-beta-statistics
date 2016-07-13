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

// Generates time-correlated Normal (Gaussian) value with zero mean.

#include "statistics/Distribution.h"
#include "statistics/Normal.h"

namespace stats
{
   class Markov : public Distribution
   {
   private:
      double& sigma; // standard deviation (allowed to change during simulation)
      const double beta_cor; // beta time correlation coefficient, Hz (1/s)
      double saved; // saved normal distribution value

      std::uniform_real_distribution<double> uniform;

      double gauss()
      {
         double rsq, v1, v2;

         do
         {
            v1 = 2.0*uniform(generator) - 1.0;
            v2 = 2.0*uniform(generator) - 1.0;
            rsq = v1*v1 + v2*v2;
         } while (rsq >= 1.0 || rsq == 0.0);

         double fac = sqrt(-2.0*log(rsq) / rsq);
         double value = v2*fac;

         return value*sigma;
      }

   protected:
      void update()
      {
         if (variable)
         {
            if (time_advanced || first_update)
               *variable = compute();
         }
      }

   public:
      double* variable = nullptr; // variable to manipulate

      Markov(size_t sim, double& sigma, const double beta_cor) : Distribution(sim), sigma(sigma), beta_cor(beta_cor)

      double compute()
      {
         double v = gauss();
         if (t != 0.0)
         {
            if (beta_cor != 0.0)
            {
               double d = exp(-beta_cor*dt);
               v = v*sqrt(1.0 - d*d) + saved*d;
            }
         }

         saved = v;
         return v;
      }
   };
}
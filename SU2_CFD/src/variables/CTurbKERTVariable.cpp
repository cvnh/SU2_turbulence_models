/*!
 * \file CTurbKERTVariable.cpp
 * \brief Definition of the solution fields.
 * \author L. Cavanha
 * \version 8.0.0 "Harrier"
 *
 * SU2 Project Website: https://su2code.github.io
 *
 * The SU2 Project is maintained by the SU2 Foundation
 * (http://su2foundation.org)
 *
 * Copyright 2012-2023, SU2 Contributors (cf. AUTHORS.md)
 *
 * SU2 is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * SU2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with SU2. If not, see <http://www.gnu.org/licenses/>.
 */


#include "../../include/variables/CTurbDUMMYTURBVariable.hpp"

CTurbKERTVariable::CTurbKERTVariable(su2double val_nu_tilde, su2double val_muT, unsigned long npoint, unsigned long ndim, unsigned long nvar, CConfig *config) :
                 CTurbVariable(npoint, ndim, nvar, config) {
    int foo=1;
  }


  /*!
   * \brief Destructor of the class.
   */
//   ~CTurbDUMMYTURBVariable() override = default;

// }


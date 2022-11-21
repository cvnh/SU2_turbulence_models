/*!
 * \file CDataDrivenFluid.hpp
 * \brief Defines a template fluid model class using multilayer perceptrons
 *  for theromodynamic state definition
 * \author E.Bunschoten
 * \version 7.4.0 "Blackbird"
 *
 * SU2 Project Website: https://su2code.github.io
 *
 * The SU2 Project is maintained by the SU2 Foundation
 * (http://su2foundation.org)
 *
 * Copyright 2012-2022, SU2 Contributors (cf. AUTHORS.md)
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

#pragma once

#include "CFluidModel.hpp"
#include "../../../Common/include/toolboxes/multilayer_perceptron/CLookUp_ANN.hpp"
#include "../../../Common/include/containers/CLookUpTable.hpp"

/*!
 * \class CDataDrivenFluid
 * \brief Template class for fluid model definition using multi-layer perceptrons for 
 * fluid dynamic state definition.
 * \author: E.Bunschoten.
 */
class CDataDrivenFluid : public CFluidModel {
 protected:

  unsigned short Kind_DataDriven_Method = ENUM_DATADRIVEN_METHOD::LUT;       // Interpolation method for data set evaluation

  size_t idx_rho,    // Interpolator index for density input
         idx_e;      // Interpolator index for energy input

  su2double Newton_Relaxation,     // Relaxation factor for Newton solvers.
            rho_start,             // Initial value for the density in Newton solver processes.
            e_start;               // Initial value for the energy in Newton solver processes.

  string input_filename;    // Data-driven method input file name.
  
  su2double dsde_rho, dsdrho_e, d2sde2, d2sdedrho, d2sdrho2;
  
  su2double Gamma{0.0};           /*!< \brief Ratio of Specific Heats. */
  su2double Gamma_Minus_One{0.0}; /*!< \brief Ratio of Specific Heats Minus One. */
  su2double Gas_Constant{0.0};    /*!< \brief Gas Constant. */
  
  vector<string> input_names_rhoe,        // Data-driven method input variable names of the independent variables (density, energy).
                 output_names_rhoe;       // Output variable names listed in the data-driven method input file name.

  vector<su2double*> outputs_rhoe;        // Pointers to output variables.

  /*--- Class variables for the multi-layer perceptron method ---*/
  MLPToolbox::CLookUp_ANN * lookup_mlp;   // multi-layer perceptron collection.
  MLPToolbox::CIOMap * iomap_rhoe;        // input-output map.
  vector<su2double> MLP_inputs;           // inputs for the multi-layer perceptron look-up operation.

  /*--- Class variables for the look-up table method ---*/
  CLookUpTable *lookup_table;

  void MapInputs_to_Outputs();

 public:
  /*!
   * \brief Constructor of the class.
   */
  CDataDrivenFluid(const CConfig* config);

  ~CDataDrivenFluid();
  /*!
   * \brief Set the Dimensionless State using Density and Internal Energy
   * \param[in] rho - first thermodynamic variable (density).
   * \param[in] e - second thermodynamic variable (static energy).
   */
  void SetTDState_rhoe(su2double rho, su2double e) override;

  /*!
   * \brief Set the Dimensionless State using Pressure  and Temperature
   * \param[in] P - first thermodynamic variable (pressure).
   * \param[in] T - second thermodynamic variable (temperature).
   */
  void SetTDState_PT(su2double P, su2double T) override;

  /*!
   * \brief Set the Dimensionless State using Pressure and Density
   * \param[in] P - first thermodynamic variable (pressure).
   * \param[in] rho - second thermodynamic variable (density).
   */
  void SetTDState_Prho(su2double P, su2double rho) override;

  /*!
   * \brief Set the Dimensionless Internal Energy using Pressure and Density
   * \param[in] P - first thermodynamic variable (pressure).
   * \param[in] rho - second thermodynamic variable (density).
   */
  void SetEnergy_Prho(su2double P, su2double rho) override;

  /*!
   * \brief Set the Dimensionless Internal Energy using Pressure and Density
   * \param[in] rho - second thermodynamic variable (density).
   */
  void SetTDState_rhoT(su2double rho, su2double T) override;

  /*!
   * \brief Set the Dimensionless State using Enthalpy and Entropy
   * \param[in] h - first thermodynamic variable (h).
   * \param[in] s - second thermodynamic variable (s).
   */
  void SetTDState_hs(su2double h, su2double s) override;

  /*!
   * \brief Set the Dimensionless State using Pressure and Entropy
   * \param[in] P - first thermodynamic variable (P).
   * \param[in] s - second thermodynamic variable (s).
   */
  void SetTDState_Ps(su2double P, su2double s) override;
};

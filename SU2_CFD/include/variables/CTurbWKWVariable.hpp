/*!
 * \file CTurbWKWVariable.hpp
 * \brief Declaration of the variables of the WKW turbulence model.
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

#pragma once

#include "CTurbVariable.hpp"


/*!
 * \brief WKW turbulence model constants
 */
struct wkw_constants{
    su2double beta;           /*!< \brief beta. */
    su2double beta_0;         /*!< \brief beta_0.*/
    su2double beta_star;      /*!< \brief beta_star.*/
    su2double Clim;           /*!< \brief Clim.*/
    su2double gamma;          /*!< \brief gamma (alpha in original ref.).*/
    su2double sigma;          /*!< \brief sigma.*/
    su2double sigma_d0;       /*!< \brief sigma_d0.*/
    su2double sigma_k;        /*!< \brief sigma_k (sigma_star in original ref.).*/
  };

/*!
 * \class CTurbWKWVariable
 * \brief Main class for defining the variables of the turbulence model.
 * \ingroup Turbulence_Model
 * \author L. Cavanha.
 */
class CTurbWKWVariable final : public CTurbVariable {
  
protected:
  su2double sigma_om2;
  su2double beta_star;
  su2double prod_lim_const;
  VectorType F1;
  VectorType F2;    /*!< \brief Menter blending function for blending of k-w and k-eps. */
  VectorType CDkw;  /*!< \brief Cross-diffusion. */
  WKW_ParsedOptions wkwParsedOptions;
public:
  /*!
   * \brief Constructor of the class.
   * \param[in] kine - Turbulence kinetic energy (k) (initialization value).
   * \param[in] omega - Turbulent variable value (initialization value).
   * \param[in] mut - Eddy viscosity (initialization value).
   * \param[in] npoint - Number of points/nodes/vertices in the domain.
   * \param[in] ndim - Number of dimensions of the problem.
   * \param[in] nvar - Number of variables of the problem.
   * \param[in] constants - WKW model constants
   * \param[in] config - Definition of the particular problem.
   */
  CTurbWKWVariable(su2double kine, su2double omega, su2double mut, unsigned long npoint,
                   unsigned long ndim, unsigned long nvar, const wkw_constants wkw_const, CConfig *config);

  /*!
   * \brief Destructor of the class.
   */
  ~CTurbWKWVariable() override = default;

  /*!
   * \brief Set the blending function for the blending of k-w and k-eps.
   * \param[in] val_viscosity - Value of the vicosity.
   * \param[in] val_dist - Value of the distance to the wall.
   * \param[in] val_density - Value of the density.
   */
  void SetBlendingFunc(unsigned long iPoint, su2double val_viscosity, su2double val_dist, su2double val_density, TURB_TRANS_MODEL trans_model) override;

  /*!
   * \brief Get the first blending function.
   */
  inline su2double GetF1blending(unsigned long iPoint) const override { return F1(iPoint); }

  /*!
   * \brief Get the second blending function.
   */
  inline su2double GetF2blending(unsigned long iPoint) const override { return F2(iPoint); }

  /*!
   * \brief Get the value of the cross diffusion of tke and omega.
   */
  inline su2double GetCrossDiff(unsigned long iPoint) const override { return CDkw(iPoint); }
};

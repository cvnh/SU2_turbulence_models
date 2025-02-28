<p align="center">
<img width="250" height="154" src="Docs/logoSU2small.png">
</p>


# SU2 (ver. 8.0.0 "Harrier"): The Open-Source CFD Code - Turbulence Models Development

Computational analysis tools have revolutionized the way we design engineering systems, but most established codes are proprietary, unavailable, or prohibitively expensive for many users. The SU2 team is changing this, making multiphysics analysis and design optimization freely available as open-source software and involving everyone in its creation and development.

For an overview of the technical details in SU2, please see the following AIAA Journal article:

"SU2: An open-source suite for multiphysics simulation and design," AIAA Journal, 54(3):828-846, 2016. <http://arc.aiaa.org/doi/10.2514/1.J053813>

Please note that this project is released with a [Contributor Code of Conduct](CODE_OF_CONDUCT.md). By participating in this project you agree to abide by its terms.

Continuous Integration:<br/>
[![Regression Testing](https://github.com/su2code/SU2/workflows/Regression%20Testing/badge.svg?branch=develop)](https://github.com/su2code/SU2/actions)
[![Release](https://github.com/su2code/SU2/workflows/Release%20Management/badge.svg?branch=develop)](https://github.com/su2code/SU2/actions)

Code Quality:<br/>
[![CodeFactor](https://www.codefactor.io/repository/github/su2code/su2/badge)](https://www.codefactor.io/repository/github/su2code/su2)

# SU2 Introduction

SU2 is a suite of open-source software tools written in C++ for the numerical solution of partial differential equations (PDE) and performing PDE constrained optimization.

The primary applications are computational fluid dynamics and aerodynamic shape optimization, but has been extended to treat more general equations such as electrodynamics and chemically reacting flows.

You will find more information and the latest news in:

- SU2 Home Page: <https://su2code.github.io>
- GitHub repository: <https://github.com/su2code>
- CFD Online: <http://www.cfd-online.com/Forums/su2/>
- Twitter: <https://twitter.com/su2code>
- Facebook: <https://www.facebook.com/su2code>

# About this fork

## Goals
Main goals are:

- Expand the selection of turbulence models
- Facilitate the creation of new turbulence models

Models and validation cases to be based on NASA Turbulence Model resources:

<https://turbmodels.larc.nasa.gov/>

## Current Progress

1 - Infraastructure for all 1, 2 and 3 equation models inputs (done)

2 - Implementation of Wilcox k-Omega (in progress)

3 - Setup of test cases (in progress)

3 - Verification of Wilcox k-Omega (next)


## Details

Refer to Doxygen module Solving the turbulence model equations

## Validation cases / validation matrix

Work in progress

## Issues 

1. Correct categorisation of turbulent model families

    Is this really relevant? Also, overlap between turbulence and transition models (trans_sources.hpp) and the adjoint solver (CAdjFlowOutput.cpp). Would be easy to enable only the existing models to the adjoint. 

    Need to create a list of properties and check if all properties can be categorised in an unique way. 

2. Code partitioning

   Suggest to partition code like option_structure.hpp into smaller files. Turb model options will exceed 1k lines.


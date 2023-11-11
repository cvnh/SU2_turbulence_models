/*! \page turb_model_page Turbulence Models Reference
  \ingroup Turbulence_Model

  \section section1 General
  Turbulence models are based on NASA Langley Turbulence Model Resource:
 
  https://turbmodels.larc.nasa.gov/
  \section section2 Reference
    
  Families of models

  - Assess whether family of turbulence models is relevant in implementation
  - Standardise models
    - SA has experimental option for non-standard options-> good idea?
    - SA has non-standard definition (withft2 instead of noft2) -> should be standardised

  <table>
  <caption id="multi_row">Summary of Models</caption>
  <tr><th>Class                               <th>Family        <th>KIND_TURB_MODEL     <th>Description
  <tr><td>Zero Equation Models                <td>DUMMYTURB     <td>DUMMYTURB           <td>Dummy model
  <tr><td rowspan="3">One Equation Models     <td>NUT 92        <td>NUT92               <td>Sekundov NUT-92
  <tr>                                        <td>SA            <td>SA                  <td>Spalart-Almaras
  <tr>                                        <td>WA (KW?)      <td>WA                  <td>Wray-Agarwal
  <tr><td rowspan="5">Two Equations Models    <td>KW            <td>BSL                 <td>Menter Baseline Turbulence Model
  <tr>                                        <td>KE            <td>C-KE                <td>Chien k-epsilon
  <tr>                                        <td>KKL           <td>KKL                 <td>Menter-Egorov and Abdol-Hamid k-KL
  <tr>                                        <td>KW            <td>SST                 <td>Menter Shear Stress Transport
  <tr>                                        <td>KW            <td>WKW                 <td>Wilcox k-omega
  <tr><td rowspan="2">Three Equations Models  <td>KERT (KE?)    <td>KERT                <td>k-epsilon Rt
  <tr>                                        <td>KEZF (KE?)    <td>KEZF                <td>k-epsilon-zeta-f
  <tr><td>Arbitrary Models                    <td>TURBDEV       <td>TURBDEV             <td>Development model
  </table>



  \subsection subsection3 Reference
According to NASA nomenclature

  Note 1 - to make consistent with NASA reference, would be necessary to switch "withft2" to "noft2" or equivalent, 
  e.g. Edwards would mean -noft2-Edwards without the need to add -noft2 flag. 
  Note 2 - fv3 is not intended in accordance with NASA

  <table>
  <caption id="multi_row">Spallart-Almaras Models</caption>
  <tr><th>Family          <th>KIND_TURB_MODEL     <th>Option Flag         <th>Option                <th>Status (v8.0.0)       <th>Short             <th>Description
  <tr><td>SA              <td>SA                  <td>-                   <td>no option             <td>Available             <td>SA-noft2          <td>Spalart-Allmaras without ft2 term
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>WITHFT2               <td>Available             <td>SA                <td>Standard Spalart-Allmaras
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>NEGATIVE              <td>Available             <td>SA-neg            <td>Negative Spalart-Allmaras
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>NEGATIVE              <td>Available             <td>SA-noft2          <td>Spalart-Allmaras without ft2 term
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>-                     <td>?                     <td>SA-la             <td>Spalart-Allmaras with trip term 
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>ROTATION              <td>Available             <td>SA-RC             <td>Spalart-Allmaras with rotation correction (Dacles-Mariani)
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>-                     <td>-                     <td>SA-KL             <td>Spalart-Allmaras with Kato-Launder correction
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>-                     <td>-                     <td>SA-LRe            <td>Spalart-Allmaras Low Reynolds Number Version
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>COMPRESSIBILITY       <td>Available             <td>SA-comp           <td>Spalart-Allmaras Mixing Layer Compressibility Correction
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>WALL_ROUGHNESS        <td>Available (TBC-check) <td>SA-comp           <td>Spalart-Allmaras Wall Roughness Correction
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>-                     <td>-                     <td>SA-TC             <td>Spalart-Allmaras Transverse curvature free-shear correction
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>QCR2000               <td>-                     <td>SA-QCR2000        <td>Spalart-Allmaras Quadratic Constitutive Relation, 2000 version
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>-                     <td>-                     <td>SA-QCR2013        <td>Spalart-Allmaras Quadratic Constitutive Relation, 2013 version (strain)
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>-                     <td>-                     <td>SA-QCR2013-V      <td>Spalart-Allmaras Quadratic Constitutive Relation, 2013 version (vorticity)
  <tr><td>SA              <td>SA                  <td>SA_OPTIONS          <td>-                     <td>-                     <td>SA-QCR2020        <td>Spalart-Allmaras Quadratic Constitutive Relation, 2013 version (vorticity)
  </table>

According to NASA nomenclature

Note: v8 defaults to 2003m if version not provided -> documentation still reads 1994m

  <table>
  <caption id="multi_row">SST Models</caption>
  <tr><th>Family          <th>KIND_TURB_MODEL     <th>Option Flag         <th>Option                <th>Status (v8.0.0)       <th>Short             <th>Description
  <tr><td>KW              <td>SST                 <td>-                   <td>-                     <td>Available             <td>SSTm              <td>Standard Menter Shear Stress Transport modified (1994)
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>(V1994)               <td>-                     <td>SST               <td>Standard Menter Shear Stress Transport (1994)
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>V1994m                <td>Available             <td>SSTm              <td>Standard Menter Shear Stress Transport modified (1994)
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>VORTICITY             <td>-                     <td>SST-V             <td>Menter Shear Stress Transport vorticity
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>VORTICITY             <td>-                     <td>SST-Vm            <td>Menter Shear Stress Transport vorticity modified
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>KATO_LAUNDER          <td>-                     <td>SST-KL            <td>Menter Shear Stress Transport vorticity with Kato-Launder source term
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>KATO_LAUNDER          <td>Available             <td>SST-KLm           <td>Menter Shear Stress Transport vorticity with Kato-Launder source term modified
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>(V2003)               <td>-                     <td>SST-2003          <td>Menter Shear Stress Transport (2003)
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>V2003m                <td>Available             <td>SST-2003m         <td>Menter Shear Stress Transport modified (2003)
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>-                     <td>-                     <td>SST-sust          <td>Menter Shear Stress Transport with controlled decay 
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>V2003m                <td>Available             <td>SST-sustm         <td>Menter Shear Stress Transport with controlled decay modified
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>SUSTAINING            <td>-                     <td>SST-Vsust         <td>Menter Shear Stress Transport with controlled decay and vorticity source term
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>SUSTAINING, VORTICITY <td>Available             <td>SST-Vsust-m       <td>Menter Shear Stress Transport with controlled decay and vorticity source term modified
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>(RC)                  <td>-                     <td>SST-RC            <td>Menter Shear Stress Transport with rotation/curvature correction
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>(RC)                  <td>-                     <td>SST-RCm           <td>Menter Shear Stress Transport with rotation/curvature correction modified
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>(RC-HELLSTEN)         <td>-                     <td>SST-RC-Hellsten   <td>Menter Shear Stress Transport with Hellsten's simplified rotation/curvature Correction
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>(RC-HELLSTEN)         <td>-                     <td>SST-RC-Hellsten-m <td>Menter Shear Stress Transport with Hellsten's simplified rotation/curvature Correction modified
  <tr><td>KW              <td>SST                 <td>SST_OPTIONS         <td>UQ                    <td>-                     <td>?                 <td>Menter Shear Stress Transport with modified stress tensor for uncertainty quantification
  </table>


  work in progress

  <table>
  <caption id="multi_row">BSL Models</caption>
  <tr><th>Family          <th>KIND_TURB_MODEL     <th>Option Flag         <th>Option                <th>Status (v8.0.0)       <th>Short             <th>Description
  <tr><td>KW              <td>BSL                 <td>-                   <td>-                     <td>-                     <td>BSL               <td>Standard Menter Baseline Two-Equation Model
  <tr><td>KW              <td>BSL                 <td>BSL_OPTIONS         <td>-                     <td>-                     <td>BSL               <td>Standard Menter Baseline Two-Equation Model
  <tr><td>KW              <td>BSL                 <td>BSL_OPTIONS         <td>-                     <td>-                     <td>BSLm              <td>Standard Menter Baseline Two-Equation Model modified
  <tr><td>KW              <td>BSL                 <td>BSL_OPTIONS         <td>VORTICITY             <td>-                     <td>BSL-V             <td>Standard Menter Baseline Two-Equation Model with vorticity source term
  <tr><td>KW              <td>BSL                 <td>BSL_OPTIONS         <td>VORTICITY             <td>-                     <td>BSL-Vm            <td>Standard Menter Baseline Two-Equation Model with vorticity source term modified
  <tr><td>KW              <td>BSL                 <td>BSL_OPTIONS         <td>KATO_LAUNDER          <td>-                     <td>BSL-KL            <td>Standard Menter Baseline Two-Equation Model with vorticity source term
  <tr><td>KW              <td>BSL                 <td>BSL_OPTIONS         <td>KATO_LAUNDER          <td>-                     <td>BSL-KLm           <td>Standard Menter Baseline Two-Equation Model with vorticity source term modified
  </table>

  work in progress
  <table>
  <caption id="multi_row">Nut-92 Models</caption>
  <tr><th>Family          <th>KIND_TURB_MODEL     <th>Option Flag         <th>Option                <th>Status (v8.0.0)       <th>Short            <th>Description
  <tr><td>NUT92           <td>NUT92               <td>-                   <td>-                     <td>-                     <td>Nut-92           <td>Nut-92 (1995)
  <tr><td>NUT92           <td>NUT92               <td>NUT92_OPTIONS       <td>V1995                 <td>-                     <td>Nut-92-FD        <td>Nut-92 (1995)    
  <tr><td>NUT92           <td>NUT92               <td>NUT92_OPTIONS       <td>V1993                 <td>-                     <td>Nut-92-FD        <td>Nut-92 (1993)      
  </table>

  work in progress
  <table>
  <caption id="multi_row">Wray-Agarwal Models</caption>
  <tr><th>Family          <th>KIND_TURB_MODEL     <th>Option Flag         <th>Option                <th>Status (v8.0.0)       <th>Short             <th>Description
  <tr><td>WA              <td>WA                  <td>-                   <td>-                     <td>-                     <td>WA-2018           <td>Wray-Agarwal (2018)
  <tr><td>WA              <td>WA                  <td>WA_OPTIONS          <td>V2018                 <td>-                     <td>WA-2018           <td>Wray-Agarwal (2018)
  <tr><td>WA              <td>WA                  <td>WA_OPTIONS          <td>V2017                 <td>-                     <td>WA-2017           <td>Wray-Agarwal (2017)    
  </table>

  work in progress
  <table>
  <caption id="multi_row">Wilcox k-omega Models</caption>
  <tr><th>Family          <th>KIND_TURB_MODEL     <th>Option Flag         <th>Option                <th>Status (v8.0.0)       <th>Short             <th>Description
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>-                     <td>-                     <td>Wilcox2006        <td>Wilcox k-omega 2006
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V2006                 <td>-                     <td>Wilcox2006        <td>Wilcox k-omega 2006
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V2006m                <td>-                     <td>Wilcox2006m       <td>Wilcox k-omega 2006 modified
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1998                 <td>-                     <td>Wilcox1998        <td>Wilcox k-omega 1998
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1998m                <td>-                     <td>Wilcox1998m       <td>Wilcox k-omega 1998 modified
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1988                 <td>-                     <td>Wilcox1988        <td>Wilcox k-omega 1988
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1988m                <td>-                     <td>Wilcox1988m       <td>Wilcox k-omega 1988 modified
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V2006 NO_POPE         <td>-                     <td>Wilcox2006-noPope <td>Wilcox k-omega 2006 without Pope correction
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V2006 K-LIM           <td>-                     <td>Wilcox2006-klim   <td>Wilcox k-omega 2006
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V2006m K-LIM          <td>-                     <td>Wilcox2006-klim-m <td>Wilcox k-omega 2006 modified
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V2006 VORTICITY       <td>-                     <td>Wilcox2006-V      <td>Wilcox k-omega 2006 with vorticity source term
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V2006m VORTICITY      <td>-                     <td>Wilcox2006m-V     <td>Wilcox k-omega 2006 modified with vorticity source term
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1998 VORTICITY       <td>-                     <td>Wilcox1998-V      <td>Wilcox k-omega 1998 with vorticity source term
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1998m VORTICITY      <td>-                     <td>Wilcox1998m-V     <td>Wilcox k-omega 1998 modified with vorticity source term
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1988 VORTICITY       <td>-                     <td>Wilcox1988-V      <td>Wilcox k-omega 1988 with vorticity source term
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1988m VORTICITY      <td>-                     <td>Wilcox1988m-V     <td>Wilcox k-omega 1988 modified with vorticity source term
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V2006 KATO_LAUNDER    <td>-                     <td>Wilcox2006-KL     <td>Wilcox k-omega 2006 with Kato-Launder correction
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V2006m KATO_LAUNDER   <td>-                     <td>Wilcox2006m-KL    <td>Wilcox k-omega 2006 modified with Kato-Launder correction
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1998 KATO_LAUNDER    <td>-                     <td>Wilcox1998-KL     <td>Wilcox k-omega 1998 with Kato-Launder correction
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1998m KATO_LAUNDER   <td>-                     <td>Wilcox1998m-KL    <td>Wilcox k-omega 1998 modified with Kato-Launder correction
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1988 KATO_LAUNDER    <td>-                     <td>Wilcox1988-KL     <td>Wilcox k-omega 1988 with Kato-Launder correction
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V1988m KATO_LAUNDER   <td>-                     <td>Wilcox1988m-KL    <td>Wilcox k-omega 1988 modified with Kato-Launder correction
  <tr><td>KW              <td>WKW                 <td>WKW_OPTIONS         <td>V2006 LOWRE           <td>-                     <td>Wilcox2006-LRN    <td>Wilcox k-omega 2006 low Reynolds number
  </table>

  work in progress
  <table>
  <caption id="multi_row">Chien k-epsilon Models</caption>
  <tr><th>Family          <th>KIND_TURB_MODEL     <th>Option Flag         <th>Option                <th>Status (v8.0.0)       <th>Short             <th>Description
  <tr><td>CKE             <td>CKE                 <td>-                   <td>-                     <td>-                     <td>KE-Chien          <td>Chien k-epsilon
  <tr><td>CKE             <td>CKE                 <td>CKE_OPTIONS         <td>-                     <td>-                     <td>KE-Chien          <td>Chien k-epsilon
  <tr><td>CKE             <td>CKE                 <td>CKE_OPTIONS         <td>COMP                  <td>-                     <td>KE-Chien-comp     <td>Chien k-epsilon with compressibility correction
  </table>

  work in progress
  <table>
  <caption id="multi_row">k-epsilon-Rt Models</caption>
  <tr><th>Family          <th>KIND_TURB_MODEL     <th>Option Flag         <th>Option                <th>Status (v8.0.0)       <th>Short             <th>Description
  <tr><td>KERT            <td>KERT                <td>-                   <td>-                     <td>-                     <td>k-e-Rt            <td>k-e-Rt model.
  <tr><td>KERT            <td>KERT                <td>KERT_OPTIONS        <td>-                     <td>-                     <td>k-e-Rt            <td>k-e-Rt model.
  <tr><td>KERT            <td>KERT                <td>KERT_OPTIONS        <td>ROTATION              <td>-                     <td>k-e-Rt-RC         <td>k-e-Rt model with rotation/curvature correction.
  </table>

  work in progress
  <table>
  <caption id="multi_row">k-epsilon-zeta-f Models</caption>
  <tr><th>Family          <th>KIND_TURB_MODEL     <th>Option Flag         <th>Option                <th>Status (v8.0.0)       <th>Short             <th>Description
  <tr><td>KEZF            <td>KEZF                <td>-                   <td>-                     <td>-                     <td>k-e-zeta-f2004    <td>k-e-zeta-f model.  
  <tr><td>KEZF            <td>KEZF                <td>KEZF_OPTIONS        <td>-                     <td>-                     <td>k-e-zeta-f2004    <td>k-e-zeta-f model.  
  </table>
*/
 
 
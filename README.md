Last update Aug-30, 2024


# **(1) General**
--------------------------------------------------------
GlueX data analysis for brnaching ratio study
  
  Desired event class:
  
    𝛾n → 𝝆⁻p → π⁻π⁰p    
  
  On a deuteron target:
  
    𝛾D → 𝝆⁻p(p) → π⁻π⁰p(p)    

  We measure the following events:
  
    𝛾D → 𝝆⁻p(p) → π⁻π⁰p(p)    


# **(2) Software**
--------------------------------------------------------

## **(2.1) Shell script**



## **(2.2) DSelector**

The DSelector created for this project was based on *Creating a DSelector* guide: 

https://halldweb.jlab.org/wiki/index.php/DSelector


GlueX software help:

https://groups.google.com/g/gluex-software


### **(2.2.1) Execute DSelector

</ cd /work/hallb/clas12/users/ecohen/halld/GlueX/GlueX_BranchingRatios_Analysis/DSelector/ >
</ root -l ../../tree_gd_pi0pimprotinc__B4_F4_T2_S2_090206.root >
</ .x $(ROOT_ANALYSIS_HOME)/scripts/Load_DSelector.C >
</ gd_pi0pimprotinc__B4_F4_T2_S2_Tree->Process("DSelector_Erez_First_DSelector.C+") >



# **(3) Data** 
--------------------------------------------------------

## **(2.1) Data set from SRC run period **

    The ReactionFilter Plugin uses a defined physics reaction, to analyze the reconstructed data (REST files) event by event testing the hypothesis of the proposed reaction.
    It creates an output  Physics Analysis Root file (PART) which in turn will be analyzed by other code like the DSelector.
    The files produced after the ReactionFilter are placed in:
    
    > /mss/halld/RunPeriod-2021-11/analysis/
    
    SRC/CT physics analysis notes:
    https://halldweb.jlab.org/wiki/index.php/SRC/CT_Physics_Analysis
    
    This analysis uses 
    **Version 06**
    (re-run of most reactions in version 03 to 05 due to the updated proton PID FOM)
    Batch 01: deuterium target
    
        𝛾D → 𝝆⁻p(p) → π⁻π⁰p(p)

    No.   Tree name                             Reaction            Flags          Size    
    12    tree_gd_pi0pimprotinc__B4_F4_T2_S2    1_45__7_9_14_m0     B4_F4_T2_S2    3.4 TB  


    > /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/


    B4_F4_T2_S2 flags are extra constraints on selecting the events:

    B4  The number of additional beam bunches we want in our data set to get a better sense of offtime photons compared to our ontime photons. 
    F4  This means the outgoing particles are momentum conserved and originate from a common vertex. 
    T2  This means we allow for 2 additional charged tracks in this data set. At the DSelector stage, we de-select events with 1 or more extra tracks to clean up the signal. 
    S2  This means extra neutral showers. Same idea as tracks, but for neutral showers (it's primarily extra photons, since we don't have a handle on neutron detection in GlueX).


### **(2.1.1) Get data from tape **

jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090253.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090590.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090593.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090245.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090581.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090586.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090602.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090252.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090662.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090249.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090592.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090579.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090563.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090572.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090585.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090571.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090580.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090584.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090232.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090246.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090564.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090242.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090591.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090587.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090598.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090582.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090240.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090570.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090596.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090243.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090578.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090248.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090560.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090599.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090567.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090589.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090601.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090575.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090568.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090573.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090574.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090583.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090600.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090577.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090565.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090576.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090588.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090247.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090595.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090569.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090561.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090597.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090234.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090558.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090562.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090233.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090241.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090227.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090231.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090226.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090225.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090230.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090244.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090223.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090221.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090228.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090229.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090222.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090220.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090219.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090217.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090206.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090218.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090212.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090214.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090209.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090207.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090215.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090211.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090208.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090210.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090213.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090661.root
jcache get /mss/halld/RunPeriod-2021-11/analysis/ver06/tree_gd_pi0pimprotinc__B4_F4_T2_S2/merged/tree_gd_pi0pimprotinc__B4_F4_T2_S2_090559.root


## **(2.2) Analysis ROOT files after DSelector on my volatile**  

    > /volatile/clas12/users/ecohen/halld/gluex
    
    Version 06
    > /volatile/clas12/users/ecohen/halld/gluex/analysis/ver06/merged



### **(2.2.3) ROOT files after Jackson' DSelector on Jackson' volatile** 


/volatile/halld/home/jrpybus/analysis

    jpsi
    jpsi_inclusive
    rho0_SRC
    rho_deuteron
    rhoMinus_SRC


/volatile/halld/home/jrpybus/analysis/rho_deuteron/ver04

    rho0_p
    rho0_p_inc
    rhoMinus_p
    rhoMinus_p_inc

/volatile/halld/home/jrpybus/analysis/rho_deuteron/ver04/rhoMinus_p/rhoMinus_p






# **(4) Event selection criteria and background subtraction**  
--------------------------------------------------------

https://diginole.lib.fsu.edu/islandora/object/fsu:777104/datastream/PDF/view 




# **(5) Variables and branches**
--------------------------------------------------------  

*decaypi0_p4_kin* 
The best-kinematic-fit 4-momentum for the decaying pi0

*accidweight* 
This is related to the fact that timing information for incoming photons is not perfect, and there exists tagger pileup and ambiguity related to the associated photon with an event. This is important because unlike in electron-scattering, the photon beam is not mono-energetic. To this end, “off-time” photons from different beam bunches (+/- 6-22 ns or so) are also picked up with each event. These off time photons are weighted with a -1/6 value, while all on-time photons are weighted with a +1 value, so that the off-time bunches can account for the on-time bunches that result from pileup. Each histogram must be filled with each combo of final-state and possible beam photon, but considering the different weights. See section 4.3 of the following thesis for details: https://diginole.lib.fsu.edu/islandora/object/fsu:777104/datastream/PDF/view 

The output of the DSelector is what we call a “flat” tree. This means is has one entry per hypothesis for the initial and final state “combo” rather than one per event. This is twofold: first, the tree includes entries for each beam photon candidate (due to tagger accidentals we don’t have a single unique photon candidate), and second, if PID is ambiguous between two particles in the final state both possibilities are considered (this is not an issue in this reaction because there are no like-charge particles to confuse). I don’t recall if we got too much into the details of beam photon accidental subtraction but this is where saving multiple “combos” is important, as you need to ultimately statistically subtract accidental beam photons using off-time photons, similarly to what’s done in band.




### **branches:**
 Meta-data
  run
  trigbits

 Event data
  event
  rftime     event-by-event for comparing the timing of the particles to the expected reaction time given the beam clock.


 Photon hypothesis
  accidweight


 Beam data
  beam_beamid
  beam_x4_meas
  beam_p4_meas
  beam_x4_kin
  beam_p4_kin

 π- data
  pim_trkid
  pim_x4_meas
  pim_p4_meas
  pim_x4_kin
  pim_p4_kin
  pim_pid_fom
  pim_beta_time
  pim_chisq_time
  pim_ndf_time
  pim_ndf_trk
  pim_chisq_trk
  pim_ndf_dedx
  pim_chisq_dedx
  pim_dedx_cdc
  pim_dedx_fdc
  pim_dedx_tof
  pim_dedx_st
  pim_ebcal
  pim_eprebcal
  pim_efcal
  pim_bcal_delphi
  pim_bcal_delz
  pim_fcal_doca

 final state reaction
  kin_chisq         the details of the kinematic fit used in the final-state of the reaction — the chiSq and number of degrees of freedom
  kin_ndf            the details of the kinematic fit used in the final-state of the reaction — the chiSq and number of degrees of freedom
  missp_p4_kin    the best-kinematic-fit 4-momentum for the missing proton, not the detected one


  The pi0 decay
  decaypi0_p4_kin     best-kinematic-fit 4-momentum for the decaying pi0

  The two measured photons from the pi0 decay
  g1_showid       = 0
  g1_x4_meas      = 24f1230
  g1_p4_meas      = 24cc660
  g1_x4_kin       = 24d29d0
  g1_p4_kin       = 2492ea0
  g1_beta_time    = 1.03294
  g1_chisq_time   = nan
  g1_ndf_time     = 1
  g1_ebcal        = 0
  g1_eprebcal     = 0
  g1_efcal        = 3.44589
  g1_bcal_delphi  = 999
  g1_bcal_delz    = 999
  g1_fcal_doca    = 7.68418
  g2_showid       = 1
  g2_x4_meas      = 24ccc90
  g2_p4_meas      = 2469190
  g2_x4_kin       = 2525140
  g2_p4_kin       = 24c4c10
  g2_beta_time    = 0.986913
  g2_chisq_time   = nan
  g2_ndf_time     = 1
  g2_ebcal        = 0
  g2_eprebcal     = 0
  g2_efcal        = 2.30071
  g2_bcal_delphi  = 999
  g2_bcal_delz    = 999
  g2_fcal_doca    = 9.16614

 Proton data
  p_trkid
  p_x4_meas
  p_p4_meas
  p_x4_kin
  p_p4_kin
  p_pid_fom
  p_beta_time
  p_chisq_time
  p_ndf_time
  p_ndf_trk
  p_chisq_trk
  p_ndf_dedx
  p_chisq_dedx
  p_dedx_cdc
  p_dedx_fdc
  p_dedx_tof
  p_dedx_st
  p_ebcal
  p_eprebcal
  p_efcal
  p_bcal_delphi
  p_bcal_delz
  p_fcal_doca

 MC data
  thrownBeam
  thrownPi0
  thrownPiMinus
  thrownProton1
  thrownProton2
  thrownS
  thrownT
  thrownU
 


## Questions to Jackson, Aug - 2024  
--------------------------------------------------------
1. For the branching ratios analysis, Tim looked at 𝛾 + d → p + π⁰ + X events and  𝛾 + d → p + η + X, where π⁰ / η is like g1 + g2 in the rhoMinus_p file and X is anything else. Is there a DSelector output of such events?

=> I need to write my own DSelector. Tim probably worked on one but it was a while ago. 
 
2. What event selection criteria (cuts) did you use ?

=> In the SRC CT analysis note that he shared with me (not the ALP) 
 
3. Do you have a set of slides / plots that I can look at? I’d like to try and reproduce your most basic plots

=> In the SRC CT analysis note that he shared with me 

4. What observable did you use for MF/SRC separation? The light cone fraction of momentum?

=> Pmiss 


5. Regarding background subtraction, you referred me to Section 4.3 of Alberto’ thesis, but I don’t quite understand what technically is done for statistical subtraction of the background. Do you have any script / code from the past that you used? 

=> Each event should be weighted by either 1 if it is "on-time" or 1/6 if it is "off-time"  






## Questions to Alexander Somov, Aug - 2024  
--------------------------------------------------------
1. What shell script / env should I use to create MakeDSelector? Should I use it only in a directory where the data sit?
 
2. I would like to compile a DSelector that produces ROOT files with events of
    𝛾D → 𝝆⁻p(p) → π⁻π⁰p(p) 
 
    Where can I compile the DSelector and how can I run it on a cooked data set?
    
3. What is the best data set to use for this study from the SRC experiment? Where are the data on the farm?     
 
3. How can I implement the basic event selection criteria (cuts) in my DSelector.

4. How can implement background subtraction weights for events that are "on-time" (1) and "off-time" (1/6)?

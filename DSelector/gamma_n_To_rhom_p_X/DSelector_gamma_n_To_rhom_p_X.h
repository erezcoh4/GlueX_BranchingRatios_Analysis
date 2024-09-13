#ifndef DSelector_gamma_n_To_rhom_p_X_h
#define DSelector_gamma_n_To_rhom_p_X_h

#include <iostream>

#include "DSelector/DSelector.h"
#include "DSelector/DHistogramActions.h"
#include "DSelector/DCutActions.h"

#include "TH1I.h"
#include "TH2I.h"
#include <stdio.h>
#include <fstream>

/*
 Desired event class:   gamma + n -> rho- + p
 On a deuteron target:  gamma + D -> rho- + p (+p) -> pi- + pi0 + p (+p) -> pi- + g1 + g2 + p (+p)
 */

class DSelector_gamma_n_To_rhom_p_X : public DSelector
{
public:
    
    int                fdebug = 5;
    int     NEntriesToProcess = 200;
    std::string     csvfilename;
    std::ofstream   csvfile;
    std::string     csvheader = "run,event,entry,combo,E_gamma,locDeltaT_RF,";
    
    
    DSelector_gamma_n_To_rhom_p_X(TTree* locTree = NULL) : DSelector(locTree){}
    virtual ~DSelector_gamma_n_To_rhom_p_X(){}
    
    void Init(TTree *tree);
    Bool_t Process(Long64_t entry);
    
    
    
    void  Debug (int _fdebug_, const char* fmt, ...);
    
private:
    
    void Get_ComboWrappers(void);
    void Finalize(void);
    
    // BEAM POLARIZATION INFORMATION
    UInt_t dPreviousRunNumber;
    bool dIsPolarizedFlag; //else is AMO
    bool dIsPARAFlag; //else is PERP or AMO
    
    bool dIsMC;
    
    // ANALYZE CUT ACTIONS
    // // Automatically makes mass histograms where one cut is missing
    DHistogramAction_AnalyzeCutActions* dAnalyzeCutActions;
    
    //CREATE REACTION-SPECIFIC PARTICLE ARRAYS
    
    //Step 0
    DParticleComboStep* dStep0Wrapper;
    DBeamParticle* dComboBeamWrapper;
    DChargedTrackHypothesis* dPiMinusWrapper;
    DChargedTrackHypothesis* dProtonWrapper;
    
    //Step 1
    DParticleComboStep* dStep1Wrapper;
    DKinematicData* dDecayingPi0Wrapper;
    DNeutralParticleHypothesis* dPhoton1Wrapper;
    DNeutralParticleHypothesis* dPhoton2Wrapper;
    
    // DEFINE YOUR HISTOGRAMS HERE
    // EXAMPLES:
    TH1I* dHist_MissingMassSquared;
    TH1I* dHist_BeamEnergy;
    
    ClassDef(DSelector_gamma_n_To_rhom_p_X, 0);
};

void DSelector_gamma_n_To_rhom_p_X::Get_ComboWrappers(void)
{
    //Step 0
    dStep0Wrapper = dComboWrapper->Get_ParticleComboStep(0);
    dComboBeamWrapper = static_cast<DBeamParticle*>(dStep0Wrapper->Get_InitialParticle());
    dPiMinusWrapper = static_cast<DChargedTrackHypothesis*>(dStep0Wrapper->Get_FinalParticle(1));
    dProtonWrapper = static_cast<DChargedTrackHypothesis*>(dStep0Wrapper->Get_FinalParticle(2));
    
    //Step 1
    dStep1Wrapper = dComboWrapper->Get_ParticleComboStep(1);
    dDecayingPi0Wrapper = dStep1Wrapper->Get_InitialParticle();
    dPhoton1Wrapper = static_cast<DNeutralParticleHypothesis*>(dStep1Wrapper->Get_FinalParticle(0));
    dPhoton2Wrapper = static_cast<DNeutralParticleHypothesis*>(dStep1Wrapper->Get_FinalParticle(1));
}

#endif // DSelector_gamma_n_To_rhom_p_X_h

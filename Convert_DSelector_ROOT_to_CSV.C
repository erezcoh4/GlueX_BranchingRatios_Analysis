/*
 
 Convert DSelector ROOT TTree to a CSV file
 root -l Convert_DSelector_ROOT_to_CSV.C\'(filepath,filename\)'
 last edit Aug-12, 2024
 
 Convert_DSelector_ROOT_to_CSV( TString filename  = "rhoMinus_p_090662",
                                TString TTreeName = "gd_pi0pimprotmissprot__B4_F4_T2_S2",
                                int NeventsMax    = 9,
                                int verbosity     = 1,
                                TString fpath     = "/Users/erezcohen/Desktop/data/GlueX/BranchingRatios/")
 
 execute:
 ----------
 
 root -l -q Convert_DSelector_ROOT_to_CSV.C'("rhoMinus_p_090662","gd_pi0pimprotmissprot__B4_F4_T2_S2",3'\)
 
 
 */


#include <stdarg.h>
#include "Auxiliary/csv_reader.h"
#define getName(VariableName) # VariableName



// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
// Globals
// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
TString                     filepath;
TString                  csvfilename;
TString                 rootfilename;
TString                   inTreeName;

// input: root file and tree
TFile*                      ROOTFile;
TTree*                        inTree;

// output: CSV file
std::ofstream                csvfile;
UInt_t                           run;
ULong64_t                      event;
int                           fdebug;
int                          Nevents;
int                      TTree_entry;
Double_t                 accidweight;
Float_t                    kin_chisq;
UInt_t                       kin_ndf;

std::vector<int>        csvprecision;
std::vector<float>         variables;

// for reading TLorentzVector branches
TBranch*                br = nullptr;
// 4-vectors for the reaction:
// gamma d  -> pi- pi0 p(n)
TLorentzVector*    beam_p4_meas = NULL; // beam
TLorentzVector*     pim_p4_meas = NULL; // pi-
// The two measured photons from the pi0 decay
TLorentzVector*      g1_p4_meas = NULL;
TLorentzVector*      g2_p4_meas = NULL;
TLorentzVector* decaypi0_p4_kin = NULL; // best fit pi0
// The measured proton
TLorentzVector*       p_p4_meas = NULL; // p
// The missing proton
TLorentzVector*    missp_p4_kin = NULL;



// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void Debug(int _fdebug_, const char* fmt, ...) {
    va_list arg;
    va_start(arg, fmt);

    if (fdebug > _fdebug_) {
        vprintf(fmt, arg);
        std::cout << std::endl;
    }
    //vprintf can be replaced with vsprintf (for sprintf behavior)
    //or any other printf function preceded by a v
    va_end(arg);
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void DebugVars(int _fdebug_, std::vector<float> vars){
    if (fdebug > _fdebug_){
        for (auto v:variables) std::cout << v << ", ";
        std::cout << std::endl;
    }
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void Print4Vector(TLorentzVector* v, TString vName, TString vDimensions="GeV",
                  int pprecision=2, int pwidth=6){
    std::cout
    << std::setprecision(pprecision)
    << std::setw(pwidth)
    << std::left
    << std::fixed
    << vName
    << ": ("
    << std::setw(pwidth)
    << v->Px() << ","
    << std::setw(pwidth)
    << v->Py() << ","
    << std::setw(pwidth)
    << v->Pz() << "; "
    << std::setw(pwidth)
    << v->E() << ") "
    << vDimensions
    << std::endl;
}


// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void PrintVariables ( std::vector<float> vars ){
    
    std::cout
    << std::endl
    << "Entry "             << TTree_entry  << ", "
    << "run "               << run          << ", event "   << event
    << std::endl
    << "accidweight: "      << accidweight  << ", "
    << "kinetic chi2/ndf: " << kin_chisq    << "/"          << kin_ndf
    << std::endl
    << std::endl;
    
    Print4Vector( beam_p4_meas, "Beam",  "GeV");
    Print4Vector( pim_p4_meas,  "pi-",   "GeV");
    Print4Vector( g1_p4_meas,   "g1",    "GeV");
    Print4Vector( g2_p4_meas,   "g2",    "GeV");
    Print4Vector( g2_p4_meas,   "pi0",   "GeV");
    Print4Vector( p_p4_meas,    "p",     "GeV");
    
    DebugVars( 5, vars );
}



// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void StreamToCSVfile (std::vector<float> vars,
                      std::vector<int> precisions){
    
    csvfile.open( filepath + csvfilename, std::ios::app );
    for (int j=0; j < vars.size(); j++){
        int precision = 9;
        if (j < precisions.size()) precision = precisions.at(j);
        auto v = variables.at(j);
        csvfile << std::setprecision(precision) << std::fixed << v << ",";
    }
    csvfile << std::endl;
    csvfile.close();
    DebugVars( 4, vars );
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void SetFilepath(TString fpath){
    filepath = fpath;
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void SetROOTFilename(TString filename, TString TTreeName){
    rootfilename = filename + ".root";
    inTreeName   = TTreeName;
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void SetCSVFilename(TString filename){
    csvfilename = filename + ".csv";
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void SetVerbosity( int verbosity ){
    fdebug = verbosity;
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void OpenROOTfile(){
    ROOTFile = new TFile( filepath + rootfilename );
    inTree   = (TTree*)ROOTFile->Get( inTreeName );
    
    // input tree branches
    inTree -> SetBranchAddress("run" ,              &run                );
    inTree -> SetBranchAddress("event" ,            &event              );
    inTree -> SetBranchAddress("accidweight",       &accidweight        );
    inTree -> SetBranchAddress("kin_chisq",         &kin_chisq          );
    inTree -> SetBranchAddress("kin_ndf",           &kin_ndf            );
    
    inTree -> SetBranchAddress("beam_p4_meas",      &beam_p4_meas,      &br);
    inTree -> SetBranchAddress("pim_p4_meas",       &pim_p4_meas,       &br);
    inTree -> SetBranchAddress("g1_p4_meas",        &g1_p4_meas,        &br);
    inTree -> SetBranchAddress("g2_p4_meas",        &g2_p4_meas,        &br);
    inTree -> SetBranchAddress("decaypi0_p4_kin",   &decaypi0_p4_kin,   &br);
    inTree -> SetBranchAddress("p_p4_meas",         &p_p4_meas,         &br);
    inTree -> SetBranchAddress("missp_p4_kin",      &missp_p4_kin,      &br);
    
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void OpenCSVfile(){
    TString csvheader = ( (TString)"entry,runnum,evnum,accidweight,"
                         +(TString)"kin_chisq,kin_ndf,"
                         +(TString)"beam_Px,beam_Py,beam_Pz,beam_E,"
                         +(TString)"pim_Px,pim_Py,pim_Pz,pim_E,"
                         +(TString)"g1_Px,g1_Py,g1_Pz,g1_E,"
                         +(TString)"g2_Px,g2_Py,g2_Pz,g2_E,"
                         +(TString)"p_Px,p_Py,p_Pz,p_E,"
                         +(TString)"missp_Px,missp_Py,missp_Pz,missp_E,"
                         +(TString)"pi0_Px,pi0_Py,pi0_Pz,pi0_E,"
                         );
    
    csvprecision      = {0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,};
    if (fdebug>1) {
        std::cout << filepath + csvfilename << std::endl;
        std::cout << csvheader << std::endl;
    }
    csvfile.open( filepath + csvfilename );
    csvfile << csvheader << std::endl;
    csvfile.close();

}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void ReadEvent( int evt_idx ){
    
    TTree_entry = evt_idx;
    Debug(4, "Entry %d", TTree_entry );
    inTree -> GetEntry( evt_idx );
    
    variables = {
        (float)evt_idx,              (float)run,                  (float)event,                (float)accidweight,
        (float)kin_chisq,            (float)kin_ndf,
        (float)beam_p4_meas->Px(),   (float)beam_p4_meas->Py(),   (float)beam_p4_meas->Pz(),   (float)beam_p4_meas->E(),
        (float)pim_p4_meas->Px(),    (float)pim_p4_meas->Py(),    (float)pim_p4_meas->Pz(),    (float)pim_p4_meas->E(),
        (float)g1_p4_meas->Px(),     (float)g1_p4_meas->Py(),     (float)g1_p4_meas->Pz(),     (float)g1_p4_meas->E(),
        (float)g2_p4_meas->Px(),     (float)g2_p4_meas->Py(),     (float)g2_p4_meas->Pz(),     (float)g2_p4_meas->E(),
        (float)p_p4_meas->Px(),      (float)p_p4_meas->Py(),      (float)p_p4_meas->Pz(),      (float)p_p4_meas->E(),
        (float)missp_p4_kin->Px(),   (float)missp_p4_kin->Py(),   (float)missp_p4_kin->Pz(),   (float)missp_p4_kin->E(),
        (float)decaypi0_p4_kin->Px(),(float)decaypi0_p4_kin->Py(),(float)decaypi0_p4_kin->Pz(),(float)decaypi0_p4_kin->E()
        
    };
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void EndEvent(){
    Debug(3,"");
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void WriteVariablesToCSVfile(){
    Debug(2, "Analyzing %d events", Nevents);
    
    for (int evt_idx = 0; evt_idx < Nevents; evt_idx++ ) {
        ReadEvent      ( evt_idx );
        StreamToCSVfile( variables, csvprecision );
        EndEvent       ();
        
        float progresspct = 100.*(float(evt_idx+1)/Nevents);
        
        bool PrintedAlready = FALSE;
        DebugVars ( 2, variables );
        PrintedAlready = TRUE;
        if ( fmod(progresspct,10)==0 ) {
            if (PrintedAlready==FALSE) DebugVars ( 1, variables );
            Debug( 0, "\nDone analysing %.0f%% (event %d/%d)\n--------------------------------------\n", progresspct, evt_idx+1, Nevents );
        }
    }
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void SetNeventsToRead( int NeventsMax ){
    Nevents = NeventsMax;
    if ((NeventsMax < 0) || (inTree->GetEntries() < NeventsMax)) Nevents = inTree->GetEntries();
}

// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void FinishProgram(){
    if (fdebug)
        std::cout
        << std::endl
        << "Done. See results in: "
        << std::endl
        << filepath + csvfilename
        << std::endl
        << std::endl;
}


// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
// main
// Oo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
void Convert_DSelector_ROOT_to_CSV(TString filename  = "rhoMinus_p_090662",
                                   TString TTreeName = "gd_pi0pimprotmissprot__B4_F4_T2_S2",
                                   int NeventsMax    = 9,
                                   int verbosity     = 1,
                                   TString fpath     = "/Users/erezcohen/Desktop/data/GlueX/BranchingRatios/"){
    
    SetFilepath             ( fpath );
    SetVerbosity            ( verbosity );
    SetROOTFilename         ( filename, TTreeName );
    OpenROOTfile            ();
    SetNeventsToRead        ( NeventsMax );
    SetCSVFilename          ( filename );
    OpenCSVfile             ();
    WriteVariablesToCSVfile ();
    FinishProgram           ();
    
}








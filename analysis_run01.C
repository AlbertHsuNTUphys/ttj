#include<TFile.h>
#include<TTree.h>
#include<TCanvas.h>
#include<TH1F.h>
#include<TLorentzVector.h>
#include<iostream>
using namespace std;
int analysis_run01()
{
  //Obtain TTree Object.
  TFile *out = new TFile("result_run01.root", "recreate");
  TFile *in  = new TFile("tag_1_delphes_events.root");
  TTree *t = (TTree*) in->Get("Delphes");
  //Show total Entry.
  Int_t nEntries = t->GetEntries();  
  cout<<"Total Entries : "<< nEntries << endl;
  cout<<"---------------------------------------------------------------"<<endl;
  //Link the branches.
  Int_t maxsize = 20;
  Int_t Jet_;
  t->SetBranchAddress("Jet", &Jet_);
  //Search for each data.
  Int_t entry = 20;
  while(1){
    cout<<"Select Entry : ";
    cin >> entry;
    t->GetEntry(entry);
    cout<<"Entry : "<<entry<<"---> Jetnumber : "<<Jet_;
    cout<<endl;

  
  }
  return 0;
} 


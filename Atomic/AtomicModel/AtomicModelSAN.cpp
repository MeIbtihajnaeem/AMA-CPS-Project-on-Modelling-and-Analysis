

// This C++ file was created by SanEditor

#include "Atomic/AtomicModel/AtomicModelSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         AtomicModelSAN Constructor             
******************************************************************/


AtomicModelSAN::AtomicModelSAN(){


  Activity* InitialActionList[7]={
    &FailureBC, //0
    &FailureB, //1
    &Activity_Repair_B, //2
    &FailureC, //3
    &Activity_Repair_C, //4
    &FailureA, //5
    &Activity_Repair_A  // 6
  };

  BaseGroupClass* InitialGroupList[7]={
    (BaseGroupClass*) &(FailureB), 
    (BaseGroupClass*) &(Activity_Repair_B), 
    (BaseGroupClass*) &(FailureC), 
    (BaseGroupClass*) &(Activity_Repair_C), 
    (BaseGroupClass*) &(FailureA), 
    (BaseGroupClass*) &(Activity_Repair_A), 
    (BaseGroupClass*) &(FailureBC)
  };

  PlaceB = new Place("PlaceB" ,2);
  B_Failure = new Place("B_Failure" ,0);
  PlaceC = new Place("PlaceC" ,3);
  C_Failure = new Place("C_Failure" ,0);
  FailState = new Place("FailState" ,0);
  PlaceA = new Place("PlaceA" ,1);
  A_Failure = new Place("A_Failure" ,0);
  BCCounter = new Place("BCCounter" ,0);
  FirstTimeFailure = new Place("FirstTimeFailure" ,0);
  BaseStateVariableClass* InitialPlaces[9]={
    PlaceB,  // 0
    B_Failure,  // 1
    PlaceC,  // 2
    C_Failure,  // 3
    FailState,  // 4
    PlaceA,  // 5
    A_Failure,  // 6
    BCCounter,  // 7
    FirstTimeFailure   // 8
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("AtomicModel", 9, InitialPlaces, 
                        0, InitialROPlaces, 
                        7, InitialActionList, 7, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[29][2]={ 
    {4,0}, {8,0}, {1,1}, {7,1}, {0,1}, {0,2}, {1,2}, {7,2}, {3,2}, 
    {4,2}, {6,2}, {3,3}, {7,3}, {2,3}, {2,4}, {3,4}, {7,4}, {1,4}, 
    {4,4}, {6,4}, {4,5}, {6,5}, {5,5}, {8,5}, {5,6}, {6,6}, {1,6}, 
    {3,6}, {4,6}
  };
  for(int n=0;n<29;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[14][2]={ 
    {4,0}, {7,0}, {4,1}, {0,1}, {1,2}, {4,2}, {4,3}, {2,3}, {3,4}, 
    {4,4}, {5,5}, {4,5}, {4,6}, {6,6}
  };
  for(int n=0;n<14;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<7;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void AtomicModelSAN::CustomInitialization() {

}
AtomicModelSAN::~AtomicModelSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void AtomicModelSAN::assignPlacesToActivitiesInst(){
  FailureBC.FailState = (Place*) LocalStateVariables[4];
  FailureBC.BCCounter = (Place*) LocalStateVariables[7];
  FailureBC.FirstTimeFailure = (Place*) LocalStateVariables[8];
}
void AtomicModelSAN::assignPlacesToActivitiesTimed(){
  FailureB.FailState = (Place*) LocalStateVariables[4];
  FailureB.PlaceB = (Place*) LocalStateVariables[0];
  FailureB.B_Failure = (Place*) LocalStateVariables[1];
  FailureB.BCCounter = (Place*) LocalStateVariables[7];
  Activity_Repair_B.B_Failure = (Place*) LocalStateVariables[1];
  Activity_Repair_B.FailState = (Place*) LocalStateVariables[4];
  Activity_Repair_B.PlaceB = (Place*) LocalStateVariables[0];
  Activity_Repair_B.BCCounter = (Place*) LocalStateVariables[7];
  Activity_Repair_B.C_Failure = (Place*) LocalStateVariables[3];
  Activity_Repair_B.A_Failure = (Place*) LocalStateVariables[6];
  FailureC.FailState = (Place*) LocalStateVariables[4];
  FailureC.PlaceC = (Place*) LocalStateVariables[2];
  FailureC.C_Failure = (Place*) LocalStateVariables[3];
  FailureC.BCCounter = (Place*) LocalStateVariables[7];
  Activity_Repair_C.C_Failure = (Place*) LocalStateVariables[3];
  Activity_Repair_C.FailState = (Place*) LocalStateVariables[4];
  Activity_Repair_C.PlaceC = (Place*) LocalStateVariables[2];
  Activity_Repair_C.BCCounter = (Place*) LocalStateVariables[7];
  Activity_Repair_C.B_Failure = (Place*) LocalStateVariables[1];
  Activity_Repair_C.A_Failure = (Place*) LocalStateVariables[6];
  FailureA.PlaceA = (Place*) LocalStateVariables[5];
  FailureA.FailState = (Place*) LocalStateVariables[4];
  FailureA.A_Failure = (Place*) LocalStateVariables[6];
  FailureA.FirstTimeFailure = (Place*) LocalStateVariables[8];
  Activity_Repair_A.FailState = (Place*) LocalStateVariables[4];
  Activity_Repair_A.A_Failure = (Place*) LocalStateVariables[6];
  Activity_Repair_A.PlaceA = (Place*) LocalStateVariables[5];
  Activity_Repair_A.B_Failure = (Place*) LocalStateVariables[1];
  Activity_Repair_A.C_Failure = (Place*) LocalStateVariables[3];
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================FailureBCActivity========================*/


AtomicModelSAN::FailureBCActivity::FailureBCActivity(){
  ActivityInitialize("FailureBC",6,Instantaneous , RaceEnabled, 2,2, false);
}

void AtomicModelSAN::FailureBCActivity::LinkVariables(){
  FailState->Register(&FailState_Mobius_Mark);
  BCCounter->Register(&BCCounter_Mobius_Mark);
  FirstTimeFailure->Register(&FirstTimeFailure_Mobius_Mark);
}

bool AtomicModelSAN::FailureBCActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((BCCounter -> Mark() == 5 && FailState->Mark()==0));
  return NewEnabled;
}

double AtomicModelSAN::FailureBCActivity::Weight(){ 
  return 1;
}

bool AtomicModelSAN::FailureBCActivity::ReactivationPredicate(){ 
  return false;
}

bool AtomicModelSAN::FailureBCActivity::ReactivationFunction(){ 
  return false;
}

double AtomicModelSAN::FailureBCActivity::SampleDistribution(){
  return 0;
}

double* AtomicModelSAN::FailureBCActivity::ReturnDistributionParameters(){
    return NULL;
}

int AtomicModelSAN::FailureBCActivity::Rank(){
  return 1;
}

BaseActionClass* AtomicModelSAN::FailureBCActivity::Fire(){
  FirstTimeFailure->Mark() = 1;
  (*(FailState_Mobius_Mark))++;
  return this;
}

/*======================FailureBActivity========================*/

AtomicModelSAN::FailureBActivity::FailureBActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("FailureB",0,Exponential, RaceEnabled, 3,2, false);
}

AtomicModelSAN::FailureBActivity::~FailureBActivity(){
  delete[] TheDistributionParameters;
}

void AtomicModelSAN::FailureBActivity::LinkVariables(){
  FailState->Register(&FailState_Mobius_Mark);
  PlaceB->Register(&PlaceB_Mobius_Mark);
  B_Failure->Register(&B_Failure_Mobius_Mark);
  BCCounter->Register(&BCCounter_Mobius_Mark);
}

bool AtomicModelSAN::FailureBActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((PlaceB-> Mark() > 0 && FailState->Mark()==0 ));
  return NewEnabled;
}

double AtomicModelSAN::FailureBActivity::Rate(){
  return PlaceB -> Mark() * (lambda/2);
  return 1.0;  // default rate if none is specified
}

double AtomicModelSAN::FailureBActivity::Weight(){ 
  return 1;
}

bool AtomicModelSAN::FailureBActivity::ReactivationPredicate(){ 
  return false;
}

bool AtomicModelSAN::FailureBActivity::ReactivationFunction(){ 
  return false;
}

double AtomicModelSAN::FailureBActivity::SampleDistribution(){
  return TheDistribution->Exponential(PlaceB -> Mark() * (lambda/2));
}

double* AtomicModelSAN::FailureBActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AtomicModelSAN::FailureBActivity::Rank(){
  return 1;
}

BaseActionClass* AtomicModelSAN::FailureBActivity::Fire(){
  PlaceB->Mark()--;
  (*(B_Failure_Mobius_Mark))++;
  (*(BCCounter_Mobius_Mark))++;
  return this;
}

/*======================Activity_Repair_BActivity========================*/

AtomicModelSAN::Activity_Repair_BActivity::Activity_Repair_BActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("Activity_Repair_B",1,Exponential, RaceEnabled, 6,2, false);
}

AtomicModelSAN::Activity_Repair_BActivity::~Activity_Repair_BActivity(){
  delete[] TheDistributionParameters;
}

void AtomicModelSAN::Activity_Repair_BActivity::LinkVariables(){
  B_Failure->Register(&B_Failure_Mobius_Mark);
  FailState->Register(&FailState_Mobius_Mark);
  PlaceB->Register(&PlaceB_Mobius_Mark);
  BCCounter->Register(&BCCounter_Mobius_Mark);
  C_Failure->Register(&C_Failure_Mobius_Mark);
  A_Failure->Register(&A_Failure_Mobius_Mark);
}

bool AtomicModelSAN::Activity_Repair_BActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((B_Failure-> Mark() >0 && FailState -> Mark() > 0 ));
  return NewEnabled;
}

double AtomicModelSAN::Activity_Repair_BActivity::Rate(){
  return (B_Failure -> Mark()) * (meo/2);
  return 1.0;  // default rate if none is specified
}

double AtomicModelSAN::Activity_Repair_BActivity::Weight(){ 
  return 1;
}

bool AtomicModelSAN::Activity_Repair_BActivity::ReactivationPredicate(){ 
  return false;
}

bool AtomicModelSAN::Activity_Repair_BActivity::ReactivationFunction(){ 
  return false;
}

double AtomicModelSAN::Activity_Repair_BActivity::SampleDistribution(){
  return TheDistribution->Exponential((B_Failure -> Mark()) * (meo/2));
}

double* AtomicModelSAN::Activity_Repair_BActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AtomicModelSAN::Activity_Repair_BActivity::Rank(){
  return 1;
}

BaseActionClass* AtomicModelSAN::Activity_Repair_BActivity::Fire(){
  B_Failure-> Mark()--;
BCCounter -> Mark()--;
  if(FailState -> Mark() == 1 && A_Failure -> Mark() == 0 && B_Failure -> Mark() == 0 && C_Failure -> Mark() == 0){
	FailState -> Mark() = 0 ;
}
  (*(PlaceB_Mobius_Mark))++;
  return this;
}

/*======================FailureCActivity========================*/

AtomicModelSAN::FailureCActivity::FailureCActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("FailureC",2,Exponential, RaceEnabled, 3,2, false);
}

AtomicModelSAN::FailureCActivity::~FailureCActivity(){
  delete[] TheDistributionParameters;
}

void AtomicModelSAN::FailureCActivity::LinkVariables(){
  FailState->Register(&FailState_Mobius_Mark);
  PlaceC->Register(&PlaceC_Mobius_Mark);
  C_Failure->Register(&C_Failure_Mobius_Mark);
  BCCounter->Register(&BCCounter_Mobius_Mark);
}

bool AtomicModelSAN::FailureCActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((PlaceC-> Mark() > 0 && FailState->Mark()==0 ));
  return NewEnabled;
}

double AtomicModelSAN::FailureCActivity::Rate(){
  return PlaceC -> Mark() * lambda;
  return 1.0;  // default rate if none is specified
}

double AtomicModelSAN::FailureCActivity::Weight(){ 
  return 1;
}

bool AtomicModelSAN::FailureCActivity::ReactivationPredicate(){ 
  return false;
}

bool AtomicModelSAN::FailureCActivity::ReactivationFunction(){ 
  return false;
}

double AtomicModelSAN::FailureCActivity::SampleDistribution(){
  return TheDistribution->Exponential(PlaceC -> Mark() * lambda);
}

double* AtomicModelSAN::FailureCActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AtomicModelSAN::FailureCActivity::Rank(){
  return 1;
}

BaseActionClass* AtomicModelSAN::FailureCActivity::Fire(){
  PlaceC->Mark()--;
  (*(C_Failure_Mobius_Mark))++;
  (*(BCCounter_Mobius_Mark))++;
  return this;
}

/*======================Activity_Repair_CActivity========================*/

AtomicModelSAN::Activity_Repair_CActivity::Activity_Repair_CActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("Activity_Repair_C",3,Exponential, RaceEnabled, 6,2, false);
}

AtomicModelSAN::Activity_Repair_CActivity::~Activity_Repair_CActivity(){
  delete[] TheDistributionParameters;
}

void AtomicModelSAN::Activity_Repair_CActivity::LinkVariables(){
  C_Failure->Register(&C_Failure_Mobius_Mark);
  FailState->Register(&FailState_Mobius_Mark);
  PlaceC->Register(&PlaceC_Mobius_Mark);
  BCCounter->Register(&BCCounter_Mobius_Mark);
  B_Failure->Register(&B_Failure_Mobius_Mark);
  A_Failure->Register(&A_Failure_Mobius_Mark);
}

bool AtomicModelSAN::Activity_Repair_CActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((C_Failure-> Mark() >0 && FailState -> Mark() > 0 ));
  return NewEnabled;
}

double AtomicModelSAN::Activity_Repair_CActivity::Rate(){
  return (C_Failure -> Mark()) * meo;
  return 1.0;  // default rate if none is specified
}

double AtomicModelSAN::Activity_Repair_CActivity::Weight(){ 
  return 1;
}

bool AtomicModelSAN::Activity_Repair_CActivity::ReactivationPredicate(){ 
  return false;
}

bool AtomicModelSAN::Activity_Repair_CActivity::ReactivationFunction(){ 
  return false;
}

double AtomicModelSAN::Activity_Repair_CActivity::SampleDistribution(){
  return TheDistribution->Exponential((C_Failure -> Mark()) * meo);
}

double* AtomicModelSAN::Activity_Repair_CActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AtomicModelSAN::Activity_Repair_CActivity::Rank(){
  return 1;
}

BaseActionClass* AtomicModelSAN::Activity_Repair_CActivity::Fire(){
  C_Failure-> Mark()--;
BCCounter -> Mark()--;
  if(FailState -> Mark() == 1 && A_Failure -> Mark() == 0 && B_Failure -> Mark() == 0 && C_Failure -> Mark() == 0){
	FailState -> Mark() = 0 ;
}
  (*(PlaceC_Mobius_Mark))++;
  return this;
}

/*======================FailureAActivity========================*/

AtomicModelSAN::FailureAActivity::FailureAActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("FailureA",4,Exponential, RaceEnabled, 4,2, false);
}

AtomicModelSAN::FailureAActivity::~FailureAActivity(){
  delete[] TheDistributionParameters;
}

void AtomicModelSAN::FailureAActivity::LinkVariables(){
  PlaceA->Register(&PlaceA_Mobius_Mark);
  FailState->Register(&FailState_Mobius_Mark);
  A_Failure->Register(&A_Failure_Mobius_Mark);
  FirstTimeFailure->Register(&FirstTimeFailure_Mobius_Mark);
}

bool AtomicModelSAN::FailureAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((PlaceA->Mark()> 0 && FailState->Mark()==0 ));
  return NewEnabled;
}

double AtomicModelSAN::FailureAActivity::Rate(){
  return PlaceA -> Mark() * (lambda/4);
  return 1.0;  // default rate if none is specified
}

double AtomicModelSAN::FailureAActivity::Weight(){ 
  return 1;
}

bool AtomicModelSAN::FailureAActivity::ReactivationPredicate(){ 
  return false;
}

bool AtomicModelSAN::FailureAActivity::ReactivationFunction(){ 
  return false;
}

double AtomicModelSAN::FailureAActivity::SampleDistribution(){
  return TheDistribution->Exponential(PlaceA -> Mark() * (lambda/4));
}

double* AtomicModelSAN::FailureAActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AtomicModelSAN::FailureAActivity::Rank(){
  return 1;
}

BaseActionClass* AtomicModelSAN::FailureAActivity::Fire(){
  PlaceA->Mark()--;
FirstTimeFailure->Mark() = 1;
  (*(FailState_Mobius_Mark))++;
  (*(A_Failure_Mobius_Mark))++;
  return this;
}

/*======================Activity_Repair_AActivity========================*/

AtomicModelSAN::Activity_Repair_AActivity::Activity_Repair_AActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("Activity_Repair_A",5,Exponential, RaceEnabled, 5,2, false);
}

AtomicModelSAN::Activity_Repair_AActivity::~Activity_Repair_AActivity(){
  delete[] TheDistributionParameters;
}

void AtomicModelSAN::Activity_Repair_AActivity::LinkVariables(){
  FailState->Register(&FailState_Mobius_Mark);
  A_Failure->Register(&A_Failure_Mobius_Mark);
  PlaceA->Register(&PlaceA_Mobius_Mark);
  B_Failure->Register(&B_Failure_Mobius_Mark);
  C_Failure->Register(&C_Failure_Mobius_Mark);
}

bool AtomicModelSAN::Activity_Repair_AActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((A_Failure-> Mark() >0 && FailState -> Mark() > 0 ));
  return NewEnabled;
}

double AtomicModelSAN::Activity_Repair_AActivity::Rate(){
  return A_Failure-> Mark() * (meo/4);
  return 1.0;  // default rate if none is specified
}

double AtomicModelSAN::Activity_Repair_AActivity::Weight(){ 
  return 1;
}

bool AtomicModelSAN::Activity_Repair_AActivity::ReactivationPredicate(){ 
  return false;
}

bool AtomicModelSAN::Activity_Repair_AActivity::ReactivationFunction(){ 
  return false;
}

double AtomicModelSAN::Activity_Repair_AActivity::SampleDistribution(){
  return TheDistribution->Exponential(A_Failure-> Mark() * (meo/4));
}

double* AtomicModelSAN::Activity_Repair_AActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AtomicModelSAN::Activity_Repair_AActivity::Rank(){
  return 1;
}

BaseActionClass* AtomicModelSAN::Activity_Repair_AActivity::Fire(){
  A_Failure-> Mark()--;
  if(FailState -> Mark() == 1 && A_Failure -> Mark() == 0 && B_Failure -> Mark() == 0 && C_Failure -> Mark() == 0){
	FailState -> Mark() = 0 ;
}
  (*(PlaceA_Mobius_Mark))++;
  return this;
}


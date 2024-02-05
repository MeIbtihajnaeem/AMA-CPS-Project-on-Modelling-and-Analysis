#ifndef AtomicModelSAN_H_
#define AtomicModelSAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Double lambda;
extern Double meo;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               AtomicModelSAN Submodel Definition                   
*********************************************************************/

class AtomicModelSAN:public SANModel{
public:

class FailureBCActivity:public Activity {
public:

  Place* FailState;
  short* FailState_Mobius_Mark;
  Place* BCCounter;
  short* BCCounter_Mobius_Mark;
  Place* FirstTimeFailure;
  short* FirstTimeFailure_Mobius_Mark;

  double* TheDistributionParameters;
  FailureBCActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // FailureBCActivityActivity

class FailureBActivity:public Activity {
public:

  Place* FailState;
  short* FailState_Mobius_Mark;
  Place* PlaceB;
  short* PlaceB_Mobius_Mark;
  Place* B_Failure;
  short* B_Failure_Mobius_Mark;
  Place* BCCounter;
  short* BCCounter_Mobius_Mark;

  double* TheDistributionParameters;
  FailureBActivity();
  ~FailureBActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // FailureBActivityActivity

class Activity_Repair_BActivity:public Activity {
public:

  Place* B_Failure;
  short* B_Failure_Mobius_Mark;
  Place* FailState;
  short* FailState_Mobius_Mark;
  Place* PlaceB;
  short* PlaceB_Mobius_Mark;
  Place* BCCounter;
  short* BCCounter_Mobius_Mark;
  Place* C_Failure;
  short* C_Failure_Mobius_Mark;
  Place* A_Failure;
  short* A_Failure_Mobius_Mark;

  double* TheDistributionParameters;
  Activity_Repair_BActivity();
  ~Activity_Repair_BActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // Activity_Repair_BActivityActivity

class FailureCActivity:public Activity {
public:

  Place* FailState;
  short* FailState_Mobius_Mark;
  Place* PlaceC;
  short* PlaceC_Mobius_Mark;
  Place* C_Failure;
  short* C_Failure_Mobius_Mark;
  Place* BCCounter;
  short* BCCounter_Mobius_Mark;

  double* TheDistributionParameters;
  FailureCActivity();
  ~FailureCActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // FailureCActivityActivity

class Activity_Repair_CActivity:public Activity {
public:

  Place* C_Failure;
  short* C_Failure_Mobius_Mark;
  Place* FailState;
  short* FailState_Mobius_Mark;
  Place* PlaceC;
  short* PlaceC_Mobius_Mark;
  Place* BCCounter;
  short* BCCounter_Mobius_Mark;
  Place* B_Failure;
  short* B_Failure_Mobius_Mark;
  Place* A_Failure;
  short* A_Failure_Mobius_Mark;

  double* TheDistributionParameters;
  Activity_Repair_CActivity();
  ~Activity_Repair_CActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // Activity_Repair_CActivityActivity

class FailureAActivity:public Activity {
public:

  Place* PlaceA;
  short* PlaceA_Mobius_Mark;
  Place* FailState;
  short* FailState_Mobius_Mark;
  Place* A_Failure;
  short* A_Failure_Mobius_Mark;
  Place* FirstTimeFailure;
  short* FirstTimeFailure_Mobius_Mark;

  double* TheDistributionParameters;
  FailureAActivity();
  ~FailureAActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // FailureAActivityActivity

class Activity_Repair_AActivity:public Activity {
public:

  Place* FailState;
  short* FailState_Mobius_Mark;
  Place* A_Failure;
  short* A_Failure_Mobius_Mark;
  Place* PlaceA;
  short* PlaceA_Mobius_Mark;
  Place* B_Failure;
  short* B_Failure_Mobius_Mark;
  Place* C_Failure;
  short* C_Failure_Mobius_Mark;

  double* TheDistributionParameters;
  Activity_Repair_AActivity();
  ~Activity_Repair_AActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // Activity_Repair_AActivityActivity

  //List of user-specified place names
  Place* PlaceB;
  Place* B_Failure;
  Place* PlaceC;
  Place* C_Failure;
  Place* FailState;
  Place* PlaceA;
  Place* A_Failure;
  Place* BCCounter;
  Place* FirstTimeFailure;

  // Create instances of all actvities
  FailureBCActivity FailureBC;
  FailureBActivity FailureB;
  Activity_Repair_BActivity Activity_Repair_B;
  FailureCActivity FailureC;
  Activity_Repair_CActivity Activity_Repair_C;
  FailureAActivity FailureA;
  Activity_Repair_AActivity Activity_Repair_A;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup FailureBCGroup;

  AtomicModelSAN();
  ~AtomicModelSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end AtomicModelSAN

#endif // AtomicModelSAN_H_

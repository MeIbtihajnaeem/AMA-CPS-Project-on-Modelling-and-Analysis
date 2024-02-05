#include "RewardCalcPVNodes.h"

RewardCalcPV0Worker::RewardCalcPV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&AtomicModel);
}

RewardCalcPV0Worker::~RewardCalcPV0Worker() {
  delete [] TheModelPtr;
}

double RewardCalcPV0Worker::Reward_Function(void) {

return (1-AtomicModel->FirstTimeFailure->Mark());

return (0);



}

RewardCalcPV0::RewardCalcPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAtomicModelSAN);
  double startpts[6]={24, 360, 1080, 2520, 5400, 11160};
  double stoppts[6]={24, 360, 1080, 2520, 5400, 11160};
  Initialize("Reliability",(RewardType)0,6, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("FirstTimeFailure","AtomicModel");
}

RewardCalcPV0::~RewardCalcPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardCalcPV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardCalcPV0Worker;
}
RewardCalcPV1Worker::RewardCalcPV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&AtomicModel);
}

RewardCalcPV1Worker::~RewardCalcPV1Worker() {
  delete [] TheModelPtr;
}

double RewardCalcPV1Worker::Reward_Function(void) {

return (1 - AtomicModel->FailState -> Mark());

return (0);



}

RewardCalcPV1::RewardCalcPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAtomicModelSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("Availibility",(RewardType)3,1, startpts, stoppts, timeindex, 0,1, 1);
  Type = steady_state;
  AddVariableDependency("FailState","AtomicModel");
}

RewardCalcPV1::~RewardCalcPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardCalcPV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardCalcPV1Worker;
}

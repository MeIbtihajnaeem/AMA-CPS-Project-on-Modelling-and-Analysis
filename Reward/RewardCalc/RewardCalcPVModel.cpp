#include "RewardCalcPVModel.h"

RewardCalcPVModel::RewardCalcPVModel(bool expandTimeArrays) {
  TheModel=new AtomicModelSAN();
  DefineName("RewardCalcPVModel");
  CreatePVList(2, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* RewardCalcPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new RewardCalcPV0(timeindex);
    break;
  case 1:
    return new RewardCalcPV1(timeindex);
    break;
  }
  return NULL;
}

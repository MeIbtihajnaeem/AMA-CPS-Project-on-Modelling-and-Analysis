#ifndef _REWARDCALC_PVMODEL_
#define _REWARDCALC_PVMODEL_
#include "RewardCalcPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/AtomicModel/AtomicModelSAN.h"
class RewardCalcPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  RewardCalcPVModel(bool expandtimepoints);
};

#endif

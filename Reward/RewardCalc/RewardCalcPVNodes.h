#ifndef _REWARDCALC_PVS_
#define _REWARDCALC_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/AtomicModel/AtomicModelSAN.h"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"
#include "Cpp/Performance_Variables/SteadyState.hpp"


class RewardCalcPV0Worker:public InstantOfTime
{
 public:
  AtomicModelSAN *AtomicModel;
  
  RewardCalcPV0Worker();
  ~RewardCalcPV0Worker();
  double Reward_Function();
};

class RewardCalcPV0:public PerformanceVariableNode
{
 public:
  AtomicModelSAN *TheAtomicModelSAN;

  RewardCalcPV0Worker *RewardCalcPV0WorkerList;

  RewardCalcPV0(int timeindex=0);
  ~RewardCalcPV0();
  void CreateWorkerList(void);
};

class RewardCalcPV1Worker:public SteadyState
{
 public:
  AtomicModelSAN *AtomicModel;
  
  RewardCalcPV1Worker();
  ~RewardCalcPV1Worker();
  double Reward_Function();
};

class RewardCalcPV1:public PerformanceVariableNode
{
 public:
  AtomicModelSAN *TheAtomicModelSAN;

  RewardCalcPV1Worker *RewardCalcPV1WorkerList;

  RewardCalcPV1(int timeindex=0);
  ~RewardCalcPV1();
  void CreateWorkerList(void);
};

#endif

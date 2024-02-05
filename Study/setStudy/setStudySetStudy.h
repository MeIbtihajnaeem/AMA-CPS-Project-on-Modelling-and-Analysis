
#ifndef setStudySetSTUDY_H_
#define setStudySetSTUDY_H_

#include "Reward/RewardCalc/RewardCalcPVNodes.h"
#include "Reward/RewardCalc/RewardCalcPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Double lambda;
extern Double meo;

class setStudySetStudy : public BaseStudyClass {
public:

setStudySetStudy();
~setStudySetStudy();

private:

double *lambdaValues;
double *meoValues;

void SetValues_lambda();
void SetValues_meo();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif


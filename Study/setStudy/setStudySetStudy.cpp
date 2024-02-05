
#include "Study/setStudy/setStudySetStudy.h"

//******************************************************
//Global Variables
//******************************************************
Double lambda;
Double meo;

//********************************************************
//setStudySetStudy Constructor
//********************************************************
setStudySetStudy::setStudySetStudy() {

  // define arrays of global variable names and types
  NumGVs = 2;
  NumExps = 6;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("lambda");
  GVTypes[0]=strdup("double");
  GVNames[1]=strdup("meo");
  GVTypes[1]=strdup("double");

  // create the arrays to store the values of each gv
  lambdaValues = new double[NumExps];
  meoValues = new double[NumExps];

  // call methods to assign values to each gv
  SetValues_lambda();
  SetValues_meo();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//setStudySetStudy Destructor
//******************************************************
setStudySetStudy::~setStudySetStudy() {
  delete [] lambdaValues;
  delete [] meoValues;
  delete ThePVModel;
}


//******************************************************
// set values for lambda
//******************************************************
void setStudySetStudy::SetValues_lambda() {
  lambdaValues[0] = 0.1;
  lambdaValues[1] = 0.01;
  lambdaValues[2] = 0.001;
  lambdaValues[3] = 0.001;
  lambdaValues[4] = 0.1;
  lambdaValues[5] = 1.0E-4;
}


//******************************************************
// set values for meo
//******************************************************
void setStudySetStudy::SetValues_meo() {
  meoValues[0] = 0.1;
  meoValues[1] = 0.01;
  meoValues[2] = 0.001;
  meoValues[3] = 0.1;
  meoValues[4] = 0.001;
  meoValues[5] = 1.0E-4;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void setStudySetStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
  cout << "lambda\tdouble\t" << lambda << endl;
  cout << "meo\tdouble\t" << meo << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *setStudySetStudy::GetGVValue(char *TheGVName) {
  if (strcmp("lambda", TheGVName) == 0)
    return &lambda;
  else if (strcmp("meo", TheGVName) == 0)
    return &meo;
  else 
    cerr<<"!! setStudySetStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void setStudySetStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("lambda", TheGVName) == 0)
    SetGvValue(lambda, *(double *)TheGVValue);
  else if (strcmp("meo", TheGVName) == 0)
    SetGvValue(meo, *(double *)TheGVValue);
  else 
    cerr<<"!! setStudySetStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void setStudySetStudy::SetGVs(int expNum) {
  SetGvValue(lambda, lambdaValues[expNum]);
  SetGvValue(meo, meoValues[expNum]);
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new setStudySetStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* setStudySetStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new RewardCalcPVModel(expandTimeArrays);
  return ThePVModel;
}



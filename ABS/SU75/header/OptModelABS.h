//#include "ComparisonModel.h"
OptModelABS(int Tbs, int* DS, int* minM, int nUser, int Modulation, int Ntp, int* ptrAdjacentBSs, double mSBP, double mABP, double* P, double ABP, double SBP, int mNbs, double BP, double MP, double mP, int DSt, double* BR, int* ConnectionAssignment){
	FILE *PrintToFile;
	if((PrintToFile=fopen("OptModelABS.txt","w"))==NULL)
		printf("\nerror!Fail to open OptModelABS.txt!");
	else
		printf("\nOpen OptModelABS.txt successfully!\n");
	fprintf(PrintToFile,"This is the input to CPLEX for Optimization Model with ABS consideration.\n");
	
	cobjective(Tbs,PrintToFile,Ntp,Modulation,BR,DS);
	
//  	fprintf(NoExistingUser,"\nst\n");
// fprintf(PowerSavingCPLEX,"\nst\n");
//  printf("\nst\n");
	ABSconstraint1(Tbs,DS,PrintToFile,minM,mNbs,Modulation,DS,DSt,Ntp);
	//cconstraint1(Tbs,DS,PrintToFile,minM,mNbs,Modulation,DS,DSt,Ntp);
	cconstraint2(Tbs,PrintToFile, mNbs, Ntp, Modulation, P, MP, mP);
	cconstraint3(Tbs,PrintToFile,nUser, Modulation);
	cconstraint4(Tbs,PrintToFile, Ntp, Modulation, BP);
	cconstraint5(Tbs,PrintToFile, Ntp, Modulation);
	cconstraint10(Tbs,PrintToFile, Ntp, Modulation, ptrAdjacentBSs);
	cconstraint6(Tbs,PrintToFile, Ntp, Modulation);
	cconstraint7(Tbs,PrintToFile, Ntp, Modulation);
	cconstraint8(Tbs,PrintToFile, Ntp, Modulation);
	cconstraint9(Tbs,PrintToFile, mNbs, ABP, SBP, Ntp, Modulation, P, mABP, mSBP);
	cconstraint11(Tbs,PrintToFile,nUser, Ntp, Modulation);
// 	int i, j, k;
// 	for (i=0; i<Tbs; i++)
// 		for (j=0; j<Ntp; j++)
// 			if (*(ConnectionAssignment+j) == i)
// 				for (k=0; k<Modulation; k++)
// 					if (k == Modulation-1)
// 						fprintf (PrintToFile, "u%d_%d_%d - t = 0\n", i, j, k);
// 					else
// 						fprintf (PrintToFile, "u%d_%d_%d + ", i, j, k);
// 	fprintf(NoExistingUser,"bounds\n");
// fprintf(PowerSavingCPLEX,"bounds\n");
//  printf("bounds\n");
	ABSbounds(Tbs,PrintToFile, Ntp, Modulation, mNbs);
	//cbounds(Tbs,PrintToFile, Ntp, Modulation);
	cspecifyTypes(Tbs,PrintToFile, Ntp, Modulation);
	fclose(PrintToFile);
}  
 
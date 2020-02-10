#include <stdio.h>

#include "Vec3.h"
#include "Mat4.h"

/*

MATH MODULE TEST

This executable tests the math module and functions that it has.
If you add somthing to the library you should test it in this file and merge it on github.



*/

int main()
{
	// FMAT4 MATH //////////////////////

    fMatrix4 fMat4_Identity();

	fMatrix4 TestMat = fMat4_Init((fVector3) { 0.5f, 5.0f, 60.0f }, (fVector3) { 0.0f, 0.0f, 0.0f }, (fVector3) { 1.0f, 1.0f, 1.0f });
	fMatrix4 TestMat2 = fMat4_Init((fVector3) { 0.5f, 5.0f, 60.0f }, (fVector3) { 0.0f, 0.0f, 0.0f }, (fVector3) { 1.0f, 1.0f, 1.0f });

	
	// FMAT4 MATH ADD
	fMatrix4 TestMatAdd = fMat4_Add(TestMat, TestMat2);
	

	char* MatAddStr = "";
	
	
	printf("Add fMatrix4 Test: "); printf(fMat4_ToString(TestMatAdd, MatAddStr)); printf("\n\n");

	MatAddStr = NULL;

	// FMAT4 MATH SUB
	fMatrix4 TestMatSub = fMat4_Sub(TestMat, TestMat2);


	char* MatSubStr = " ";

	printf("Sub fMatrix4 Test: "); 
	fMat4_ToString(TestMatSub, MatSubStr); 
	printf("\n\n");

	MatSubStr = NULL;




	return 0;
} 
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     touch,          sensorTouch)
#pragma config(Sensor, S4,     IR2,            sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          vacuumA,       tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,          vacuumB,       tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     flag,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_2,     lift,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     leftMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     rightMotor,    tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	//Intial Readings
int degreesToTurn = 86;  //Positive value turns to the left.  Negative value turns to the right.
float degreesSoFar = 0;
int initialTurnReading =SensorValue[gyro];

//start turning
motor[leftMotor] = 50*sgn(degreesToTurn);
motor[rightMotor]= -50*sgn(degreesToTurn);


//Check Turn ammount
while (abs(degreesSoFar) < abs(degreesToTurn))
{
	wait1Msec(10);
	int currentGyroReading = SensorValue[gyro] - initialTurnReading;
	degreesSoFar = degreesSoFar + currentGyroReading*.01;
}
//Stop Motors
motor[leftMotor] = 0;
motor[rightMotor] = 0;
}

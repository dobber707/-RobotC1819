#pragma config(Sensor, dgtl2,  OnButton,       sensorTouch)
#pragma config(Sensor, dgtl5,  USenInput,      sensorSONAR_cm)
#pragma config(Motor,  port2,           CraneMotor,    tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
/*
Project title: Vex Crane
Team Members: Rohan Saini, Ben Arnett, Cody Dobbs, Evan Don
Date: 2/25/19

Task Description: A 393 Motor will rotate causing a wooden block to drop.
When the ultrasonic sensor has a value of 4 (4cm above) the motor will change direction
and raise the block till it is 13cm above the senor.

Psuedocode:
-Click bump switch
-393 motor starts at a power level of 15
-ultrasonic senor will sense distance until block is 4cm above sensor
-sensor will tell the motor to rotate the opposite direction
-turns off after ultrasonic senor sense the block at 13cm above it
*/
task main()
{
	while(true)
	{
		if (SensorValue[OnButton] == 1)
		{
			startMotor(CraneMotor, -25);
			if (SensorValue[USenInput] == 4)
			{
				startMotor(CraneMotor,25);
			}
		}
		wait (3);

	}
}

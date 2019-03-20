#include<stdio.h>
#include<wiringPi.h>
#include<stdlib.h>
#include<unistd.h>

#define delayMax 1024
//#define delayTime 500 //ms
#define loopCount 10

// ./helloGpio [PinNumber]
int main(int argc, char** argv)
{	
	int gpioNo;
	int i;
	int delayTime;
	
	// STEP 1. WiringPi Init
	wiringPiSetup();

	// Pin number Error
	if(argc<2)
	{
		printf("Usage : %s gpioNo\n", argv[0]);
		return -1;
	}

	// STEP 2. Pin direction setup
	gpioNo = atoi(argv[1]);
	pinMode(gpioNo, OUTPUT);

	for(i=0;i<loopCount;i++){
		// STEP 3. Pin Write
		for(delayTime=0;delayTime<delayMax;delayTime++)
		{
			digitalWrite(gpioNo, HIGH);
			usleep(delayTime);
			digitalWrite(gpioNo, LOW);
			usleep(delayMax-delayTime);	
		}
		
		for(delayTime=0;delayTime<delayMax;delayTime++)
		{
			digitalWrite(gpioNo, LOW);
			usleep(delayTime);
			digitalWrite(gpioNo, HIGH);
			usleep(delayMax-delayTime);	
		}
	}
	return 0;
}



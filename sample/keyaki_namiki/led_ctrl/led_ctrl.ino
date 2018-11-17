/*
 * This is a test program for universal16 with external Arduino.
 * Use with keyaki_namiki/master/master.ino
 * 
 */
#include <SoftwareSerial.h>
const int ledcols = 4;
const int ledrows = 4;
const int ledcol[ledcols] = {A2,A3,4,2};
const int srclk = 7;
const int srclr = 8;
const int sra = A0;
const int srb = A1;
//const int renc = 2;
//const int rencr[renc] = {11,6};
//const int rencg[renc] = {10,5};
//const int rencb[renc] = {9,3};

const int Tx = A4;
const int Rx = A5;
SoftwareSerial keyserial(Rx,Tx);

byte sendData,readData;

//int r[renc] = {0};
//int g[renc] = {0};
//int b[renc] = {0};
int matrixDefault[ledrows][ledcols] = {
	{1,1,1,1},
	{1,1,1,1},
	{1,1,1,1},
	{1,1,1,1}
};
int keyPressed[ledrows][ledcols]={0};
void srclock(){
	digitalWrite(srclk,1);
	digitalWrite(srclk,0);
};

void setup(){
	Serial.begin(9600);
	keyserial.begin(115200);
	while(!Serial);
	if(keyserial.available()){
	    readSerial();
	}
	pinMode(srclk,OUTPUT);
	pinMode(srclr,OUTPUT);
	pinMode(sra,OUTPUT);
	pinMode(srb,OUTPUT);
	for(int i=0;i<4;i++){
		pinMode(ledcol[i],OUTPUT);
		digitalWrite(ledcol[i],0);
	}
	Serial.println("initialized");
	digitalWrite(srclk,0);
	digitalWrite(srclr,0);
	digitalWrite(sra,0);
	digitalWrite(srb,0);
}

void loop(){
	int *matrix[ledrows];
	for(int k=0;k<ledrows;k++){
		matrix[k] = matrixDefault[k];
	}
	for(int i=0;i<ledrows;i++){
		int swapMatrix = 0;
		for(int j=0;j<ledcols;j++){
			swapMatrix += keyPressed[i][j];
		}
		if(swapMatrix != 0){
			for(int k=0;k<ledrows;k++){
				matrix[k] = keyPressed[k];
			}
			break;
		}
	}
	for(int i=ledcols;i>=0;i--){
		digitalWrite(srclr,1);
		digitalWrite(srb,1);
		for(int j=ledrows;j>=0;j--){
			digitalWrite(sra,matrix[j][i]);
			srclock();
			digitalWrite(sra,0);
		}
		digitalWrite(ledcol[i],1);
		delay(3);
		digitalWrite(srclr,0);
		digitalWrite(ledcol[i],0);
	}
	if(keyserial.available()){
		readSerial();
	}
}

void readSerial(){
	int Row1, Col1, isPress;

	readData = keyserial.read();
	Serial.println(readData);

	if(readData & 0b00000000){

	} else {
		isPress = readData >> 5;
		Row1 = (readData & 0b00011000) >> 3;
		Col1 = (readData & 0b00000110) >> 1;
		Serial.print("key ");
		Serial.print(Row1);
		Serial.print(",");
		Serial.print(Col1);
		if(isPress){
			keyPressed[Row1][Col1] = 1;
			Serial.println(" pressed!");
		} else {
			keyPressed[Row1][Col1] = 0;
			Serial.println(" released!");
		}
	}
}
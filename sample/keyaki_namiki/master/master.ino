/*
 * This is a test program for universal16 with external Arduino.
 * Use with keyaki_namiki/led_ctrl/led_ctrl.ino
 * 
 */
const int Rowpin[] = {4,5,7,8};
const int Colpin[] = {10,15,14,16};
const int Cols = (sizeof(Rowpin)/sizeof(Rowpin[0]));
const int Rows = (sizeof(Colpin)/sizeof(Colpin[0]));
bool beforeState[Rows][Cols];
bool currentState[Rows][Cols];
byte sendData,readData;
/* data description
 * 
 * 0b0000000
 *   _			matrix or renc
 *   if matrix(0)
 *   *_			press or release
 *   **_		master or slave
 *   ***__		matrix position (row)
 *   *****__	matrix position (col)
 *   *******0	blank
 *   if renc(1)
 *   *_			renc0 or renc1
 *   **_		button press or release
 *   ***_		rotate (en/dis)able
 *   ****_		rotate direction
 *   *****000	blank
 */
void setup(){
	Serial.begin(9600);
	Serial1.begin(115200);
	Serial1.write("hello!");
//	while(!Serial);
	Serial.println("Started.");
	for(int i=0;i<Cols;i++){
		pinMode(Rowpin[i],OUTPUT);
	}
	Serial.print("num of Rowpin: ");
	Serial.println(Rows);
	Serial.println("Rowpin initialized.");
	for(int i=0;i<Rows;i++){
		pinMode(Colpin[i],INPUT_PULLUP);
	}
	Serial.print("num of Colpin: ");
	Serial.println(Cols);
	Serial.println("Colpin initialized.");
	for(int i=0;i<Rows;i++){
		for(int j=0;j<Cols;j++){
			currentState[i][j] = HIGH;
			beforeState[i][j] = HIGH;
		}
	}
	Serial.println("initialize finished");
}
void loop(){
	int isPress = 0;
	delay(1);
	for(int i=0;i<Rows;i++){
		digitalWrite(Rowpin[i],LOW);
		for(int j=0;j<Cols;j++){
			currentState[i][j] = digitalRead(Colpin[j]);
			if (currentState[i][j] != beforeState[i][j]){
					Serial.print("key ");
					Serial.print(i);
					Serial.print(",");
					Serial.print(j);
				if(currentState[i][j] == LOW){
					Serial.println(" pressed!");
					isPress = 1;
				} else {
					Serial.println(" released!");
					isPress = 0;
				}
				beforeState[i][j] = currentState[i][j];
				sendData = isPress << 5 | i << 3 | j << 1 | 0 ;
				Serial1.write(sendData);
				Serial.print("sent :");
				Serial.println(sendData);
			}
		}
		digitalWrite(Rowpin[i],HIGH);
	}
}
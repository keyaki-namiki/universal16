/* This is a test program for universal16 with arduino.
 * to run this program properly, you have to hand-wire
 * between some pads and controller.
 *
 */

const int Rowpin[] = {4,5,7,8};
const int Colpin[] = {10,15,14,16};
const int Cols = (sizeof(Rowpin)/sizeof(Rowpin[0]));
const int Rows = (sizeof(Colpin)/sizeof(Colpin[0]));
bool beforeState[Rows][Cols];
bool currentState[Rows][Cols];
void setup(){
	Serial.begin(9600);
	while(!Serial);
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
	delay(1);
	for(int i=0;i<Rows;i++){
		digitalWrite(Rowpin[i],LOW);
		for(int j=0;j<Cols;j++){
			currentState[i][j] = digitalRead(Colpin[j]);
			if (currentState[i][j] != beforeState[i][j]){
				if(currentState[i][j] == LOW){
					Serial.print("key ");
					Serial.print(i);
					Serial.print(",");
					Serial.print(j);
					Serial.println(" pressed!");
				} else {
					Serial.print("key ");
					Serial.print(i);
					Serial.print(",");
					Serial.print(j);
					Serial.println(" released!");
				}
				beforeState[i][j] = currentState[i][j];
			}
		}
		digitalWrite(Rowpin[i],HIGH);
	}
}
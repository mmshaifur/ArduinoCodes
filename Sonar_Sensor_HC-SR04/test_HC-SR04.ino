/*
  Author : Shaifur Rahman
  Date      : April 14, 2021
  Device(s) : Arduino UNO, HC-SR04
  Version   : 1.0
*/

const int trigPin = 9; 
const int echoPin = 10;
float duration, distance;
void setup() { 
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 Serial.begin(9600); 
}

void loop() { 
	 digitalWrite(trigPin, LOW); 
	 delayMicroseconds(2); 
	 digitalWrite(trigPin, HIGH); 
	 delayMicroseconds(10); 
	 digitalWrite(trigPin, LOW);
	 /*
	 When the sound waves hit the receiver, it turns the Echo pin high for however long the waves were traveling for. To get that, we can use a handy Arduino function called pulseIn(). It takes 2 arguments, the pin you are listening to(In our case, the Echo pin), and a state(HIGH or LOW). What the function does is waits for the pin to go whichever state you put in, starts timing, and then stops timing when it switches to the other state. In our case we would put HIGH since we want to start timing when the Echo pin goes high. We will store the time in the duration variable. (It returns the time in microseconds)
	 */

	 duration = pulseIn(echoPin, HIGH);

	 distance = (duration*.0343)/2;

	 /*
	 Now that we have the time, we can use the equation speed = distance/time, but we will make it time x speed = distance because we have the speed. What speed do we have? The speed of sound, of course! The speed of sound is approximately 340 meters per second, but since the pulseIn() function returns the time in microseconds, we will need to have a speed in microseconds also, which is easy to get. A quick Google search for "speed of sound in centimeters per microsecond" will say that it is .0343 c/μS. You could do the math, but searching it is easier. Anyway, with that information, we can calculate the distance! Just multiply the duration by .0343 and then divide it by 2(Because the sound waves travel to the object AND back). We will store that in the distance variable.
	 */

	 Serial.print("Distance: "); 
	 Serial.println(distance); 
	 delay(100); 
} 
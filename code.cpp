// C++ code
//
int sensor=A0;  //Analog channel 0 of arduino. 
int Buz= 11;    //Arduino buzzer interface pin
int Led= 6;     //Arduino Led interface pin

void setup()
{
Serial.begin(9600);    //Begin Serial monitor of arduino ide
pinMode(Buz, OUTPUT);  //Arduino buzzer pin as output
pinMode(Led, OUTPUT);  //Arduino Led pin as output
}

void loop()
{
//Read Intensity of light thrown on LDR and
//store the measured value in variable senValue
int senValue=analogRead(sensor); 
delay(10);                       //Time for ADC to stable 
Serial.println(senValue);        //Print the read value on arduino serial monitor

//If the voltage at 10 k resitor is 4.7 volts or senValue is Smaller then 970. Then
//enter in the if statement.
if(senValue<970){
    //same Output voltage to buzzer which apperas as input on A0 channel of arduino
  	analogWrite(Buz, senValue/4); 
    //Same Output voltage to Led which apperas as input on A0 channel of arduino
    analogWrite(Led, senValue/4); 
}
else
{
  digitalWrite(Buz,HIGH); 
  digitalWrite(Led,HIGH); 
}

}//End Loop

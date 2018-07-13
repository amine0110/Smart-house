String voice;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //for the LCD

#include <Servo.h> //for the servo or the door 
Servo door;



int one = 4;
int two = 5;
int three = 2;
int four = 3;
int ventilator = 7; //const

float voltage = 0;
float temperature; //for the temperature using LM35    

void roomOne(){
digitalWrite (one, HIGH); //this fonction to turn on the light of the room one ... the same thing with the other roomsssss
}
void oneOff(){
digitalWrite (one, LOW);
}
void roomTwo(){
digitalWrite (two, HIGH);
}
void twoOff(){
digitalWrite (two, LOW);
}
void roomThree(){
digitalWrite (three, HIGH);
}
void threeOff(){
digitalWrite (three, LOW);
}
void roomFour(){
digitalWrite (four, HIGH);  
}
void fourOff(){
digitalWrite(four, LOW);  
}
void venti(){
digitalWrite(ventilator, HIGH);
}
void ventilatorOff(){
digitalWrite(ventilator, LOW);  
}

void emergency() {
digitalWrite (one, LOW);
digitalWrite (two, LOW);
digitalWrite (three, LOW);
digitalWrite (four, LOW);
digitalWrite (ventilator, LOW); //this fonction is for the emergency it turn off the the digital pinsssss
}
void openDoor(){
door.write(180);
delay(10000);
door.write(0); //this fonction for the door or the servo yo can call it as you want
}
void closeDoor(){
door.write(0);  
}
void temp(){
voltage = analogRead(voltage);
temperature = (5.0*voltage*100.0)/1024.0; //this fonction to transform the voltage to a temperature

lcd.setCursor(11,1);
lcd.print(temperature);  
}
void setup() {
Serial.begin(9600);

lcd.begin(16,2);
lcd.backlight();

pinMode(one, OUTPUT);
pinMode(two, OUTPUT);
pinMode(three, OUTPUT);
pinMode(four, OUTPUT);
pinMode(ventilator, OUTPUT);

digitalWrite(one, LOW);
digitalWrite(two, LOW);
digitalWrite(three, LOW);
digitalWrite(four, LOW);
digitalWrite(ventilator, LOW);

door.attach(11);
door.write(0);
}
void loop() {
while(Serial.available()) {
delay(10);
char c=Serial.read();
if(c=='#')
{break; }
voice += c;
}
if (voice.length() > 0) {
Serial.println(voice);
if (voice == "room one" )
{
roomOne() ;
lcd.clear();
lcd.print("room one on");
}
else if (voice == "one off" || voice == "one of" ) // i used of because it's very hard to say off with this app  // as you have seen in the video 
{
oneOff() ;
}
else if(voice =="room 2" ){
roomTwo();
lcd.clear();
lcd.print("room two on");
}
else if(voice =="two off" || voice == "two of"){
twoOff();
}
else if(voice =="room 3"  ){
roomThree();
lcd.clear();
lcd.print("room three on");
}
else if( voice =="three off" || voice =="three of" ){
threeOff();
}
else if(voice =="room four" || voice =="room for"){
roomFour();
lcd.clear();
lcd.print("room four on");
}
else if(voice =="4 of" || voice == "for of"){ // i used for because it's very hard to say four with this app 
fourOff();
}
else if(voice =="ventilator"){
venti(); 
lcd.clear();
lcd.print("ventilator on"); 
}
else if(voice =="ventilator off"){
ventilatorOff();  
}
else if (voice == "open"){
lcd.clear(); 
lcd.print("Enter password");
}
else if (voice == "emergency"){
emergency();  
}
else if (voice == "6 5 8 2" || "six five eight two"){  // here we can change the password as we like
  
lcd.clear();
lcd.print("Welcome Amine"); 
lcd.setCursor(0,1);
lcd.print("temperature"); 
temp();
openDoor();  
}
else if (voice == "close"){
closeDoor();  
}
  

voice="";
}
}

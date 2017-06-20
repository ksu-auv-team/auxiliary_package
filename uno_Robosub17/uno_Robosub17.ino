//Define the libraries
#include <ros.h>
#include <std_msgs/Int32.h>
#include <Servo.h> 

//Define PINS used by components (2 Servos, LED Strips), and their variables
int ledStrips = 2;      //PIN2
Servo armServo;  		//PIN3
int pos3 = 0;			//Position of the servo for the arm
Servo dropperServo;     //PIN6
int pos6 = 0;			//Position of the servo for the dropper

//Instantiate the node handle
ros::NodeHandle nh;

//Callback function of subscriber, swith statements to be executed upon receiving messages from master
void unoMessage(const std_msgs::Int32& msg){

}

//Instantiate the Subscriber
ros::Subscriber<std_msgs::Int32> uno_Robosub2017("std_msgs/Int32",&unoMessage);

//Setup node and PINS
void setup()
{
  //Initialize node and Subscriber
  nh.initNode();
  nh.subscribe(uno_car);
  //Initialize PINS and set servos initial positions
  pinMode(ledStrips, OUTPUT);
  armServo.attach(3);        //attaches the Servo for the arm on PIN 3
  armServo.write(0); 		 //Set the Servo initial position to 0 degrees
  dropperServo.attach(6);    //attaches the Servo for the dropper on PIN 6
  dropperServo.write(0);     //Set the Servo initial position to 0 degrees
}

//Void loop mostly awaits for messages, doesn't do anything 
void loop()
{
  nh.spinOnce();
  delay(1);
}








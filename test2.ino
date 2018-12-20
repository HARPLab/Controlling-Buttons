/* 
     * Button Example for Rosserial
     */
    
    #include <ros.h>
    #include <std_msgs/Bool.h>
    #include <std_msgs/String.h>
    
    ros::NodeHandle nh;
   
   std_msgs:: String pushed_msg;
   ros::Publisher pub_button("pushed", &pushed_msg);
   
   const int button1 = 8;
   const int button2 = 9;
   const int button3 = 10;
   const int led_pin = 13;

  bool b1 = false;
  bool b2 = false;
  bool b3 = false;

  char* dataB1 = "1";
  char* dataB2 = "2";
  char* dataB3 = "3";


   long debounce_delay=250;

   bool last_readingB1;
long last_debounce_timeB1=0;
bool publishedB1 = true;

bool last_readingB2;
long last_debounce_timeB2=0;
bool publishedB2 = true;

bool last_readingB3;
long last_debounce_timeB3=0;
bool publishedB3 = true;
   
   void setup()
   {
     nh.initNode();
     nh.advertise(pub_button);
     
     //initialize an LED output pin 
     //and a input pin for our push button
     pinMode(led_pin, OUTPUT);
     pinMode(button1, INPUT);
     pinMode(button2, INPUT);
     pinMode(button3, INPUT);
   }
   
   void loop()
   {
    bool readingB1 =  digitalRead(button1);
    bool readingB2 =  digitalRead(button2);
    bool readingB3 =  digitalRead(button3);
  if (last_readingB1!= readingB1){
      last_debounce_timeB1 = millis();
      publishedB1 = false;
  }
  
  //if the button value has not changed for the debounce delay, we know its stable
  if ( !publishedB1 && (millis() - last_debounce_timeB1)  > debounce_delay) {
    digitalWrite(led_pin, readingB1);
    pushed_msg.data = dataB1;
    pub_button.publish(&pushed_msg);
    publishedB1 = true;
  }
if (last_readingB2!= readingB2){
      last_debounce_timeB2 = millis();
      publishedB2 = false;
  }
  
  //if the button value has not changed for the debounce delay, we know its stable
  if ( !publishedB2 && (millis() - last_debounce_timeB2)  > debounce_delay) {
    digitalWrite(led_pin, readingB2);
    pushed_msg.data = dataB2;
    pub_button.publish(&pushed_msg);
    publishedB2 = true;
  }
  if (last_readingB3!= readingB3){
      last_debounce_timeB3 = millis();
      publishedB3 = false;
  }
  
  //if the button value has not changed for the debounce delay, we know its stable
  if ( !publishedB3 && (millis() - last_debounce_timeB3)  > debounce_delay) {
    digitalWrite(led_pin, readingB3);
    pushed_msg.data = dataB3;
    pub_button.publish(&pushed_msg);
    publishedB3 = true;
  }
  last_readingB1 = readingB1;
  last_readingB2 = readingB2;
  last_readingB3 = readingB3;
      
     
     nh.spinOnce();
  }

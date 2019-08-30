#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#define OK1 0x78FA9946
#define OK2 0x8BAF4C83
IRrecv ali(2);

decode_results results;


void setup() 
{
Serial.begin(9600); 

ali.enableIRIn();

pinMode(3,OUTPUT);

digitalWrite(3,LOW);




pinMode(4,OUTPUT); // başka led gelirse

digitalWrite(4,LOW);
}

void loop() 
{
if (ali.decode(&results))  
 {
  Serial.print(results.value , HEX);
 if(results.value==OK1)
 

 digitalWrite( 3, !digitalRead(3));
 
if(results.value==OK2)
{
digitalWrite( 4, !digitalRead(4));
}

 
  ali.resume();
 }


}


#include <RH_ASK.h>


RH_ASK driver(3000,3,4);// speed,rx,tx

void setup()
{
    Serial.begin(9600);	// Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
	int i;

	// Message with a good checksum received, dump it.
	driver.printBuffer("Got:", buf, buflen);

String str="";
  for(int i=0;i<buflen;++i)
  {
    str=str+(char)buf[i];
  }
  
  Serial.println(str);
  
    }
}

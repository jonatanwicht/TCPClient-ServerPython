#include "Particle.h"

TCPClient client;
int port = 1727;
byte server[] = { x, x, x, x }; 

const size_t bufSize = 8;
unsigned char buf[bufSize];

void setup() {
    
    delay(5000);
    Serial.begin(9600);
    Serial.println("Setup \r");
    
    // Connect to the remote server
    if(client.connect(server, port)) {
        Serial.println("Connected \r");
    } else {
        // if we can't connect, then we display an error.
        Serial.println("Fail to connect... \r");
    }
    
}

void loop() {
    
    Serial.println("Loop ! \r");
	
    for(size_t i = 0; i < bufSize; i++) {
		buf[i] = i;
    }
	
    Serial.println("Buffer created ! \r");
    
    client.write(buf, bufSize);
    
    delay(10000);
}






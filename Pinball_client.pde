import processing.net.*; 
import processing.serial.*;

Client c;
Serial myPort;  

int charIn; 
String inString;
String data;

void setup() { 
  size(200, 200); 
  
  println(Serial.list()[3]);
  myPort = new Serial(this, Serial.list()[3], 9600);
  
  c = new Client(this, "192.168.1.7", 8080); // Connect to server on port 80
  c.write("GET / HTTP/1.0\r\n"); // Use the HTTP "GET" command to ask for a Web page
  c.write("\r\n");
  c.write("n=Rubin Huang");
  c.write("\r\n");
  
  myPort.write("A");
  
} 

void draw() { 
  
   while (myPort.available() > 0) {
    char dir = myPort.readChar();
    //print(dir);
    writeClient(dir);
    
    myPort.write("A");
   }
}


void writeClient(char dir){
  
  if(c.available() > 0){
  
  if( dir == 'r' || dir == 'l' ){
    
    if(frameCount%2 == 0){
    c.write(dir);  
    }
    
  }else{
    c.write(dir); 
  }
  
  }
  
}


// void testingInput(){

//     if (c.available() > 0) { 
     
//      if(frameCount%2==0){
//      if(keyPressed == true){
//      //println(keyCode);
//      if(keyCode == 38){
//      c.write("u");
//      }
//      else if(keyCode == 40){
//      c.write("d");
//      }
//      else if(keyCode == 39){
//      c.write("r");
//      }
//      else if(keyCode == 37){
//      c.write("l");
//      }
//      }
//      }

//    }

// }

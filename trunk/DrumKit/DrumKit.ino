#define DRUM1 0
#define THRESHOLD 200

byte val = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(DRUM1);

  if(val > THRESHOLD) { Serial.println("HARD"); }
  else if(val > 0) { Serial.println("SOFT"); }
 
}



void setup()
{
  pinMode(1, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(0, OUTPUT);
pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}
int income=0;
void loop()
{
  if(Serial.available()>0)
    {
      income=Serial.read();
        switch(income)
        {
          case 'f':
              forward();
              break;
            case 'b':
              backward();
              break;
            case 'l':
              left();
              break;
            case 'r':
              right();
              break;
            case 's':
              stop();
              break;
            default:
              break;
        }
    }
}

void forward()
{
  digitalWrite(1,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
}

void backward()
{
  digitalWrite(1,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(0,HIGH);
  digitalWrite1,LOW);
}

void left()
{
  digitalWrite(1,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(0,LOW);
  digitalWrite(0,LOW);
   digitalWrite(0,LOW);
  digitalWrite(2,LOW);
  digitalWrite(9,LOW);
}

void right()
{
  digitalWrite(1,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(0,LOW);
  digitalWrite(0,LOW);
    digitalWrite(0,LOW);
  digitalWrite(2,LOW);
  digitalWrite(9,LOW);
  
}

void stop()
{
  digitalWrite(1,LOW);
  digitalWrite(8,LOW);
  digitalWrite(0,LOW);
  digitalWrite(1,LOW);
}

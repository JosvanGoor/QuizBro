

int count = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.write(count++);
    Delay(1000);
}
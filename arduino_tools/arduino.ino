

int count = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.print(count++);
    delay(1000);
}
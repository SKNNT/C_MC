int ledPin = 13; // Пин для светодиода
int dotTime = 200; // Время для точки в миллисекундах

const char* morseCodes[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};
void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("Введите сообщение:");
}
void loop() {
    if (Serial.available() > 0) {
        String inputMessage = Serial.readString();
        inputMessage.toUpperCase();

        for (int i = 0; i < inputMessage.length(); i++) {
            char currentChar = inputMessage[i];
            
            if (currentChar == ' ') {
                delay(dotTime * 7);
            } else if (currentChar >= 'A' && currentChar <= 'Z') {
                sendMorse(currentChar - 'A');
            }
            delay(dotTime);
        }
        Serial.println("Сообщение отправлено");
    }
}
void sendMorse(int index) {
    const char* code = morseCodes[index];
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '.') {
            digitalWrite(ledPin, HIGH);
            delay(dotTime);
            digitalWrite(ledPin, LOW);
            delay(dotTime);
        } else if (code[i] == '-') {
            digitalWrite(ledPin, HIGH);
            delay(dotTime * 3);
            digitalWrite(ledPin, LOW);
            delay(dotTime);
        }
    }
}

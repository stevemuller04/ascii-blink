#define PIN1 1
#define PIN2 2

char *code = "HELLO WORLD";

void setup() {
	pinMode(PIN1, OUTPUT);
	pinMode(PIN2, OUTPUT);
	digitalWrite(PIN1, LOW);
	digitalWrite(PIN2, LOW);

	for (char *ptr = code; *ptr != 0; ptr++) {
		for (int i = 0; i < 7; i++) {
			char bit = ((*ptr) >> (6 - i)) & 1;
			if (bit)
				one();
			else
				zero();
			betweenBits();
		}
		betweenBytes();
	}
	end();
}

void loop() {
}

void one() {
	digitalWrite(PIN1, HIGH);
	digitalWrite(PIN2, LOW);
	delay(1000);
}

void zero() {
	digitalWrite(PIN1, LOW);
	digitalWrite(PIN2, HIGH);
	delay(1000);
}

void betweenBits() {
	digitalWrite(PIN1, LOW);
	digitalWrite(PIN2, LOW);
	delay(300);
}

void betweenBytes() {
	delay(1000);
}

void end() {
	for (int i = 0; i < 3; i++) {
		digitalWrite(PIN1, HIGH);
		digitalWrite(PIN2, HIGH);
		delay(100);
		digitalWrite(PIN1, LOW);
		digitalWrite(PIN2, LOW);
		delay(100);
	}
}

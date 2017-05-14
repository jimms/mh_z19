# A simple arduino library for MH-Z19 by using SoftwareSerial

## Example

```c

#define CO2_PWM_PIN 5
#define CO2_UART_TX_PIN 9
#define CO2_UART_RX_PIN 10

MH_Z19 mhz19(CO2_PWM_PIN, CO2_UART_TX_PIN, CO2_UART_RX_PIN);

void setup() {
	// ...

	mhz19.setup();

	// ...
}

void loop(void) {
	// ...

	Serial1.println(mhz19.read_pwm_value());
	Serial1.println(mhz19.read_uart_value());

	// ...
}
```

## Links

1. [MHZ19 Spec on Rev Space](https://revspace.nl/MHZ19)

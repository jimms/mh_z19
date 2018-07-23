#include <MH_Z19.h>

#define CO2_PWM_PIN 5
#define CO2_UART_TX_PIN 9
#define CO2_UART_RX_PIN 10

MH_Z19 co2(CO2_PWM_PIN, CO2_UART_TX_PIN, CO2_UART_RX_PIN);

void setup(void)
{
  Serial.begin(9600);

  co2.setup();
}

void loop(void)
{
  Serial.println(co2.read_pwm_value());
  Serial.println(co2.read_uart_value());
  Serial.println();

  delay(1000);
}

#include <RHReliableDatagram.h>                      // biblioteca Radiohead reliableDatagram
#include <RH_ASK.h>                                  // biblioteca Radiohead ASK
#include <SPI.h>                                     // biblioteca SPI
 
#define TX_ADDRESS 12                                 // endereço do transmissor
#define RX_ADDRESS 13                                 // endereço do recept

#define RF_RX_PIN 13
#define RF_TX_PIN 12

RH_ASK driver;                                       // instância RH ASK
RHReliableDatagram gerente(driver, TX_ADDRESS);      // configurando o gerenciador

RH_ASK RF_driver(5000, RF_RX_PIN, RF_TX_PIN, 0); 

uint8_t count = 1;                                   // contador
uint8_t data[] = "Mensagem de teste";                // mensagem a ser enviada
uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];                 // buffer da mensagem
 
void setup()
{
  Serial.begin(9600);                                // inicializa console serial 9600 bps
  if (!gerente.init())                               // se a inicialização do gerenciador falhar
    Serial.println("Falha na inicializacao");        // print na console serial
}
 
void loop()
{
  Serial.print("Transmitindo mensagem n. ");                // print na console serial
  Serial.println(count);                                    // print do contador 
  if (!gerente.sendtoWait(data, sizeof(data), RX_ADDRESS))  // se gerenciador enviar mensagem 
  {
    count++;                                                // incrementa contador 
  }
  delay(500);                                               // atraso 0,5 segundo
}

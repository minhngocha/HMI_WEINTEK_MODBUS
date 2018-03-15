/************************************************************
   INCLUDE
*/

/************************************************************
   DEFINE
*/
#define led1 13
#define led2 8
#define led3 7
#define analog0 A0

/************************************************************
   LOCAL VARIABLE
*/

enum {
  MB_40000,       // address in HIM  =  MB_400xx + 1
  MB_40001,       //
  MB_40002,       //
  MB_40003,       //
  MB_40004,       //
  MB_40005,       //
  MB_40006,       //
  MB_40007,       //
  //SAIDAS PWM
  MB_40008,       //
  MB_40009,       //
  MB_40010,       //
  MB_40011,       //
  //SAIDAS DIGITAIS
  MB_40012,       //
  MB_40013,       //
  MB_40014,       //
  MB_40015,       //
  //ENTRDAS DIGITAIS
  MB_40016,       //
  MB_40017,       //
  MB_40018,       //
  MB_40019,       //

  MB_REGS = 20,
};

/* Set one array to modbus */
unsigned int holdingRegs[MB_REGS]; // function 3 and 16 register array

/*******************************************
 * VOID SETUP
 */
void setup() {
  /* Configu mudbus */
  /* modbus_configure( &Serial , Baud , Serial_Format , Slave_ID , Transmit_enable , Array_modbus); */
  /* Serial_Format is SERIAL_8N2 or SERIAL_8E1 */
  modbus_configure(&Serial, 9600, SERIAL_8E1, 1, 7, MB_REGS, holdingRegs);

  /* Set pin mode */
  pinMode(13, OUTPUT);

}


void loop()
{

  holdingRegs[MB_40003] = analogRead(A0);
  modbus_update();

  digitalWrite(13, holdingRegs[MB_40000]);

}








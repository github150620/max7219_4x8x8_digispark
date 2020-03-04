// How to use a 4 * max7219 module.
//
// Register Settings
// 1. Decode Mode:
//   0 - No decode;
//   0x01 - Code B decode for digit 0, No decode for digits 1~7;
//   0x03 - Code B decode for digits 0~1, No decode for digits 2~7;
//   ...
//   0xff - Code B decode for digits 0~7;
//
// 2. Intensity:
//   0 - Darkest;
//   1 - Darker;
//   2 - Dark;
//   ...
//   5 - Bright;
//   6 - Brighter;
//   7 - Brightest;
//
// 3. Scan Limit:
//   0 ~ 7 - The number of rows will be used.
//
// 4. Shutdown:
//   0 - Shutdown;
//   1 - Normal;

#define ADDR_NOOP        0
#define ADDR_DIGIT0      1
#define ADDR_DIGIT1      2
#define ADDR_DIGIT2      3
#define ADDR_DIGIT3      4
#define ADDR_DIGIT4      5
#define ADDR_DIGIT5      6
#define ADDR_DIGIT6      7
#define ADDR_DIGIT7      8
#define ADDR_DECODEMODE  9
#define ADDR_INTENSITY   10
#define ADDR_SCANLIMIT   11
#define ADDR_SHUTDOWN    12
#define ADDR_DISPLAYTEST 15

byte font[10][8] = {
  {0x7E,0x7E,0x66,0x66,0x66,0x66,0x7E,0x7E}, // "0"
  {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18}, // "1"
  {0x7E,0x7E,0x06,0x7E,0x7E,0x60,0x7E,0x7E}, // "2"
  {0x7E,0x7E,0x06,0x7E,0x7E,0x06,0x7E,0x7E}, // "3"
  {0x66,0x66,0x66,0x7E,0x7E,0x06,0x06,0x06}, // "4"
  {0x7E,0x7E,0x60,0x7E,0x7E,0x06,0x7E,0x7E}, // "5"
  {0x7E,0x7E,0x60,0x7E,0x7E,0x66,0x7E,0x7E}, // "6"
  {0x7E,0x7E,0x06,0x06,0x06,0x06,0x06,0x06}, // "7"
  {0x7E,0x7E,0x66,0x7E,0x7E,0x66,0x7E,0x7E}, // "8"
  {0x7E,0x7E,0x66,0x7E,0x7E,0x06,0x7E,0x7E}  // "9"
};

int buf[4] = {0, 0, 0, 0};  // Display buffer

int SPI_MOSI = 0;
int SPI_CLK  = 2;
int SPI_CS   = 1;

void max7219Write(byte addr, byte data) {
  shiftOut(SPI_MOSI,SPI_CLK, MSBFIRST, addr);
  shiftOut(SPI_MOSI,SPI_CLK, MSBFIRST, data);  
}

void setup() {
  // put your setup code here, to run once:
  pinMode(SPI_MOSI, OUTPUT);
  pinMode(SPI_CLK, OUTPUT);
  pinMode(SPI_CS, OUTPUT);
  digitalWrite(SPI_CS, HIGH);

  digitalWrite(SPI_CS, LOW);
  max7219Write(ADDR_DECODEMODE, 0); // Set no decode mode.
  digitalWrite(SPI_CS, HIGH);
  
  digitalWrite(SPI_CS, LOW);
  max7219Write(ADDR_INTENSITY, 0); // Set darkest display.
  digitalWrite(SPI_CS, HIGH);
  
  digitalWrite(SPI_CS, LOW);
  max7219Write(ADDR_SCANLIMIT, 7); // Set all rows working.
  digitalWrite(SPI_CS, HIGH);
  
  digitalWrite(SPI_CS, LOW);
  max7219Write(ADDR_SHUTDOWN, 1); // Turn on display.
  digitalWrite(SPI_CS, HIGH);
  
  digitalWrite(SPI_CS, LOW);
  max7219Write(ADDR_DISPLAYTEST, 0); // Turn off display test.
  digitalWrite(SPI_CS, HIGH);
  
  digitalWrite(SPI_CS, LOW);
  max7219Write(ADDR_NOOP, 0); // After the command, last command will reach the 2nd max7219.
  digitalWrite(SPI_CS, HIGH);

  digitalWrite(SPI_CS, LOW);
  max7219Write(ADDR_NOOP, 0); // After the command, last command will reach the 3rd max7219.
  digitalWrite(SPI_CS,HIGH);

  digitalWrite(SPI_CS, LOW);
  max7219Write(ADDR_NOOP, 0); // After the command, last command will reach the 4th max7219.
  digitalWrite(SPI_CS, HIGH);
}

int n = -1;

void loop() {
  n++;
  
  buf[0] = (n / 1000) % 10;
  buf[1] = (n / 100) % 10;
  buf[2] = (n / 10) % 10;
  buf[3] = (n / 1) % 10;
  
  for (int i=0;i<8;i++) {
    digitalWrite(SPI_CS, LOW);
    max7219Write(i+1, font[buf[0]][i]);
    max7219Write(i+1, font[buf[1]][i]);
    max7219Write(i+1, font[buf[2]][i]);
    max7219Write(i+1, font[buf[3]][i]);
    digitalWrite(SPI_CS, HIGH);
  }

  delay(1000);
}

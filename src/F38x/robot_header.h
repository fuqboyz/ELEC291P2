#define SYSCLK    48000000L // SYSCLK frequency in Hz
#define BAUDRATE  115200L   // Baud rate of UART in bps

// useful defines
#define HIGH 1
#define LOW 0

// motor pins
#define MOTOR_LEFT0 P1_5
#define MOTOR_LEFT1 P1_6
#define MOTOR_RIGHT0 P2_0
#define MOTOR_RIGHT1 P2_1

// ADC read pins
#define TANK_FL LQFP32_MUX_P2_3
#define TANK_FR LQFP32_MUX_P2_4
#define TANK_RL LQFP32_MUX_P2_5
#define TANK_RR LQFP32_MUX_P2_6

// Command receiving
#define COMMAND_PIN P1_1
#define	CMDFRQ 64

// Commands
#define CMD_NONE 0
#define CMD_LEFT 1
#define CMD_RIGHT 2
#define CMD_FORWARD 3
#define CMD_REVERSE 4
#define CMD_STOP 5
#define CMD_UTURN 6

// Robot states
#define FORWARD_STATE 1
#define REVERSE_STATE 2
#define STOP_STATE 3
#define DEBUG_STATE 4

// sonar
#define Trigger     P0_6 
#define Echo		P0_1

// blinkers
#define L_BLINKER P0_3
#define R_BLINKER P0_2

// ===[FUNCTION PROTOTYPES]===
// system functions
char _c51_external_startup(void);

// timing functions
void Timer3us(unsigned char us);
void waitms (unsigned int ms);

void TIMER0_Init(void);

// adc functions
void InitADC(void);
void InitPinADC(unsigned char portno, unsigned char pinno);
unsigned int ADC_at_Pin(unsigned char pin);
float Volts_at_Pin(unsigned char pin);

// robot control functions
unsigned char readData(unsigned char prevcommand);
void forward_backward(unsigned char direction);
void linetrack(int forwardbackward);
void stopcar(void);
void turncar(int leftright);
void uturn(void);
void movecar (int forback, int power);

// led matrix functions
void mxDirection(unsigned char flipped);
void mxGo(unsigned char flipped);
void mxStop(void);
void mxUTurn(void);

// led matrix helper functions
unsigned char reverse(unsigned char b);
void mxSPI(unsigned char value); // FIX ME
void mxPulse(void);
void mxClear(void);
void mxWrite(unsigned char address, unsigned char value); // FIX ME
void mxTest(void);
void mxDisplay(unsigned char *grid, unsigned char options); // FIXME
void mxSetIntensity(unsigned char intensity);
void mxInit(void);
void Sonar_Reading(void);

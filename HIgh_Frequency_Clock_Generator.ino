
//
// This is a modified version of a sketch from (http://forum.arduino.cc/index.php?topic=74977.0)
// Timer 2 is used to generate a high freqeuncy singal by dividing the onboard clock
//



float Frequency=31500; // Enter freqeuncy in Hz

const int freqOutputPin = 11;   // OC2A output pin for ATmega328 boards
const int prescale  = 1;
float  DivVar; //Frequency Dvision Factor
float Period;


void setup()
{
  Period = (1/Frequency)*1.0e6;
  DivVar=  (F_CPU/2/Frequency)-1;
  pinMode(freqOutputPin, OUTPUT);
  Serial.begin(9600);

  
   TCCR2A = ((1 << WGM21) | (1 << COM2A0));

   // Set Timer 2  No prescaling  (i.e. prescale division = 1)
   // CS22:0 = 001: Use CPU clock with no prescaling
   // CS2 bits 2:0 are all in TCCR2B
   
   TCCR2B = (1 << CS20);
   TIMSK2 = 0;
   
   
   OCR2A = DivVar; // This value determines the output frequency

   Serial.print("CPU Clock Frequency: ");
   Serial.print(F_CPU/1.0e6); 
   Serial.println(" MHz");
   Serial.print("Frequency Division Factor: "); 
   Serial.println(DivVar); 
   Serial.print("Ouput Frequency = ");
   Serial.print(Frequency); 
   Serial.println(" Hz");
   Serial.print("Period    = ");
   Serial.print(Period); 
   Serial.println(" microseconds");
   Serial.println("Duty Cycle = 50%");
    
}


void loop()
{
   // Do (almost) anything you want here.  Just don't do analogWrite to
   // pins controlled by Timer 2.  In fact, don't do anything that messes
   // with the registers in Timer 2.
}

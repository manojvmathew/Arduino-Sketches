int SignalPin=9;      // Specify the DIO pin number
double Freq=9000;     // Specify the required freqeuncy in hertz
double DutyCycle=20;  // Specify duty cycle in percentage
double Counter=10000000; // Specifiy the no: of trigger pulses required.
double Period;        // Period is calulated in the code
double TOn;           // Calculated in the code
double TOff;           // Calcualted in the code
double c;             // Declares a variable
int CorrFactor=20;     // Correction Factor
void setup()
{ 
 
  Period=(1000000/Freq);      // Calculates period in microseconds
  TOn=(DutyCycle/100)*Period; // Calculates On Time
  TOn=int(TOn);               // Converts the value to an integer              
  TOff=Period-TOn;            // Calculates Off Time
  TOff=int(TOff);             // Converts the value to an integer

if (TOn>CorrFactor)
   {TOn=TOn-CorrFactor;
   }
if (TOff>CorrFactor)
   {TOff=TOff-CorrFactor;
   }

  pinMode(SignalPin, OUTPUT);   // sets the pin as output
      
  //  Writes the calulated values to the COM port. Can be read on the serial monitor
  // This is optional but helps in troubleshooting
    
    Serial.begin(9600);
    Serial.print("Time Period (microseconds)=: ");
    Serial.println(Period);
    Serial.print("ON Time (microseconds)=: ");
    Serial.println(TOn);
    Serial.print("OFF Time (microseconds)=: ");
    Serial.println(TOff); 
    
}

void loop()
{
if (c < Counter)
      {delayMicroseconds(TOff);    // Delay output for duration equials to TOff
  digitalWrite(SignalPin, HIGH);   // Write High Voltage onto output pin

    delayMicroseconds(TOn);        // Delay output for duration equials to TOn
  digitalWrite(SignalPin,LOW);     // Write Low Voltage onto output pin
    c = c+1;
      }
}



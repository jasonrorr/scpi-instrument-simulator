# SCPI Instrument Simulator
A project to convert a cheap prototyping board (rpi pico, arduino, etc.) into a SCPI-compliant instrument for simulation and hardware test purposes. This project will adhere to the SCPI-99 standard.

## Supported Boards
- Arduino Nano
- Arduino Pro Micro (ATMega32U4)*
- Arduino Uno*
- Raspberry Pi Pico*

*Planned

## Supported Interfaces
- USB (Serial)
- TCP/IP*
- UDP*

*Planned

## SCPI Commands
### Mandatory Commands in SCPI-99

- *CLS - Clear Status Command
- *ESE - Standard Event Status Enable Command
- *ESE? - Standard Event Status Enable Query
- *ESR? - Standard Event Status Register Query
- *IDN? - Identification Query
- *OPC - Operation Complete Command
- *OPC? - Operation Complete Query
- *RST - Reset Command
- *SRE - Service Request Enable Command
- *SRE? - Service Request Enable Query
- *STB? - Read Status Byte Query
- *TST? - Self-Test Query
- *WAI - Wait-to-Continue Command
- :SYSTem
  - :ERRor? - Error Query Command
  - :VERSion? - Firmware Version Query COmmand
- STATus
  - :OPERation?
    - :CONDition?
    - ENABle
    - ENABle?
  - QUEStionable
    - :CONDition?
    - :ENABle
    - :ENABle?
  - :PRESet

### Additional Commands
- :FETCh
  - :SCALar
    - :<CURRent|RESistance|TEMPerature|VOLTage>?
  - :ARRay
    - :<CURRent|RESistance|TEMPerature|VOLTage>?
- :MEASure:<CURRent|RESistance|TEMPerature|VOLTage>?
- :OUTPut
  - :OFF
    - :<Line>
  - :ON
    - :<Line>
  - :STATe
    - :<Line>?
- :SENSe
  - :<CURRent:[:DC]|RESistance|TEMPerature|VOLTage[:DC]>
  - :TEMPerature
    - :UNITs<C|F|K>
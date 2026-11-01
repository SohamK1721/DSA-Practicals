Q1: What is UART?

UART stands for Universal Asynchronous Receiver/Transmitter.
It is a hardware block (or peripheral) inside a microcontroller that converts parallel data from the processor into a serial bit stream for transmission,
and converts incoming serial bits back into parallel data on reception.

Q2: Why use a circular buffer for UART?

UART data arrives at unpredictable times, and the CPU may be busy doing something else when a byte arrives. 
If the CPU does not read each byte before the next one arrives, data is overwritten. A buffer solves this by temporarily storing incoming bytes.

Q3: What happens when the buffer is full?

When the buffer is full and a new byte arrives, there is no space left to store it.
This is called a buffer overflow (or overrun). Depending on how the software is designed, one of the following happens:
1.Drop the new data
2.Overwrite the oldest data
3.Flow control
4.Set an error flag

Q4: Is UART synchronous or asynchronous?

UART is asynchronous, meaning there is no shared clock line between the transmitter and receiver. Instead:

Both devices must be pre-configured to the same baud rate, data bits, parity, and stop bits.
The start bit (a high-to-low transition) tells the receiver that a frame is beginning. The receiver then starts its own internal timer and samples each bit at the middle of its bit period.
The stop bit(s) mark the end of the frame and return the line to idle (high).

Q5: What is baud rate?

Baud rate is the speed of communication, i.e. the number of signal changes (symbols) per second. 
In UART, each symbol carries one bit, so baud rate is effectively the same as bits per second (

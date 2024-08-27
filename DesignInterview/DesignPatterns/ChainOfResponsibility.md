# Chain Of Responsibility

Suppose we have a bunch of Processors each capable of processing some part of the request. But not sure what so we can use this Design Pattern.

Ex.

We are designing an ATM system where we requested a withdrawl of Rs 2300. We can have a bunch of processors which handle withdrawl of Rs 2000, Rs 500 and Rs 100.


Chain would be like

Request(Rs 2300) -> Process(Rs 2000) -> Request(Rs 300) -> Process(Rs 500) -> Request(Rs 300) -> Process(Rs 100) -> Request(Rs 0)

Similarly we can create Solution for Vending Machines and Logging system, where we divide responsibilities such that 
# Concurrency Control

Critical Resaource-> Common resource used by multiple threads simultaneously.

synchronized()-> synchonised block is put around the critical resource to ensure that only one request/thread uses it at a time. This doesn't work in distributed software where we have different instance of the same program running.

## Distributed Concurrency Control

1. What is the usage of Transaction?

Helps us avoid inconsistency in DB.

2. What is DB Locking?

Ensures that no other transaction can update a Locked Row.

a. Shared Locks(S): Read Locks, Wont allow an Exclusive Lock to Update the System as long as a Shared Lock is active
b. Exclusive Locks(X): Write Locks

3. What are the Isolation Level Present?


# Handling Null Obj

How to avoid check of '!= null'

1. A Null Object returns Null
2. No Need to check if 'obj != NULL'
3. Null Object reflects do Nothing behaviour or the default behaviour

class Vehicle {
    void method();
}

class Car extends Vehicle {
    // Override
    void method();
}

class Bike extends Vehicle {
    // Override
    void method();
}

class NullVehicle extends Vehicle {
    // Override
    void method();
}

class Main {
    Vehicle v;

    public static void main() {
        v = getVehicleObject("CAR");
    }
}
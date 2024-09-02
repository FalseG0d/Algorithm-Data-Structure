## Strategy Design Pattern

A Child class will always extend the functionality of the Base class that is given, but sometimes two or more child classes will have the same functionality. This will lead to Code duplication. To avoid this we can use Strategy Design Pattern.

class Vehicle {
    void drive() {

    }
};

class FamilyCar extends Vehicle {
    void drive() {
        // Normal Drive
    }
};

class LuxuryCar extends Vehicle {
    void drive() {
        // Special Drive
    }
};

class SportsCar extends Vehicle {
    void drive() {
        // Special Drive
    }
};

// Will become


interface DriveStrategy {
    void drive() {

    }
};

// Implement new Drive Strategy as they are Designed

class StandardDriveStrategy implements DriveStrategy {

}

class SportsDriveStrategy implements DriveStrategy {
    
}

class Vehicle {
    DriveStrategy drive;

    Vehicle(DriveStrategy drive) {
        this.drive = drive;
    }

    void drive() {
        this.drive.drive();
    }
};

class FamilyCar extends Vehicle {
    FamilyCar() {
        super(new StandardDriveStrategy());
    }
};

class LuxuryCar extends Vehicle {
    LuxuryCar() {
        super(new SportsDriveStrategy());
    }
};

class SportsCar extends Vehicle {
    SportsCar() {
        super(new SportsDriveStrategy());
    }
};
# SOLID Principles

1. S -> Single Responsibvility 
2. O -> Open to Extension/Close to Modification
3. L -> Liskov Subsitution
4. I -> Interface Segragation
5. D -> Dependency Inversion


## Single Responsibility

A class should have only one reason to change/One class should have a single responsibility

eg.

class Marker {
    int price;
    Color color;
};


class MarkerInvoice {
    List<Marker>markers;
    List<int>quantity;

    // Create Invoice

    MarkerInvoice(List<Marker>markers, List<int>quantity) {
        this.markers = markers;
        this.quantity = quantity;
    }

    long long getTotal() {
        long long total = 0;
        int N = markers.size();
        
        for(int i=0;i<N;i++) {
            total += markers[i].price * quantity[i];
        }

        return total;
    }

    void saveToDB() {
        
    }

    void shareInvoice() {
        
    }
};

// This should be broken into

class MarkerInvoice {
    List<Marker>markers;
    List<int>quantity;

    // Create Invoice

    MarkerInvoice(List<Marker>markers, List<int>quantity) {
        this.markers = markers;
        this.quantity = quantity;
    }

    long long getTotal() {
        long long total = 0;
        int N = markers.size();
        
        for(int i=0;i<N;i++) {
            total += markers[i].price * quantity[i];
        }

        return total;
    }
};

class MarkerInvoicDAO {
    MarkerInvoice mi;

    void saveToDB() {

    }
};

class MarkerInvoiceShare {
    MarkerInvoice mi;

    void shareInvoice() {

    }
};

## Open to Extension/Close to Modification

Once a class has been checked into production we can assume that it has been tested and any changes made to it now will only cause Bugs.

We should thus only keep the class open to extension so that any bugs which do occur remain in the New Code(currently being tested) and not the Older Code(in production).


class InvoiceDao {
    // Implementation

    void saveToDB()
    void saveToCloud()
    void saveToFile()
};

// should become

interface InvoiceDao {
    void save()
}

class DBInvoiceDao implements InvoidDao {
    void save() {
        // Save to DB
    }
}

class CloudInvoiceDao implements InvoidDao {
    void save() {
        // Save to Cloud
    }
}

class FileInvoiceDao implements InvoidDao {
    void save() {
        // Save to File
    }
}

## Liskov Subsitution

A subclass should extend the capability of the parent and not narrow it down

A child class should be able to subsitute a base class without breaking the progam behaviour

class Motorcycle {
    void turnEngineOn() {

    }
}

class Bike extends Motorcycle {
    void turnEngineOn() {
        // NA
    }
}

## Interface Segmentation

Interfaces should be such that Classes don't need to implement useless features

interface RestaurantWorker {
    void serveFood()
    void takeOrder()
    void washDished()
    void cookFood()
}

class Waiter extends RestaurantWorker{
    void serveFood()
    void takeOrder()
    void decideMenu() // Not Needed
    void cookFood() // Not Needed
}

// This should be like

interface CheffInterface {
    void decideMenu()
    void cookFood()
}

interface WaiterInterface {
    void serveFood()
    void takeOrder()
}

class Waiter extends WaiterInterface {
    void serveFood()
    void takeOrder()
}

## Dependency Inversion

Class should depend on interfaces instead of concrete class.

class Laptop {
    WiredKeyboard keyboard;
    WiredMouse mouse;
};

class Main() {
    public static void main(String arg[]) {
        // This will cause an issue
        Laptop lp = new Laptop(new WirelessKeyboard(), new WirelessMouse());
    }
};

// This should instead be

interface Keyboard {

};

interface Mouse {

};

class WiredKeyboard implements Keyboard {

};

class WiredMouse implements Mouse {

};

class WirelessKeyboard implements Keyboard {

};

class WirelessMouse implements Mouse {

};

class Laptop {
    Keyboard keyboard;
    Mouse mouse;
};

class Main() {
    public static void main(String arg[]) {
        // This will cause an issue
        Laptop wirelessLP = new Laptop(new WirelessKeyboard(), new WirelessMouse());
        Laptop wiredLP = new Laptop(new WiredKeyboard(), new WiredMouse());
    }
};
# Adapter Design Pattern

A bridge between eisting interface and expected interface. 

Convert Weight from Pound to Kg

class Client {
    public static void main() {
        Adapter ad = new AdapterImpl();
        int wt = ad.getWeightInKG();
    }
}

class BabyWeight {
    int getWeightInPounds() {
        return 28;
    }
}

interfact Adapter {
    int getWeightInKG();
}

class AdapterImpl {
    BabyWeight bw;
    AdapterImpl() {
        bw = new BabyWeight();
    }
    int getWeightInKG() {
        return 0.45 * bw.getWeightInPounds();
    }
}
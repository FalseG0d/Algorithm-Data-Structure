# Obvserver Design Patter

1. Observable: Notifies all Obvservers that its state has changed
2. Observer: Performs necessary operations when State Change is observed

interface ObserverInterface {
    void update()
}

interface ObservableInterface {
    int state;
    List<ObserverInterface> observers;

    void register(ObserverInterface oi) {
        observers.add(oi);
    }

    void remove(ObserverInterface oi) {
        observers.remove(oi);
    }

    void notify() {
        observers.forEach(obvserver => obvserver.update());
    }
    
    void setData(int state) {
        this.state = state;
        this.notify();
    }
}
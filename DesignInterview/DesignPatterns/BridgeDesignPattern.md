# Bridge Dessign Pattern

Bridge decouples Abstraction from its Implementation. So that they both can vary independently.

abstract class Living {
    void breathe();
}

abstract class Dog extends Living {
    void breathe() {

    }
}

abstract class Fish extends Living {
    void breathe() {

    }
}

abstract class Tree extends Living {
    void breathe() {

    }
}

Here to introduce another breathing process we need to introduce another class, instead we can do the following.

intrface BreatheImplementor {
    void breathe();
}

intrface LandBreatheImpl extends BreatheImplementor {
    void breathe() {

    }
}

intrface WaterBreatheImpl extends BreatheImplementor {
    void breathe() {

    }
}

intrface TreeBreatheImpl extends BreatheImplementor {
    void breathe() {

    }
}

class Living {
    BreatheImplementor breatheImpl;

    Living(BreatheImplementor breatheImpl) {
        this.breatheImpl = breatheImpl;
    }
}

class Dog extends Living {
    Dog(BreatheImplementor breatheImpl) {
        super(breatheImpl);
    }

    void breathe() {
        this.breatheImpl.breathe();
    }
}
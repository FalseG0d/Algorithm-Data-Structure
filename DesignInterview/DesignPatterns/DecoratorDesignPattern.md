# Decorator Design Pattern


Decorators have both Is-A and Has-A relation with BaseClass

Class Explosion: Too many child classes with too similar functionality or a combination of generic functionalities

public abstract class BasePizza {
    public abstract int cost();
}

public class Farmhouse extends BasePizza {
    @Override
    int cost() {
        return 200;
    }
}

public class VegDelight extends BasePizza {
    @Override
    int cost() {
        return 120;
    }
}

public class Margherita extends BasePizza {
    @Override
    int cost() {
        return 100;
    }
}

public abstract class ToppingsDecorator extends BasePizza {

}

public class ExtraCheeseDecorator extends ToppingsDecorator {
    BasePizza bp;

    public ExtraCheese(BasePizza bp) {
        this.bp = bp;
    }

    public int cost() {
        return this.bp.cost() + 15;
    }
}

public class ExtraMushroomDecorator extends ToppingsDecorator {
    BasePizza bp;

    public ExtraMushroom(BasePizza bp) {
        this.bp = bp;
    }

    public int cost() {
        return this.bp.cost() + 20;
    }
}

BasePizza bp = new ExtraMushroomDecorator(new ExtraCheeseDecorator(new Farmhouse()));